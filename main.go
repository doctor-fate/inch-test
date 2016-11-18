package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
	"sync"
	"sync/atomic"
)

var failed uint32

type file struct {
	path string
	name string
}

type result struct {
	name string
	out  string
	err  error
}

func walkFiles(root string) (<-chan file, <-chan error) {
	paths := make(chan file)
	errc := make(chan error, 1)
	go func() {
		defer close(paths)

		errc <- filepath.Walk(root, func(path string, info os.FileInfo, err error) error {
			if err != nil {
				return err
			}
			if info.Mode().IsRegular() {
				paths <- file{path, info.Name()}
			}
			return nil
		})
	}()

	return paths, errc
}

func execer(checker string, paths <-chan file, rc chan<- result) {
	var bout bytes.Buffer
	for f := range paths {
		cmd := exec.Command("clang", "-std=c11", "-w", "-fsyntax-only", "-c", f.path)
		if err := cmd.Run(); err != nil {
			atomic.AddUint32(&failed, 1)
			continue
		}

		bout.Reset()
		cmd = exec.Command(checker, f.path)
		cmd.Stdout = &bout
		if err := cmd.Run(); err != nil {
			panic(err)
		}

		if strings.Contains(f.name, "GOOD") && bout.Len() > 0 {
			rc <- result{f.name, bout.String(), nil}
		} else if strings.Contains(f.name, "BAD") && bout.Len() == 0 {
			rc <- result{f.name, "not catched", nil}
		}
	}
}

func testAll(checker, root string, w io.Writer) error {
	paths, errc := walkFiles(root)

	rc := make(chan result)
	var wg sync.WaitGroup
	const nw = 128
	wg.Add(nw)
	for i := 0; i < nw; i++ {
		go func() {
			execer(checker, paths, rc)
			wg.Done()
		}()
	}

	go func() {
		wg.Wait()
		close(rc)
	}()

	for r := range rc {
		if r.err == nil {
			fmt.Fprintf(w, "%s: %s\n", r.name, r.out)
		}
	}

	if err := <-errc; err != nil {
		return err
	}

	return nil
}

func main() {
	if len(os.Args) < 3 {
		panic("len(os.Args) < 3")
	}

	w, err := os.Create("wrong.log")
	if err != nil {
		panic(err)
	}
	defer w.Close()

	if err := os.Chdir(os.Args[2]); err != nil {
		panic(err)
	}

	if err := testAll(os.Args[1], os.Args[2], w); err != nil {
		panic(err)
	}

	fmt.Printf("failed to compile: %d\n", failed)
}

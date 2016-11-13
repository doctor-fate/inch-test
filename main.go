package main

import (
	"bytes"
	"fmt"
	"io"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
	"sync"
	"sync/atomic"
)

var all, wrong, failed uint32

type file struct {
	path string
	name string
}

type result struct {
	path string
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
				all++
				paths <- file{path, info.Name()}
			}
			return nil
		})
	}()

	return paths, errc
}

func execer(checker string, paths <-chan file, c chan<- result) {
	for f := range paths {
		var bout, berr bytes.Buffer
		cmd := exec.Command("gcc", "-std=c11", "-w", "-fsyntax-only", "-c", f.path)
		cmd.Stderr = &berr
		if err := cmd.Run(); err != nil {
			atomic.AddUint32(&failed, 1)
			continue
		}

		cmd = exec.Command(checker, f.path)
		cmd.Stdout = &bout
		cmd.Stderr = &berr
		if err := cmd.Run(); err != nil {
			c <- result{f.name, berr.String(), err}
		}

		if strings.Contains(f.name, "GOOD") && bout.Len() > 0 {
			atomic.AddUint32(&wrong, 1)
			c <- result{f.name, bout.String(), nil}
		} else if strings.Contains(f.name, "BAD") && bout.Len() == 0 {
			atomic.AddUint32(&wrong, 1)
			c <- result{f.name, "not catched", nil}
		}
	}
}

func testAll(checker, root string, w io.Writer) error {
	paths, errc := walkFiles(root)

	c := make(chan result)
	var wg sync.WaitGroup
	const nw = 32
	wg.Add(nw)
	for i := 0; i < nw; i++ {
		go func() {
			execer(checker, paths, c)
			wg.Done()
		}()
	}

	go func() {
		wg.Wait()
		close(c)
	}()

	for r := range c {
		if r.err != nil {
			log.Printf("%s: %s\n", r.path, r.out)
			continue
		}
		fmt.Fprintf(w, "%s: %s\n", r.path, r.out)
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

	out, err := os.Create("out.stat")
	if err != nil {
		panic(err)
	}
	defer out.Close()

	if err := testAll(os.Args[1], os.Args[2], out); err != nil {
		panic(err)
	}

	fmt.Printf("all: %d\n", all)
	fmt.Printf("wrong: %d\n", wrong)
	fmt.Printf("failed to compile: %d\n", failed)
}

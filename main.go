package main

import (
	"bytes"
	"errors"
	"fmt"
	"go/build"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

func init() {
	p, err := build.Import("github.com/doctor-fate/inch_test", "", build.FindOnly)
	if err != nil {
		log.Fatalln("Unable to find Go package in your GOPATH, it's needed to load tests:", err)
	}
	err = os.Chdir(p.Dir)
	if err != nil {
		log.Panicln("os.Chdir:", err)
	}
}

func main() {
	if len(os.Args) < 2 {
		log.Fatalln("specify 'inch' program")
		return
	}
	checker := os.Args[1]
	if err := filepath.Walk("testdata", func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}

		if info.IsDir() {
			return nil
		}

		var bout, berr bytes.Buffer
		cmd := exec.Command(checker, path)
		cmd.Stdout = &bout
		cmd.Stderr = &berr
		if err := cmd.Run(); err != nil {
			return err
		}
		name := info.Name()
		if strings.Contains(name, "GOOD") && bout.Len() > 0 {
			return errors.New(fmt.Sprintf("%s: %s", name, bout.String()))
		} else if strings.Contains(name, "BAD") && bout.Len() == 0 {
			return errors.New(fmt.Sprintf("%s: not catched", name))
		}

		return nil
	}); err != nil {
		log.Println(err)
	}
}

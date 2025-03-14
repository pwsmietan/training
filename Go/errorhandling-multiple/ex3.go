package main

import (
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	f, err := os.Create("foo.txt")
	if err != nil {
		fmt.Println("Error: ", err)
		return
	}

	defer f.Close()
	txt := strings.NewReader("this is a test!\n")
	io.Copy(f, txt)
}

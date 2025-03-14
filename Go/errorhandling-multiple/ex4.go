package main

import (
	"fmt"
	"io"
	"os"
)

func main() {
	f, err := os.Open("foo.txt")
	if err != nil {
		fmt.Println("Error: ", err)
		return
	}
	defer f.Close()

	txt, err2 := io.ReadAll(f)
	if err != nil {
		fmt.Println("Error: ", err2)
		return
	}

	fmt.Println(string(txt))
}

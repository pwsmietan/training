package main

import (
	"fmt"
	"io"
	"log"
	"os"
)

func main() {
	f, err := os.Open("foo.txt")
	if err != nil {
		fmt.Println("Error: ", err)
		log.Println("An error occured during open: ", err)
		return
	}
	defer f.Close()

	txt, err2 := io.ReadAll(f)
	if err != nil {
		fmt.Println("Error: ", err2)
		log.Println("An error occured during read: ", err)
		return
	}

	fmt.Println(string(txt))
}

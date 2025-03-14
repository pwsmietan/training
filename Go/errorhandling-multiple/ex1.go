package main

import (
	"fmt"
)

func main() {
	n, err := fmt.Println("Hello Go!")
	fmt.Printf("n: %d; err: %v\n", n, err)
	if err != nil {
		fmt.Println(err)
	}

}

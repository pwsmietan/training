package main

import (
	"fmt"
)

func main() {
	fmt.Println("Defer / Panic / Recover")
	fmt.Printf("throw() = panic\ncatch() = recover; neither are used by purists of Go.\n" +
		"Best practice is to return error objects from functions.\n")

	defer func() {
		if r := recover(); r != nil {
			fmt.Println("Recovered from function with div by 0")
		}
	}()

	// Go will report a +inf message on the div by 0:
	bad()

	n, err := fmt.Println("Hello Go!")
	fmt.Printf("n: %d; err: %v\n", n, err)
	if err != nil {
		fmt.Println(err)
	}

	var answer string
	fmt.Println("Enter name:")
	n, err = fmt.Scan(&answer)
	fmt.Printf("n: %d; err: %v; name: %s\n", n, err, answer)

	fmt.Println("EOJ")
}

func bad() {
	a := 1.0
	b := 0.0
	fmt.Println(a / b)
}

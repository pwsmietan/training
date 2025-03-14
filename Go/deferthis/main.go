package main

import (
	"fmt"
)

func main() {
	f()
	fmt.Println("Returned normally from f()")
}

func f() {
	defer func() {
		fmt.Println("Getting recovered value from panic event to gracefully handle a panic-crash")
		if r := recover(); r != nil {
			fmt.Println("Recovered in f()", r)
		}
	}()
	fmt.Println("Calling g()")
	g(0)

	// Since we panicked we'll never hit this line of code:
	fmt.Println("Returned normally from g()")
}

func g(i int) {
	if i > 3 {
		fmt.Println("Panicking!")
		panic(fmt.Sprintf("%v", i))
	}

	defer fmt.Println("Defer in g()", i)
	fmt.Println("Printing in g()", i)
	g(i + 1)
}

package main

import (
	"fmt"
)

func main() {
	for i := 0; i < 10; i++ {
		fmt.Printf("iteration: %d\n", i)
	}

	for i := 100; i > 1; i -= 10 {
		fmt.Printf("iteration: %d\n", i)
	}

	a := 1
	b := 100
	for a < b {
		a += 10
		fmt.Printf("a=%d\n", a)
	}

	switch 1 {
	case 10:
		fmt.Println("It's 10")
	case 100:
		fmt.Println("It's 100")
		//fallthrough	// forces next condition to be true
	case 200:
		fmt.Printf("It's 200")
	case 1,2,3:
		fmt.Printf("It's 1 2 or 3")
	default:
		fmt.Printf("Default hit!")
	}
}

package main

import "fmt"

func main() {
	x := [5]int{5, 4, 3, 2, 1}
	var y [5]int

	for i := 0; i < len(x); i++ {
		fmt.Println(x[i])
	}

	for i := 0; i < len(y); i++ {
		fmt.Println(y[i])
	}

	y = x
	for i := 0; i < len(y); i++ {
		fmt.Println(y[i])
	}

}

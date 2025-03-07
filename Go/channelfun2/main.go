package main

import (
	"fmt"
)

func main() {
	chnl := make(chan string)

	fmt.Println("Send go routine.")
	go func(c chan<- string) {
		for i := range 3 {
			c <- fmt.Sprintf("Herrrroo %d", i+1)
		}
		close(c)
	}(chnl)

	fmt.Println("Read channel.")
	fmt.Println("-------------------------")
	for v := range chnl {
		fmt.Println(v)
	}
}

package main

import (
	"fmt"
)

func main() {
	c := make(chan int)

	fmt.Printf("If a channel assignment is made by itself a deadlock will occur at runtime.\n" +
		"Spin up a go routine to send to the channel and avoid deadlock.\n")

	go func() {
		c <- 42
	}()
	fmt.Println("c: ", <-c)

	fmt.Printf("Another method to avoid deadlock is to allocate space in the channel\n" +
		"by using the 2nd parameter of chan()\n")
	d := make(chan int, 5)
	d <- 42
	fmt.Println("d: ", <-d)

	fmt.Println("Bi-directional channels can send & receive:")
	cr := make(chan int)
	go func() {
		cr <- 42
	}()
	fmt.Println("cr: ", <-cr)

}

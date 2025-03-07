package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup

func main() {
	chnl := make(chan string)

	wg.Add(2) // Add 2 go routines to waitgroup
	go send(chnl)
	go receive(chnl)
	wg.Wait()

	fmt.Println("EOJ")

}

func send(c chan<- string) {
	c <- "Eat your vegeteberrrrr!"
	wg.Done()
}

func receive(c <-chan string) {
	fmt.Println(<-c)
	wg.Done()
}

package main

import (
	"fmt"
)

func main() {
	even := make(chan int)
	odd := make(chan int)
	end := make(chan bool)

	go send(odd, even, end)

	rcv(odd, even, end)
}

func send(odd, even chan<- int, end chan<- bool) {
	for i := range 100 {
		if i%2 == 0 {
			even <- i
		} else {
			odd <- i
		}
	}

	// Close the sending channels within this function scope.
	close(odd)
	close(even)
	close(end)
}

func rcv(odd, even <-chan int, end <-chan bool) {
	var evenSlice []int
	var oddSlice []int
	var endSlice []bool

	for {
		select {
		case v, ok := <-even:
			evenSlice = append(evenSlice, v)
			fmt.Println(v, "is an even number", ok)
			fmt.Println(evenSlice)

		case v, ok := <-odd:
			oddSlice = append(oddSlice, v)
			fmt.Println(v, "is an odd number", ok)

		case v, ok := <-end:
			endSlice = append(endSlice, v)
			fmt.Println("False is stop signal derived from ok signal:", ok)
			return
		}
	}
}

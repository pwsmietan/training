package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func main() {
	even := make(chan int)
	odd := make(chan int)
	fanIn := make(chan int)

	go send(odd, even)
	go rcv(odd, even, fanIn)

	for vals := range fanIn {
		fmt.Println(vals)
	}

	fmt.Println("---------------------------")
	c := faninfn(boring("Joe"), boring("Paul"))
	for i := range 10 {
		fmt.Printf("%d %v\n", i, <-c)
	}

}

func boring(msg string) <-chan string {
	c := make(chan string)
	go func() {

		for i := 0; ; i++ {
			c <- fmt.Sprintf("%s %d", msg, i)
			time.Sleep(time.Duration(rand.Intn(1e3)) * time.Millisecond)
		}
	}()

	return c
}

func send(odd, even chan<- int) {
	for i := range 100 {
		if i%2 == 0 {
			even <- i
		} else {
			odd <- i
		}
	}

	close(odd)
	close(even)
}

func rcv(od, ev <-chan int, fanIn chan<- int) {
	var wg sync.WaitGroup
	wg.Add(2)

	go func() {
		for vEven := range ev {
			fanIn <- vEven
		}
		wg.Done()
	}()

	go func() {
		for vOdd := range od {
			fanIn <- vOdd
		}
		wg.Done()
	}()

	wg.Wait()
	close(fanIn)
}

func faninfn(input1, input2 <-chan string) <-chan string {
	c := make(chan string)

	go func() {
		for {
			c <- <-input1
		}
	}()

	go func() {
		for {
			c <- <-input2
		}
	}()

	return c
}

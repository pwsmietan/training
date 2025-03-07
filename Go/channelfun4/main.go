package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func main() {
	c1 := make(chan int)
	c2 := make(chan int)

	go putDataOnChannel(c1)
	go fanOutIn(c1, c2)

	for v := range c2 {
		fmt.Println(v)
	}
}

func putDataOnChannel(c chan int) {
	for i := range 100 {
		c <- i
	}
	close(c)
}

func fanOutIn(c1, c2 chan int) {
	var wg sync.WaitGroup
	const maxGoRoutines = 5

	wg.Add(maxGoRoutines)
	for i := 0; i < maxGoRoutines; i++ {
		go func() {
			for valsInC1 := range c1 {
				go func(valFromC1InC2 int) {
					c2 <- timeConsumingJob(valFromC1InC2)
					wg.Done()
				}(valsInC1)
			}
		}()
	}

	wg.Wait()
	close(c2)
}

func timeConsumingJob(n int) int {
	time.Sleep(time.Millisecond * time.Duration(rand.Intn(500)))
	return n + 1000
}

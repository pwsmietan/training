package main

import (
	"fmt"
	"runtime"
	"sync"
)

var wg sync.WaitGroup

func thing1(){
	fmt.Println("I am Thing 1")
	wg.Done()
}

func thing2(){
	fmt.Println("I am Thing 2")
	wg.Done()
}

func main() {
	wg.Add(2)
	go thing1()
	fmt.Printf("Thing1 started %d\n", runtime.NumGoroutine())
	go thing2()
	fmt.Printf("Thing2 started %d\n", runtime.NumGoroutine())
	wg.Wait()

	fmt.Println("EOJ")
}
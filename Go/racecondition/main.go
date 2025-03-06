package main

import (
	"fmt"
	"runtime"
	"sync"
)

func main() {
	fmt.Println("System information derived from runtime object:")
	fmt.Printf("OS\t%v\n", runtime.GOOS)
	fmt.Printf("OS\t%v\n", runtime.GOARCH)
	fmt.Printf("OS\t%d\n", runtime.NumCPU())
	fmt.Printf("Goroutines\t%v\n", runtime.NumGoroutine())
	fmt.Printf("***************************************\n\n")

	counter := 0
	gs := 100
	var wg sync.WaitGroup
	wg.Add(gs)

	for i := 0; i < gs; i++ {
		// Kick-off anonyumous function:
		go func() {
			v := counter
			//time.Sleep(time.Second * 1)
			runtime.Gosched()
			v++
			counter = v
			wg.Done()
		}()
		fmt.Printf("Goroutines -> Launch #%d\t%v\n", i, runtime.NumGoroutine())
	}

	wg.Wait()
	fmt.Printf("Goroutines after wait()\t%v\n", runtime.NumGoroutine())
	fmt.Printf("Counter: %d\n", counter)
}

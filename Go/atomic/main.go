package main

import (
	"fmt"
	"runtime"
	"sync"
	"sync/atomic"
)

func main() {
	fmt.Println("System information derived from runtime object:")
	fmt.Printf("OS\t%v\n", runtime.GOOS)
	fmt.Printf("OS\t%v\n", runtime.GOARCH)
	fmt.Printf("OS\t%d\n", runtime.NumCPU())
	fmt.Printf("Goroutines\t%v\n", runtime.NumGoroutine())
	fmt.Printf("***************************************\n\n")

	var counter int64
	gs := 100
	var wg sync.WaitGroup
	wg.Add(gs)

	for i := range gs {
		// Kick-off anonyumous function:
		go func() {
			atomic.AddInt64(&counter, 1)
			fmt.Printf("C: %v\n", atomic.LoadInt64(&counter))
			//runtime.Gosched()
			wg.Done()
		}()
		fmt.Printf("Goroutines -> Launch #%d\t%v\n", i, runtime.NumGoroutine())
	}

	wg.Wait()
	fmt.Printf("Goroutines after wait()\t%v\n", runtime.NumGoroutine())
	fmt.Printf("Counter: %d\n", counter)
}

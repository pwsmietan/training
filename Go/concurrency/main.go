package main

import (
	"fmt"
	"runtime"
	"sync"
	"time"
)

func main() {
	fmt.Println("System information derived from runtime object:")
	fmt.Printf("OS\t%v\n", runtime.GOOS)
	fmt.Printf("OS\t%v\n", runtime.GOARCH)
	fmt.Printf("OS\t%d\n\n", runtime.NumCPU())

	fmt.Println("We'll now kick-off threads using the 'go' routine:")
	fmt.Printf("Number of Go Routines:\t%d\n", runtime.NumGoroutine())
	go fooWorker1()
	fmt.Printf("Number of Go Routines:\t%d\n", runtime.NumGoroutine())
	foo()
	go fooWorker2()
	fmt.Printf("Number of Go Routines:\t%d\n", runtime.NumGoroutine())

	fmt.Printf("\nEOJ")

	var wg sync.WaitGroup

	// Launch several goroutines and increment the WaitGroup counter for each.
	for i := 1; i <= 5; i++ {
		wg.Add(1)

		// Wrap the worker call in a closure that makes sure to tell the WaitGroup
		// that this worker is done. This way the worker itself does not have to be aware of the concurrency primitives involved in its execution.
		go func() {
			defer wg.Done()
			wgWorker(i)
		}()
	}

	//Block until the WaitGroup counter goes back to 0; all the workers notified they’re done.
	wg.Wait()
}

func fooWorker1() {
	for i := 0; i < 6; i++ {
		fmt.Printf("worker 1 iteration %d\n", i)
	}
}

func fooWorker2() {
	for i := 0; i < 100; i++ {
		fmt.Printf("worker 2 iteration %d\n", i^2)
	}
}

func foo() {
	for i := 0; i < 10; i++ {
		fmt.Printf("foo() iteration %d\n", i)
	}
}

func wgWorker(id int) {
	fmt.Printf("Worker %d starting\n", id)
	// Sleep to simulate an expensive task.
	time.Sleep(time.Second)
	fmt.Printf("Worker %d done\n", id)
}

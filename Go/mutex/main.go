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
	var mu sync.Mutex

	wg.Add(gs)

	for i := 0; i < gs; i++ {
		// Kick-off anonyumous function:
		go func() {
			// Set our mutex lock:
			mu.Lock()

			v := counter
			/*
			 * Sleeping causes goroutines to increment and there's a noticeable
			 * wait period before the final release.
			 */
			//time.Sleep(time.Second * 1)

			/*
			 * Goscheduler hits the final release WAAAAYYYY sooner than the sleep method.
			 * The number of Goroutines never seems to exceed 2 (on a dual XEON system).
			 */
			runtime.Gosched()

			/*
			 * Interesting Go tidbit:
			 * Incrementing a variable in a complex assigment is not allowed as it is in C
			 * Ex. counter = v++
			 * Has to be broken out into two lines. :-(
			 */
			v++
			counter = v

			// Unlock Mutex lock and waitgroup:
			mu.Unlock()
			wg.Done()
		}()
		fmt.Printf("Goroutines -> Launch #%06d\tNumber of Goroutines: %04d\n", i, runtime.NumGoroutine())
	}

	wg.Wait()
	fmt.Printf("Goroutines after wait()\t%04d\n", runtime.NumGoroutine())
	fmt.Printf("Counter: %06d\n", counter)
}

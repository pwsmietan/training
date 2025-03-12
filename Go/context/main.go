package main

import (
	"context"
	"fmt"
	"runtime"
	"time"
)

func main() {
	ctx := context.Background()

	fmt.Println("context: ", ctx)
	fmt.Println("context err: ", ctx.Err())
	fmt.Printf("context type: %T\n", ctx)
	fmt.Println("--------------------")

	ctx, cancel := context.WithCancel(ctx)

	fmt.Println("context: ", ctx)
	fmt.Println("context err: ", ctx.Err())
	fmt.Printf("context type: %T\n", ctx)
	fmt.Println("cancel: ", cancel)
	fmt.Printf("cancel type: %T\n", cancel)
	fmt.Printf("Number of Go routines: %d\n", runtime.NumGoroutine())

	// Kick-off anonymous function
	go func() {
		n := 0
		for {
			select {
			// Check channel for Done event
			case <-ctx.Done():
				return

			default:
				n++
				time.Sleep(time.Millisecond * 200)
				fmt.Println("Working: ", n)
			}
		}
	}()

	time.Sleep(time.Second * 2)
	fmt.Println("Error check: ", ctx.Err())
	fmt.Printf("Number of Go routines: %d\n", runtime.NumGoroutine())
	fmt.Println("Cancelling context")
	cancel()
	fmt.Println("--------------------")

	fmt.Println("context: ", ctx)
	fmt.Println("context err: ", ctx.Err())
	fmt.Printf("context type: %T\n", ctx)
	fmt.Println("cancel: ", cancel)
	fmt.Printf("cancel type: %T\n", cancel)
	fmt.Printf("Number of Go routines: %d\n", runtime.NumGoroutine())
	fmt.Println("--------------------")

	// Call deadline() - there's also WithTimeout() and WithValue()
	fmt.Println("Now we'll set a deadline 500ms from now:")
	d := time.Now().Add(500 * time.Millisecond)
	ctx, cancel = context.WithDeadline(context.Background(), d)
	defer cancel()
	select {
	case <-time.After(1 * time.Second):
		fmt.Println("Oops I overslept!")
	case <-ctx.Done():
		fmt.Println(ctx.Err())
	}

	fmt.Println("--------------------")

	fmt.Println("Now we'll create a context using values:")
	ctx = context.WithValue(context.Background(), "pws", "coder")
	checkContext(ctx, "pws")
	fmt.Println(ctx)

	ctx = context.WithValue(ctx, "bp", "Data Boy")
	checkContext(ctx, "bp")
	fmt.Println(ctx)

	// this value is NOT in our context so we'll get a runtime message:
	checkContext(ctx, "sks")
	fmt.Println(ctx)
}

func checkContext(ctx context.Context, s string) {
	if v := ctx.Value(s); v != nil {
		fmt.Println("Found: ", v)
		return
	} else {
		fmt.Println("Key not found: ", s)
	}

}

package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup

func main() {
	/*
	 * Unbuffered channel has 0 capacity.
	 *
	 * If capacity is not defined the runtime will report a deadlock
	 * stating all goroutines are asleep. In essence, a buffer size of
	 * 0 will block the channel.
	 */
	channelOfInts := make(chan int, 10)

	wg.Add(1)
	go func() {
		// Use directional flow into the channel:
		channelOfInts <- 23
		fmt.Println("Gofunc is not blocked!")

		channelOfInts <- 24
		fmt.Println("Gofunc is not blocked!")

		// Notify the waitgroup that we're done!
		wg.Done()
	}()

	// Before we read from our channel make sure we wait for the routine to finish.
	wg.Wait()

	// Read/receive from the channel (note: FIFO method)
	fmt.Println(<-channelOfInts)
	fmt.Println(<-channelOfInts)

	/*
	 * receiver channel: c := make(<-chan string, 2)
	 * send channel: c := make(chan<- string, 2)
	 * bidirectional channel: c := make(chan string, 2)
	 */

	/*
		// Receiver-only channel
		cos_rcv := make(<-chan string, 2)

		// cannot send to receive-only channel cos_rcv (variable of type <-chan string)
		cos_rcv <- "Hello"
		cos_rcv <- "World"

		fmt.Println(<-cos_rcv)
		fmt.Printf("%T\n", cos_rcv)

		// Send-only channel
		cos_snd := make(chan<- string, 2)
		cos_snd <- "Hello"
		cos_snd <- "World"

		// invalid operation: cannot receive from send-only channel cos_snd (variable of type chan<- string)
		fmt.Println(<-cos_snd)

		fmt.Printf("%T\n", cos_snd)
	*/
	fmt.Println("----------------------")
	cos := make(chan string, 2)    // bi-directional
	cosr := make(<-chan string, 2) // receiver
	coss := make(chan<- string, 2) // sender

	// MUST do assignment to avoid deadlock error:
	cos <- "Line 1"
	cos <- "Line 2"
	fmt.Println(<-cos)
	fmt.Println(<-cos)
	fmt.Println("----------------------")

	fmt.Printf("cos: %T\n", cos)
	fmt.Printf("cosr: %T\n", cosr)
	fmt.Printf("coss: %T\n", coss)

	// sender/receiver/bi-directional assignment are incompatible types:
	//coss = cosr
	//cosr = coss
	//cos = cosr
	//cos = coss

	fmt.Println("----------------------")
	fmt.Printf("cos: %T\n", cos)

	/*
		  Wrong ways to convert:
			fmt.Printf("conversion to sender: %T\n", chan<- string(cos))
			fmt.Printf("conversion to rcvr: %T\n", <-chan string(cos))
	*/

	// Bi-directional channels may be converted by casting type:
	fmt.Printf("conversion : %T\n", (chan<- string)(cos))
	fmt.Printf("conversion : %T\n", (<-chan string)(cos))

}

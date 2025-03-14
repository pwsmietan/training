package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	os.Remove("log.txt")
	f, err := os.Create("log.txt")
	if err != nil {
		fmt.Println("Error: ", err)
		log.Println("An error occured during create: ", err)
		return
	}
	/*
	 * Deferred functions are executed at end of the current routine's flow and
	 * push values onto the stack in a LIFO method.
	 */
	defer f.Close()

	/*
	 * Logging is available through the log namespace. Kinda like having
	 * NLog built-in which is nice! The SetOutput redirect STDOUT.
	 */
	log.SetOutput(f)

	f2, err2 := os.Open("foo.txt")
	if err2 != nil {
		//fmt.Println("Error: ", err2)
		log.Println("An error occured during read: ", err2)
		//log.Fatalln("FATAL!!!") // calls exit(1) immediate abort!
		//log.Panicln("PANIC!!!") // change state to panic
	}

	f2.Close()
}

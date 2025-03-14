package main

import (
	"fmt"
)

func main() {
	var name string
	_, err := fmt.Scan(&name)
	fmt.Printf("Hello %s!", name)

	if err != nil {
		fmt.Println(err)
	}

}

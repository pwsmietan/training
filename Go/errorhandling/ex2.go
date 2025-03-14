package main

import (
	"fmt"
	"log"
)

func main() {
	_, err := squareRoot(-10)
	if err != nil {
		log.Fatalln(err)
	}
}

func squareRoot(f float64) (float64, error) {
	if f < 0 {
		//return 0, errors.New("Not defined: square root of a negative number!")
		return 0, fmt.Errorf("Not defined: square root of a negative number!")
	}
	return 23, nil
}

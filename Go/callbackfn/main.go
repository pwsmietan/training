package main

import "fmt"

func sum(data ...int) int {
	var total int = 0

	for _, v := range data {
		total += v
	}

	return total
}

/*
 * Returns even numbers from an integer slice then invokes callback to
 * function 'f'.
 */
func even(f func(wholeNumbers ...int) int, wholeNumbersSlice ...int) int {
	var tempSliceOfInt []int
	for _, value := range wholeNumbersSlice {
		if value%2 == 0 {
			tempSliceOfInt = append(tempSliceOfInt, value)
		}
	}

	fmt.Printf("temp slice from even(): %v\n", tempSliceOfInt)

	// returns the results of callback function 'f'
	return f(tempSliceOfInt...)
}

func main() {
	sliceOfInt := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	fmt.Printf("Fun with slices and callback functions!\n")
	fmt.Printf("Here is our slice of integers: %d -> of type: %T\n", sliceOfInt, sliceOfInt)
	fmt.Println("-----------------------------------------")

	s1 := sum(sliceOfInt...)
	fmt.Printf("Sum of our integer slice: %d\n", s1)
	s2 := even(sum, sliceOfInt...)
	fmt.Printf("Sigma of even values=%v\n", s2)
}

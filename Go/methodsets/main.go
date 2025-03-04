/*
 * 1. receiver is not a pointer but can accept values as pointer or non-pointer.package methodsets.
 * 2. Receiver is a pointer (to a type) can only accept values in the form of pointers.
 *
 * Receivers		Values
 * ------------------------------------------
 * (t T)			T or *T
 * (t *T)			*T
 */

package main

import (
	"fmt"
	"math"
)

// Method set of circle contains area()
type circle struct {
	radius float64
}

type shape interface {
	area() float64
}

/*
 * The receiver 'c' binds to the structure definition "circle" and using the
 * definition on line #8 we could make the receiver a pointer (e.g., (c *circle))
 * but then calling output(&c) passing the addresswould execute properly.
 */
func (c circle) area() float64 {
	return math.Pi * c.radius * c.radius
}

func output(a shape) {
	fmt.Printf("Area: %v\n", a.area())
}

func main() {
	c := circle{5}
	fmt.Printf("Display area through method set: %v\n\n", c.area())

	fmt.Println("Display area through interface:")
	output(c)
	fmt.Println()

	fmt.Println("Display area through interface passing a pointer:")
	output(&c)

}

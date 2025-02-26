package main

import "fmt"

/*
 * Define an abstraction in terms of what our types can
 * execute. There is no "implements" keyword in Go.
 */
type Animal interface {
	Speak() string
}

/*
 * An empty interface has no methods. Since there is no "implements" keyword,
 * all types implement at least zero methods, and satisfying (referencing) an interface
 * all types satisfy the empty interface.
 *
 * func doSomething(v interface{}) {
    v is of interface type. A passed-in value goes through type conversion (if necessary)
    and is converted to static type interface.
    An intercace value is constructed of two words of data (type, value):
	  - word 1: points to a method table for the value's underlying type.
	  - word 2: points to the actual data help by that value.
 }
*/

func printAll(vals []interface{}) {
	for _, val := range vals {
		fmt.Println(val)
	}
}

// Define multiple types of animals:
type Dog struct {
}

func (d Dog) Speak() string {
	return "woof!"
}

type Cat struct {
}

func (c Cat) Speak() string {
	return "meow!"
}

type Llama struct{}

func (l Llama) Speak() string {
	return "mmmaaaaaa!"
}

type Programmer struct {
}

func (p Programmer) Speak() string {
	return "Write Code - sleep - repeat!"
}

func main() {

	/* For range over slices:

	In for v := range values { the v is the index of the element in the slice.
	In for _, v := range values { the v is the actual element value.
	In for i, v := range values { the i is the index and the v is the element.
	In for i, _ := range values { the i is the index of the element in the slice.
	*/

	/*
	 * Create a slice of Animals and put each animal
	 * onto a slice.
	 */
	fmt.Println("Call method by interface type:")
	animals := []Animal{Dog{}, Cat{}, Llama{}, Programmer{}}
	for _, animal := range animals {
		fmt.Println(animal.Speak())
	}

	fmt.Println("\nConvert []string -> []interface using make():")
	names := []string{"pws", "bp", "mikes"}
	vals := make([]interface{}, len(names))
	for i, v := range names {
		fmt.Printf("i=%d, v=%s\n", i, v)
		vals[i] = v
	}
}

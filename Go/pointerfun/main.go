package main

import "fmt"

func ptr(i *int) {
	*i *= 2
	fmt.Printf("%v %T in ptr()\n", i, i)
	fmt.Printf("%v %T value at memory location pointed to.\n", *i, *i)
}

type person struct {
	givenname  string
	familyname string
	age        int
	address    string
}

func change(p *person) {
	// Dereferencing way
	(*p).address = "109 Carroll Way"
	// or using shorthand
	p.address = "333 Zoo"
}

func main() {
	val := 23
	fmt.Printf("%v %T before ptr() at addr: %X\n", val, val, &val)
	ptr(&val)
	fmt.Printf("%v %T after ptr() at addr: %X\n", val, val, &val)

	myP := person{givenname: "Smith", familyname: "Jonz", age: 33, address: "123 Main St"}
	fmt.Println(myP)
	change(&myP)
	fmt.Println(myP)
}

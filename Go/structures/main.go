package main

import (
	"fmt"
)

type Address struct {
	city  string
	state string
}

type Person struct {
	name     string
	age      int
	address  Address
	nickname []string
}

func main() {
	fmt.Printf("If a struct type starts with a capital letter, then it is an exported type and it can be accessed\n" +
		"from other packages. Similarly, if the fields of a struct start with caps, they can be accessed from other packages.\n\n")

	p := Person{
		name: "Paul",
		age:  63,
		address: Address{
			city:  "Chehalis",
			state: "WA",
		},
		nickname: []string{
			"pws",
			"NT7PS",
			"KN6PH",
		},
	}

	fmt.Println("Name:", p.name)
	fmt.Println("Age:", p.age)
	fmt.Println("City:", p.address.city)
	fmt.Println("State:", p.address.state)

	fmt.Printf("%v %T\n", p, p)

	fmt.Println("Ranging over a string array within the structure:")
	for _, v := range p.nickname {
		fmt.Println((v))
	}

	fmt.Println("Anonymous struct")
	somebody := struct {
		name string
		age  uint8
		sex  string
	}{
		"Paul", 123, "Male",
	}
	fmt.Println(somebody)
}

package main

import (
	"fmt"
)

func main() {
	fmt.Println("Map is unordered group of ONE type ala key/value pair.")
	m := map[string]int{
		"Paul": 63,
		"Bill": 68,
		"Geo":  64,
		"Foo" : 10,
	}

	fmt.Println(m)
	fmt.Println("Paul is ", m["Paul"])
	fmt.Println("Foo is ", m["foo"])

	v, ok := m["Foo"]
	fmt.Println(v)
	fmt.Println(ok)

	if v, ok := m["Foo"]; ok {
		fmt.Println(v)
	} else {
		fmt.Println("Key value not in map!")
	}

	m["LT"] = 62
	fmt.Println("Added an entry to map LT: ", m["LT"])

	for k, v := range m {
		fmt.Println("key: ", k, " value: ", v)
	}


	delete(m, "Foo")
	fmt.Println("Deleted Foo: ", m)
	if _, ok := m["Paul"]; ok {
		delete(m, "Paul")
	} else {
		fmt.Println("Key value not in map!")
	}
	fmt.Println("Deleted Paul: ", m)
}

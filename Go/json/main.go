/*
 * JSON Marshall/Unmarshall: encoding & decoding into/from JSON.
 */
package main

import (
	"encoding/json"
	"fmt"
)

// Field name must be Pascal casing in order for Marshalling to encode correctly.
type person struct {
	Name string
	Age  int
}

func main() {
	pws := person{
		Name: "Paul",
		Age:  63,
	}

	bp := person{
		Name: "Billy",
		Age:  69,
	}

	fmt.Println("Create our person slice")
	people := []person{pws, bp}
	fmt.Println(people)

	fmt.Println("Marshalling slice into JSON")
	marshalledJson, err := json.Marshal(people)
	if err != nil {
		fmt.Println(err)
	}

	fmt.Println(marshalledJson)
	fmt.Println("------------------------")
	fmt.Println("Encoded into JSON")
	fmt.Println(string(marshalledJson))

	fmt.Println("Create our decoded slice of person type")
	var unM []person
	// 2nd arg is a pointer to unmarshalled structure:
	err2 := json.Unmarshal(marshalledJson, &unM)
	if err2 != nil {
		fmt.Println(err2)
	}

	fmt.Println(unM, len(unM), " items in decoded person structure.")
}

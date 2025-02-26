package main

import "fmt"

type employee struct {
	name   string
	age    int
	role   string
	salary int
}

func (r employee) display() {
	fmt.Printf("Name: %s\n", r.name)
	fmt.Printf("Age: %v\n", r.age)
	fmt.Println("role: ", r.role)
	fmt.Printf("Salary: %v\n", r.salary)
	fmt.Println()
}

type freelancer struct {
	givenName  string
	familyName string
	contractor bool
	payment    int
}

func (rcv freelancer) display() {
	fmt.Printf("givenName: %s\n", rcv.givenName)
	fmt.Printf("familyName: %s\n", rcv.familyName)
	fmt.Printf("Contractor: %v\n", rcv.contractor)
	fmt.Printf("Payment: %v\n", rcv.payment)
	fmt.Println()
}

type allRcvs interface {
	display()
}

func showMotto(ars allRcvs) {
	//var emptype string

	//Cool way to get type of interface:
	switch ars.(type) {
	case employee:
		emptype := "Employee"
		// we can further drill down into the object model and to the name field:
		if ars.(employee).name == "Paul S" {
			emptype += " named Paul S!"
		}

		fmt.Println("I love interfaces especially those that are: ", emptype)
	case freelancer:
		emptype := "Contractor"
		fmt.Println("I love interfaces especially those that are: ", emptype)
	}

	// emptype is not assigned the string within the switch scope :(
	//fmt.Printf("Emptype: %s\n", emptype)

	ars.display()
}

func main() {
	pws := employee{
		name:   "Paul S",
		age:    63,
		role:   "SW Eng",
		salary: 50000,
	}

	bp := employee{
		name:   "Billy",
		age:    68,
		role:   "DBA",
		salary: 55000,
	}

	pws.display()
	bp.display()

	peter := freelancer{
		givenName:  "Peter",
		familyName: "Smith",
		contractor: true,
		payment:    40000,
	}

	peter.display()

	showMotto(pws)
	showMotto(bp)
	showMotto(peter)
}

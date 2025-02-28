package main

import (
	"fmt"
	"sort"
)

type Person struct {
	Name string
	Age  int
}

func (p Person) String() string {
	return fmt.Sprintf("%s: %d", p.Name, p.Age)
}

// ByAge implements sort.Interface for []Person based on
// the Age field. These three functions are required to be implemented.
// https://pkg.go.dev/sort
type ByAge []Person

func (a ByAge) Len() int           { return len(a) }
func (a ByAge) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByAge) Less(i, j int) bool { return a[i].Age < a[j].Age }

type ByName []Person

func (a ByName) Len() int           { return len(a) }
func (a ByName) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByName) Less(i, j int) bool { return a[i].Name < a[j].Name }

func main() {
	sliceOfInts := []int{12345, 1, 22, -1, 13, 3, 54, 666, 109, 11}
	sliceOfString := []string{"Paul", "daniel", "Billy", "kenney", "Keith", "Cody", "Allan"}

	fmt.Println("Unsorted:")
	fmt.Println(sliceOfInts)
	fmt.Println(sliceOfString)

	sort.Ints(sliceOfInts)
	sort.Strings(sliceOfString)
	fmt.Println("Sorted:")
	fmt.Println(sliceOfInts)
	fmt.Println(sliceOfString)

	fmt.Println("Reversed:")
	sort.Sort(sort.Reverse(sort.IntSlice(sliceOfInts)))
	fmt.Println(sliceOfInts)
	sort.Strings(sliceOfString)
	sort.Sort(sort.Reverse(sort.StringSlice(sliceOfString)))
	fmt.Println(sliceOfString)

	p1 := Person{"Paul", 63}
	p2 := Person{"Jonz", 40}
	p3 := Person{"Peter", 23}
	p4 := Person{"Larry", 72}
	p5 := Person{"AWU", 26}
	p6 := Person{"Gary", 68}

	people := []Person{p1, p2, p3, p4, p5, p6}
	fmt.Println("Unsorted: ", people)

	// There are two ways to sort a slice. First, one can define
	// a set of methods for the slice type, as with ByAge, and
	// call sort.Sort. In this first example we use that technique.
	sort.Sort(ByAge(people))
	fmt.Println("Sorted by age: ", people)

	// The other way is to use sort.Slice with a custom Less
	// function, which can be provided as a closure. In this
	// case no methods are needed. (And if they exist, they
	// are ignored.) Here we re-sort in reverse order: compare
	// the closure with ByAge.Less.
	sort.Slice(people, func(i, j int) bool {
		return people[i].Age > people[j].Age
	})
	fmt.Println(people)

	sort.Sort(ByName(people))
	fmt.Println("Sorted by name: ", people)
}

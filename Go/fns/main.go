package main

import "fmt"

func main() {
	fmt.Println("Defering bail()")
	defer bail()

	fmt.Println("Calling function with variable # of arguments using ...")
	sum(1, 2, 3)

	sliceOfInts := []int{0, 1, 2, 3, 4, 5, 6}
	iSum := sum(sliceOfInts...)
	fmt.Printf("Unraveled slice array int sum: %d\n", iSum)

	r := rect{width: 10, height: 5}

	fmt.Println("area: ", r.area())
	fmt.Println("perim:", r.perim())

	rp := &r
	fmt.Println("area: ", rp.area())
	fmt.Println("perim:", rp.perim())
}

type rect struct {
	width, height int
}

// The receiver (explicit result object) binds a type/struct and makes it
// convenient to pass by val/ref (use the *) an entire object.
func (r *rect) area() int {
	return r.width * r.height
}

func (r rect) perim() int {
	return 2*r.width + 2*r.height
}

func sum(x ...int) int {
	sum := 0

	for _, val := range x {
		fmt.Printf("%d plus %d = ", sum, val)
		sum += int(val)
		fmt.Printf("%d %T\n", sum, sum)
	}

	fmt.Printf("The sum of all args is %d\n", sum)
	return sum
}

func bail() {
	fmt.Println("Bail!")
}

package main

import "fmt"

func main() {
	fmt.Println("Defering bail()")
	defer bail()
	dashes()

	fmt.Println("Calling function with variable # of arguments using ...")
	sum(1, 2, 3)
	dashes()

	/*
		Create a slice of integers and pass it to sum()
	*/
	sliceOfInts := []int{0, 1, 2, 3, 4, 5, 6}
	iSum := sum(sliceOfInts...)
	fmt.Printf("Unpacked/unraveled slice array int sum: %d\n", iSum)

	r := rect{width: 10, height: 5}

	fmt.Println("area: ", r.area())
	fmt.Println("perim:", r.perim())

	rp := &r
	fmt.Println("area: ", rp.area())
	fmt.Println("perim:", rp.perim())
	dashes()

	// Anonymous Functions: trailing () means execute function (function call)
	func() {}()
	func(aNumber int) {
		fmt.Printf("Life is %d\n", aNumber)
	}(42)

	// Call anonymous function and return result:
	f := func(degs int) {
		fmt.Printf("Degrees: %d\n", degs)
	}

	f(451)
	fmt.Printf("f return type=%T\n", f)
	fmt.Println("x is a pointer to function bar()")
	x := bar()
	fmt.Printf("address of x=%X; type=%T\n", &x, x)

	fmt.Println("Now we call x() which points to bar()")
	x1 := x()
	fmt.Printf("x1=%v; type=%T\n", x1, x1)
	dashes()

	fmt.Println("Fun with Closure Functions")
	followTheClosureFn := myClosureFn()
	fmt.Printf("Calling the follower %d\n", followTheClosureFn())
	fmt.Printf("Calling the follower %d\n", followTheClosureFn())
	fmt.Printf("Calling the follower %d\n", followTheClosureFn())

	anotherFollower := myClosureFn()
	fmt.Printf("Calling the second follower %d\n", anotherFollower())
	fmt.Printf("Calling the second follower %d\n", anotherFollower())
	dashes()

	fmt.Println("Fun with recursion!")
	fmt.Println(factorial(4))

}

func dashes() {
	fmt.Println("-------------------------------------------")
}

func bar() func() string {
	return func() string {
		return "Hello from anonymous function that returns type string"
	}
}

/*
 * Closure function allows a variable to be referenced beyond the scope of its function { ... }
 * The anonymous function encapsulates the logic to be performed. The 'i' variable is given
 * a static life similar to C's static int.
 */
func myClosureFn() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
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

/*
 * Use elipses (...) inside of function parameter indicating a variadic (variable number)
 * of arguments of same type.
 */
func sum(x ...int) int {
	sum := 0

	// loop through each value in slice:
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

func factorial(input int) int {
	fmt.Printf("Recursive Entry %d\n", input)
	if input == 0 {
		return 1
	}

	return input * factorial((input - 1))
}

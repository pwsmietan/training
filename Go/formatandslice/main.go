package main

import (
	"fmt"
	"slices"
)

var y = 42
var z string = "Here is string z"
var a string = "and here is string y"

type myInt int

func main() {

	fmt.Println(y)
	fmt.Printf("%T\n", y)

	fmt.Println(a)
	fmt.Printf("%T\n", a)

	fmt.Println(z)
	fmt.Printf("%T\n", z)

	fmt.Printf("%d\t%#x\t%X\n", y, y, y)

	val1 := fmt.Sprintf("the val is %d", y)
	fmt.Println(val1)

	var b myInt = 16
	fmt.Printf("b is %d and its type is %T\n", b, b)
	c := int(b)
	fmt.Printf("converted b to c: %d and its type is %T\n", c, c)

	const (
		d        = 23
		e        = iota // pre-defined identifier
		f        = d + iota
		g string = "My typed string"
	)

	fmt.Printf("d=%d e=%d f=%d g=%s\n", d, e, f, g)

	fmt.Println("\nShifting Fun")
	var sval = 10
	fmt.Printf("Value:\t\t%08b\t%d\t%T\n", sval, sval, sval)
	sval = sval >> 1
	fmt.Printf("Shift Right 1:\t%08b\t%d\t%T\n", sval, sval, sval)
	sval = sval >> 1
	fmt.Printf("Shift Right 1:\t%08b\t%d\t%T\n", sval, sval, sval)
	sval = sval << 4
	fmt.Printf("Shift Left 4:\t%08b\t%d\t%T\n", sval, sval, sval)

	fmt.Println("Back Tick and double quote in strings")
	simon := `Simon says
		"feh!"`

	fmt.Println(simon)

	str1 := "this is a test"
	fmt.Println(str1)

	sfun()
}

func sfun() {
	fmt.Println("\n***")
	fmt.Println("Slices are stored contiguously")
	fmt.Println("***")

	var s []string
	fmt.Println("uninit:", s, s == nil, len(s) == 0)

	fmt.Println("Use make() to create a slice:")
	s = make([]string, 3)
	fmt.Println("emp:", s, "len:", len(s), "cap:", cap(s))
	fmt.Printf("Type: %T\n", s)

	s[0] = "a"
	s[1] = "b"
	s[2] = "c"
	fmt.Println("set:", s)
	fmt.Println("get:", s[2])

	fmt.Println("len:", len(s))

	s = append(s, "d")
	s = append(s, "e", "f")
	fmt.Println("apd:", s)

	c := make([]string, len(s))
	copy(c, s)
	fmt.Println("cpy:", c)

	l := s[2:5]
	fmt.Println("sl1:", l)

	l = s[:5]
	fmt.Println("sl2:", l)

	l = s[2:]
	fmt.Println("sl3:", l)

	t := []string{"g", "h", "i"}
	fmt.Println("dcl:", t)

	t2 := []string{"g", "h", "i"}
	if slices.Equal(t, t2) {
		fmt.Println("t == t2")
	}

	twoD := make([][]int, 3)
	for i := 0; i < 3; i++ {
		innerLen := i + 1
		twoD[i] = make([]int, innerLen)
		for j := 0; j < innerLen; j++ {
			twoD[i][j] = i + j
		}
	}
	fmt.Println("2d: ", twoD)

	x := []uint{1, 23, 3, 4, 1, 333, 42}
	fmt.Printf("Composite literal: %d %T\n", x, x)
	fmt.Println("x: ", x)
	for i := 0; i < len(x); i++ {
		fmt.Printf("%v\t", x[i])
	}

	fmt.Println("\nIterating via range()")
	for i, v := range x {
		fmt.Printf("%d\t%d\n", i, v)
	}

	fmt.Println("Slicing via subscripting (first 4 elements)[start_idx, count]")
	fmt.Println(x[0:4])
	fmt.Println(x[:2])
	fmt.Println(x[2:])
	fmt.Println("4th element onwards: ", x[4:])

	fmt.Println("Before append x:", x, " len: ", len(x), " capacity: ", cap(x))
	x = append(x, 255, 254, 253)
	fmt.Println("Capacity gets increased automatically! x:", x, " len: ", len(x), " capacity: ", cap(x))
	x = append(x[1:], 9)
	fmt.Println("Excluded 1st element x:", x, " len: ", len(x), " capacity: ", cap(x))
	x = slices.Insert(x, 0, 8)
	fmt.Println("Insertion at 0th element x:", x, " len: ", len(x), " capacity: ", cap(x))

	fmt.Println("Deleting from a slice slices.delete(s,start_idx,end_idx)")
	x = slices.Delete(x, 3, 4)
	fmt.Println("Deleted 3rd element x:", x, " len: ", len(x), " capacity: ", cap(x))

	

	var y []interface{}
	y = append(y, 23, 3, 3.14, "foo")
	fmt.Println("y []interface", y)
}

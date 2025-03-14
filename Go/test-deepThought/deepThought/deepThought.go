package deepThought

import (
	"fmt"
)

type question struct {
	thing1 string
	thing2 string
	thing3 string
}

const InLife string = "change"

var Uglue question

func Ask(life, universe, everything string) (int8, string) {
	Uglue = question{
		thing1: "life",
		thing2: "universe",
		thing3: "everything",
	}

	fmt.Printf("What is the answer to the ultiumate question of %s, %s, and %s\n", life, universe, everything)
	if life == Uglue.thing1 && universe == Uglue.thing2 && everything == Uglue.thing3 {
		return 42, InLife
	}

	return 0, "nothing"
}

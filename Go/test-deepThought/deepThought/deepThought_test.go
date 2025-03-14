package deepThought

import "testing"

func TestAskPositive(t *testing.T) {
	argumentToTestPositive_1 := "life"
	argumentToTestPositive_2 := "universe"
	argumentToTestPositive_3 := "everything"
	v1, v2 := Ask(argumentToTestPositive_1, argumentToTestPositive_2, argumentToTestPositive_3)
	if v1 != 42 || v2 != "change" {
		t.Error("expected results not found!")
	}

}

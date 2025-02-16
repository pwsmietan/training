# Morse code dictionary:
cw = {
    "A": ".-",
    "B": "-...",
    "C": "-.-.",
    "D": "-..",
    "E": ".",
    "F": "..-.",
    "G": "--.",
    "H": "....",
    "I": "..",
    "J": ".---",
    "K": "-.-",
    "L": ".-..",
    "M": "--",
    "N": "-.",
    "O": "---",
    "P": ".--.",
    "Q": "--.-",
    "R": ".-.",
    "S": "...",
    "T": "-",
    "U": "..-",
    "V": "...-",
    "W": ".--",
    "X": "-..-",
    "Y": "-.--",
    "Z": "--..",
    "0": "-----",
    "1": ".----",
    "2": "..---",
    "3": "...--",
    "4": "....-",
    "5": ".....",
    "6": "-....",
    "7": "--...",
    "8": "---..",
    "9": "----.",
    ".": ".-.-.-",
    ",": "--..--",
    "?": "..--..",
    ":": "---...",
    ";": "-.-.-.",
    "$": "...-..-",
    '"': ".-..-.",
    "'": ".----.",
    "-": "-....-",
    "/": "-..-.",
    "=": "-...-",
    "@": ".--.-.",
    "!": "---.",
}


# Translate alphabet character into CW
def GetCWCharFromAlpha(alphaChar):
    return cw[alphaChar.upper()]


# Translate CW from alpha by traversing dictionary:
def GetAlphaCharFromCW(cwChar):
    return [k for k, v in cw.items() if v == cwChar][0]


# Translate an entire string to CW:
def GetCWFromString(strVal):
    retVal = ""
    for c in strVal:
        if c != " ":
            val = " " + GetCWCharFromAlpha(c)
            # print(f"val is {val} from {c}")
        else:
            val = " / "

        retVal += val

    return retVal


# Main Entry Point:
def main():
    # Test individual char:
    # alphaVal = input("Enter a character: ").upper()
    # cwVal = GetCWCharFromAlpha(alphaVal)
    # print(f"{alphaVal} -> {cwVal}")
    # print(f"{cwVal} -> is {GetAlphaCharFromCW(cwVal)} ")

    msg1 = "QST QST QST Now hear this all hands battlestations! END QST DE NT7PS. SK"
    print(GetCWFromString(msg1))


# Use special var for module name/entry:
if __name__ == "__main__":
    main()

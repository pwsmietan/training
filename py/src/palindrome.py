n = int(input("Enter number: "))
m = n
rev = 0
while n > 0:
    r = n % 10
    n //= 10
    rev = rev * 10 + r

print("Reverse number is: ", rev)

if m == rev:
    print("Palindrome!")
else:
    print("Not a palindrome :-(")

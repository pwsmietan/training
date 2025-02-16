import common as c

c.MyCommonFn()

# Alias fn
z = c.disp
z("NT7PS")

c.coverFn(c.add, 33, 44)
c.coverFn(c.sqrSigma, 2, 14)

# function factory
d = c.Outer()
d()

# Instantiate a class object and call fn:
dep = c.Department()
print(dep("hr"))


"""
closures in Python help to invoke functions outside their scope. The function innerFunction has its scope 
only inside the outerFunction. 
But with the use of Python closures, we can easily extend its scope to invoke a function outside its scope.
"""
deptsFromFnCall = c.Depts()
d2 = deptsFromFnCall("en")
print(d2)

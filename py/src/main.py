# rectangle area
# area = length * width
# length = int(input("Enter length of rectangle: "))
# width = int(input("Enter width1: "))
# area = length * width
# print("Area is: ", area)

# LIGHT_MESSAGES = {
#     'English': "There are %(number_of_lights)s lights.",
#     'Pirate':  "Arr! Thar be %(number_of_lights)s lights."
#

# def lights_message(language, number_of_lights):
#     """Return a language-appropriate string reporting the light count."""
#     return LIGHT_MESSAGES[language] % locals()

# def is_pirate(message):
#     """Return True if the given message sounds piratical."""
#     return re.search(r"(?i)(arr|avast|yohoho)!", message) is not None

# displacement
initialVelocity = float(input("Initial velocity: "))
finalVelocity = float(input("Final velocity: "))
acceleration = float(input("Acceleration: "))

displacement = ((finalVelocity**2) - (initialVelocity**2)) / (2 * acceleration)
print("displacement = ", displacement)

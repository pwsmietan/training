from zipfile import *

# f = ZipFile("img.zip", "w", ZIP_DEFLATED)
# f.write("students.data")
# f.close()

# Unzip
f = ZipFile("img.zip", "r")
f.extractall()
f.close()

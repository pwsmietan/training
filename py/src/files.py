try:
    print("File I/O")
    fHandle = open("mssql.sh", "+r")
    print("File Class: ", type(fHandle))
    print(dir(fHandle))
    txt = fHandle.read()
    print(txt)
    fHandle.write("//EOJ")

    with open("test.txt", "+w") as f:
        f.write("Test DE NT7PS\n")
        f.flush()

    with open("test.txt", "a") as f:
        f.write("QRT")
        f.flush()

    with open("mydata.data", "wb") as g:
        g.write(b"NT7PS")

    # random access use seek() 0 = leftmost, 1 = current pos, 2 = rightmost
    with open("mydata.data", "rb") as f:
        print(f"Reading 2 bytes from binary file: {f.read(2).decode()}")
        print(f"Stream pointer now at: {f.tell()}")
        print("Moving file pointer back to 0,0")
        f.seek(0, 0)
        print(f"Stream pointer now at: {f.tell()}")
        print(f"Now reading one byte after seek: {f.read(1).decode()}")

except FileNotFoundError as eX:
    print(eX)
except Exception as m:
    print(m)
finally:
    print("Housekeeping - closing handles")
    fHandle.close()

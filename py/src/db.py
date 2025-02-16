import sqlite3

# Create connection variable:
conn = sqlite3.connect("d:\\corporate\\py\\sqlite\\test.db")
print(conn)

# Create cursor object to perform DML/DDL commands:
cur = conn.cursor()
cur.execute("CREATE TABLE TblTest(id integer primary key)")

# Commit changes and close handles:
conn.commit()
cur.close()
conn.close()

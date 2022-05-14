import sqlite3

# Create db or use in RAM
conn = sqlite3.connect(':memory:')
# conn = sqlite3.connect('customer.db')

# Create cursor to the db
c = conn.cursor()

# Create the table
# dot string """..."""
c.execute("""
    CREATE TABLE customers (
        first_name text,
        last_name  text,
        email      text
    )
""")
# 5 DATATYPE for sqlite:
#   NULL
#   INTEGER
#   REAL
#   TEXT
#   BLOB (mp3, file)

# Commit/execute the command
conn.commit()

# Add single entry data
c.execute("INSERT INTO customers VALUES ('John', 'Elder', 'john@email.com)")

# Add multiple entries
# tuples inside a list
# many_customers = [(), (), ()]
many_customers = [
    ('Wes'), ('Brown'), ('wes@email.com'),
    ('Steph'), ('Johnson'), ('steph@email.com'),
    ('Jimmy'), ('Doe'), ('doe@email.com'),
]
c.executemany("INSERT INTO customers VALUES (?, ?, ?)", many_customers)
conn.commit()

# Query and Fetchone/all/many, doesn't require commit()
c.execute("SELECT * FROM customers")
# since the entry is tuples
# print(c.fetchone())
# print(c.fetchone()[0])
# print(c.fetchone()[1])
# print(c.fetchone()[2])
# c.fetchmany(3)
print(c.fetchall())

# Format queries
items = c.fetchall()
for item in items:
    print item
    print (item[0] + " " + item[1] + " | " + item[2])

# Primary key ID: rowid, pre-created by sqlite
c.execute("SELECT rowid, * FROM customers")
items = c.fetchall()

# WHERE clause
c.execute("SELECT * FROM customers WHERE last_name = 'Doe'")
# Logical opeartors: = >=
# LIKE:
#   % wild card any char
#   - wild card single char

# Update records
c.execute("""
    UPDATE customers SET first_name = "Bob"
    WHERE  last_name = 'Elder'
""")
conn.commit()

# Delete records
c.execute("DELETE FROM customers WHERE last_name LIKE 'D%'")

# Order by
c.execute("SELECT * FROM customers ORDER BY last_name ASC")

# AND / OR
c.execute("""
    SELECT * FROM customers
     WHERE last_name = 'D%' AND rowid > 3
     ORDER BY last_name ASC
""")

# Limiting results
c.execute("SELECT * FROM customers LIMIT 2")

# Drop table
c.execute("DROP TABLE customers")
conn.commit()

# Close the connection
conn.close()

import sqlite3

conn = sqlite3.connect('customer.db')

c = conn.cursor()

c.execute("INSERT INTO customers VALUES ('John', 'Elder', 'john@email.com)")
c.execute("INSERT INTO customers VALUES ('Eddy', 'Smith', 'john@email.com)")
c.execute("INSERT INTO customers VALUES ('Adam', 'Blue', 'john@email.com)")

conn.commi()

conn.close()

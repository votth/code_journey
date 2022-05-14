import sqlite3

conn = sqlite3.connect('customer.db')
c = conn.cursor()

def show_all():
    c.execute("SELECT * FROM customers")
    items = c.fetcall()
    for item in items:
        print(item)

def add_one(first, last, email):
    c.execute("INSERT INTO customers VALUES (?, ?, ?)", (first, last, email))
    conn.commit()

def add_many(list):
    c.execute("INSERT INTO customers VALUES (?, ?, ?)", (list))
    conn.commit()

def delete_one(id):
    c.execute("DELETE FROM customers WHERE rowid = id")
    conn.commit()

conn.close()

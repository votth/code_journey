import sqlite3
from employee import Employee

# conn = sqlite3.connect('employee.db')
# conn = sqlite3.connect(':memory:')    taking db from RAM, mostly for testing, won't save to employee.db
conn = sqlite3.connect(':memory:')

c = conn.cursor()

c.execute("""
    CREATE TABLE employees (
        first text,
        last  text,
        pay   integer
    )
""")

## SQL-ish way
#c.execute("INSERT INTO employees VALUES ('Corey', 'Schafer', '50000')")
#c.execute("INSERT INTO employees VALUES ('Marry', 'Schafer', '70000')")
##
## tuple approach
#c.execute("INSERT INTO employees VALUES (?, ?, ?)", (emp1.first, emp1.last, emp1.pay))
#conn.commit()
#c.execute("SELECT * FROM employees WHERE last=?", ('Schafer', ))
#print(c.fetchall())
##
## dictionary approach
#c.execute("INSERT INTO employees VALUES (:first, :last, :pay)", {'first': emp2.first, 'last': emp2.last, 'pay': emp2.pay})
#conn.commit()
#c.execute("SELECT * FROM employees WHERE last=:last", {'last': 'Doe'})
#print(c.fetchall())
##
#conn.commit()
## c.fetchone()
## c.fetchall()
## c.fetchmany(<number>)


# Python way, using function
def insertEmp(emp):
    # no need for conn.commit()
    with conn:
        c.execute("INSERT INTO employees VALUES (:first, :last, :pay)", {'first': emp.first, 'last': emp.last, 'pay': emp.pay})

def getEmpsByName(lastname):
    c.execute("SELECT * FROM employees WHERE last=:last", {'last': lastname})
    return c.fetchall()

def updatePay(emp, pay):
    with conn:
        c.execute("""
            UPDATE employees
               SET pay=:pay
             WHERE first=:first AND last=:last
        """, {'first': emp.first, 'last': emp.last, 'pay': pay})

def removeEmp(emp):
    with conn:
        c.execute("DELETE FROM employees WHERE first=:first AND last=:last", {'first': emp.first, 'last': emp.last})

emp1 = Employee('John', 'Doe', 80000)
emp2 = Employee('Johnny', 'Doe', 90000)
emp3 = Employee('Jimmy', 'Doe', 70000)

insertEmp(emp1)
insertEmp(emp2)
insertEmp(emp3)

emps = getEmpsByName('Doe')
print(emps)

updatePay(emp2, 100000)
removeEmp(emp1)

emps = getEmpsByName('Doe')
print(emps)

conn.close()

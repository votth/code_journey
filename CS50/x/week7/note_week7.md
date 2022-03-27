# Python
## set()
- list without dupplicates (?)
## sorted()
- only sort dict{} by keys, not their value, by default
- default: A -> Z, sort by keys
``` python
def get_value(title):
	return titles[title]

# sort by get_value: which is the value of key in this example
for title in sorted(titles, key=get_value, reverse=True):
	print(title, titles[title])

# or, using no-name function lambda
# no need to define def get_value():
for title in sorted(titles, key=lambda title: titles[title], reverse=True)
```
## lambda
- no-named function, used for function that used once, eg: the above get_value(title)
- but usually a one-liner so it's still readable
## import re
- regular expression
- re.search("\<pattern\>", \<from\>)
``` python
if re.search("^(OFFICE|THE.OFFICE)$", title):
```
## misc
upper(), strip()

# Regular expression
- . any character
- .\* 0 or more characters
- .+ 1 or more characters
- ? optional
- ^ start of input
- $ end of input

# Databases
- SQL, MySQL - SQLite, phpMyAdmin
- storing data locally and not in memory
- csv portable file format

## Relational database
- spreadsheet-ish program, or tables
- tables that have common column: FOREIGN KEY

## SQL
- Structed Query Language
- optimized for reading, updating, creating databases
- nested-query
- The four fundamental operations:
	- INSERT
	- SELECT
	- UPDATE
	- DELETE
### CRUD
- create: CREATE, INSERT
- read: SELECT
- update: UPDATE
- delete: DELETE, DROP
	...
### Others:
- columns manipulation
	- AVG
	- COUNT
	- DISTINCT
	- LOWER, UPPER
	- MAX, MIN
- table manipulation
	- WHERE
	- LIKE
	- ORDER BY
	- LIMIT
	- GROUP BY
	- !! JOIN

#### JOIN
- if between an N number of relational tables, you want to get data from B WHERE A, but there's no direct-relation between the 2

### Data types
- NULL
- INTEGER
- REAL
- TEXT
- BLOB
- NUMERIC
- CHAR vs VARCHAR: the former is fixed length, while the later is not
---
- Primary key: column that uniquely indentifies all of the data
- Foreign key: appearance of another table's primary key

### indexes
- index table, improve searching
- B-trees (not binary): nodes can have more than 2 children
``` SQL
CREATE INDEX name ON table (column, ...);
```

### Sample
``` SQL
.mode csv

.import FILE TABLE
.import favorite.csv favorites

.schema

SELECT columns FROM table;
SELECT DISTINCT(UPPER(title)) FROM favorites;
SELECT title, genres FROM favorites;

SELECT title FROM favorites WHERE title LIKE "%office%";
	   COUNT(title)
```
- sqlite3 (iPhone or Andoir is available too), mySQL, postregSQL
- !! no undo
``` SQL
SELECT DISTINCT(title) FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Comedy") ORDER BY title;
```
	- start small, and slowly adding into your "command" to ultimately solve your problem

# Add SQL to Python
``` python
import csv
from cs50 import SQL

db = SQL("sqlite:///favorites.db")

title = input("Title: ").strip()

# parsing Python's title into ? for SQL
rows = db.execute("SELECT COUNT(*) FROM favorites WHERE title LIKE ?", title))
row = rows[0]
print(row["COUNT(*)"])

# OR
rows = db.execute("SELECT COUNT(*) AS counter FROM favorites WHERE title LIKE ?", title))
row = rows[0]
print(row["counter"])
```

# Real-world problems
## SQL injection attacks: comment: '--
## Race conditions
- happend with shared data/bases
- too many interactions happend at the same time
- atomic code: execute top-down, line by line
	- results in lines of code get splitted and ran for different people
- solution: commmunicate / multiple-thread
	- LOCKS
	- BEGIN TRANSACTION
	- COMMIT
	- ROLLBACK
``` python
# soft-locked the database
db.execute("BEGIN TRANSACTION")
# some python+SQL code for the action
# commit transaction
db.execute("COMMIT")
```
	- best to have the least possible line of code/tasks in TRANSACTION to avoid too-long downtime for others

---
# SQL prompts

.schema
to show table columns

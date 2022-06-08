Create table
``` sql
CREATE TABLE students(
	id INT,
	name TEXT,
	birthday TEXT,
	PRIMARY KEY(id)
	FOREIGN KEY (class_id)
		REFERENCES classes (class_id)
);
```

Drop table
``` sql
DROP TABLE classes;
```

Insert, update, delete row, info
``` sql
UPDATE students
   SET class_id = NULL;

INSERT INTO students
VALUES
	(1, James, 1990),
	(2, Tommy, 1993),
	(3, David, 1989);

INSERT INTO students (id, name)
VALUES
	(4, Elizabeth);

DELETE FROM students
 WHERE condition;

DELETE FROM students;
```

Manipulate table
``` sql
ALTER TABLE students
RENAME TO new_students;

CREATE TABLE copy_students;
INSERT INTO copy_students SELECT * FROM new_students;

DROP TABLE IF EXIST copy_students;
```

Manipulate columns, with restrictions:
- The new column cannot have a UNIQUE or PRIMARY KEY constraint.
- If the new column has a NOT NULL constraint, then you must specify a default value for it.
- New column cannot have a default of CURRENT_TIMESTAMP, CURRENT_DATE, CURRENT_TIME or an expression.
``` sql
ALTER TABLE new_students
  ADD COLUMN address TEXT;

ALTER TABLE new_students
RENAME COLUMN address TO home_address;

ALTER TABLE new_students
 DROP COLUMN home_address;
```

Constraints
`NOT NULL` `UNIQUE` `AUTO_INCREMENT`
``` sql
CREATE TABLE contacts (
	contact_id INTEGER PRIMARY KEY,
	first_name TEXT NOT NULL,
	last_name  TEXT NOT NULL,
	email      TEXT,
	phone      TEXT NOT NULL
		CHECK (length(phone) >= 10)
);
```

Queries
using `AS` to rename the queries columns
using `DISTINCT` for unique values or `GROUP BY ... WHERE COUNT(*) = 1`

How many males or females there are in the table
``` sql
SELECT COUNT(sex), sex
FROM employee
GROUP BY sex;
```

Total sales of each salemans
``` sql
SELECT SUM(total_sales), emp_id
  FROM logs
 GROUP BY emp_id;
```

Wildcards
using with `LIKE 'expression'`  
- `%` for any number of character
- `_` for one character

Union
same number of columns in `SELECT`

Joins
``` sql
SELECT table1.something1, table1.something2, table2.something1
  FROM table1
  JOIN table2
    ON table1.columnThis = table2.columnThat;
```
Default JOIN is INNER JOIN  
`LEFT JOIN` includes all rows from 'left' table, `RIGHT JOIN` vice versa.

ON DELETE
``` sql
CREATE TABLE branch (
	branch_id INT PRIMARY KEY,
	branch_name VARCHAR(40),
	mgr_id INT,
	mgr_start_date DATE,
	FOREIGN KEY(mgr_id) REFERENCES employee(emp_id) ON DELETE SET NULL
);

DELETE FROM employee
WHERE emp_id = 102;
```

`ON DELETE CASCADE` would delete the whole row where the deletion has effected.

Triggers
Perform a set of action when its condition is met, eg. some kind of entries got added to the table.
``` sql
DELIMITER $$
CREATE
	TRIGGER my_trigger BEFORE INSERT
	ON employee
	FOR EACH ROW BEGIN
		INSERT INTO trigger_test VALUES('added new employee')
	END $$
DELIMITER;
```

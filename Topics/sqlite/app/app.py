import database

# add record to db
database.add_one('John', 'Doe', 'john@email.com')

# print all entries
database.show_all()

# add many
stuff = [
    ('Elena', 'Snowden', 'elena@email.com'),
    ('Vildred', 'Arbiter', 'decending@email.com')
]
database.add_many(stuff)

# delete one
database.delete_one(2)

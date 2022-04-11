# https://www.learnpython.org/en/Pandas_Basics

print("Pandas (differenty from panda with no `s`) is a high-level data manipulation tool, built on the Numpy package, its key data structure is DataFrame: store and manipulate tabular data in rows of observations and columns of variables\n")

dict = {
        "country": ["Brazil", "Russia", "India", "China", "South Africa"],
        "capital": ["Brasilia", "Moscow", "New Dehli", "Beijing", "Pretoria"],
        "area": [8.516, 17.10, 3.286, 9.597, 1.221],
        "population": [200.4, 143.5, 1252, 1357, 52.98]
}

import pandas as pd
brics = pd.DataFrame(dict)
print(brics)

brics.index = ["BR", "RU", "IN", "CN", "SA"]
print("\n", brics)


# print("\n\nImporting from a csv file")
# cars = pd.read_csv('cars.csv')
# print(cars)

print("Use `loc` and `iloc` to perform data selection operation.\n'loc` is label-based while `iloc` is integer index based")

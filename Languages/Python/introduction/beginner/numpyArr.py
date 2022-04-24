print("Alternatives to `lists`, fast, easy to work with, and the ability to perform calculations across the arrays")

# Create 2 new lists height and weight
height = [1.87,  1.87, 1.82, 1.91, 1.90, 1.85]
weight = [81.65, 97.52, 95.25, 92.98, 86.18, 88.45]

# Import the numpy package as np
import numpy as np

# Create 2 numpy arrays from height and weight
np_height = np.array(height)
np_weight = np.array(weight)

print(type(np_height))

bmi = np_weight / np_height ** 2
print(bmi)

print("-------------")
# For a boolean response
print(bmi > 25)

# Print only those observations above 23
print(bmi[bmi > 25])

# Basic statistic
# np.mean for average value
# np.median for ???
# these 2 are good to use for checking "odd-balls" in big data

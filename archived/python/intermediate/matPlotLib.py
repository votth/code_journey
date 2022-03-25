# line plot
import matplotlib.pyplot as plt

x = [1, 2, 3, 4]
y = [2, 4, 6, 8]

# Line plot is good when you have a time scale along the horizontal/x axis
plt.plot(x,y)
plt.show()

# plt.plot(gdp_cap, life_exp)
# # Put the x-axis on a logarithmic scale
# plt.xscale('log')

# Scatter plot is good when you're trying to assess if there's a correlation between two variables
plt.scatter(x,y)

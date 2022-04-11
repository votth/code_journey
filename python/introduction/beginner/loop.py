primes = [2, 3, 5, 7]

for number in primes:
    print(number)

print("Print from 0 to 4")
for x in range(5):
    print(x)

print("Print from 4 to 6")
for x in range(4, 7):
    print(x)

print("Print number with 2 value apart")
for x in range (4, 7, 2):
    print(x)

print("While loop")
count = 0
while count < 5:
    print(count)
    count += 1


print("break and continue, break exits the loop statment, and continue skip the current block")

count = 0
while True:
    print(count)
    count += 1
    if count > 5:
        break

for x in range(10):
    if x % 2 == 0:
        continue
    print(x)


print("Using `else` with loop statments, when the loop condition failes then code part in `else` is executed, `break` will skip `else` but `continue` won't")

count = 0
while(count < 5):
    print(count)
    count += 1
else:
    print("Count value reached %d" %(count))

for i in range(1,10):
    if(i % 5 == 0):
        break
    print(i)
else:
    print("This is not printed because for loop is terminated because of break but not due to a fail in condition")

def split(lst):
    return [float(i) for i in lst.split(" ")]
def average(lst):
    sum = n = 0
    for i in lst:
        n += 1
        sum += i
    return [sum/n, n]

x = average(split(input("Numbers: ")))
print("n=",x[1])
print("Average=",x[0])


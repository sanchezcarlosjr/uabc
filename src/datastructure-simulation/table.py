import time

x=int(time.time())+10
def rand(a=2147483649, c=4294967297, m=4294967296):
    global x
    x=(a*x+c)%m
    return x

print(rand())
print(rand())
print(rand())
print(rand())
print(rand())

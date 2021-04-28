import numpy as np

def generate(n):
    print("Example: [2x1]=5")
    userRequest=input("")
    arr=userRequest.split("=")
    pos=arr[0].replace("[","").replace("]","").split("x")
    value=arr[1]
    value=int(value)
    if value < 0 or value > n*n:
        raise Error("value should be in interval")
    temp = [int(i) for i in pos]
    temp.append(int(value))
    return temp

t=generate(3)

A = np.array([
        [1,1,1,0,0,0,0,0,0], 
        [0,0,0,1,1,1,0,0,0], 
        [0,0,0,0,0,0,1,1,1],
        [1,0,0,1,0,0,1,0,0],
        [0,1,0,0,1,0,0,1,0],
        [0,0,1,0,0,1,0,0,0],
        [1,0,0,0,1,0,0,0,1],
        [0,0,1,0,1,0,1,0,1],
        [0,0,0,0,0,0,0,0,0]
    ]
)
A[8][3*t[0]+t[1]] = 1
B = np.array([15, 15, 15, 15, 15, 15, 15, 15, t[2]])

X = np.linalg.solve(A,B)

print(X.reshape(3,3))

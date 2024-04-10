import numpy as np

m = 8
def addarr(arr, n, g1, g2):
    for i in range(n):
        for j in range(n):
            arr[i][j] = 0
    arr[g1][g2] = 1

def showarr(arr, n):
    for i in range(n):
        for j in range(n):
            print(f"[{i}] [{j}]= {arr[i][j]}\t", end="")
        print("\n")

def move_u(arr, n, g1, g2):
    x = int(input("How many moves?\n"))
    if x > g1:
        print("Can not move!!\n")
    else:
        arr[g1][g2] = 0
        g1 -= x
        arr[g1][g2] = 1
        showarr(arr, n)

def move_d(arr, n, g1, g2):
    x = int(input("How many moves?\n"))
    if x + g1 > 7:
        print("Can not move!!\n")
    else:
        arr[g1][g2] = 0
        g1 += x
        arr[g1][g2] = 1
        showarr(arr, n)

def move_l(arr, n, g1, g2):
    x = int(input("How many moves?\n"))
    if x > g2:
        print("Can not move!!\n")
    else:
        arr[g1][g2] = 0
        g2 -= x
        arr[g1][g2] = 1
        showarr(arr, n)

def move_r(arr, n, g1, g2):
    x = int(input("How many moves?\n"))
    if x + g2 > 7:
        print("Can not move!!\n")
    else:
        arr[g1][g2] = 0
        g2 += x
        arr[g1][g2] = 1
        showarr(arr, n)

arr = np.zeros((8, 8), dtype=int)
g1, g2 = 7, 0
n = arr.shape[0]

addarr(arr, n, g1, g2)
showarr(arr, n)

while True:
    x = input("U or D or L or R or UL=i or UR=o or DL=p or DR=k (exit = E)\n")
    if x in ['U', 'u']:
        move_u(arr, n, g1, g2)
    elif x in ['D', 'd']:
        move_d(arr, n, g1, g2)
    elif x in ['L', 'l']:
        move_l(arr, n, g1, g2)
    elif x in ['R', 'r']:
        move_r(arr, n, g1, g2)
    elif x in ['E', 'e']:
        break
    else:
        print("\nU or D or L or R or UL=i or UR=o or DL=p or DR=k (exit = E)\n")

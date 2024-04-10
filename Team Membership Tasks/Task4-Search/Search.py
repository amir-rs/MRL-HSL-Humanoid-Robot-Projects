import random

def findElement2(arr, n, key):
    position = -1
    i = int(input("[i][j] i=?\n"))
    j = int(input("[i][j] j=?\n"))
    if arr[i][j] == key:
        position = 1
        print(f"Element Found at Position: [{i}] [{j}]")
    if position == -1:
        print("Element not found")

def findElement1(arr, n, key):
    position = -1
    for i in range(n):
        for j in range(n):
            if arr[i][j] == key:
                position = 1
                break
        if arr[i][j] == key:
            break
    if position == -1:
        print("Element not found")
    else:
        print(f"Element Found at Position: [{i}] [{j}]")

def addarr(arr, n):
    for i in range(n):
        for j in range(n):
            arr[i][j] = 0
    g1 = random.randint(0, 99)
    g2 = random.randint(0, 99)
    print(g1)
    print(g2)
    arr[g1][g2] = 1

arr = [[0 for j in range(100)] for i in range(100)]
n = len(arr)
key = 1

addarr(arr, n)
x = int(input("1 or 2\n"))
if x == 1:
    findElement1(arr, n, key)
elif x == 2:
    findElement2(arr, n, key)
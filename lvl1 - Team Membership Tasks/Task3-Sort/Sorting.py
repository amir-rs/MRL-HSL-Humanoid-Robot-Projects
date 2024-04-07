import random

def merge(a, low, mid, high):
    n1 = mid - low + 1
    n2 = high - mid

    L = [0] * (n1)
    R = [0] * (n2)

    for i in range(0, n1):
        L[i] = a[low + i]

    for j in range(0, n2):
        R[j] = a[mid + 1 + j]

    i = 0
    j = 0
    k = low

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        a[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        a[k] = R[j]
        j += 1
        k += 1

def mergeSort(a, low, high):
    if low < high:
        mid = (low + (high - 1)) // 2
        mergeSort(a, low, mid)
        mergeSort(a, mid + 1, high)
        merge(a, low, mid, high)

def selectionSort(a):
    for i in range(len(a)):
        min_idx = i
        for j in range(i + 1, len(a)):
            if a[min_idx] > a[j]:
                min_idx = j
        a[i], a[min_idx] = a[min_idx], a[i]

a = []
n = 20
max = 100
min = 0
for i in range(n):
    a.append(random.randint(min, max))

print("Your array is:")
for i in range(n):
    print(a[i], end=" ")
print("\n\n1(selectionSort) or 2(mergesort)")
x = int(input())

if x == 1:
    selectionSort(a)
elif x == 2:
    mergeSort(a, 0, n - 1)

print("\nYour array after sorting:")
for i in range(n):
    print(a[i], end=" ")
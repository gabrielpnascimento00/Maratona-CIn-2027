#Dinossauros que cantam 1v1

import sys
import math as m
input = sys.stdin.readline

n = int(input())

arr = input().split()
cont = []
maxd = 0
x = m.ceil(m.log2(len(arr)))

if len(arr) % 2 == 0:
    for _ in range(x):
        for i in range(1, n + 1, +2):
            if int(arr[i]) > int(arr[i - 1]):
                maxd = max(maxd, abs(int(arr[i]) - int(arr[i - 1])))
                cont.append(arr[i])
            else:
                maxd = max(maxd, abs(int(arr[i]) - int(arr[i - 1])))
                cont.append(arr[i - 1])

        if len(cont) > 1:
            arr = cont
            n = len(arr)
        else:
            break
else:
    for _ in range(x):
        for i in range(0, n, +2):
            if (i != n - 1):
                if int(arr[i]) > int(arr[i + 1]):
                    maxd = max(maxd, abs(int(arr[i]) - int(arr[i + 1])))
                    cont.append(arr[i])
                else:
                    maxd = max(maxd, abs(int(arr[i]) - int(arr[i + 1])))
                    cont.append(arr[i + 1])
            else:
                cont.append(arr[i])

        if len(cont) > 1:
            arr = cont
            n = len(arr)
        else:
            break

print(maxd)
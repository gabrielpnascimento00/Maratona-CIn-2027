import sys
import math as m
input = sys.stdin.readline

n = int(input())
x = 0
ans = 0
arr = [int(x) for x in input().split()]

if len(arr) % 2 == 0:
    for _ in range(m.ceil(m.log2(n))):
        cont = 0
        for i in range(1, n + 1, +2):
            if arr[i] > arr[i - 1]:
                x = abs(arr[i] - arr[i - 1])
                ans = max(ans, x)
                arr.insert(cont, max(arr[i], arr[i - 1]))
                cont += 1
            else:
                x = abs(arr[i] - arr[i - 1])
                ans = max(ans, x)
                arr.insert(cont, max(arr[i], arr[i - 1]))
                cont += 1
        n = n//2
else:
    for _ in range(m.ceil(m.log2(n))):
        cont = 0
        for i in range(1, n + 1, +2):
            if arr[i] > arr[i - 1]:
                x = abs(arr[i] - arr[i - 1])
                ans = max(ans, x)
                arr.insert(cont, max(arr[i], arr[i - 1]))
                cont += 1
            else:
                x = abs(arr[i] - arr[i - 1])
                ans = max(ans, x)
                arr.insert(cont, max(arr[i], arr[i - 1]))
                cont += 1
            n = n//2 + 1

print(ans)
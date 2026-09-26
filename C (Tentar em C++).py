#Questão da corrida (time C) arrays lexicamente menores

import sys
input = sys.stdin.readline

n, m, k = [int(x) for x in input().split()]

arrA = input().split()
arrB = input().split()
ans = ''

a = 0
b = 0

for i in range(k):
    if a < n and b < m:
        if int(arrA[a]) > int(arrB[b]):
            b += 1
            ans += 'B'
        else:
            a += 1
            ans += 'A'
    else:
        break

ans += 'A' * (n - a)
ans += 'B' * (m - b)

print(ans)
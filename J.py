import sys
input = sys.stdin.readline

n, k = [int(x) for x in input().split()]

sum = n
ans = 0

if n != k and k > n:
    n += 1
    while True:
        sum += n
        ans += 1

        if sum >= k:
            break

        n += 1

print(ans)
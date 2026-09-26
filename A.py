import sys
input = sys.stdin.readline

n = int(input())

arr = [int(x) for x in input().split()]

print(int(((n + 1)*(n/2)) - sum(arr)))
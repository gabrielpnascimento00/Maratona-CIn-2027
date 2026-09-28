#Qual o número que falta na sequencia de 1 até n

import sys
input = sys.stdin.readline

n = int(input())

arr = [int(x) for x in input().split()]

print(int(((n + 1)*(n/2)) - sum(arr)))
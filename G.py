#Maior divisor comum

import math as m
import sys
input = sys.stdin.readline

a, b = [int(x) for x in input().split()]

print(m.gcd(a, b))
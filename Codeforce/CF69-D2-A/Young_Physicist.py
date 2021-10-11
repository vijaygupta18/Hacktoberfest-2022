#!/usr/bin/env python3
import sys
input = sys.stdin.readline

############ ---- Input Functions, coutery of 'thekushalghosh' ---- ############


def inp():
    return(int(input()))


def inlt():
    return(list(map(int, input().split())))


def insr():
    s = input()
    return(list(s[:len(s) - 1]))


def invr():
    return(map(int, input().split()))


if __name__ == "__main__":
    n = inp()
    x, y, z = 0, 0, 0
    for i in range(n):
        a, b, c = invr()
        x += a
        y += b
        z += c
    if x == 0 and y == 0 and z == 0:
        print('YES')
    else:
        print('NO')

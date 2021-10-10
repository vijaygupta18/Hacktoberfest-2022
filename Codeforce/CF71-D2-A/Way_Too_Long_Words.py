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
    results = []
    for i in range(n):
        s = insr()
        if len(s) > 10:
            results.append(s[0] + str(len(s) - 2) + s[-1])
        else:
            results.append(''.join(s))
    for r in results:
        print(r)

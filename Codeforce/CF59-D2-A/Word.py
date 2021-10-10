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
    s = insr()
    countl = 0
    countu = 0
    countl = sum(1 for c in s if c.islower())
    countu = len(s) - countl
    if countu > countl:
        s = [i.upper() for i in s]
        print(''.join(s))
    else:
        s = [i.lower() for i in s]
        print(''.join(s))

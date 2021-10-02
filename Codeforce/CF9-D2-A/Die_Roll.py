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
    a, b = invr()
    m = 7 - max(a, b)
    if m == 6:
        print('1/1')
    if m == 5:
        print('5/6')
    if m == 4:
        print('2/3')
    if m == 3:
        print('1/2')
    if m == 2:
        print('1/3')
    if m == 1:
        print('1/6')

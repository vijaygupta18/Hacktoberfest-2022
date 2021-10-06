import numpy as np
import cv2 as cv


def nothing():
    pass


cv.namedWindow('image')
cv.createTrackbar('lH', 'image', 0, 255, nothing)
cv.createTrackbar('lS', 'image', 0, 255, nothing)
cv.createTrackbar('lV', 'image', 0, 255, nothing)
cv.createTrackbar('uH', 'image', 255, 255, nothing)
cv.createTrackbar('uS', 'image', 255, 255, nothing)
cv.createTrackbar('uV', 'image', 255, 255, nothing)

while 1:
    frame = cv.imread('A1.png', -1)
    lh = cv.getTrackbarPos('lH', 'image')
    ls = cv.getTrackbarPos('lS', 'image')
    lv = cv.getTrackbarPos('lV', 'image')
    uh = cv.getTrackbarPos('uH', 'image')
    us = cv.getTrackbarPos('uS', 'image')
    uv = cv.getTrackbarPos('uV', 'image')

    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
    lb = np.array([lh, ls, lv])
    ub = np.array([uh, us, uv])
    mask = cv.inRange(frame, lb, ub)
    res = cv.bitwise_and(frame, frame, mask)
    res = cv.resize(res, (500, 500))
    mask = cv.resize(mask, (500, 500))
    frame = cv.resize(frame, (500, 500))
    cv.imshow('res', res)
    # cv.imshow('frame', frame)
    cv.imshow('mask', mask)

    k = cv.waitKey(1) & 0xFF
    if k == 27:
        break

cv.destroyAllWindows()

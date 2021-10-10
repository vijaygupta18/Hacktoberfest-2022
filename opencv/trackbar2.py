import numpy as np
import cv2 as cv


def nothing(x):
    print(x)


img = np.zeros((300, 512, 3), np.uint8)  # creating a black image
cv.namedWindow('image')  # creating a window

cv.createTrackbar('B', 'image', 0, 255, nothing)  # add trackbar to image
cv.createTrackbar('G', 'image', 0, 255, nothing)
cv.createTrackbar('R', 'image', 0, 255, nothing)

switch = '0 : OFF\n 1: ON'
cv.createTrackbar(switch, 'image', 0, 1, nothing)

while 1:
    cv.imshow('image', img)  # show the image
    k = cv.waitKey(1) & 0xFF  # checks the input - esc key
    if k == 27:
        break

    b = cv.getTrackbarPos('B', 'image')  # get the position value of b
    g = cv.getTrackbarPos('G', 'image')  # get the position value of g
    r = cv.getTrackbarPos('R', 'image')  # get the position value of r
    s = cv.getTrackbarPos(switch, 'image')

    if s == 0:
        img[:] = 0
    else:
        img[:] = [b, g, r]

# cv.destroyAllWindow()
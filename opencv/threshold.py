import numpy as np
import cv2 as cv

grad = cv.imread('gradient.png')

_, th1 = cv.threshold(grad, 127, 255, cv.THRESH_BINARY)
_, th2 = cv.threshold(grad, 127, 255, cv.THRESH_TRUNC)
_, th3 = cv.threshold(grad, 127, 255, cv.THRESH_TOZERO)

cv.imshow('image', grad)
cv.imshow('th1', th1)
cv.imshow('th2', th2)
cv.imshow('th3', th3)
cv.waitKey(0)
cv.destroyAllWindows()
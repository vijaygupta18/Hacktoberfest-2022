import numpy as np
import cv2 as cv

img1 = np.hstack((np.zeros((500,250,3),dtype = np.uint8) , np.ones((500,250,3) , dtype=np.uint8)*225))
img2 = np.zeros((500,500,3), dtype=np.uint8)
img2 = cv.rectangle(img2 , (200,200), (300,300) , (255,255,255) , -1)

B_and = cv.bitwise_and(img1,img2)
B_or = cv.bitwise_or(img1,img2)
B_nor = cv.bitwise_not(img2)
B_xor = cv.bitwise_xor(img1,img2)

cv.imshow("img1", img1)
cv.imshow("img2", img2)
cv.imshow('and',B_and)
cv.imshow('or',B_or)
cv.imshow('nor',B_nor)
cv.imshow('xor',B_xor)
cv.waitKey(0)
cv.destroyAllWindows()
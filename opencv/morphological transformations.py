from matplotlib import pyplot as plt
import cv2 as cv
import numpy as np

img = cv.imread('balls1.jpg', cv.IMREAD_GRAYSCALE)
# img = cv.cvtColor(img, cv.COLOR_BGR2RGB)
_,mask = cv.threshold(img, 220, 255, cv.THRESH_BINARY_INV)
kernel = np.ones((5, 5), np.uint8)
erosion = cv.erode(mask, kernel, iterations=1)
dilation = cv.dilate(mask, kernel, iterations=1)
closing = cv.morphologyEx(mask, cv.MORPH_CLOSE, kernel)
opening = cv.morphologyEx(mask, cv.MORPH_OPEN, kernel)
gradient = cv.morphologyEx(mask, cv.MORPH_GRADIENT, kernel)

titles = ['Original', 'mask', 'erode', 'dilate', 'closing', 'opening', 'gradient']
images = [img, mask, erosion, dilation, closing, opening, gradient]

# cv.imshow('img', img)
# cv.waitKey(0)
for i in range(7):
    plt.subplot(2, 4, i+1)
    plt.imshow(images[i], 'gray')
    plt.title(titles[i])
    plt.xticks([]),plt.yticks([])

# plt.imshow(img, 'gray')
plt.show()
import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt

img = cv.imread('bella.jpg')
img = cv.cvtColor(img, cv.COLOR_BGR2RGB)
kernel = np.ones((5, 5), np.float32)/25
dst = cv.filter2D(img, -1, kernel)
blur = cv.blur(img, (5, 5))
Gblur = cv.GaussianBlur(img, (5, 5), 0)
median = cv.medianBlur(img, 5)
bilateral = cv.bilateralFilter(img, 5, 75, 75)

images = [img, dst, blur, Gblur, median, bilateral]
titles = ['image', 'dst', 'blur', 'Gblur', 'median', 'bilateral']
for i in range(len(images)):
    plt.subplot(2, 3, i+1)
    plt.imshow(images[i])
    plt.xticks([]), plt.yticks([])
    plt.title(titles[i])

plt.show()
import cv2 as cv
import numpy as np

img = cv.imread("Emilia-Clarke.jpeg",-1)
img1 = cv.imread("bella.jpg",-1)
print(img.shape)
print(img.size)
print(img.dtype)
b , g , r = cv.split(img)
# cv.imshow("green", r)
img = cv.merge((b,g ,r ))
# img = cv.resize(img , (512,512))
img1 = cv.resize(img1 , (512,512))
face = img[400:600 , 200:500]
img[0:200,0:300] = face

# dst = cv.add(img , img1)
# dst = cv.addWeighted(img , 0.5, img1 , 0.5 , 0)

cv.imshow("bella",img1)
cv.imshow("bella",img)

# cv.imshow("image",dst)
cv.waitKey(0)
cv.destroyAllWindows()
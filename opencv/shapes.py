import numpy as np
import cv2 as cv

img = cv.imread("Emilia-Clarke.jpeg", -1)
img1 = np.zeros([500,500,3], dtype=np.uint8)

img = cv.line(img, (300,100),(600,600), (255,0,0) , 10)
img = cv.line(img, (600,600), (900,100), (255,0,0), 10)
img = cv.circle(img , (600,250) , 200 , (0,255,0) , 10)
img = cv.arrowedLine(img , (600,0) , (600,100) , (255,255,255) , 10)
img = cv.rectangle(img, (50,50) , (1000,1000) , (255,255,255) , 10)
img = cv.putText(img , "Emilia Clerke" , (800,600) , cv.FONT_HERSHEY_SIMPLEX , 1 , (100,100,0) , 3 , cv.LINE_AA)
# cv.imshow("baw",img1)
cv.imshow("img",img)
cv.waitKey(0)
cv.destroyAllWindows()
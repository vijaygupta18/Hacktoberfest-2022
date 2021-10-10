import cv2 as cv
import numpy as np

cap = cv.VideoCapture(1)

print(cap.get(cv.CAP_PROP_FRAME_WIDTH))
print(cap.get(cv.CAP_PROP_FRAME_HEIGHT))

cap.set(3,3000)
cap.set(4,3000)

print(cap.get(cv.CAP_PROP_FRAME_WIDTH))
print(cap.get(cv.CAP_PROP_FRAME_HEIGHT))

while (cap.isOpened()):
    ret , frame = cap.read()

    if (ret == True):
        cv.imshow("camVid", frame)
        if cv.waitKey(25) & 0xFF == ord('q'):
          break
    else:
        break

cap.release()
cv.destroyAllWindows()

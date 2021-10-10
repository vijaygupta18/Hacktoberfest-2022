import cv2 as cv
import numpy as np
import datetime

cap = cv.VideoCapture(1)
cap.set(3,1280)
cap.set(4,1500)
if cap.isOpened() == False:
    print("Error capturing the video")
while cap.isOpened():
    ret , frame = cap.read()
    if ret == True:
        # text = "Width: " + str(cap.get(3)) + " Height: " + str(cap.get(4))
        text = str(datetime.datetime.now())
        frame = cv.putText(frame , text , (10,50) , cv.FONT_HERSHEY_SIMPLEX , 2 , (0,0,0), 1 , cv.LINE_AA)
        cv.imshow("Camera",frame)
        if cv.waitKey(25) & 0xFF == ord('q'):
            break
    else:
        break

cap.release()
cv.destroyAllWindows()
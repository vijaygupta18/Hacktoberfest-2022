import cv2 as cv
# import numpy as np
# from matplotlib import pyplot as plt

cap = cv.VideoCapture('vtest.avi')
_, frame1 = cap.read()
_, frame2 = cap.read()

while cap.isOpened():
    diff = cv.absdiff(frame1, frame2)
    grey = cv.cvtColor(diff, cv.COLOR_BGR2GRAY)
    blur = cv.GaussianBlur(grey, (5,5), 0)
    _, thresh = cv.threshold(blur, 20, 255, cv.THRESH_BINARY)
    # cv.imshow('thresh', thresh)
    dilated = cv.dilate(thresh, None, iterations=3)
    contours, _ = cv.findContours(dilated, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
    # cv.drawContours(frame1, contours, -1, (0, 255, 0), 2)

    for cnt in contours:
        x, y, w, h = cv.boundingRect(cnt)
        if cv.contourArea(cnt) <= 1500:
            continue
        cv.rectangle(frame1, (x,y), (x+w, y+h), (0, 255, 0), 2)
        cv.putText(frame1, 'Status: {}'.format('Occupied'), (20, 20), cv.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 3)

    cv.imshow('Cap', frame1)
    frame1 = frame2
    ret, frame2 = cap.read()
    if cv.waitKey(40) == 27:
        break

cv.destroyAllWindows()
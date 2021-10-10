import cv2 as cv

img = cv.imread("img.png",0)
# print(img)
cap  = cv.VideoCapture(0)

if (cap.isOpened()==False):
    print("error")
while (cap.isOpened()):
    ret, frame = cap.read()
    if ret == True:
        cv.imshow("Frame", frame)
        if cv.waitKey(25) & 0xFF == ord('q'):
          break
cap.release()

# cv.imshow("img", img)
# cv.waitKey(0)
cv.destroyAllWindows()
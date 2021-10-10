import cv2

faceCascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
#for image
#img = cv2.imread('multiple1.jpg')

#for video
vdo = cv2.VideoCapture(0)
vdo.set(3,640)
vdo.set(4,480)
vdo.set(10,500)
    
while True:
    success, img = vdo.read()
    
    imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    face = faceCascade.detectMultiScale(imgGray , 1.1 , 4 )
    
    for (x,y,w,h) in face:
        a = cv2.rectangle(img , (x,y) , (x+w, y+h) , (255,0,0) , 2)
        cv2.putText(img , f'FACES : {len(face)} ' , (20,70) , cv2.FONT_HERSHEY_COMPLEX , 1 , (255,255,0) ,1 )
    cv2.imshow("OUTPUT",img)
    if cv2.waitKey(1) & 0xff == ord('q'):
        break
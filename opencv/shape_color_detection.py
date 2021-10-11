import cv2 as cv
import numpy as np

image = cv.imread('A1.png')
# _, image = cv.threshold(image, 70, 255, cv.THRESH_TOZERO)
# print(image.shape)

l_b_r = np.array([0, 10, 0], np.uint8)
u_b_r = np.array([255, 70, 255], np.uint8)
l_b_o = np.array([80, 140, 250], np.uint8)
u_b_o = np.array([130, 190, 255], np.uint8)
l_b_y = np.array([65, 200, 220], np.uint8)
u_b_y = np.array([90, 235, 245], np.uint8)
l_b_g = np.array([110, 150, 25], np.uint8)
u_b_g = np.array([175, 210, 75], np.uint8)
l_b_b = np.array([0, 0, 0], np.uint8)
u_b_b = np.array([255, 255, 25], np.uint8)
b = [[l_b_r, u_b_r], [l_b_o, u_b_o], [l_b_y, u_b_y], [l_b_g, u_b_g], [l_b_b, u_b_b]]
color = ['Red', 'Orange', 'Yellow', 'Green', 'Blue']
# print(l_b_b.shape)
# img = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
# ret, thresh = cv.threshold(img, 70, 255, cv.THRESH_TOZERO)
# contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_NONE)
# print(len(contours))
# cv.drawContours(image, contours, -1, (255, 255, 225), 1)

img = cv.GaussianBlur(image, (5, 5), 0)

for i in range(len(b)):
    j, k = b[i]
    mask = cv.inRange(img, j, k)
    res = cv.bitwise_and(image, image, mask=mask)
    ret, res1 = cv.threshold(res, 70, 255, cv.THRESH_TOZERO)
    res = cv.cvtColor(res, cv.COLOR_BGR2GRAY)
    res = cv.GaussianBlur(res, (5, 5), 0)
    _, thresh = cv.threshold(res, 70, 255, cv.THRESH_BINARY)
    contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_NONE)

    for con in contours:
        poly_approx = cv.approxPolyDP(con, 0.01 * cv.arcLength(con, True), True)
        cv.drawContours(res1, poly_approx, 0, (255, 255, 225), 1)
        x = poly_approx.ravel()[0]
        y = poly_approx.ravel()[1] - 10

        if len(poly_approx) == 3:
            cv.putText(res1, 'Triangle', (x,y), cv.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 225), 1)
        elif len(poly_approx) == 4:
            cv.putText(res1, 'Quad', (x,y), cv.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 225), 1)
        elif len(poly_approx) == 5:
            cv.putText(res1, 'Pentagon', (x,y), cv.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 225), 1)
        else:
            cv.putText(res1, 'Circle', (x,y), cv.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 225), 1)
    title = color[i]
    cv.imshow(title, res1)
    # cv.drawContours(img, contours, -1, (255, 255, 225), 1)
    cv.imshow('image', image)
    cv.waitKey(0)
    cv.destroyAllWindows()

# mask = cv.inRange(img, l_b_r, u_b_r)
# cv.imshow('mask', mask)
# res = cv.bitwise_and(image, image, mask=mask)
# ret, res1 = cv.threshold(res, 70, 255, cv.THRESH_TOZERO)
# cv.imshow('res', res1)
# res = cv.cvtColor(res, cv.COLOR_BGR2GRAY)
# res = cv.GaussianBlur(res, (5,5), 0)
# _, thresh = cv.threshold(res, 70, 255, cv.THRESH_BINARY)
# contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_NONE)
# cv.drawContours(res, contours, -1, (255, 255, 225), 1)
# cv.imshow('image', image)
# cv.imshow('thresh', thresh)
# cv.imshow('res', res)

# cv.waitKey(0)
# cv.destroyAllWindows(
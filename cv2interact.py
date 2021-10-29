import cv2
import numpy as np

canny = rho = threshold = minLen = maxGap = None


def draw():
    lines = cv2.HoughLinesP(canny, rho, np.pi / 180,
                            threshold, None, minLen, maxGap)
    dst = cv2.cvtColor(canny, cv2.COLOR_GRAY2BGR)
    for l in lines[0]:
        x1, y1, x2, y2 = l
        cv2.line(dst, (x1, y1), (x2, y2), (0, 0, 255), 1)
    cv2.imshow('demo', dst)


def onRho(v):
    global rho
    rho = v
    draw()


def onThreshold(v):
    global threshold
    threshold = v
    draw()


def onMinLen(v):
    global minLen
    minLen = v
    draw()


def onMaxGap(v):
    global maxGap
    maxGap = v
    draw()


def main():
    global canny, rho, threshold, minLen, maxGap

    im = cv2.imread('doc1.jpg')
    h, w, _ = im.shape
    min_w = 200
    scale = w * 1. / min_w
    h_proc = int(h * 1. / scale)
    w_proc = int(w * 1. / scale)

    im_dis = cv2.resize(im, (w_proc, h_proc))
    gray = cv2.cvtColor(im_dis, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (3, 3), 0)

    high_thres = cv2.threshold(
        gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)[0]
    low_thres = high_thres * 0.5
    canny = cv2.Canny(gray, low_thres, high_thres)

    rho, threshold, minLen, maxGap = 1, w_proc / 3, w_proc / 3, 20

    cv2.namedWindow('demo', cv2.WINDOW_NORMAL)
    cv2.createTrackbar('rho', 'demo', rho, 5, onRho)
    cv2.createTrackbar('threshold', 'demo', threshold, w_proc, onThreshold)
    cv2.createTrackbar('minLen', 'demo', minLen, w_proc, onMinLen)
    cv2.createTrackbar('maxGap', 'demo', maxGap, 50, onMaxGap)

    draw()
    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main()
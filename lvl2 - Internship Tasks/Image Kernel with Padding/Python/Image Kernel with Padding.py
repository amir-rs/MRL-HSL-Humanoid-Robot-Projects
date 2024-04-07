import cv2
import numpy as np

def reflect(M, x):
    if x < 0:
        return -x - 1
    if x >= M:
        return 2*M - x - 1
    return x

def circular(M, x):
    if x < 0:
        return x + M
    if x >= M:
        return x - M
    return x

def noBorderProcessing(src, dst, kernel):
    for y in range(1, src.shape[0] - 1):
        for x in range(1, src.shape[1] - 1):
            sum = 0.0
            for k in range(-1, 2):
                for j in range(-1, 2):
                    sum += kernel[j+1][k+1] * src[y - j, x - k]
            dst[y, x] = sum

def refletedIndexing(src, dst, kernel):
    for y in range(src.shape[0]):
        for x in range(src.shape[1]):
            sum = 0.0
            for k in range(-1, 2):
                for j in range(-1, 2):
                    x1 = reflect(src.shape[1], x - j)
                    y1 = reflect(src.shape[0], y - k)
                    sum += kernel[j+1][k+1] * src[y1, x1]
            dst[y, x] = sum

def circularIndexing(src, dst, kernel):
    for y in range(src.shape[0]):
        for x in range(src.shape[1]):
            sum = 0.0
            for k in range(-1, 2):
                for j in range(-1, 2):
                    x1 = circular(src.shape[1], x - j)
                    y1 = circular(src.shape[0], y - k)
                    sum += kernel[j+1][k+1] * src[y1, x1]
            dst[y, x] = sum

if __name__ == '__main__':
    src = cv2.imread("Robot.jpg", 0)

    if src is None:
        print("Failed to load image")
        exit()

    kernel = np.array([[0.0625, 0.125, 0.0625],
                       [0.125, 0.25, 0.125],
                       [0.0625, 0.125, 0.0625]])

    dst = np.zeros(src.shape, dtype=np.uint8)
    dst2 = np.zeros(src.shape, dtype=np.uint8)

    circularIndexing(src, dst, kernel)
    cv2.imshow("circularIndexing", dst)

    noBorderProcessing(src, dst2, kernel)
    cv2.imshow("noBorderProcessing", dst2)

    print("rows :", src.shape[0])
    print("cols :", src.shape[1])
    print("rows :", dst.shape[0])
    print("cols :", dst.shape[1])

    cv2.waitKey(0)
    cv2.destroyAllWindows()
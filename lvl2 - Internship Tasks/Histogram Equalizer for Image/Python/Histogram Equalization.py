import cv2
import numpy as np
import matplotlib.pyplot as plt

def PDF(image, histogram):
    for i in range(256):
        histogram[i] = 0

    for y in range(image.shape[0]):
        for x in range(image.shape[1]):
            histogram[int(image[y,x])] += 1

def CDF(histogram, cumulativeHistogram):
    cumulativeHistogram[0] = histogram[0]
    for i in range(1, 256):
        cumulativeHistogram[i] = histogram[i] + cumulativeHistogram[i-1]

def histogramDisplay(histogram, cumulativeHistogram):
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))
    ax1.bar(range(len(histogram)), histogram)
    ax1.set_title("PDF Histogram")
    ax2.bar(range(len(cumulativeHistogram)), cumulativeHistogram)
    ax2.set_title("CDF Histogram")
    plt.show()

if __name__ == '__main__':
    image = cv2.imread("Robot.jpg", 0)
    histogram = np.zeros(256, np.int32)
    PDF(image, histogram)
    size = image.shape[0] * image.shape[1]
    alpha = 255.0/size
    PRk = np.zeros(256, np.float32)
    for i in range(256):
        PRk[i] = float(histogram[i]) / size
    cumulativeHistogram = np.zeros(256, np.int32)
    CDF(histogram, cumulativeHistogram)
    Sk = np.zeros(256, np.int32)
    for i in range(256):
        Sk[i] = int(float(cumulativeHistogram[i]) * alpha)
    PSk = np.zeros(256, np.float32)
    for i in range(256):
        PSk[Sk[i]] += PRk[i]
    finalValues = np.zeros(256, np.int32)
    for i in range(256):
        finalValues[i] = int(PSk[i]*255)
    finalImage = np.copy(image)
    for y in range(image.shape[0]):
        for x in range(image.shape[1]):
            finalImage[y,x] = np.uint8(Sk[image[y,x]])
    cv2.namedWindow("Original Image")
    cv2.imshow("Original Image", image)
    cv2.namedWindow("Equalized Image")
    cv2.imshow("Equalized Image", finalImage)
    cv2.imwrite("EqualizedImage.jpg", finalImage)
    histogramDisplay(histogram, cumulativeHistogram)
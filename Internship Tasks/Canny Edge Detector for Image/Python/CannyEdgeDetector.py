import cv2
import numpy as np
import math

class Canny:
    def __init__(self, filename):
        self.sourceImage = cv2.imread(filename, 0)
        grayscaled = self.sourceImage.copy()
        gFiltered = self.gaussianBlur(grayscaled)
        sFiltered = self.sobel(gFiltered)
        non = self.nonMaxSupp(sFiltered)
        threshold = self.thresholding(non)

        cv2.namedWindow("GrayScaled")
        cv2.namedWindow("Gaussian Blur")
        cv2.namedWindow("Sobel Filtered")
        cv2.namedWindow("Edge Thinning")
        cv2.namedWindow("Threshold sourceImage")

        cv2.imshow("GrayScaled", grayscaled)
        cv2.imshow("Gaussian Blur", gFiltered)
        cv2.imshow("Sobel Filtered", sFiltered)
        cv2.imshow("Edge Thinning", non)
        cv2.imshow("Threshold sourceImage", threshold)

        cv2.waitKey(0)
        cv2.destroyAllWindows()

    def gaussianBlur(self, grayscaled):
        Gaussiankernel = np.zeros((3, 3), np.float32)
        sigma = 3
        size = 3
        sum_g = 0

        for i in range(3):
            for j in range(3):
                Gaussiankernel[i, j] = (
                    1 / (math.pi) * pow(sigma, 2)
                    - ((pow(i, 2) + pow(j, 2))) / (2 * pow(sigma, 2))
                )
                sum_g += Gaussiankernel[i, j]

        blurImage = np.zeros(
            (
                self.sourceImage.shape[0] - size + 1,
                self.sourceImage.shape[1] - size + 1,
            ),
            dtype=np.uint8,
        )

        dx = size // 2
        dy = size // 2
        sumIndex = 0

        for i in range(blurImage.shape[0]):
            for j in range(blurImage.shape[1]):
                sumIndex = 0
                for k in range(size):
                    for l in range(size):
                        x = j - dx + l
                        y = i - dy + k

                        if (
                            x >= 0
                            and x < grayscaled.shape[1]
                            and y >= 0
                            and y < grayscaled.shape[0]
                        ):
                            sumIndex += (
                                Gaussiankernel[k, l]
                                * grayscaled[y, x]
                                / sum_g
                            )
                blurImage[i, j] = np.uint8(sumIndex)
        return blurImage

    def sobel(self, gFiltered):
        size = 1

        xFilter = np.array(
            [[-1.0, 0, 1.0], [-2.0, 0, 2.0], [-1.0, 0, 1.0]], dtype=np.float32
        )
        yFilter = np.array(
            [[-1.0, -2.0, -1.0], [0, 0, 0], [1.0, 2.0, 1.0]], dtype=np.float32
        )

        filteredImg = np.zeros(
            gFiltered.shape, dtype=np.uint8
        )
        self.angles = np.zeros(
            gFiltered.shape, dtype=np.float32
        )

        for i in range(size, gFiltered.shape[0] - size):
            for j in range(size, gFiltered.shape[1] - size):
                sumx = 0
                sumy = 0

                for x in range(-size, size + 1):
                    for y in range(-size, size + 1):
                        sumx += (
                            xFilter[x + size, y + size]
                            * gFiltered[i + x, j + y]
                        )
                        sumy += (
                            yFilter[x + size, y + size]
                            * gFiltered[i + x, j + y]
                        )

                sumxsq = sumx * sumx
                sumysq = sumy * sumy

                sq2 = math.sqrt(sumxsq + sumysq)

                if sq2 > 255:
                    sq2 = 255

                filteredImg[i, j] = np.uint8(sq2)

                self.angles[i, j] = math.atan2(sumy, sumx)
        return filteredImg

    def nonMaxSupp(self, sFiltered):
        nonMaxSupped = sFiltered.copy()

        for i in range(1, sFiltered.shape[0] - 1):
            for j in range(1, sFiltered.shape[1] - 1):
                tangent = self.angles[i, j]

                nonMaxSupped[i - 1, j - 1] = sFiltered[i, j]

                # Horizontal Edge
                if (
                    (-22.5 < tangent <= 22.5)
                    or (157.5 < tangent <= -157.5)
                ):
                    if (
                        (sFiltered[i, j] < sFiltered[i, j + 1])
                        or (sFiltered[i, j] < sFiltered[i, j - 1])
                    ):
                        nonMaxSupped[i - 1, j - 1] = 0

                # Vertical Edge
                if (
                    (-112.5 < tangent <= -67.5)
                    or (67.5 < tangent <= 112.5)
                ):
                    if (
                        (sFiltered[i, j] < sFiltered[i + 1, j])
                        or (sFiltered[i, j] < sFiltered[i - 1, j])
                    ):
                        nonMaxSupped[i - 1, j - 1] = 0

                # -45 Degree Edge
                if (
                    (-67.5 < tangent <= -22.5)
                    or (112.5 < tangent <= 157.5)
                ):
                    if (
                        (sFiltered[i, j] < sFiltered[i - 1, j + 1])
                        or (sFiltered[i, j] < sFiltered[i + 1, j - 1])
                    ):
                        nonMaxSupped[i - 1, j - 1] = 0

                # 45 Degree Edge
                if (
                    (-157.5 < tangent <= -112.5)
                    or (22.5 < tangent <= 67.5)
                ):
                    if (
                        (sFiltered[i, j] < sFiltered[i + 1, j + 1])
                        or (sFiltered[i, j] < sFiltered[i - 1, j - 1])
                    ):
                        nonMaxSupped[i - 1, j - 1] = 0
        return nonMaxSupped

    def thresholding(self, non):
        thres = non.copy()

        threshold = 65
        for i in range(non.shape[0]):
            for j in range(non.shape[1]):
                if thres[i, j] > threshold:
                    thres[i, j] = 255
                else:
                    thres[i, j] = 10

        cv2.imwrite("single_threshold.png", thres)

        return thres


filePath = "Robot.jpg"  # Filepath of input image 
test = Canny(filePath)

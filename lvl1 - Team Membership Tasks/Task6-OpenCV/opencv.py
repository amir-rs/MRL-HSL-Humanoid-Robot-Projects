import cv2

image = None

cv2.namedWindow("Display window")

cap = cv2.VideoCapture(0)

if not cap.isOpened():

print("cannot open camera")

while True:

ret, image = cap.read()

cv2.imshow("Display window", image)

cv2.waitKey(25)

cap.release()

cv2.destroyAllWindows()

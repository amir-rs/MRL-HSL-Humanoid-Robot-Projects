import cv2


def on_trackbar(val):
    print(val)


g_slider_min = 0
g_slider_max = 255

cap = cv2.VideoCapture(0)
if not cap.isOpened():
    exit()

cv2.namedWindow("ThreshHold")
cv2.createTrackbar("TrackbarName", "ThreshHold", g_slider_min, g_slider_max, on_trackbar)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    edges = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    edges = cv2.GaussianBlur(edges, (7, 7), 1.5, 1.5)
    edges = cv2.Canny(edges, g_slider_min, 30, 3)

    cv2.imshow("ThreshHold", edges)
    if cv2.waitKey(30) >= 0:
        break

cap.release()
cv2.destroyAllWindows()

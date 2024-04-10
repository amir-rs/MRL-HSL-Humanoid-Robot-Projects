import json
import os
from fnmatch import fnmatch
import numpy as np
import cv2
import math

destPath = "/media/rider/New Volume/Arshia/Logs-2019-RoboCup/Amir/2019-06-01-13-22/file.txt"

def coord(x, y):
    """Convert world coordinates to pixel coordinates."""
    return int(450 + 170 * x), int(300 - 170 * y)

def drawField(x, y, angle):
    greenField = np.full((600, 900, 3), 127, np.uint8)
    greenField[:] = (5, 144, 51)
    center_coordinates = (450, 300)
    color = (0, 0, 0)
    thickness = 2

    cv2.circle(greenField, center_coordinates, 75, color, thickness)
    cv2.line(greenField, (450, 0), (450, 600), color, thickness)

    angle = math.radians(angle)
    x2 = x + 50 * math.cos(angle)
    y2 = y + 50 * math.sin(angle)

    cv2.line(greenField, coord(x, y), coord(x2, y2), color, thickness)
    cv2.circle(greenField, coord(x2, y2), 10, color, -1)
    cv2.rectangle(greenField, (0, 0), (900, 600), (0, 0, 0), 15)
    cv2.imshow('Field', greenField)
    cv2.waitKey(0)
    cv2.destroyWindow('Field')

def jsonToJPG(path):
    path = path.strip('.json')
    path = path + ".jpg"
    return path

def showImage(path, destPath, x_cor, y_cor, radius, ballDetected):
    img = cv2.imread(path)
    if ballDetected:
        center_coordinates = (int(x_cor * 2), int(y_cor * 2))
        color = (0, 0, 255)
        thickness = 2
        cv2.circle(img, center_coordinates, int(radius * 2), color, thickness)
    cv2.imshow(path, img)
    key = cv2.waitKey(0)

    if key == 27:  # Press 'ESC' to exit
        cv2.destroyAllWindows()
        exit()

    if key == 102 or key == 70:  # Press 'F' to save
        print(path + " added successfully")
        with open(destPath, "a") as file1:
            file1.write(path + "\n")
        cv2.destroyAllWindows()

    if key == 106 or key == 74:  # Press 'J' to skip
        print(path + " dismissed")
        cv2.destroyAllWindows()

def getData(root, shouldShowField):
    for path, _, files in os.walk(root):
        for name in files:
            if fnmatch(name, "*.json"):
                pathJson = os.path.join(path, name)
                jsonSize = os.path.getsize(pathJson)
                if 0 < jsonSize < 300:
                    with open(pathJson) as json_file:
                        data = json.load(json_file)
                        detected = data["Ball"]["detected"]
                        x_corBall = int(data["Ball"]["x"])
                        y_corBall = int(data["Ball"]["y"])
                        radius = int(data["Ball"]["r"])
                        x_corRobotPose = float(data["RobotPose"]["x"])
                        y_corRobotPose = float(data["RobotPose"]["y"])
                        angleRobotPose = float(data["RobotPose"]["angle"])

                        jpgFiles = jsonToJPG(os.path.join(path, name))
                        showImage(jpgFiles, destPath, x_corBall, y_corBall, radius, detected)
                        key = cv2.waitKey(0)

                        if shouldShowField:
                            drawField(x_corRobotPose, y_corRobotPose, angleRobotPose)

path = "/media/rider/New Volume/Arshia/Logs-2019-RoboCup/Amir/2019-06-01-13-22"
shouldShowFieldState = False

getData(path, shouldShowFieldState)

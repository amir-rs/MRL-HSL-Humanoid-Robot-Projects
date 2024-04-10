#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int meter2Pixel = 80; // Conversion factor from meters to pixels

// Field dimensions in meters
int fieldLength = 9, fieldWidth = 6, goalDepth = 0.6, goalWidth = 2.6, goalHeight = 1.2;
int goalAreaLength = 1, goalAreaWidth = 3, penaltyMarkDistance = 1.5, centerCircleDiameter = 1.5;
int borderStripWidth = 1, penaltyAreaLength = 2, penaltyAreaWidth = 5;

// Derived dimensions in pixels
int windowLength, windowWidth, radius, penaltyRadius, robotSize;

void initialize() {
   // Convert dimensions from meters to pixels
   fieldLength *= meter2Pixel;
   fieldWidth *= meter2Pixel;
   goalDepth *= meter2Pixel;
   goalWidth *= meter2Pixel;
   goalHeight *= meter2Pixel;
   goalAreaLength *= meter2Pixel;
   goalAreaWidth *= meter2Pixel;
   penaltyMarkDistance *= meter2Pixel;
   centerCircleDiameter *= meter2Pixel;
   borderStripWidth *= meter2Pixel;
   penaltyAreaLength *= meter2Pixel;
   penaltyAreaWidth *= meter2Pixel;

   windowWidth = fieldWidth + 2 * borderStripWidth;
   windowLength = fieldLength + 2 * borderStripWidth;
   radius = centerCircleDiameter / 2;
   penaltyRadius = 0.075 * meter2Pixel;
   robotSize = 0.27 * meter2Pixel;
}

void drawField(Mat& Ground) {
   // Draw the field boundaries
   Point playgroundLeftUp(borderStripWidth, borderStripWidth);
   Point playgroundRightUp(borderStripWidth + fieldLength, borderStripWidth);
   Point playgroundRightDown(borderStripWidth + fieldLength, borderStripWidth + fieldWidth);
   Point playgroundLeftDown(borderStripWidth, borderStripWidth + fieldWidth);
   line(Ground, playgroundLeftUp, playgroundLeftDown, Scalar(255, 255, 255), 2, 8, 0);
   line(Ground, playgroundRightUp, playgroundRightDown, Scalar(255, 255, 255), 2, 8, 0);
   line(Ground, playgroundRightDown, playgroundLeftDown, Scalar(255, 255, 255), 2, 8, 0);
   line(Ground, playgroundLeftUp, playgroundRightUp, Scalar(255, 255, 255), 2, 8, 0);

   // Draw the center line
   Point centerLineStart(borderStripWidth + fieldLength / 2, borderStripWidth);
   Point centerLineEnd(borderStripWidth + fieldLength / 2, borderStripWidth + fieldWidth);
   line(Ground, centerLineStart, centerLineEnd, Scalar(255, 255, 255), 2, 8, 0);

   // Draw the center circle
   Point centerCircle(borderStripWidth + fieldLength / 2, borderStripWidth + fieldWidth / 2);
   circle(Ground, centerCircle, radius, Scalar(255, 255, 255), 2, 8, 0);
   circle(Ground, centerCircle, penaltyRadius, Scalar(255, 255, 255), -1, 8, 0);

   // Draw the penalty marks
   Point penaltyMarkLeft(borderStripWidth + penaltyMarkDistance, borderStripWidth + fieldWidth / 2);
   Point penaltyMarkRight(borderStripWidth + fieldLength - penaltyMarkDistance, borderStripWidth + fieldWidth / 2);
   circle(Ground, penaltyMarkLeft, penaltyRadius, Scalar(255, 255, 255), -1, 8, 0);
   circle(Ground, penaltyMarkRight, penaltyRadius, Scalar(255, 255, 255), -1, 8, 0);

   // Draw the penalty areas
   Point penaltyAreaUpLeft(borderStripWidth, borderStripWidth + (fieldWidth / 2 - penaltyAreaWidth / 2));
   Point penaltyAreaUpRight(borderStripWidth + penaltyAreaLength, borderStripWidth + (fieldWidth / 2 - penaltyAreaWidth / 2));
   line(Ground, penaltyAreaUpLeft, penaltyAreaUpRight, Scalar(255, 255, 255), 2, 8, 0);

   Point penaltyAreaDownLeft(borderStripWidth, borderStripWidth + (fieldWidth / 2 + penaltyAreaWidth / 2));
   Point penaltyAreaDownRight(borderStripWidth + penaltyAreaLength, borderStripWidth + (fieldWidth / 2 + penaltyAreaWidth / 2));
   line(Ground, penaltyAreaDownLeft, penaltyAreaDownRight, Scalar(255, 255, 255), 2, 8, 0);

   Point penaltyAreaRightUp(borderStripWidth + penaltyAreaLength, borderStripWidth + (fieldWidth / 2 - penaltyAreaWidth / 2));
   Point penaltyAreaRightDown(borderStripWidth + penaltyAreaLength, borderStripWidth + (fieldWidth / 2 + penaltyAreaWidth / 2));
   line(Ground, penaltyAreaRightUp, penaltyAreaRightDown, Scalar(255, 255, 255), 2, 8, 0);

   Point penaltyAreaRightDownCorner(borderStripWidth + fieldLength - penaltyAreaLength, borderStripWidth + (fieldWidth / 2 - penaltyAreaWidth / 2));
   Point penaltyAreaRightUpCorner(borderStripWidth + fieldLength - penaltyAreaLength, borderStripWidth + (fieldWidth / 2 + penaltyAreaWidth / 2));
   line(Ground, penaltyAreaRightDownCorner, penaltyAreaRightUpCorner, Scalar(255, 255, 255), 2, 8, 0);

   // Draw the goal areas
   Point goalAreaUpLeft(borderStripWidth, borderStripWidth + (fieldWidth / 2 - goalAreaWidth / 2));
   Point goalAreaUpRight(borderStripWidth + goalAreaLength, borderStripWidth + (fieldWidth / 2 - goalAreaWidth / 2));
   line(Ground, goalAreaUpLeft, goalAreaUpRight, Scalar(255, 255, 255), 2, 8, 0);

   Point goalAreaDownLeft(borderStripWidth, borderStripWidth + (fieldWidth / 2 + goalAreaWidth / 2));
   Point goalAreaDownRight(borderStripWidth + goalAreaLength, borderStripWidth + (fieldWidth / 2 + goalAreaWidth / 2));
   line(Ground, goalAreaDownLeft, goalAreaDownRight, Scalar(255, 255, 255), 2, 8, 0);

   Point goalAreaRightUp(borderStripWidth + goalAreaLength, borderStripWidth + (fieldWidth / 2 - goalAreaWidth / 2));
   Point goalAreaRightDown(borderStripWidth + goalAreaLength, borderStripWidth + (fieldWidth / 2 + goalAreaWidth / 2));
   line(Ground, goalAreaRightUp, goalAreaRightDown, Scalar(255, 255, 255), 2, 8, 0);

   Point goalAreaRightDownCorner(borderStripWidth + fieldLength - goalAreaLength, borderStripWidth + (fieldWidth / 2 - goalAreaWidth / 2));
   Point goalAreaRightUpCorner(borderStripWidth + fieldLength - goalAreaLength, borderStripWidth + (fieldWidth / 2 + goalAreaWidth / 2));
   line(Ground, goalAreaRightDownCorner, goalAreaRightUpCorner, Scalar(255, 255, 255), 2, 8, 0);

   // Draw the goals
   Point goalLeftDepth(borderStripWidth - goalDepth, borderStripWidth + fieldWidth / 2 - goalWidth / 2);
   Point goalLeftHeight(borderStripWidth - goalDepth, borderStripWidth + fieldWidth / 2 + goalWidth / 2);
   line(Ground, goalLeftDepth, goalLeftHeight, Scalar(0, 255, 255), 2, 8, 0);

   Point goalLeftUpPost(borderStripWidth - goalDepth, borderStripWidth + fieldWidth / 2 - goalWidth / 2);
   Point goalLeftUpBar(borderStripWidth, borderStripWidth + fieldWidth / 2 - goalWidth / 2);
   line(Ground, goalLeftUpPost, goalLeftUpBar, Scalar(0, 255, 255), 2, 8, 0);

   Point goalLeftDownPost(borderStripWidth - goalDepth, borderStripWidth + fieldWidth / 2 + goalWidth / 2);
   Point goalLeftDownBar(borderStripWidth, borderStripWidth + fieldWidth / 2 + goalWidth / 2);
   line(Ground, goalLeftDownPost, goalLeftDownBar, Scalar(0, 255, 255), 2, 8, 0);

   Point goalRightDepth(borderStripWidth + fieldLength + goalDepth, borderStripWidth + fieldWidth / 2 - goalWidth / 2);
   Point goalRightHeight(borderStripWidth + fieldLength + goalDepth, borderStripWidth + fieldWidth / 2 + goalWidth / 2);
   line(Ground, goalRightDepth, goalRightHeight, Scalar(255, 255, 0), 2, 8, 0);

   Point goalRightUpPost(borderStripWidth + fieldLength + goalDepth, borderStripWidth + fieldWidth / 2 - goalWidth / 2);
   Point goalRightUpBar(borderStripWidth + fieldLength, borderStripWidth + fieldWidth / 2 - goalWidth / 2);
   line(Ground, goalRightUpPost, goalRightUpBar, Scalar(255, 255, 0), 2, 8, 0);

   Point goalRightDownPost(borderStripWidth + fieldLength + goalDepth, borderStripWidth + fieldWidth / 2 + goalWidth / 2);
   Point goalRightDownBar(borderStripWidth + fieldLength, borderStripWidth + fieldWidth / 2 + goalWidth / 2);
   line(Ground, goalRightDownPost, goalRightDownBar, Scalar(255, 255, 0), 2, 8, 0);
}

int main() {
   initialize();

   // Create a window to display the field
   Mat Ground(windowWidth, windowLength, CV_8UC3, Scalar(0, 50, 0));

   drawField(Ground);

   // Display the field and wait for a key press
   imshow("Soccer Field", Ground);
   waitKey(0);
   destroyWindow("Soccer Field");

   return 0;
}

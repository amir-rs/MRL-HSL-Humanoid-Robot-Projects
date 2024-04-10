#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int g_slider_min;
int g_slider_max;

void on_trackbar(int, void*)
{
 cout("%d\n", g_slider);
}

int main()
{
    Mat edges;
    VideoCapture cap = VideoCapture(0);
    if (!cap.isOpened()) return -1;
    g_slider_min = 0;
    g_slider_max = 255;
    namedWindow("ThreshHold", 1);
    createTrackbar("TrackbarName", "ThreshHold", &g_slider_min, g_slider_max, on_trackbar);

    for (;;) {
        Mat frame;
        cap >> frame;
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
        Canny(edges, edges, g_slider_min, 30, 3);
        imshow("ThreshHold", edges);
        if (waitKey(30) >= 0)
        break;
    }
  return 0;
}

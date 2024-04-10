#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

int main() {
   // Create a VideoCapture object to access the camera
   VideoCapture cap(0);  // 0 is the default camera index

   // Check if the camera was opened successfully
   if (!cap.isOpened()) {
       std::cout << "Cannot open camera" << std::endl;
       return -1;
   }

   // Create a window to display the camera feed
   namedWindow("Camera Feed", WINDOW_NORMAL);

   // Loop to capture and display frames
   while (true) {
       // Capture the next frame from the camera
       Mat frame;
       cap >> frame;

       // Check if the frame was captured successfully
       if (frame.empty()) {
           std::cout << "Error capturing frame" << std::endl;
           break;
       }

       // Display the frame in the window
       imshow("Camera Feed", frame);

       // Wait for the user to press 'q' to quit the loop
       if (waitKey(25) == 'q') {
           break;
       }
   }

   // Release the VideoCapture object and close the window
   cap.release();
   destroyAllWindows();

   return 0;
}

<h1 align="center">
  <br>
  <a href="https://github.com/Awrsha/Image-Tresholding"><img src="https://s6.uupload.ir/files/hsl_0dhk.png" alt="HSL" width="200"></a>
  <br>
  Humanoid Soccer Robot 
  <br>
</h1>
<h4 align="center">.:: WebCam Tresholding ::.</h4></b>

<p align="center">
<a href="https://github.com/Awrsha/Webcam-Thresholding"><img src="https://img.shields.io/badge/Version-1.2.1-brightgreen" alt="HSL" width="100"></a>
<a href="https://github.com/Awrsha/Webcam-Thresholding"><img src="https://img.shields.io/badge/Platform-linux--64 -blue" alt="HSL" width="130"></a>
<a href="https://github.com/Awrsha/Webcam-Thresholding"><img src="https://img.shields.io/badge/Platform-windows-cyan" alt="HSL" width="130"></a>
<a href="https://github.com/Awrsha/Webcam-Thresholding/blob/main/LICENSE.md"><img src="https://img.shields.io/badge/LICENSE-GPL3-red" alt="HSL" width="110"></a>
<a href="https://github.com/Awrsha/Webcam-Thresholding/network/members"><img src="https://img.shields.io/badge/Developers-1-lightgrey" alt="HSL" width="100"></a>
</p>
<a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"></a>

# WebCam Thresholding

This is a simple webcam thresholding program written in Python. The program captures frames from the user's webcam in real-time, applies a threshold to each frame, and displays the binary output image on the screen. The program uses NumPy library for image manipulation.

Webcam thresholding is a common technique used in computer vision to perform real-time object detection and tracking. The technique involves capturing frames from a webcam in real-time, applying a threshold to each frame, and displaying the binary output image on the screen. This allows the user to track objects or regions of interest in the video stream.

In this project, we have implemented a simple webcam thresholding program using Python and OpenCV. The program captures frames from the user's webcam in real-time, applies a threshold to each frame using NumPy, and displays the binary output image on the screen using OpenCV. The program is designed to be simple and easy to use, making it a good starting point for anyone interested in learning about webcam thresholding and real-time object detection and tracking.

OpenCV is a powerful library for computer vision that provides many useful functions and tools for image and video processing. It is widely used in industry and academia for a wide range of applications, including object detection, tracking, segmentation, and more. By learning how to use OpenCV, you can gain valuable skills in computer vision and image processing that can be applied to many different fields and industries.
## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Requirements

To run this program, you will need:
- Python 3.x installed on your machine
- NumPy library for Python

## Installation

1. Install Python 3.x from the official website: [https://www.python.org/downloads/ ↗](https://www.python.org/downloads/)
2. Install NumPy library using pip:
   ```
   pip install numpy
   ```
3. Install OpenCv library using pip:
   ```
   pip install opencv-python
   ```

## Usage

1. Clone or download the source code from this repository.
2. Open a terminal or command prompt and navigate to the project directory.
3. Place your input image in the project directory.
4. Open the `image_thresholding.py` file in a text editor and modify the `input_image_filename` variable to match the filename of your input image.
5. Modify the `threshold_value` variable to change the threshold value if desired.
6. Use the following command to run the program:
   `````
   python fileName.py
   ``````
7. The binary image will be saved in the project directory with the filename `output.jpg`.

## How it Works

The program uses OpenCV to capture frames from the user's webcam in real-time. Each frame is loaded as a 3-dimensional NumPy array with dimensions (height, width, channels). The program then applies a threshold to each pixel in the array to generate a new NumPy array of the same shape, where each pixel is either 0 or 255.

The program uses the cv2.threshold() function from OpenCV to apply the threshold. This function takes the input image, a threshold value, and a maximum value, and returns a tuple containing the threshold value and the output image. In this case, the threshold value is specified by the user, and the maximum value is set to 255.

## Contributing

This is an open-source project and contributions are welcome. To contribute, please fork this repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Developers 👨🏻‍💻
<p align="center">
<a href="https://github.com/Awrsha"><img src="https://avatars.githubusercontent.com/u/89135083?v=4" width="100;" alt="Awrsha Parvizi"/><br /><sub><b>.:: Amir M. Parvizi ::.</b></sub></a>
</p>

## System & Hardware 🛠  
<br> <summary><b>⚙️ Things I use to get stuff done</b></summary> <ul> <li><b>OS:</b> Windows 11</li> <li><b>Laptop: </b>TUF Gaming</li> <li><b>Code Editor:</b> Visual Studio Code - The best editor out there.</li> <li><b>To Stay Updated:</b> Medium, Linkedin and Instagram.</li> <br /> ⚛️ Checkout Our VSCode Configrations <a href="">Here</a>. </ul> <p align="center">💙 If you like my projects, Give them ⭐ and Share it with friends!</p></p><p align="center"><img height="27" src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="Github Stats" /></p>

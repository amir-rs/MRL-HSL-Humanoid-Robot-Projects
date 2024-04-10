<h1 align="center">
  <br>
  <a href="https://github.com/Awrsha/Canny-Edge-Detector-for-Image"><img src="https://s6.uupload.ir/files/hsl_0dhk.png" alt="HSL" width="200"></a>
  <br>
  Humanoid Soccer Robot 
  <br>
</h1>

<b><h4 align="center">.:: Canny Edge Detector for Image ::.</h4></b>

<p align="center">
<a href="https://github.com/Awrsha/Canny-Edge-Detector-for-Image"><img src="https://img.shields.io/badge/Version-1.2.1-brightgreen" alt="HSL" width="100"></a>
<a href="https://github.com/Awrsha/Canny-Edge-Detector-for-Image"><img src="https://img.shields.io/badge/Platform-linux--64 -blue" alt="HSL" width="130"></a>
<a href="https://github.com/Awrsha/Canny-Edge-Detector-for-Image"><img src="https://img.shields.io/badge/Platform-windows-cyan" alt="HSL" width="130"></a>
<a href="https://github.com/Awrsha/Canny-Edge-Detector-for-Image/blob/main/LICENSE.md"><img src="https://img.shields.io/badge/LICENSE-MIT-red" alt="HSL" width="110"></a>
<a href="https://github.com/Awrsha/Canny-Edge-Detector-for-Image/network/members"><img src="https://img.shields.io/badge/Developers-1-lightgrey" alt="HSL" width="100"></a>
</p>
<a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"></a>

# Canny Edge Detector for Image

This is a simple implementation of Canny edge detection for images using C++ and Python with NumPy. The Canny edge detector is a popular technique used in edge detection to identify edges in images. The technique works by detecting the changes in intensity in an image and finding regions with high gradient values.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Requirements

To run this program, you will need:
- A C++ compiler (for the C++ implementation)
- Python 3.x installed on your machine (for the Python implementation)
- NumPy library for Python

## Installation

1. Install a C++ compiler on your machine. For Windows, you can use Visual Studio or MinGW. For Mac or Linux, you can use GCC or Clang.
2. Install Python 3.x from the official website: [https://www.python.org/downloads/ ↗](https://www.python.org/downloads/)
3. Install NumPy library using pip:
   ```
   pip install numpy
   ```
4. Install OpenCv library using pip:
   ```
   pip install opencv-python
   ```

## Usage

### C++ Implementation

1. Navigate to the `cpp` directory.
2. Compile the `main.cpp` file using your C++ compiler:
   ```
   g++ main.cpp -o canny
   ```
3. Run the executable file:
   ```
   ./canny
   ```
4. The program will prompt you to enter the filename of the input image.
5. The program will apply the Canny edge detection algorithm to the input image and save the output image in the same directory with the filename `output.jpg`.

### Python Implementation

1. Navigate to the `python` directory.
2. Use the following command to run the program:
   ``````
   python fileName.py
   ``````
3. The program will prompt you to enter the filename of the input image.
4. The program will apply the Canny edge detection algorithm to the input image and display the original and edge-detected images side by side using Matplotlib.

## How it Works

The program loads the input image as a 2-dimensional NumPy array with dimensions `(height, width)`. The program then applies Gaussian smoothing to the input image to reduce noise and remove small details using the NumPy `convolve()` function and a Gaussian kernel.

The program then calculates the gradient of the smoothed image using the Sobel operator. The Sobel operator is a filter used for edge detection that calculates the gradient of an image at each point. The program uses two Sobel kernels to calculate the gradient in the x and y directions.

The program then applies non-maximum suppression to the gradient image to thin the edges and remove false detections. Non-maximum suppression works by selecting the local maximum in the gradient direction and suppressing all other values.

The program then applies hysteresis thresholding to the non-maximum suppressed image to identify the final edges. Hysteresis thresholding works by setting two threshold values, a high and a low threshold. All pixels with a gradient value above the high threshold are considered edges, and all pixels with a gradient value below the low threshold are considered non-edges. Pixels with a gradient value between the high and low threshold are considered edges if they are connected to pixels above the high threshold.

The program then saves the final edge-detected image and displays it using Matplotlib.

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

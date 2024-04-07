<h1 align="center">
  <br>
  <a href="https://github.com/mrl-hsl"><img src="https://s6.uupload.ir/files/hsl_0dhk.png" alt="HSL" width="200"></a>
  <br>
  Humanoid Soccer Robot
  <br>
</h1>

<b><h4 align="center">.:: Histogram Equalizer for Image ::.</h4></b>

https://medium.com/@official.parvizi/histogram-equalization-for-an-image-and-webcam-33f443b8a533

<p align="center">
<a href="https://github.com/Awrsha/Histogram-Equalizer-for-Image"><img src="https://img.shields.io/badge/Version-1.2.1-brightgreen" alt="HSL" width="100"></a>
<a href="https://github.com/Awrsha/Histogram-Equalizer-for-Image"><img src="https://img.shields.io/badge/Platform-linux--64 -blue" alt="HSL" width="130"></a>
<a href="https://github.com/Awrsha/Histogram-Equalizer-for-Image"><img src="https://img.shields.io/badge/Platform-windows-cyan" alt="HSL" width="130"></a>
<a href="https://github.com/Awrsha/Histogram-Equalizer-for-Image/blob/main/LICENSE.md"><img src="https://img.shields.io/badge/LICENSE-GPL3-red" alt="HSL" width="110"></a>
<a href="https://github.com/Awrsha/Histogram-Equalizer-for-Image/network/members"><img src="https://img.shields.io/badge/Developers-1-lightgrey" alt="HSL" width="100"></a>
</p>
<a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"></a>

# Histogram Equalization for Image

This is a simple implementation of histogram equalization for images using Python, NumPy, and Matplotlib. Histogram equalization is a technique used in image processing to adjust the contrast of an image by redistributing the pixel values. The technique works by mapping the original pixel values to new values that are more evenly distributed across the available range of values.

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Requirements

To run this program, you will need:
- Python 3.x installed on your machine
- NumPy library for Python
- Matplotlib library for Python

## Installation

1. Install Python 3.x from the official website: [https://www.python.org/downloads/ ↗](https://www.python.org/downloads/)
2. Install NumPy library using pip:
   ```
   pip install numpy
   ```
3. Install Matplotlib library using pip:
   ```
   pip install matplotlib
   ```
4. Install OpenCV library using pip:
   ```
   pip install opencv-python
   ```

## Usage

1. Clone or download the source code from this repository.
2. Open a terminal or command prompt and navigate to the project directory.
3. Place your input image in the project directory.
4. Open the `histogram_equalization.py` file in a text editor and modify the `input_image_filename` variable to match the filename of your input image.
5. Use the following command to run the program:
   `````
   python fileName.py
   ``````
6. The program will generate a new image with the histogram equalization applied and save it in the project directory with the filename `output.jpg`.
7. The program will also display the original image and the equalized image side by side using Matplotlib.

## How it Works

The program uses NumPy to load the input image as a 2-dimensional NumPy array with dimensions `(height, width)`. The program then calculates the histogram of the input image using the NumPy `histogram()` function. The histogram is a representation of the distribution of pixel values in the image.

The program then applies histogram equalization to the input image by mapping the original pixel values to new values that are more evenly distributed across the available range of values. The mapping function is calculated using the cumulative distribution function (CDF) of the pixel values in the input image. The CDF is calculated using the NumPy `cumsum()` function.

The program then applies the mapping function to each pixel in the input image to generate a new NumPy array of the same shape, where each pixel has a new value that is more evenly distributed across the available range of values.

The program then saves the new array as an image using NumPy and displays the original and equalized images side by side using Matplotlib.

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

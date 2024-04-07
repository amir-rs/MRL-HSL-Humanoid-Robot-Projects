<h1 align="center">
  <br>
  <a href="https://github.com/mrl-hsl"><img src="https://github.com/Awrsha/World-Model/assets/89135083/a77cc83e-8bce-43b5-81e7-d5c584ac6f23" alt="HSL" width="200"></a>
  <br>
  Humanoid Soccer Robot
  <br>
</h1>

<b><h4 align="center">.:: Blurring an image with kernel 3*3 ::.</h4></b>

<p align="center">
<a href="https://github.com/"><img src="https://img.shields.io/badge/Version-1.2.1-brightgreen" alt="HSL" width="100"></a>
<a href="https://github.com/"><img src="https://img.shields.io/badge/Platform-linux--64-blue" alt="HSL" width="130"></a>
<a href="https://github.com/AmirMwhmd/Blur-image-with-kernel/blob/main/LICENSE.md"><img src="https://img.shields.io/badge/LICENSE-GNU-red" alt="HSL" width="110"></a>
<a href="https://github.com/AmirMwhmd/Blur-image-with-kernel/network/members"><img src="https://img.shields.io/badge/Developers-2-lightgrey" alt="HSL" width="100"></a>
</p>

## Languages  
<code>
<img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/python/python-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/vscode/vscode-original-wordmark.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/numpy/numpy-original.svg" width="50" height="50"/><img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/opencv/opencv-original-wordmark.svg" width="50" height="50" /> <img align="center" src="https://github.com/devicons/devicon/blob/v2.15.1/icons/pycharm/pycharm-original.svg" width="50" height="50"/>
</code>

## Requirements

To run this program, you will need:
- Python 3.x installed on your machine
- NumPy library for Python

## Installation

1. Install Python 3.x from the official website: [Python](https://www.python.org/downloads/)
2. Install NumPy library using pip:
   ```
   pip install numpy
   ```

## Usage

1. Clone or download the source code from this repository.
2. Open a terminal or command prompt and navigate to the project directory.
3. Place your input image in the project directory.
4. Open the `image_filtering.py` file in a text editor and modify the `input_image_filename` variable to match the filename of your input image.
5. Modify the `kernel` variable to change the kernel values if desired.
6. Use the following command to run the program:
   ````
   python fileName.py
   ````
7. The output image will be saved in the project directory with the filename `output.jpg`.

# Image Kernels ⚙️
An image kernel is a small matrix used to apply effects like the ones you might find in Photoshop or Gimp, such as blurring, sharpening, outlining or embossing. They're also used in machine learning for 'feature extraction', a technique for determining the most important portions of an image. In this context the process is referred to more generally as "convolution" (see: [convolutional neural networks](https://en.wikipedia.org/wiki/Convolutional_neural_network).)

for apllying 3x3 **blur**.

      [ 0.0625, 0.125, 0.0625
        0.125,  0.25,  0.125 
        0.0625, 0.125, 0.0625 ]
                    
		 
<br /> 
<div>
<img align="center" height="250" width="375" alt="example of kernel" src="https://s6.uupload.ir/files/kernel_ae01.jpg"/>
</div>


<br /><br />

Live Demo 🔗 ([click here](https://setosa.io/ev/image-kernels/))

## UML diagrams 📊

And this will produce a flow chart:

```mermaid
graph LR
A[image]--> B(opencv)
A --> C(Kernel 3*3)
C --> E
B --> E{image with blur filter}
```

# Download OpenCV 📥
Download OpenCV in this site 🔗 ([Download Offline Installers | Source Package Offline Installer | Clone in Terminal](https://opencv.org/releases/))

## Create files and folders 
Create a folder for example **Kernel** after downloading **OpenCv**.

## How to install OpenCV on Ubuntu 📂

OpenCV is a library of computer vision abbreviated as Open Source Computer Vision Library. Open means it is an open-source library with bindings for python, C++, and Java and supports different Operating Systems like Windows and Linux. It is able to use multi-core processing and GPU acceleration for real-time operating tasks. OpenCV library can be used for a wide range of applications, including face recognition and detection, medical image analysis, motion tracking, surveillance video, 3D model extraction, and much more.

In this article, we will describe how to install the OpenCV library on Linux distribution Ubuntu.

You can install OpenCV using two different ways:

1.  Install OpenCV using Ubuntu repository
2.  Install OpenCV through the source

If you want to install the latest stable version of the OpenCV library on your system then, using the source method you can install it. Open the terminal by pressing ‘Ctrl+Alt+t’ and start the installation of OpenCV using the following methods:

## Installing OpenCV from the Ubuntu Repository 

OpenCV library is available in the official Ubuntu repository in Ubuntu. Update the apt cache by using the following command:

   ```sh
   $ sudo apt update
   ```
   * Install OpenCV by running the following command:

   ```sh
   $ sudo apt install libopencv-dev python3-opencv
   ```
   The above command will install all the necessary packages on your system.
   * Verify the installation by importing the `cv2` module and printing the OpenCV version:
```sh
   python3 -c "import cv2; print(cv2.__version__)"
   ```
   
## Installing OpenCV from the Source 
Building the OpenCV library from the source allows you to have the latest available version. It will be optimized for your particular system, and you will have complete control over the build options. This is the recommended way of installing OpenCV.

Perform the following steps to install the latest OpenCV version from the source:
* Install the [build tools](https://linuxize.com/post/how-to-install-gcc-on-ubuntu-20-04/) and dependencies:
 ```sh
$ sudo apt install build-essential cmake git pkg-config libgtk-3-dev \ libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \ libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \ gfortran openexr libatlas-base-dev python3-dev python3-numpy \ libtbb2 libtbb-dev libdc1394-22-dev libopenexr-dev \ libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev
```
* Clone the OpenCV’s and OpenCV contrib repositories:
 ```sh
$ mkdir ~/opencv_build && cd ~/opencv_build
$ git clone https://github.com/opencv/opencv.git
$ git clone https://github.com/opencv/opencv_contrib.git
```
At the time of writing, the default version in the github repositories is version 4.3.0. If you want to install an older version of OpenCV, cd to both `opencv` and `opencv_contrib` directories and run `git checkout <opencv-version>`
* Once the download is complete, create a temporary build directory, and [navigate](https://linuxize.com/post/linux-cd-command/) to it:
 ```sh
$ cd ~/opencv_build/opencv
$ mkdir -p build && cd build
```
Set up the OpenCV build with CMake:
 ```sh
$ cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D INSTALL_C_EXAMPLES=ON \
-D INSTALL_PYTHON_EXAMPLES=ON \
-D OPENCV_GENERATE_PKGCONFIG=ON \
-D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules \
-D BUILD_EXAMPLES=ON ..
```
* Start the compilation process:
```sh
$ make -j8
```
Modify the  `-j`  flag according to your processor. If you do not know the number of cores in your processor, you can find it by typing  `nproc`.

The compilation may take several minutes or more, depending on your system configuration.
* Install OpenCV with:
```sh
$ sudo make install
```
 * To verify the installation, type the following commands and you should see the OpenCV version.
 C++ bindings:
 ```sh
$ pkg-config --modversion opencv4
```
Python bindings:
 ```sh
$ python3 -c "import cv2; print(cv2.__version__)"
```

## If You have Error 🐞
For easily execute the code, it is better to first make sure that the required versions are up-to-date before starting.
run this commands in your **ubuntu terminal** for get necessary package.

1. 
  ```sh
  sudo apt-get install build-essential -y
  ```
 2. 
  ```sh
  sudo apt-get install clang -y
  ```

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

<p align="center">
<img src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="Github Stats" />
</p>

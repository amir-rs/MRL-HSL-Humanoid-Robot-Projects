<h1 align="center">
  <br>
  <a href="https://github.com/"><img src="https://github.com/Awrsha/Tello-Drone-Object-Following/assets/89135083/d5d03b44-eb26-4093-b4dd-1679c6530d1c" alt="KAREN" width="600"></a>
  <b><h4 align="center">.:: RoboCup Log Analysis Tool ::.</h4></b>
</h1>

### Overview

The tool is designed to analyze log data captured during RoboCup matches. It processes JSON log files containing information about robot poses and detected ball positions. The tool extracts this data and displays relevant images with annotated ball positions and robot poses.

### Requirements

- Python 3.x
- OpenCV (`cv2`)
- NumPy (`numpy`)
- Math module

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/mrl-hsl/Scripts.git
    cd Scripts
    ```

2. Install required dependencies:

    ```bash
    pip install opencv-python-headless numpy
    ```

### Usage

The tool includes the following main functions:

- `drawField`: Draws the field and robot poses.
- `jsonToJPG`: Converts JSON files to corresponding JPG images.
- `showImage`: Displays images with annotated ball positions.

To use the tool:

1. Provide the root directory containing RoboCup log files (`path`) and destination file path (`destPath`).

2. Execute the `getData` function, passing the root directory and a boolean indicating whether to display the field with robot poses (`shouldShowFieldState`).

3. Press keys while viewing images:
    - `F`: Saves the current image file path to the destination file.
    - `J`: Skips displaying the current image.
    - `ESC`: Exits the program.

### Contributors

- Arash Rahmani (@arashrahmani)
- Nima Akbarzadeh (@iw4p)

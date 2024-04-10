<h1 align="center">
  <br>
  <a href="https://github.com/mrl-hsl"><img src="https://github.com/Awrsha/World-Model/assets/89135083/a77cc83e-8bce-43b5-81e7-d5c584ac6f23" alt="HSL" width="200"></a>
  <br>
  Humanoid Soccer Robot
  <br>
</h1>

<b><h4 align="center">.:: Angle Sensor Model ::.</h4></b>

# Angle Sensor Model (C++)

This repository provides an advanced implementation of an Angle Sensor Model in C++ without the use of external libraries. The Angle Sensor Model simulates the behavior of an angle sensor, which measures the rotational angle of an object or system. It can be used in various applications such as robotics, control systems, and virtual reality.

## Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Model Details](#model-details)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Angle Sensor Model is a mathematical representation of an angle sensor that provides accurate measurements of the rotational angle. This implementation aims to provide a versatile and efficient framework for simulating angle sensors in C++ without relying on external libraries.

The model takes into account various factors such as noise, resolution, and range limitations, which are common in real-world angle sensors. It allows users to configure the sensor parameters and obtain reliable angle measurements.

## Getting Started

To use this Angle Sensor Model in your C++ project, follow these steps:

1. Clone this repository to your local machine or download the source code.
2. Include the `AngleSensorModel.h` header file in your project.
3. Add the `AngleSensorModel.cpp` source file to your project's compilation.

## Usage

To use the Angle Sensor Model in your application, follow these steps:

1. Create an instance of the `AngleSensorModel` class.
2. Configure the sensor parameters such as noise level, resolution, and measurement range.
3. Call the `measureAngle()` method, passing the actual angle as an argument.
4. The `measureAngle()` method will return the measured angle value, considering the configured sensor parameters.

Refer to the example section for a more detailed demonstration of the usage.

## Model Details

The Angle Sensor Model incorporates the following aspects to simulate the behavior of an angle sensor:

1. Noise: The model introduces random noise into the measured angle, simulating the inherent noise present in real-world sensors. The noise level can be adjusted to reflect the sensor's characteristics.
2. Resolution: The model quantizes the measured angle to the specified resolution, emulating the limited precision of the sensor output.
3. Measurement Range: The model enforces the measurement range of the sensor, ensuring that the measured angle remains within the defined bounds.
4. Error Handling: The model incorporates appropriate error handling mechanisms to handle invalid inputs and maintain the integrity of the sensor measurements.

Users can configure these parameters based on their specific requirements and sensor characteristics.

## Example

Here's an example demonstrating the usage of the Angle Sensor Model implementation:

```cpp
#include "AngleSensorModel.h"
#include <iostream>

int main() {
    // Create an instance of AngleSensorModel
    AngleSensorModel angleSensor;

    // Configure sensor parameters
    angleSensor.setNoiseLevel(0.1); // Set noise level to 0.1 radians
    angleSensor.setResolution(0.01); // Set resolution to 0.01 radians
    angleSensor.setMeasurementRange(-3.14, 3.14); // Set measurement range from -pi to pi

    // Simulate measurement
    double actualAngle = 1.57; // Actual angle in radians
    double measuredAngle = angleSensor.measureAngle(actualAngle);

    // Print the measured angle
    std::cout << "Measured Angle: " << measuredAngle << " radians" << std::endl;

    return 0;
}
```

Make sure to adjust the sensor parameters and provide the appropriate actual angle for your specific application.

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

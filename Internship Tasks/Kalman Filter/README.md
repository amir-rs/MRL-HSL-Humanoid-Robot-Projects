<h1 align="center">
  <br>
  <a href="https://github.com/mrl-hsl"><img src="https://github.com/Awrsha/World-Model/assets/89135083/a77cc83e-8bce-43b5-81e7-d5c584ac6f23" alt="HSL" width="200"></a>
  <br>
  Humanoid Soccer Robot
  <br>
</h1>

<b><h4 align="center">.:: Kalman Filter Implementation ::.</h4></b>

# Kalman Filter Implementation (C++)

This repository provides an implementation of the Kalman Filter algorithm in C++ without the use of external libraries. The Kalman Filter is a widely used recursive mathematical filter that provides an optimal estimate of the state of a system given noisy measurements over time.

## Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Kalman Filter is an algorithm that estimates the state of a system by combining predictions from a mathematical model with measurements from sensors. It is particularly useful when dealing with noisy measurements and uncertain system dynamics.

This implementation provides a basic framework for utilizing the Kalman Filter algorithm in a C++ project. It includes the necessary functions for initializing the filter, performing predictions, incorporating measurements, and obtaining the filtered state estimate.

## Getting Started

To use this implementation in your C++ project, follow these steps:

1. Clone this repository to your local machine or download the source code.
2. Include the `KalmanFilter.h` header file in your project.
3. Add the `KalmanFilter.cpp` source file to your project's compilation.

## Usage

To use the Kalman Filter in your application, follow these steps:

1. Create an instance of the `KalmanFilter` class.
2. Initialize the filter using the `init()` method, providing the initial state, initial covariance matrix, and system dynamics matrices.
3. For each time step:
   - Predict the next state using the `predict()` method, providing the control input (if applicable) and the system dynamics matrices.
   - Incorporate measurements using the `update()` method, providing the measurement vector and the measurement noise covariance matrix.
   - Obtain the filtered state estimate using the `getStateEstimate()` method.

Refer to the example section for a more detailed demonstration of the usage.

## Algorithm

The Kalman Filter algorithm consists of two main steps: prediction and update.

In the prediction step, the filter predicts the current state based on the previous state and the system dynamics. This prediction is performed using the following equations:

- Predicted state estimate: `x_hat = F * x + B * u`
- Predicted covariance estimate: `P = F * P * F^T + Q`

Here, `x_hat` is the predicted state estimate, `x` is the previous state estimate, `F` is the state transition matrix, `B` is the control input matrix (if applicable), `u` is the control input vector (if applicable), `P` is the previous covariance estimate, and `Q` is the process noise covariance matrix.

In the update step, the filter incorporates new measurements and updates the state estimate. This update is performed using the following equations:

- Measurement residual: `y = z - H * x_hat`
- Residual covariance: `S = H * P * H^T + R`
- Kalman gain: `K = P * H^T * S^-1`
- Updated state estimate: `x = x_hat + K * y`
- Updated covariance estimate: `P = (I - K * H) * P`

Here, `z` is the measurement vector, `H` is the measurement matrix, `y` is the measurement residual, `R` is the measurement noise covariance matrix, `S` is the residual covariance, `K` is the Kalman gain, `I` is the identity matrix, `x` is the updated state estimate, and `P` is the updated covariance estimate.

## Example

Here's an example demonstrating the usage of the Kalman Filter implementation:

```cpp
#include "KalmanFilter.h"
#include <iostream>

int main() {
    // Create Kalman Filter instance
    KalmanFilter filter;

    // Initialize the filter
    Eigen::VectorXd x0(2); // Initial state vector
    Eigen::MatrixXd P0(2, 2); // Initial covariance matrix
    Eigen::MatrixXd F(2, 2); // State transition matrix
    Eigen::MatrixXd Q(2, 2); // Process noise covariance matrix
    Eigen::MatrixXd H(1, 2); // Measurement matrix
    Eigen::MatrixXd R(1, 1); // Measurement noise covariance matrix

    // Set values for the matrices
    // ...

    filter.init(x0, P0, F, Q, H, R);

    // Perform prediction and update steps
    Eigen::VectorXd u(1); // Control input vector
    Eigen::VectorXd z(1); // Measurement vector

    for (int i = 0; i < num_iterations; ++i) {
        // Predict
        filter.predict(u);

        // Update
        filter.update(z);

        // Get filtered state estimate
        Eigen::VectorXd state = filter.getStateEstimate();

        // Print the filtered state estimate
        std::cout << "Filtered State: " << state << std::endl;
    }

    return 0;
}
```

Make sure to fill in the appropriate values for the matrices `x0`, `P0`, `F`, `Q`, `H`, and `R` based on your specific application.

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

<h1 align="center">
  <br>
  <a href="https://github.com/mrl-hsl"><img src="https://github.com/Awrsha/World-Model/assets/89135083/a77cc83e-8bce-43b5-81e7-d5c584ac6f23" alt="HSL" width="200"></a>
  <br>
  Humanoid Soccer Robot
  <br>
</h1>

<b><h4 align="center">.:: Convex Hull Implementation ::.</h4></b>

# Convex Hull Implementation (C++)

This repository provides an implementation of the Convex Hull algorithm in C++ without the use of external libraries. The Convex Hull is a fundamental algorithm in computational geometry that finds the smallest convex polygon that contains all the given points in a 2D plane.

## Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Convex Hull algorithm is widely used in various applications such as computer graphics, image processing, pattern recognition, and computational geometry. It is used to find the outer boundary or the convex envelope of a set of points.

This implementation provides a basic framework for utilizing the Convex Hull algorithm in a C++ project. It includes the necessary functions for finding the convex hull of a set of points using the Graham's scan algorithm.

## Getting Started

To use this implementation in your C++ project, follow these steps:

1. Clone this repository to your local machine or download the source code.
2. Include the `ConvexHull.h` header file in your project.
3. Add the `ConvexHull.cpp` source file to your project's compilation.

## Usage

To use the Convex Hull algorithm in your application, follow these steps:

1. Create a vector of 2D points (`std::vector<std::pair<double, double>>`) representing the input points.
2. Create an instance of the `ConvexHull` class.
3. Call the `computeConvexHull()` method, passing the vector of points as an argument.
4. The `computeConvexHull()` method will return a vector of 2D points representing the convex hull.

Refer to the example section for a more detailed demonstration of the usage.

## Algorithm

The Convex Hull algorithm implemented in this repository uses the Graham's scan algorithm. The algorithm follows these steps:

1. Find the point with the lowest y-coordinate (the bottommost point). In case of a tie, choose the leftmost point.
2. Sort the remaining points in counterclockwise order around the lowest point. This can be done using the polar angle with respect to the lowest point.
3. Initialize an empty stack and push the first three points onto the stack.
4. For each remaining point, do the following:
   - While the last two points and the current point make a non-left turn, remove the second-to-last point from the stack.
   - Push the current point onto the stack.
5. The stack now contains the vertices of the convex hull in counterclockwise order.

## Example

Here's an example demonstrating the usage of the Convex Hull implementation:

```cpp
#include "ConvexHull.h"
#include <iostream>

int main() {
    // Create a vector of 2D points
    std::vector<std::pair<double, double>> points = {
        {0.0, 0.0},
        {1.0, 1.0},
        {2.0, 2.0},
        {3.0, 1.0},
        {2.0, 0.0},
        {1.0, 2.0}
    };

    // Create ConvexHull instance
    ConvexHull convexHull;

    // Compute the convex hull
    std::vector<std::pair<double, double>> hull = convexHull.computeConvexHull(points);

    // Print the convex hull vertices
    for (const auto& vertex : hull) {
        std::cout << "(" << vertex.first << ", " << vertex.second << ")" << std::endl;
    }

    return 0;
}
```

Make sure to fill in the appropriate values for the `points` vector based on your specific application.

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

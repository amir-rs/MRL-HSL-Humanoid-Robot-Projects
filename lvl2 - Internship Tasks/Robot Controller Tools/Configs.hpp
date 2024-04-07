#ifndef CONFIGS_HPP
#define CONFIGS_HPP
//-- Default CPP Libraries
#include <cmath>
#include <string> 
#include <vector>
#include <iostream>
//-- Configure According to OS Type by Checking Macros
//- 1 Stands for Windows
//- 2 Stands for Linux (or Unix Based Like MacOS)
//- 3 Stands for MacOS
//- 4 Stands for None-Supported Operating Systems (Like FreeBSD or Android)
extern int16_t osType;
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #define DEFAULT_OS 1
    #ifndef _WCTYPE_H
        #include <wctype.h>
    #endif
    #include <windows.h>
#elif defined(unix) || defined(__unix) || defined(__unix__)
    #define DEFAULT_OS 2
    #ifndef _X11_XLIB_H_
        #include <X11/Xlib.h>
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #define DEFAULT_OS 3
#else
    #define DEFAULT_OS 4
#endif
//-- Needed Libraries to Display Graphical Windows
#ifndef OPENCV_HIGHGUI_HPP
    #include <opencv4/opencv2/highgui.hpp>
#endif
#ifndef OPENCV_IMGPROC_HPP
    #include <opencv4/opencv2/imgproc.hpp>
#endif

//-- User Defined Names for Robots
enum Robots {
    Arash, Aref, Parizad, Soheil
};


#endif // CONFIGS_HPP
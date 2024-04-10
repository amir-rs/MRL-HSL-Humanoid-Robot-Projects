#ifndef SENSORS_HPP
#define SENSORS_HPP

#include "Configs.hpp"


//-- Sensors class
class Sensors{

    private:
        double meanTheta;
        double stdDevTheta;
        double meanLocate;
        double stdDevLocate;
        double noiseTheta;
        double noiseX;
        double noiseY;
        double measureTheta;
        double measureX;
        double measureY;
    public:
        Sensors();
        void measureUpdate(double sysX, double sysY, double sysTheta);
        double NoiseGet();
        void setSensor(double meanTheta , double stdTheta, double meanLocate, double stdLocate);
        double getTheta();
        double getX();
        double getY();
        double getStdlocate();
        double getStdTheta();
    };

#endif // FIELD_HPP

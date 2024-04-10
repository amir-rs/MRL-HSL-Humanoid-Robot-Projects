#include "Sensors.hpp"


Sensors::Sensors()
{
}
// -- Set mean And standard deviation
void Sensors::setSensor(double mT , double stdT, double mL, double stdL)
{
    meanTheta = mT;
    stdDevTheta = stdT;
    meanLocate = mL ;
    stdDevLocate = stdL;

}
// --  Make Noise for Theta
void Sensors::measureUpdate(double sysX, double sysY, double sysTheta)
{
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine angle(seed); 
    default_random_engine locate(seed);
    normal_distribution<double> distNtheta(meanTheta, stdDevTheta); 
    normal_distribution<double> distNlocate(meanLocate, stdDevLocate);
    noiseTheta = distNtheta(angle);
    noiseX = distNlocate(locate);
    noiseY = distNlocate(locate);
    measureTheta = sysTheta + noiseTheta;
    measureX = sysX + noiseX;
    measureY = sysY + noiseY;   
}
// -- return measure Theta from Sensor
double Sensors::getTheta()
{
    return measureTheta;
}
// -- return measure X from Sensor
double Sensors::getX()
{
    return measureX
}
// -- return measure Y from Sensor
double Sensors::getY()
{
    return measureY;
}
// -- return standard deviation
double Sensors::getStdlocate()
{
    return stdDevLocate;
}

double Sensors::getStdTheta()
{
    return stdDevTheta;
}
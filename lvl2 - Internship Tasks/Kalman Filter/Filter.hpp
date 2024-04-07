#ifndef FILTER.HPP
#define FILTER.HPP

#include "Configs.hpp"


class Filter
{
    private:
        double GainTheta;
        double GainLocate;
        double measureTheta;
        double measureX;
        double measureY;
        double estimateX;
        double estimateY;
        double estimateTheta;
        double estimateError;
        double measureError;
    public:
        Filter(/* args */);
        ~Filter();
        void initialize(double x, double y, double theta);
        void estimate();
        void predicate();
        void kalmanGain();
};

#endif //FILTER.HPP
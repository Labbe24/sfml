#include "configuration.hpp"

Configuration::Configuration()
{
}

Configuration::Configuration(float sortingSpeed, SortingAlgorithm sortingAlgo)
{
    sortingSpeed_ = sortingSpeed;
    sortingAlgo_ = sortingAlgo;
}

void Configuration::setSpeed(const float speed)
{
    sortingSpeed_ = speed;
}

float Configuration::getSpeed() const
{
    return sortingSpeed_;
}
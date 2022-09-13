#include "configuration.hpp"

Configuration::Configuration()
{
}

Configuration::Configuration(float sortingSpeed, SortingAlgorithm sortingAlgo)
{
    sortingSpeed_ = sortingSpeed;
    sortingAlgo_ = sortingAlgo;
}

float Configuration::getSpeed() const
{
    return sortingSpeed_;
}
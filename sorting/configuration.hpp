#ifndef CONFIG_H
#define CONFIG_H

enum SortingAlgorithm
{
    Bubble
};

class Configuration
{
public:
    Configuration();
    Configuration(float sortingSpeed, SortingAlgorithm sortingAlgo);
    float getSpeed() const;

private:
    float sortingSpeed_;
    SortingAlgorithm sortingAlgo_;
};

#endif
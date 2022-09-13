#ifndef CONFIG_H
#define CONFIG_H

enum SortingAlgorithm
{
    BubbleSort
};

class Config
{
public:
    Config(float sortingSpeed, SortingAlgorithm sortingAlgo);

private:
    float sortingSpeed_;
    SortingAlgorithm sortingAlgo_;
};

#endif
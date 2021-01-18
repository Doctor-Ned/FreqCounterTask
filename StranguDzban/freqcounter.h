#pragma once
#include <map>
#include <string>
#include <fstream>

template <typename T>
class freqcounter
{
public:
    void addData(T t);
    void create(std::string filePath);
private:
    std::map<T, unsigned int> occurrenceCount{};
};

template <typename T>
void freqcounter<T>::addData(T t)
{
    auto it = occurrenceCount.find(t);
    if (it != occurrenceCount.end())
    {
        ++it->second;
    } else
    {
        occurrenceCount.emplace(t, 1U);
    }
}

template<typename T>
void freqcounter<T>::create(std::string filePath)
{
    std::ofstream file(filePath, std::ios::trunc);
    for (auto& pair : occurrenceCount)
    {
        file << pair.first << ',' << pair.second << std::endl;
    }
}

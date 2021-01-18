#pragma once

#include "freqcounter.h"

#include <string>
#include <locale>
#include <fstream>
#include <sstream>

inline freqcounter<char> countCharacters(std::string filePath)
{
    freqcounter<char> counter;
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw std::exception("Unable to open file!");
    }
    char currChar;
    while (file.good())
    {
        file.get(currChar);
        counter.addData(currChar);
    }
    return counter;
}

inline std::string clearWord(const std::string& word)
{
    std::stringstream ss;
    const std::locale LOCALE_PL("pl_PL");
    for (char character : word)
    {
        if (isalpha(character, LOCALE_PL))
        {
            ss << character;
        }
    }
    return ss.str();
}

inline freqcounter<std::string> countWords(std::string filePath)
{
    freqcounter<std::string> counter;
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw std::exception("Unable to open file!");
    }
    std::string currWord;
    while (file >> currWord)
    {
        std::string cleanWord = clearWord(currWord);
        if (!cleanWord.empty())
        {
            counter.addData(cleanWord);
        }
    }
    return counter;
}
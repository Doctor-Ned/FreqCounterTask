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

inline std::string clearWord(const std::string& word, bool clearApostrophes)
{
    std::string trimmed;
    size_t apostrophePos = word.find_last_of('\'');
    if (!clearApostrophes || apostrophePos == std::string::npos)
    {
        trimmed = word;
    } else
    {
        trimmed = word.substr(0, apostrophePos);
    }
    std::stringstream ss;
    const std::locale LOCALE_EN("en_US"), LOCALE_PL("pl_PL"), LOCALE_IT("it_IT");
    for (char character : trimmed)
    {
        if (isalpha(character, LOCALE_EN) ||
            isalpha(character, LOCALE_PL) ||
            isalpha(character, LOCALE_IT))
        {
            ss << character;
        }
    }
    return ss.str();
}

inline freqcounter<std::string> countWords(std::string filePath, bool clearApostrophes)
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
        std::string cleanWord = clearWord(currWord, clearApostrophes);
        if (!cleanWord.empty())
        {
            counter.addData(cleanWord);
        }
    }
    return counter;
}
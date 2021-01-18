#include "counters.h"
#include "ppm.h"

#include <ctime>

int main()
{
    std::srand(time(nullptr));
    freqcounter<char> fc_ch_pl = countCharacters("biblia-pl_ksiega_rdzaju.txt");
    freqcounter<char> fc_ch_en = countCharacters("biblia-en.txt");
    freqcounter<char> fc_ch_it = countCharacters("biblia-it.txt");
    freqcounter<std::string> fc_s_pl = countWords("biblia-pl_ksiega_rdzaju.txt");
    freqcounter<int> fc_int;
    for (int i = 0; i < 1'000'000; ++i)
    {
        fc_int.addData(std::rand() % 1000 + 1);
    }
    freqcounter<color> fc_c;
    ppm obr("lena.ppm");
    int colorCount = obr.getHeight() * obr.getWidth();
    color* colorPointer = obr.getColors();
    for (int i = 0; i < colorCount; ++i)
    {
        fc_c.addData(*(colorPointer + i));
    }
    fc_ch_pl.create("fc_ch_pl.txt");
    fc_ch_en.create("fc_ch_en.txt");
    fc_ch_it.create("fc_ch_it.txt");
    fc_s_pl.create("fc_s_pl.txt");
    fc_int.create("fc_int.txt");
    fc_c.create("fc_c.txt");
}

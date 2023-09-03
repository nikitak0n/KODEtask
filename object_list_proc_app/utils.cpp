#include "utils.h"

bool utils::is_integer(std::string maby_number)
{
    for (int i = 0; i < maby_number.size(); i++)
    {
        if (maby_number[i] < (char)0x30 || maby_number[i] > (char)0x39)
            return false;
    }
    return true;
}

bool utils::is_double(std::string maby_number)
{
    bool res = true;
    bool is_digit = false;
    int dot_count = 0;

    for (int i = 0; i < maby_number.size(); i++)
    {
        if (dot_count > 1)
            return false;

        if (maby_number[i] == (char)0x2e)
            dot_count++;

        is_digit = maby_number[i] >= (char)0x30 && maby_number[i] <= (char)0x39;
        is_digit = is_digit || maby_number[i] == (char)0x2e;
        res = res && is_digit;
    }
    return res;
}

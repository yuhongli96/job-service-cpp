#include "functions.ih"

bool isNumber(string const &str)
{
    if (str.empty())
        return false;

    for (char ch : str)
    {
        if (!isdigit(static_cast<unsigned char>(ch)))
            return false;
    }

    return true;
}
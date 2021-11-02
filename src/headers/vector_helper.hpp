#ifndef _DIFF_VECTORS_HPP_
#define _DIFF_VECTORS_HPP_
#include<vector>
#include<iostream>
using namespace std;
static ostream& operator<<(ostream& os, const vector<int> &dt)
{
    auto siz = dt.size();
    int i = 0;
    for(const auto& num: dt)
    {
        i++;
        os << (num == -1 ? 0 : 1) << ' ';
        if(i == 6)
        {
            os << '\n';
            i = 0;
        }
    }
    os << endl;
    return os;
}

static bool equals(std::vector<int> vec1, std::vector<int> vec2)
{
    for(int i = 0; i < vec1.size(); i++)
    {
        if(vec1[i] != vec2[i]) return false;
    }
    return true;
}
#endif
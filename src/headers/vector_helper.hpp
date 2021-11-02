#ifndef _DIFF_VECTORS_HPP_
#define _DIFF_VECTORS_HPP_
#include<vector>
static bool equals(std::vector<int> vec1, std::vector<int> vec2)
{
    for(int i = 0; i < vec1.size(); i++)
    {
        if(vec1[i] != vec2[i]) return false;
    }
    return true;
}
#endif
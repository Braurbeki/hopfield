#include<.\headers\symbols_reader.hpp>
#include<.\headers\vector_helper.hpp>
#include<iostream>
symobls_reader::symobls_reader()
{
    _x = read_file(_learning_path + "\\x");
    _y = read_file(_learning_path + "\\y");
    _u = read_file(_learning_path + "\\u");
    _z = read_file(_learning_path + "\\z");
}

vector<int> symobls_reader::read_file(string filename) 
{
    vector<int> res;
    ifstream in(filename);
    int a = 0;
    while(in >> a) 
    {
        res.push_back(a == 0 ? -1 : 1); 
    } 
    return res;
}

void symobls_reader::print_letter(vector<int> vec)
{
    if(equals(vec, _x)) std::cout << "Guess is 'X'\n";
    else if (equals(vec, _y)) std::cout << "Guess is 'Y'\n";
    else if (equals(vec, _u)) std::cout << "Guess is 'U'\n";
    else if (equals(vec, _z)) std::cout << "Guess is 'Z'\n";
    else std::cout << "No matches found";
}

vector<vector<int>> symobls_reader::get_learn_data()
{
    return vector<vector<int>>{_x, _y, _u, _z};
}

vector<vector<int>> symobls_reader::get_test_data()
{
    return vector<vector<int>>{read_file(_test_path + "\\x"), read_file(_test_path + "\\z")};
}
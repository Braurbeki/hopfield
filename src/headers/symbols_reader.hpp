#ifndef _SYMBOLS_READER_H_
#define _SYMBOLS_READER_H_
#include<vector>
#include<fstream>
using namespace std;

class symobls_reader
{
private:
    const string _learning_path = "C:\\Projects\\Labs\\c_lab2\\learning";
    const string _test_path = "C:\\Projects\\Labs\\c_lab2\\testing";
    vector<int> _x, _y, _u, _z;
private:
    vector<int> read_file(string filename);
public:
    symobls_reader();
    vector<vector<int>> get_learn_data();
    vector<vector<int>> get_test_data();
    void print_letter(vector<int> vec);
};
#endif
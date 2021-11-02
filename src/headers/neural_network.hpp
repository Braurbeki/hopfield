#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_
#include<vector>
#include<./headers/symbols_reader.hpp>
using namespace std;
class NeuralNetwork
{
private:
    vector<vector<double>> _weights;
    symobls_reader _reader;
    int _siz;
public:
    NeuralNetwork(int num_w);
    void learn();
    vector<int> recognize(vector<int> to_recognize, int depth);
};
#endif
#include<.\headers\neural_network.hpp>
#include<.\headers\vector_helper.hpp>
#include<iostream>
#include<iomanip>
NeuralNetwork::NeuralNetwork(int num_w)
{
    _siz = pow(num_w, 2);
    _weights = vector<vector<double>>(_siz, vector<double>(_siz, 0));
}

void NeuralNetwork::learn()
{
    auto learning_vec = _reader.get_learn_data();
    for(auto learn_data : learning_vec)
    {
        for(int i = 0; i < _siz; i++)
        {
            for(int j = 0; j < _siz; j++)
            {
                if(i == j) continue;
                _weights[i][j] += learn_data[i] * learn_data[j];
                _weights[i][j] /= pow(_siz, 2);
            }
        }
    }

}

vector<int> NeuralNetwork::recognize(vector<int> to_recognize)
{
    vector<int> res(_siz, 0);
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < _siz; j++)
        {
            double d = 0;
            for(int i = 0; i <_siz; i++)
            {
                d += _weights[j][i] * to_recognize[i];
            }
            if(d > 0)
            {
                res[j] = 1;
            }
            else
            {
                res[j] = -1;
            }
        }

        for(auto vec : _reader.get_learn_data())
        {
            if(equals(vec, res)) 
            {
                return res;
            }
        }
        
    }

    for(auto vec : _reader.get_learn_data())
    {
        if(equals(vec, res)) 
        {
            return res;
        }
    }

    return vector<int>();
}
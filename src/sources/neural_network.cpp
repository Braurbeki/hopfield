#include<.\headers\neural_network.hpp>
#include<.\headers\vector_helper.hpp>
#include<iostream>
NeuralNetwork::NeuralNetwork(int num_w)
{
    _siz = num_w;
    _weights = vector<vector<double>>(num_w, vector<double>(num_w, 0));
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
                for(int t = 0; t < _siz; t++)
                {
                    _weights[i][j] += learn_data[t  + i * _siz] * learn_data[t  + j * _siz];
                }
                _weights[i][j] /= pow(_siz, 2);
            }
        }
    }

    for(int i = 0; i < _siz; i++)
    {
        for(int j = 0; j < _siz; j++)
        {
            _weights[i][j] /= pow(_siz, 2);
        }
    }
}

vector<int> NeuralNetwork::recognize(vector<int> to_recognize, int depth)
{
    int j = 0;
    for(auto i : to_recognize)
    {
        j++;
        std::cout << i << ' ';
        if(j == 6)
        {
            std::cout << std::endl;
            j = 0;
        }
    }
    std::cout << std::endl << std::endl;
    vector<int> res(pow(_siz,2), 0);
    for(int j = 0; j < pow(_siz, 2); j++)
    {
        double d = 0;
        for(int i = 0; i < pow(_siz, 2); i++)
        {
            d += _weights[i / _siz][j / _siz] * to_recognize[i];
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
        if(equals(vec, res) || depth > 50) 
        {
            std::cout<< "Learning finished";
            return res;
        }
    }
    j = 0;
    for(auto i : res)
    {
        j++;
        std::cout << i << ' ';
        if(j == 6)
        {
            std::cout << std::endl;
            j = 0;
        }
    }
    std::cout << std::endl << std::endl;
    recognize(res, depth + 1);
}
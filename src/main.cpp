#include<iostream>
#include<headers/neural_network.hpp>
#include<headers/symbols_reader.hpp>
#include<headers/vector_helper.hpp>
static const uint16_t siz = 6;

int main()
{
    NeuralNetwork network(siz);
    network.learn();
    symobls_reader reader;
    for(auto vec : reader.get_test_data())
    {
        cout << vec;
        reader.print_letter(network.recognize(vec));
    }
    return 0;
}
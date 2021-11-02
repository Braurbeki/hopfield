#include<iostream>
#include<headers/neural_network.hpp>
#include<headers/symbols_reader.hpp>
static const uint16_t siz = 6;

int main()
{
    NeuralNetwork network(siz);
    network.learn();
    symobls_reader reader;
    for(auto vec : reader.get_test_data())
    {
        reader.print_letter(network.recognize(vec, 0));
        break;
    }
    return 0;
}
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
    auto vec = reader.get_test_data();
    cout << vec[0];
    reader.print_letter(network.recognize(vec[0]));
    cout << vec[1];
    reader.print_letter(network.recognize(vec[1]));
    return 0;
}
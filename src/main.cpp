#include<iostream>
#include<headers/neural_network.hpp>
#include<headers/symbols_reader.hpp>
static const uint16_t siz = 6;

int main()
{
    NeuralNetwork network(siz);
    network.learn();
    symobls_reader reader;
    auto vec = reader.get_test_data();
    cout << "For X - ";
    reader.print_letter(network.recognize(vec[0]));
    cout << "For Z - ";
    reader.print_letter(network.recognize(vec[1]));
    return 0;
}
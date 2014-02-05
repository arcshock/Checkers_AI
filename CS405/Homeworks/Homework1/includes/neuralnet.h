#ifndef NEURAL_NET_H
#define NEURAL_NET_H
/*
 * Author: Bucky Frost
 * File: neuralnet.h
 * CS 405 Intro to A.I.
 * Purpose: Header of neural network class.
 */

#include<vector>
#include<array>
//#include<ostream>
#include<iterator>
#include<cstdlib>
#include<iostream>

template<class Iter>
class NeuralNet {
public:
	NeuralNet();
	NeuralNet(int input, Iter begin, Iter end, int output);
	NeuralNet(Iter begin, Iter end, int size);
	void setWeights();

private:
	void printNetwork();
	std::vector< std::vector< double > > network_m;
	//TODO: pairs for bias and weight of each node
};

template<class Iter>
void NeuralNet<Iter>::printNetwork()
{
	for ( auto iter = network_m.begin(); iter != network_m.end(); ++iter ) {
		for ( auto iterr = iter->begin(); iterr != iter->end(); ++iterr ) {
			std::cout << *iterr << std::endl;
		}
	}
}

template<class Iter>
NeuralNet<Iter>::NeuralNet (Iter begin, Iter end, int size )
{
	Iter it = begin;
	network_m.reserve( size );
	for (int i = 0; i < size; ++i) {
		network_m[i].reserve(*it);
		++it;
	}

/*
	network_m.reserve(size);
	std::vector< std::vector< double >>::iterator network_iter = network_m.begin();

	for ( auto it = begin; it != end; it++ ) {
//		std::cout << *it << std::endl; //debug output
		network_iter[].reserve( *it );
	}
*/
}
template<class Iter>
NeuralNet<Iter>::NeuralNet (int input, Iter begin, Iter end, int output)
{
	//TODO
}
#endif //NEURAL_NET_H

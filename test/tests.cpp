#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

/**
 * Author: Bucky Frost
 * File: tests.cpp
 * Purpose: Testing surite for checkers AI.
 */


#include "catch.hpp"
#include "neural_network.hpp"
#include "checker_board.hpp"


std::vector<double> negative_checker_board(32, -1.0);
std::vector<double> empty_checker_board(32, 0.0);
std::vector<double> full_checker_board(32, 1.0);

std::vector<int> standard_network = {32, 40, 10, 1};


TEST_CASE( "Default Constructed Neural Network Class" ) {

	Neural_Network first_net;

	double solution1 = (-1.0*32.0)/(1.0 + abs(-1.0*32.0));
	double solution2 = (0.0*32.0)/(1.0 + abs(0.0*32.0));
	double solution3 = (1.0*32.0)/(1.0 + abs(1.0*32.0));

}


TEST_CASE( "Specified Network Construction" ) {
	std::vector<double> negative_checker_board(32, -1.0);

	std::vector<int> network_layout = {32, 1, 1, 1};

	Neural_Network constructed_network(network_layout);

	REQUIRE( constructed_network.network_evaluate(empty_checker_board) != 0.0 );
	REQUIRE( constructed_network.network_evaluate(negative_checker_board) != 0.0 );
}


TEST_CASE( "Network Operators" ) {
	Neural_Network first_network(standard_network);
	Neural_Network second_network(standard_network);

	REQUIRE( first_network == first_network);

}


TEST_CASE( "Neural Netowrk Serialization" ) {
	Neural_Network saved_network(standard_network);

	std::ofstream ofs("test_network_save.txt");

	boost::archive::text_oarchive oa(ofs);

	oa << saved_network;
	ofs.close();

	saved_network.network_evaluate(negative_checker_board);

	Neural_Network restored_network(standard_network);

	std::ifstream ifs("test_network_save.txt");
	boost::archive::text_iarchive ia(ifs);
	ia >> restored_network;

	REQUIRE( saved_network != restored_network );	

	restored_network.network_evaluate(negative_checker_board);
	REQUIRE( restored_network == saved_network );	
}


TEST_CASE( "Checker Board" ) {
	std::string initial_board = "_w_w_w_w\n"      // h
					"w_w_w_w_\n"  // g
					"_w_w_w_w\n"  // f
					"________\n"  // e
					"________\n"  // d
					"r_r_r_r_\n"  // c
					"_r_r_r_r\n"  // b
					"r_r_r_r_\n"; // a


	std::ostringstream board_format;

	Checker_Board board;
	board.print_board(board_format);

	REQUIRE(board_format.str() == initial_board);


	std::vector<coordinate> possible_moves = board.get_moves(std::make_pair('a', 0));
	REQUIRE( possible_moves.empty() == true );

	possible_moves = board.get_moves(std::make_pair('c', 2));
	REQUIRE( possible_moves.size() == 2 );
	REQUIRE( possible_moves[0] == std::make_pair('d', 1) );
	REQUIRE( possible_moves[1] == std::make_pair('d', 3) );
}
#endif /*CATCH_CONFIG_MAIN*/

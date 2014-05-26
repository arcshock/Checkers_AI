#ifndef CHECKER_BOARD_HPP
#define CHECKER_BOARD_HPP

/**
 * Author: Bucky Frost
 * File: checker_baord.hpp
 * Purpose: A board and functions for playing checkers.
 */

#include <map>
#include <string>
#include <ostream>
#include "game_piece.hpp"


class Checker_Board
{
public:
	Checker_Board()
	{
		int board_spaces = 32;
		for (char board_column = 'a'; board_column < 'i'; ++board_column) {
			for (int board_row = 0; board_row < 8; ++board_row) {
				if (board_column == 'a' || board_column == 'c') {
					if (board_row%2 == 0) {
						_board_pieces[std::make_pair(board_column, board_row)] = Checker_Piece('r', std::make_pair(board_column, board_row));
					}
				} else if (board_column == 'b') {
					if (board_row%2 == 1) {
						_board_pieces[std::make_pair(board_row, board_column)] = Checker_Piece('r', std::make_pair(board_column, board_row));
					}
				} else if (board_column == 'f' || board_column == 'h') {
					if (board_row%2 == 1) {
						_board_pieces[std::make_pair(board_row, board_column)] = Checker_Piece('w', std::make_pair(board_column, board_row));
					}
				} else if (board_column == 'g') {
					if (board_row%2 == 0) {
						_board_pieces[std::make_pair(board_row, board_column)] = Checker_Piece('w', std::make_pair(board_column, board_row));
					}
				}
			}
		}
	}


	void print_board(std::ostream & output_stream)
	{
		output_stream << _board;
	}
	

	std::vector<coordinate> get_moves(coordinate board_coordinate)
	{
		// TODO - validate the moves that are returned by the piece.
		std::vector<coordinate> possible_piece_moves = {};
		possible_piece_moves.clear();

		try {
			auto queried_piece = _board_pieces.at(board_coordinate);
			possible_piece_moves = queried_piece.get_moves();

		} catch (std::out_of_range & range_error) {
			// No piece was found at this location.
		}
		
		possible_piece_moves.erase(std::remove_if(possible_piece_moves.begin(), possible_piece_moves.end(), [&](coordinate location) {return _board_pieces.count(location);}));
		
		return possible_piece_moves;
	}
private:
	std::map<coordinate, Checker_Piece> _board_pieces;
	std::string _board = "_w_w_w_w\n"
				"w_w_w_w_\n"
				"_w_w_w_w\n"
				"________\n"
				"________\n"
				"r_r_r_r_\n"
				"_r_r_r_r\n"
				"r_r_r_r_\n";
};
#endif /*CHECKER_BOARD_HPP*/

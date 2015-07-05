#ifndef CHECKER_TEST
#define CHECKER_TEST

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "catch.hpp"
#include "checker_board.hpp"

TEST_CASE ("Checker Moves") {
	SECTION ("Pawn Moves") {
		Checker_Board test_board;
		char expected = ' ';
		std::string location = "";
		test_board.print();

		for (int row = 0; row < 3; ++row) {
			for (char column = 'A'; column < 'I'; ++column) {
				switch (row) {
					case 0:
					case 2:
						switch (column) {
							case 'A':
							case 'C':
							case 'E':
							case 'G':
								expected = 'r';
								location = column + std::to_string(row);
								REQUIRE ( test_board.space_state(location) == expected );
								break;
						}
						break;
					case 1:
						switch (column) {
							case 'B':
							case 'D':
							case 'F':
							case 'H':
								expected = 'r';
								location = column + std::to_string(row);
								REQUIRE ( test_board.space_state(location) == expected );
								break;
						}
						break;
					case 6:
						switch (column) {
							case 'A':
							case 'C':
							case 'E':
							case 'G':
								expected = 'w';
								location = column + std::to_string(row);
								REQUIRE ( test_board.space_state(location) == expected );
								break;
						}
						break;

					case 5:
					case 7:
						switch (column) {
							case 'B':
							case 'D':
							case 'F':
							case 'H':
								expected = 'w';
								location = column + std::to_string(row);
								REQUIRE ( test_board.space_state(location) == expected );
								break;
						}
						break;

					default:
						expected = '_';
						location = column + std::to_string(row);
						REQUIRE ( test_board.space_state(location) == expected );
						break;
				}
			}
		}
	}
}
#endif /*CHECKER_TEST*/

#pragma once

#include <iostream>
#include <string>

inline int getNumberInput() {
	std::string line;
	
	bool validInput = false;

	int input;

	do {
		try {
			std::getline(std::cin, line);
			
			validInput = true;
			input = std::stoi(line);

			if (validInput) {
				if (input <= 0) throw std::out_of_range("");
				return input;
			}
		}
		catch (std::invalid_argument err) {
			std::cout << "Invalid input! Try again!\n";
			validInput = false;
		}
		catch (std::out_of_range err) {
			std::cout << "Entered number is out of range! Try again!\n";
			validInput = false;
		}
	} while (!validInput);
}

#include "check_fitness.hpp"
#include "square.hpp"

#include <ctime>
#include <iostream>
#include <list>

int main(int, char**) {
	srand(time(nullptr));

	std::list<Square<3>> squareList;

	for (int i = 0; i < 1000; i++) {
		squareList.push_back({
//			(rand() % 1000) ^2, (rand() % 1000) ^2, (rand() % 1000) ^2,
//			(rand() % 1000) ^2, (rand() % 1000) ^2, (rand() % 1000) ^2,
//			(rand() % 1000) ^2, (rand() % 1000) ^2, (rand() % 1000) ^2

			(rand() % 9) + 1, (rand() % 9) + 1, (rand() % 9) + 1,
			(rand() % 9) + 1, (rand() % 9) + 1, (rand() % 9) + 1,
			(rand() % 9) + 1, (rand() % 9) + 1, (rand() % 9) + 1
		});
	}

	squareList.sort([](Square<3> const& lhs, Square<3> const& rhs) -> bool {
		return checkFitness<3>(lhs) < checkFitness<3>(rhs);
	});

	std::cout << "Front: " << checkFitness<3>(squareList.front()) << std::endl;
	std::cout << "Back: " << checkFitness<3>(squareList.back()) << std::endl;

	Square<3>& square = squareList.back();

	std::cout << square.Get(0, 0) << ", " <<square.Get(1, 0) << ", " << square.Get(2, 0) << std::endl;
	std::cout << square.Get(0, 1) << ", " <<square.Get(1, 1) << ", " << square.Get(2, 1) << std::endl;
	std::cout << square.Get(0, 2) << ", " <<square.Get(1, 2) << ", " << square.Get(2, 2) << std::endl;

	return 0;
}
#include "check_fitness.hpp"
#include "square.hpp"

#include <ctime>
#include <iostream>
#include <list>

template <int N>
void twist(Square<N>& lhs, Square<N>& rhs) {
	int array[N*N];

	//cache lhs
	for (int i = 0; i < N*N; i++) {
		array[i] = lhs.Get(i % N, i / N);
	}

	//starting from a random point between 0 and N*N
	for (int i = rand() % N*N; i < N*N; i++) {
		//set lhs to rhs values
		lhs.Set(i % N, i / N, rhs.Get(i % N, i / N));
		//set rhs to lhs values
		rhs.Set(i % N, i / N, array[i]);
	}
}

int main(int, char**) {
	srand(time(nullptr));

	std::list<Square<3>> squareList;

	//initial seeding
	for (int i = 0; i < 10000; i++) {
		squareList.push_back({
//			(rand() % 1000) ^2, (rand() % 1000) ^2, (rand() % 1000) ^2,
//			(rand() % 1000) ^2, (rand() % 1000) ^2, (rand() % 1000) ^2,
//			(rand() % 1000) ^2, (rand() % 1000) ^2, (rand() % 1000) ^2

			(rand() % 9) + 1, (rand() % 9) + 1, (rand() % 9) + 1,
			(rand() % 9) + 1, (rand() % 9) + 1, (rand() % 9) + 1,
			(rand() % 9) + 1, (rand() % 9) + 1, (rand() % 9) + 1
		});
	}

	for (int i = 0; i < 10; i++) {
		//sort
		squareList.sort([](Square<3> const& lhs, Square<3> const& rhs) -> bool {
			//front is best
			return checkFitness<3>(lhs) > checkFitness<3>(rhs);
		});

		//output
		std::cout << "Front ( " << i << "): " << checkFitness<3>(squareList.front()) << std::endl;

		//eliminate the lower half
		int size = squareList.size() / 2;
		std::list<Square<3>>::iterator begin = squareList.begin();
		while(size--) begin++;
		squareList.erase(begin, squareList.end());

		//splice the remaining results
		begin = squareList.begin();
		std::list<Square<3>>::iterator tmp;
		for (auto& it = begin; it != squareList.end(); it++) {
			//push duplicates onto the list
			tmp = it;
			squareList.push_front(tmp);
			tmp++;
			squareList.push_front(tmp);

			//twist the newly pushed elements
			twist(*squareList.begin(), *(squareList.begin()++));
		}
	}

	return 0;
}
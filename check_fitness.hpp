#pragma once

#include "square.hpp"

#include <list>
#include <map>

template<int N>
int checkFitness(Square<N> square) {
	std::list<int> sumList;

	//get the cardinal sums
	for(int i = 0; i < N; i++) {
		int sumX = 0;
		int sumY = 0;
		for (int j = 0; j < N; j++) {
			sumX += square.Get(i, j);
			sumY += square.Get(j, i);
		}
		sumList.push_back(sumX);
		sumList.push_back(sumY);
	}

	//diagonal sums
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < N; i++) {
		sumA += square.Get(i, i);
		sumB += square.Get(i, N - i - 1);
	}

	sumList.push_back(sumA);
	sumList.push_back(sumB);

	sumList.sort();

	//find the highest number of matches
	std::map<int, int> duplicates;
	for (auto& it : sumList) {
		duplicates[it]++; //i.e. d[15] = 2, etc.
	}
	int max = 0;
	for (auto& it : duplicates) {
		if (it.second > max) {
			max = it.second;
		}
	}

	//a perfect result should be N*N+2
	return max;
}

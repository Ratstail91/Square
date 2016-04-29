#pragma once

#include <cstdarg>
#include <cstdlib>

template<int N>
class Square {
public:
	Square();
	Square(...);
	~Square();

	int Set(int x, int y, int i);
	int Get(int x, int y);

private:
	int array[N][N];
};

template<int N>
Square<N>::Square() {
	memset(array, 0, sizeof(int) * N);
}

template<int N>
Square<N>::Square(...) {
	va_list args;
	va_start(args, N*N);
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			array[i][j] = va_arg(args, int);
		}
	}
	va_end(args);
}

template<int N>
Square<N>::~Square() {
	//EMPTY
}

template<int N>
int Square<N>::Set(int x, int y, int i) {
	if (x < 0 || x >= N) {
		return -1;
	}
	if (y < 0 || y >= N) {
		return -1;
	}
	return array[x][y] = i;
}

template<int N>
int Square<N>::Get(int x, int y) {
	if (x < 0 || x >= N) {
		return -1;
	}
	if (y < 0 || y >= N) {
		return -1;
	}
	return array[x][y];
}

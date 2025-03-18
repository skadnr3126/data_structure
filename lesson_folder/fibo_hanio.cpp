#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stdio.h>

#define MAX_SIZE 1000
//#define FIBO
#define HANOI
int fibo_arr[MAX_SIZE];


void fibo_init() {
	fibo_arr[1] = 1;
	fibo_arr[2] = 1;
}

void make_fibo(int n){
	for (int i = 3; i <= n; ++i) {
		if (fibo_arr[i] == 0) {
			fibo_arr[i] = fibo_arr[i - 1] + fibo_arr[i - 2];
		}
	}
}

int fibo(int n) {
	if (n == 2 || n == 1) {
		return 1;
	}
	else {
		return fibo(n - 1) + fibo(n - 2);
	}
}


void hanoi_tower(int n, char from, char buf, char to) {
	if (n == 1) {
		printf("move from %c to %c \n", from, to);
		return;
	}

	hanoi_tower(n - 1, from, to, buf);
	hanoi_tower(1, from, buf, to);
	hanoi_tower(n - 1, buf, from, to);
	return;
	
}
int main() {
	int  n;

#ifdef FIBO
	
	fibo_init();
	while (1) {
		std::cin >> n;

		make_fibo(n);

		std::cout << "optimized fibo : " << fibo_arr[n] << std::endl;
		std::cout << "typical fibo :" << fibo(n) << std::endl;
	}
#endif // FIBO

#ifdef HANOI
	while (1) {
		std::cin >> n;
		hanoi_tower(n, 'A', 'B', 'C');
	}
#endif // HANIO

}
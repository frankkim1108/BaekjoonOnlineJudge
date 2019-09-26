#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];

void checkHor() {
	
	for (int i = 0; i < 9; i++) {
		bool check[10] = { false, };
		for (int j = 0; j < 9; j++) {
			check[sudoku[i][j]] = true;
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			cin >> sudoku[i][k];
		}
	}


}
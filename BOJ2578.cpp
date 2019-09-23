#include <iostream>
using namespace std;

int bingo[5][5] = { 0, };
int number[5][5] = { 0, };
int bingocount = 0;
bool winner = false;

void checkHB() {
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] == 0)
				count++;
		}
		if (count == 5) {
			bingocount++;
			if (bingocount == 3) {
				winner = true;
				return;
			}
		}
		count = 0;
	}
}
void checkVB() {
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[j][i] == 0)
				count++;
		}
		if (count == 5) {
			bingocount++;
			if (bingocount == 3) {
				winner = true;
				return;
			}
		}
		count = 0;
	}
}
void checkDB() {
	int count = 0;
	for (int i = 0; i < 5; i++) {

		if (bingo[i][i] == 0)
			count++;

	}
	if (count == 5) {
		bingocount++;
		if (bingocount == 3) {
			winner = true;
			return;
		}
	}

	count = 0;
	for (int i = 0; i < 5; i++) {
		
			if (bingo[i][4-i] == 0)
				count++;
		
	}
	if (count == 5) {
		bingocount++;
		if (bingocount == 3) {
			winner = true;
			return;
		}
	}

	count = 0;
}

int main() {

	int count = 0;
	bool checked = false;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num; cin >> num;
			bingo[i][j] = num;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num; cin >> num;
			number[i][j] = num;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			bingocount = 0;
			int num = number[i][j];
			for (int k = 0; k < 5; k++) {
				for (int l = 0; l < 5; l++) {
					if (num == bingo[k][l]) {
						bingo[k][l] = 0;
						checked = true;
						break;
					}
					if (checked == true)
						break;
				}
			}
			checked = false;
			count++;
			checkHB();
			if (winner == true)
				break;
			checkVB();
			if (winner == true)
				break;
			checkDB(); 
			if (winner == true)
				break;
		}
		if (winner == true)
			break;
		
			
	}

	cout << count;

}
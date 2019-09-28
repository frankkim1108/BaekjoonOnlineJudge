#include<iostream>
using namespace std;

int Bacon[5001][5001];


int main() {
	int min = 5000;
	int max = 987654321;
	for (int i = 0; i < 5001; i++) {
		for (int j = 0; j < 5001; j++) {
			Bacon[i][j] = 0;
		}
	}
	for (int i = 1; i < 5001; i++) {
		for (int j = 1; j < 5001; j++) {
			if (i == j)
				continue;
			Bacon[i][j] = max;
		}
	}
	int friendnum;
	int relationship;

	cin >> friendnum >> relationship;

	for (int i = 0; i < relationship; i++) {
		int F1, F2;
		cin >> F1 >> F2;
		Bacon[F1][F2] = 1;
		Bacon[F2][F1] = 1;
	}

	for (int i = 1; i <= friendnum; i++) {
		for (int j = 1; j <= friendnum; j++) {
			if (i == j)
				continue;
			for (int k = 1; k <= friendnum; k++) {
				if (j == k || i == k) {
					continue;
				}
				if (Bacon[j][k] > Bacon[j][i] + Bacon[i][k])
					Bacon[j][k] = Bacon[j][i] + Bacon[i][k];
			}
		}
	}

	for (int i = friendnum; i >= 1; i--) {
		int sum = 0;
		for (int j = 0; j <= friendnum; j++) {
			sum += Bacon[i][j];	
		}if (sum <= max) {
				max = sum;
				min = i;
			}
	}

	cout << min;
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string plate;
	int count = 0;
	cin >> plate;
	char last = 0;
	for (int i = 0; i < plate.length(); i++) {

		if (i == 0) {
			count += 10;
			last = plate[i];
		}
		else {
			if (plate[i] == last) {
				count += 5;
				last = plate[i];
			}
			else if (plate[i] != last) {
				count += 10;
				last = plate[i];
			}
		}
	}

	cout << count;

}

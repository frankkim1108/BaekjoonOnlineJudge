#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Node {
public:
	Node* next;
	int number;

	Node() {
		next = NULL;
		number = NULL;
	}
};

class Stack {
public:
	vector<Node*> V;
	Node* TOP;
	int size;

	Stack() {
		TOP = NULL;
		size = 0;
	}

	void push(int n) {
		Node* newNode = new Node();
		newNode->number = n;
		V.push_back(newNode);
		size++;
	}

	void top() {
		if (size == 0) {
			cout << -1 << "\n";
		}
		else
			cout << V.back()->number << "\n";
	}

	void Size() {
		cout << size << "\n";
	}

	void empty() {
		if (size == 0)
			cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	void pop() {
		if (size == 0)
			cout << -1 << "\n";
		else {
			cout << V.back()->number << "\n";
			V.pop_back();
			size--;
		}
	}
};

int main() {
	int num;
	cin >> num;
	Stack S;

	for (int i = 0; i < num; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int N;
			cin >> N;
			S.push(N);
		}
		if (s == "pop") {
			S.pop();
		}
		if (s == "size") {
			S.Size();
		}
		if (s == "top") {
			S.top();
		}
		if (s == "empty") {
			S.empty();
		}
	}
}
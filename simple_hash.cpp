#include <iostream>
#include <string>

using namespace std;

int addHash(string key) {
	long long hash = 0;
	const int MODULUS = 1000000007;
	for (unsigned char c : key) {
		hash = (hash + (int)c) % MODULUS;
	}
	return (int)hash;
}

int mulHash(string key) {
	long long hash = 0;
	const int MODULUS = 1000000007;
	for (unsigned char c : key) {
		hash = (31 * hash + (int)c) % MODULUS;
	}
	return (int)hash;
}

int xorHash(string key) {
	int hash = 0;
	const int MODULUS = 100000007;
	for (unsigned char c : key) {
		hash ^= (int)c;
	}
	return hash & MODULUS;
}

int rotHash(string key) {
	long long hash = 0;
	const int MODULUS = 1000000007;
	for (unsigned char c : key) {
		hash = ((hash << 4) ^ (hash >> 28) ^ (int)c) % MODULUS;
	}
	return (int)hash;
}

int main() {
	string test = "HelloWorld";
	cout << "addHash:" << addHash(test) << endl;
	cout << "mulHash:" << mulHash(test) << endl;
	cout << "xorHash:" << xorHash(test) << endl;
	cout << "rotHash:" << rotHash(test) << endl;
	return 0;
}
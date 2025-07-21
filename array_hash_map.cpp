#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pair {
public:
	int key;
	string val;
	Pair(int key, string val) {
		this->key = key;
		this->val = val;
	}
};

class ArrayHashMap {
private:
	vector<Pair*> buckets;
public:
	ArrayHashMap() {
		buckets = vector<Pair*>(100);
	}

	~ArrayHashMap() {
		for (const auto& bucket : buckets) {
			delete bucket;
		}
		buckets.clear();
	}

	int hashFunc(int key) {
		int index = key % 100;
		return index;
	}

	string get(int key) {
		int index = hashFunc(key);
		Pair* pair = buckets[index];
		if (pair == nullptr)
			return "";
		return pair->val;
	}

	void put(int key, string val) {
		Pair* pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index] = pair;
	}

	void remove(int key) {
		int index = hashFunc(key);
		delete buckets[index];
		buckets[index] = nullptr;
	}

	vector<Pair*> pairSet() {
		vector<Pair*> pairSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				pairSet.push_back(pair);
			}
		}
		return pairSet;
	}

	vector<int> keySet() {
		vector<int> keySet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				keySet.push_back(pair->key);
			}
		}
		return keySet;
	}

	vector<string> valueSet() {
		vector<string> valueSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				valueSet.push_back(pair->val);
			}
		}
		return valueSet;
	}

	void print() {
		for (Pair* kv : pairSet()) {
			cout << kv->key << " -> " << kv->val << endl;
		}
	}
};
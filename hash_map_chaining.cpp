#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pair {
public:
    int key;
    string val;
    Pair(int k, string v) : key(k), val(v) {}
};

class HashMapchaining {
private:
    int size;
    int capacity;
    double loadThres;
    int extendRatio;
    vector<vector<Pair*>> buckets;

public:
    HashMapchaining() : size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2) {
        buckets.resize(capacity);
    }

    ~HashMapchaining() {
        for (auto& bucket : buckets) {
            for (Pair* pair : bucket) {
                delete pair;
            }
        }
    }

    int hashFunc(int key) {
        return key % capacity;
    }

    double loadFactor() {
        return (double)size / (double)capacity;
    }

    string get(int key) {
        int index = hashFunc(key);
        for (Pair* pair : buckets[index]) {
            if (pair->key == key) {
                return pair->val;
            }
        }
        return "";
    }

    void put(int key, string val) {
        if (loadFactor() > loadThres) {
            extend();
        }
        int index = hashFunc(key);
        for (Pair* pair : buckets[index]) {
            if (pair->key == key) {
                pair->val = val;
                return;
            }
        }
        buckets[index].push_back(new Pair(key, val));
        size++;
    }

    void remove(int key) {
        int index = hashFunc(key);
        auto& bucket = buckets[index];

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i]->key == key) {
                Pair* tmp = bucket[i];
                bucket.erase(bucket.begin() + i);
                delete tmp;
                size--;
                return;
            }
        }
    }

    void extend() {
        vector<vector<Pair*>> bucketsTmp = buckets;
        capacity *= extendRatio;
        buckets.clear();
        buckets.resize(capacity);
        size = 0;
        for (auto& bucket : bucketsTmp) {
            for (Pair* pair : bucket) {
                put(pair->key, pair->val);
                delete pair;
            }
        }
    }

    void print() {
        for (auto& bucket : buckets) {
            cout << "[";
            for (Pair* pair : bucket) {
                cout << pair->key << " -> " << pair->val << ", ";
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    HashMapchaining hashMap;
    hashMap.put(1, "apple");
    hashMap.put(2, "banana");
    hashMap.put(5, "cherry");
    hashMap.print();

    cout << "Get key 2: " << hashMap.get(2) << endl;

    hashMap.remove(2);
    cout << "After removing key 2:" << endl;
    hashMap.print();

    return 0;
}
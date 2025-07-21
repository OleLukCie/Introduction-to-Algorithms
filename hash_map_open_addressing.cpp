/* Open Addressing Hash Map */
#include <iostream>
#include <vector>
using namespace std;

/* Pair Structure */
struct Pair {
    int key;
    string val;
    Pair(int key, string val) : key(key), val(val) {}
};

class HashMapOpenAddressing {
private:
    int size;                             // Number of key-value pairs
    int capacity = 4;                     // Hash map capacity
    const double loadThres = 2.0 / 3.0;   // Load factor threshold for resizing
    const int extendRatio = 2;            // Capacity extension ratio
    vector<Pair*> buckets;                // Bucket array
    Pair* TOMBSTONE = new Pair(-1, "-1"); // Tombstone marker for deleted entries

public:
    /* Constructor */
    HashMapOpenAddressing() : size(0), buckets(capacity, nullptr) {}

    /* Destructor */
    ~HashMapOpenAddressing() {
        for (Pair* pair : buckets) {
            if (pair != nullptr && pair != TOMBSTONE) {
                delete pair;
            }
        }
        delete TOMBSTONE;
    }

    /* Hash Function */
    int hashFunc(int key) {
        return key % capacity;
    }

    /* Load Factor Calculation */
    double loadFactor() {
        return (double)size / capacity;
    }

    /* Find bucket index for given key */
    int findBucket(int key) {
        int index = hashFunc(key);
        int firstTombstone = -1;

        // Linear probing until an empty bucket is found
        while (buckets[index] != nullptr) {
            // If key is found, return its index
            if (buckets[index]->key == key) {
                // Move the pair to the first tombstone position if applicable
                if (firstTombstone != -1) {
                    buckets[firstTombstone] = buckets[index];
                    buckets[index] = TOMBSTONE;
                    return firstTombstone; // Return new index after move
                }
                return index; // Return original index
            }

            // Track the first tombstone encountered
            if (firstTombstone == -1 && buckets[index] == TOMBSTONE) {
                firstTombstone = index;
            }

            // Probe to next bucket (wrap around if end is reached)
            index = (index + 1) % capacity;
        }

        // Return first tombstone index if found, otherwise return empty bucket index
        return firstTombstone != -1 ? firstTombstone : index;
    }

    /* Get value associated with key */
    string get(int key) {
        int index = findBucket(key);
        // Return value if key exists and is not a tombstone
        if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
            return buckets[index]->val;
        }
        // Return empty string if key not found
        return "";
    }

    /* Insert or update key-value pair */
    void put(int key, string val) {
        // Resize if load factor exceeds threshold
        if (loadFactor() > loadThres) {
            extend();
        }

        int index = findBucket(key);
        // Update existing key's value
        if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
            buckets[index]->val = val;
            return;
        }

        // Insert new key-value pair
        buckets[index] = new Pair(key, val);
        size++;
    }

    /* Remove key-value pair */
    void remove(int key) {
        int index = findBucket(key);
        // Mark as tombstone if key exists
        if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
            delete buckets[index];
            buckets[index] = TOMBSTONE;
            size--;
        }
    }

    /* Extend hash map capacity */
    void extend() {
        vector<Pair*> oldBuckets = buckets;
        // Double capacity
        capacity *= extendRatio;
        buckets = vector<Pair*>(capacity, nullptr);
        size = 0;

        // Rehash all existing key-value pairs
        for (Pair* pair : oldBuckets) {
            if (pair != nullptr && pair != TOMBSTONE) {
                put(pair->key, pair->val);
                delete pair;
            }
        }
    }

    /* Print hash map contents */
    void print() {
        for (Pair* pair : buckets) {
            if (pair == nullptr) {
                cout << "nullptr" << endl;
            }
            else if (pair == TOMBSTONE) {
                cout << "TOMBSTONE" << endl;
            }
            else {
                cout << pair->key << " -> " << pair->val << endl;
            }
        }
    }
};
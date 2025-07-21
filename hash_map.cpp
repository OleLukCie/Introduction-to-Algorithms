#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> userMap;

    userMap[12836] = "Alice";
    userMap[15937] = "Bob";
    userMap[16750] = "Chambers";
    userMap[13276] = "Deil";
    userMap[10583] = "Eve";

    int queryKey = 15937;
    if (userMap.find(queryKey) != userMap.end()) {
        string userName = userMap[queryKey];
        cout << "User with key " << queryKey << " is " << userName << endl;
    }
    else {
        cout << "User with key " << queryKey << " not found." << endl;
    }

    int removeKey = 10583;
    userMap.erase(removeKey);

    if (userMap.find(removeKey) == userMap.end()) {
        cout << "Key " << removeKey << " has been removed." << endl;
    }

    return 0;
}
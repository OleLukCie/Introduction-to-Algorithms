#include <iostream>

int main() {
	int num = 3;
	size_t hashNum = std::hash<int>()(num);

	bool bol = true;
	size_t hashBol = std::hash<bool>()(bol);

	double dec = 3.14159;
	size_t hashDec = std::hash<double>()(dec);

	std::string str = "algo";
	size_t hashStr = std::hash<std::string>()(str);

	std::cout << "Hash of int " << num << ": " << hashNum << std::endl;
	std::cout << "Hash of bool " << bol << ": " << hashBol << std::endl;
	std::cout << "Hash of double " << dec << ": " << hashDec << std::endl;
	std::cout << "Hash of string " << str << ": " << hashStr << std::endl;
}
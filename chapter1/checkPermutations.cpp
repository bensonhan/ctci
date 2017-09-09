//	1.2	Check Permutation: 
//	Given two strings, write a method to decide if one is a permutation of the other

#include <iostream>

using namespace std;

bool checkPermutation(string first, string second);

int main() {
	cout << checkPermutation("sabrina", "brinasa") << endl;
	cout << checkPermutation("benson", "sabrina") << endl;
	cout << checkPermutation("benson", "nesnob") << endl;
	cout << checkPermutation("gazebo", "placebo") << endl;
	cout << checkPermutation("rfbaeghralejgea", "arhfejgarlaebg") << endl;
}

bool checkPermutation(string first, string second) {
	int firstLetters[26];
	int secondLetters[26];
	bool check = true;
	int difference; 
	for (size_t i = 0; i < first.length(); i++) {
		firstLetters[first[i] - 97]++;
	}
	for (size_t i = 0; i < second.length(); i++) {
		secondLetters[second[i] - 97]++;
	}
	for (size_t i = 0; i < 26; i++) {
		if (firstLetters[i] != secondLetters[i]) {
			check = false;
			difference = firstLetters[i] - secondLetters[i];
			if (difference > 0) {
				cout << "in first and not second: ";
				for (size_t j = 0; j < difference; j++) {
					 cout << char(i + 97);
				}
				cout << endl;
			}
			else if (difference < 0) {
				cout << "in second and not first: ";
				for (size_t j = 0; j > difference; j--) {
					 cout << char(i + 97);
				}
				cout << endl;
			}
		}
	}
	return check;
}
#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 64;

class LinkedHashEntry {
private:
	int key;
	int value;
	LinkedHashEntry *next;
public:
	LinkedHashEntry(int key, int value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
	int getKey() {
		return key;
	}
	int getValue() {
		return value;
	}
	LinkedHashEntry* getNext() {
		return next;
	}
	void setNext(LinkedHashEntry *next) {
		this->next = next;
	}
};

class HashMap {
private:
	LinkedHashEntry **table;
public:
	HashMap() {
		table = new LinkedHashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++) {
			table[i] = NULL;
		}
	}
	int get(int key) {
		int hash = (key % TABLE_SIZE);
		if (table[hash] == NULL) {
			return -1;
		}
		else {
			LinkedHashEntry *entry = table[hash];
			while (entry != NULL && entry->getKey() != key) {
				entry = entry->getNext();
			}
			if (entry == NULL) {
				return -1;
			}
			else {
				return entry->getValue();
			}
		}
	}
	void put(int key, int value) {
		int hash = (key % TABLE_SIZE);
		if (table[hash] == NULL) {
			table[hash] = new LinkedHashEntry(key, value);
		}
		else {
			LinkedHashEntry* entry = table[hash];
			while (entry->getNext() != NULL) {
				entry = entry->getNext();
			}
			entry->setNext(new LinkedHashEntry(key, value));
		}
	}
	void remove(int key) {
		int hash = (key % TABLE_SIZE);
		LinkedHashEntry* previous = NULL;
		LinkedHashEntry* current = table[hash];
		while (current->getNext() != NULL && current->getKey() != key) {
			previous = current;
			current = current->getNext();
		}
		if (current->getKey() == key) {
			if (previous == NULL) {
				table[hash] = current->getNext();
				delete current;
			}
			else {
				previous->setNext(current->getNext());
				delete current;
			}
		}
	}
	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (table[i] != NULL) {
				LinkedHashEntry* previous = NULL;
				LinkedHashEntry* current = table[i];
				while (current != NULL) {
					previous = current;
					current = current->getNext();
					delete previous;
				}
			}
		}
		delete[] table;
	}
};

bool isUnique(string word);

int main() {
	cout << isUnique("bobby") << endl;
	cout << isUnique("benson") << endl;
	cout << isUnique("sabrina") << endl;
	cout << isUnique("top") << endl;
}

bool isUnique(string word) {
	bool letters[26];
	for (int i = 0; i < 26; i++) {
		letters[i] = false;
	}
	for (size_t i = 0; i < word.length(); i++) {
		if (!letters[word[i] - 97]) {
			letters[word[i] - 97] = true;
		}
		else if (letters[word[i] - 97]) {
			return false;
		}
	}
	return true;
}
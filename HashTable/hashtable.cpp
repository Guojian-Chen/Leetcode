#include<string>
#include<iostream>

using namespace std;

class HashEntry {
private:
      string key;
      int value;

public:
      HashEntry(string key, int value) {
            this->key = key;
            this->value = value;
      }
      string getKey() {
            return key;
      }
 
      int getValue() {
            return value;
      }
};

const int TABLE_SIZE = 128;

class HashMap {

private:
	HashEntry *table[TABLE_SIZE];

public:
	HashMap() 
	{
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	int hash_func(string key) 
	{
		int mod = (std::hash<string>()(key)) % TABLE_SIZE;
		return mod < 0 ? mod + TABLE_SIZE : mod;
	}

	int findIndex(string key) {
		int index = hash_func(key);
		while (table[index] != NULL && 
			table[index]->getKey() != key) {
			index = (index + 1) % TABLE_SIZE;
		}
		return index;
	}

	int get(string key) 
	{
		int index = findIndex(key);
		return table[index] == NULL ? -1 : table[index]->getValue();
	}

	void put(string key, int value) 
	{
		table[findIndex(key)] = new HashEntry(key, value);
	}

	~HashMap() 
	{
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
	}
};

int main()
{
	HashMap myHash;
	myHash.put("adb", 1);
	myHash.put("mno", 2);
	myHash.put("xyz", 3);
	cout << "xyz is" << myHash.get("xyz") << endl;

}

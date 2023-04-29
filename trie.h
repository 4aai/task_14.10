#pragma once
#include <string>
#include <vector>

const size_t ALPHABET_SIZE = 33;

class trie
{
	trie* child_[ALPHABET_SIZE] = {};
	bool endOfWord_ = false;

public:
	std::vector<std::string> prefixes_;
	int prefCount = 0;

	trie();
	~trie();

	void Insert(trie* root, std::string word);
	bool Search(trie* root, std::string word);
	void FindAllPrefixes(trie* root, char* wordConstructor, int index, std::string const word);
};



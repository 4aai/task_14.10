#include "trie.h"

trie::trie()
{
    endOfWord_ = false;
    for (size_t i = 0; i < ALPHABET_SIZE; i++) child_[i] = nullptr;
}

trie::~trie() {}

void trie::Insert(trie* root, std::string word)
{
    trie* node = root;
    for (size_t i = 0; i < word.length(); i++)
    {

        int index = word[i] - 'à';
        if (index < 0) index += 32;

        if (!node->child_[index]) node->child_[index] = new trie;
        node = node->child_[index];
    }
    node->endOfWord_ = true;
}
 
bool trie::Search(trie* root, std::string word)
{
    trie* node = root;
    for (size_t i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'à';
        if (index < 0) index += 32;
        if (!node->child_[index]) return false;
        node = node->child_[index];
    }
    return true;
}

void trie::FindAllPrefixes(trie* root, char* wordConstructor, int index, std::string const prefix)
{
    if (!root) return;
 
    if (index == 0)
    {
        prefCount = 0;
        prefixes_.clear();
    }
    
    if (prefix.length() > index)
    {
        wordConstructor[index] = prefix[index];
        int i = wordConstructor[index] - 'à';
        if (i < 0) i += 32;
        FindAllPrefixes(root->child_[i], wordConstructor, index + 1, prefix);
    }
    else
    {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            if (root->child_[i] != nullptr)
            {
                wordConstructor[index - prefix.length()] = i + 'à';
                if (root->child_[i]->endOfWord_)
                {
                    wordConstructor[index + 1 - prefix.length()] = '\0';
                    prefixes_.emplace_back(std::string(wordConstructor));
                    prefCount++;
                }
                FindAllPrefixes(root->child_[i], wordConstructor, index + 1, prefix);
            }
        }
    }
    if (root->endOfWord_ && prefCount == 0)
    {
        prefixes_.emplace_back("");
        prefCount++;
    }
}





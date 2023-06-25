
#include "trie.h"
#include <iostream>


void PrintSuggestionAll(trie* root, const std::string& start_prefix )
{
    if (root->prefCount > 1)
    {
        for (size_t i = 0; i < root->prefCount; i++)
        {
            std::cout << "\033[101m" << start_prefix << "\033[44m" << root->prefixes_[i] << "\033[0m\n";
        }
         
    }
    std::cout << "\n";
}

int main()
{
    system("chcp 1251"); system("cls");
    trie* root = new trie;
    char buf[100] = {};
    std::string const words[] =
    {
        {"коллега"},        {"привет"},
        {"пока"},           {"спасибо"},
        {"семья"},          {"средство"},
        {"сделать"},        {"человек"},
        {"утилитарный"},    {"контент"},
        {"метать"},         {"рандомный"},
        {"обожать"},        {"созидать"},
        {"кофе"},           {"прийти"},
        {"протеже"},        {"эфемерный"},
        {"перманентно"},    {"эпичный"},
        {"работать"},       {"рецепт"},
    };
    for (auto& word : words){
        root->Insert(root, word);
    }
    std::string inputWord;
    
    while (inputWord != "exit")
    {
        std::cout << "введите слово или exit что бы выйти\n";
        std::cout << "ввод: "; std::cin >> inputWord;
        if (inputWord != "exit") {

        
            root->Insert(root, inputWord);

            if (root->Search(root, inputWord) && inputWord != "") {
                root->FindAllPrefixes(root, buf, 0, inputWord);
                PrintSuggestionAll(root, inputWord);
            }
            root->Insert(root, inputWord);
            inputWord.clear();
        }
    }
    
   

    delete root;
    return 0;
}

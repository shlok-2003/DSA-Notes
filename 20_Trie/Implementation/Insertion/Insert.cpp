#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    public:
        TrieNode(char ch) {
            data = ch;
            for(int i = 0; i < 26; i++)
                children[i] = NULL;
            isTerminal = false;
        }
};

class Trie {
    private:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode('\0');
        }

        //! Inserting 
        void insertUtil(TrieNode* root, string word) {
            if(word.length() == 0)
            {
                root -> isTerminal = true;
                return;
            }
            int idx = word[0] - 'A';

            if(root -> children[idx])
                insertUtil(root -> children[idx], word.substr(1));
            else    
            {
                root -> children[idx] = new TrieNode(word[0]);
                insertUtil(root -> children[idx], word.substr(1));
            }
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }
};

int main() {
    //! Assumption: Data is of capital letters

    Trie* t = new Trie();
    
    vector<string> arr = {"ABCD", "CODECHEF", "CODEFORCES", "SHLOK", "PRAJAPATI"};
    for(int i = 0; i < arr.size(); i++)
    {
        t -> insertWord(arr[i]);
        cout << arr[i] << " inserted" << endl;
    }
    
}
#include <iostream>
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

        //! Searching
        bool searchUtil(TrieNode* root, string word) {
            if(word.length() == 0)
                return root -> isTerminal;

            int idx = word[0] - 'A';

            if(root -> children[idx])
                return searchUtil(root -> children[idx], word.substr(1));
            else    
                return false;
        }

        bool searchWord(string word) {
            return searchUtil(root, word);
        }

        //! isEmpty
        bool isEmpty(TrieNode* root) {
            int count = 0;
            for(int i = 0; i < 26; i++)
                if(root -> children[i])
                    count++;

            return count <= 1;
        }

        //! Removing Method 1
        void removeUtil1(TrieNode* root, string word) {
            if(word.length() == 0)
            {
                //! Simply mark the last node of the desired word as false so that it cannot be found in Search Method. But it
                //! occupy space and it is not space efficient
                root -> isTerminal = false;         
                return;
            }

            int idx = word[0] - 'A';
            TrieNode* child;

            if(root -> children[idx])
                removeUtil1(root -> children[idx], word.substr(1));
            else    
                return;
        }

        void removeWord1(string word) {
            removeUtil1(root, word);
        }
};

int main() {
    //! Assumption: Data is of capital letters

    Trie* t = new Trie();
    t -> insertWord("ABCD");
    t -> insertWord("CODECHEF");
    t -> insertWord("CODEFORCES");
    t -> insertWord("SHLOK");
    t -> insertWord("PRAJAPATI");

    cout << "ABCD " << "Present or Not: " << t -> searchWord("ABCD") << endl << endl;

    t -> removeWord1("ABCD");
    cout << "After removing ABCD by Method 1" << endl;
    cout << "ABCD " << "Present or Not: " << t -> searchWord("ABCD") << endl << endl;

    cout << "CODECHEF " << "Present or Not: " << t -> searchWord("CODECHEF") << endl << endl;
}
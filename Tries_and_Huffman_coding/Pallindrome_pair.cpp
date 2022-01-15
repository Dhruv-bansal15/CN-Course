#include <iostream>
#include <unordered_map>
#include<algorithm>
#include <string>

using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
	bool isPalindrome(string str){
    	int len = str.length();
        for (int i = 0; i < len/2; i++ )
            if (str[i] != str[len-i-1])
                return false;

        return true;
	}
    bool isPalindromePair(vector<string> words) {
        if(words.size()==0){
            return false;
        }
        if(words.size()==1){
            return isPalindrome(words[0]);
        }
        for (int i = 0; i< words.size()-1; i++){
            for (int j = i+1; j< words.size() ; j++){
                string check_str="";
                check_str = words[i] + words[j];
                if (isPalindrome(check_str))
                    return true;
                check_str = words[j] + words[i];
                if (isPalindrome(check_str))
                    return true;
                check_str = words[j];
                if (isPalindrome(check_str))
                    return true;
                check_str = words[i];
                if (isPalindrome(check_str))
                    return true;
            }
    	}
    	return false;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        string s;cin>>s;
        words[i]=s;
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
#include<iostream>
using namespace std;
class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }

};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root= new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'A';
        TrieNode* child;
            // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent 
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // cout<<"kaam chlra hai \n";
        // recursion call krlo 
        insertUtil(child, word.substr(1));
    }
    void insert(string word){
        insertUtil(root, word);
        // cout<<"insert completed";
    }
    bool searchUtil(TrieNode* root, string word){
        // base condition
        if(word.length() == 0){
            return root->isTerminal;
        }
        // find index & assumption ye hai sb caps hai 
        int index = word[0] - 'A';
        TrieNode* child;
        // present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool search(string word){
        return searchUtil(root, word);
    }
};
int main(){
    Trie* t = new Trie();
    // cout<<"before inserting\n";
    t->insert("ABCD");
    // cout<<"after";
    cout<<"\nPresent or Not : "<< t->search("ABC");

    return 0;
}
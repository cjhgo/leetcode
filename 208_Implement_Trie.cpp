#include"struct_define.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 

struct TrieNode
{
  char ele;
  bool iskey;  
  TrieNode* children[26];
  TrieNode(char c):ele(c),iskey(false),children{nullptr}{};
};
class Trie 
{

private:
  TrieNode* root;  
public:
    /** Initialize your data structure here. */
    Trie() 
    {
      root = new TrieNode('\0');      
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
      TrieNode* ptr=root;
      for(char c : word)
      {
        size_t index = c - 'a';
        if( ptr->children[index] == nullptr)
        {
          ptr->children[index] = new TrieNode(c);
        }
        ptr = ptr->children[index];
      }
      ptr->iskey=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
      TrieNode* ptr=root;
      for(char c : word)
      {
        size_t index = c - 'a';
        if( ptr->children[index] != nullptr) 
        {
          ptr = ptr->children[index];
        }
        else return false;        
      }
      return ptr->iskey;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
      TrieNode* ptr=root;
      for(char c : prefix)
      {
        size_t index = c - 'a';
        if( ptr->children[index] != nullptr)
        {
          ptr = ptr->children[index];
        } 
        else return false;        
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char const *argv[])
{
  
  Trie* trie = new Trie();

  trie->insert("apple");
  std::cout<<std::endl<<trie->search("apple");   // returns true
  std::cout<<std::endl<<trie->search("app");     // returns false
  std::cout<<std::endl<<trie->startsWith("app"); // returns true
  trie->insert("app");   
  std::cout<<std::endl<<trie->search("app");     // returns true

  return 0;
}
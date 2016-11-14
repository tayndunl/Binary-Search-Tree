#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Node{

  // private:
 public:
  Node *left, *right, *current;
  string key;
  int data;

  // public:
  Node(int data);
  Node(string key, int data);
  ~Node();

};


class BST{

 private:
  Node *root;
  void set_Helper(Node *current,string s, int value);
  void print_Helper(Node *current);
  void destructor_Helper(Node *current);
  void remove_Helper(Node *current, int value);
  void min_Helper(Node *current);
  void max_Helper();

 public:
  BST();
  ~BST();
  void set(string s, int value);
  int find(string s);
  void print();
  void min();
  void max();
  void save_file(string fileName);
  void remove(string fileName);

};


#endif

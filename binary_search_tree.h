/*Author: Taylor Dunlap
 *Date: Nov 17, 2016
 *File: binary_search_tree.h
 *Description: BST & Node class header files
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Node{
  
 public:
  //pointers to the left, right, and current nodes
  Node *left, *right, *current;
  string key;
  int data;
  
  Node(string keyValue, int dataValue);
  /* Description:
   *   Defualt  Node constructor.  Initializes an empty node.
   *
   * Post-conditions:
   *    left, right, and current are null
   *    keyValue equals key, and dataValue = data
   */
  
  ~Node();
  /* Description:
   *    Destructor.  Deletes left and right nodes
   *
   * Postconditions:
   *   left and right are deleted and equal null
   */
  
};


class BST{
  
 private:
  Node *root;
  void set_Helper(Node *current,string s, int value);
  /* Description:
   *   helps the set function, using recursion 
   *
   * Parameters:
   *    *current - pointer to current node
   *    s - the string value to be stored
   *    value - the number to be stored
   *
   */
  
  void find_Helper();
  /* Description:
   *   helps the find function, using recursion 
   *
   */
  
  void print_Helper(Node *current);
  /* Description:
   *   helps the print function, using recursion 
   *
   *   *current - pointer to current node
   *
   */
  
  void destructor_Helper(Node *current);
  /* Description:
   *   helps the destructor function, using recursion 
   *
   *    *current - pointer to current node
   */
  
  void remove_Helper(Node* &current, int value);
  /* Description:
   *   helps the remove function, using recursion 
   *
   *    *current - pointer to current node address
   *    value - the number to be removed
   *
   */
  
  void min_Helper(Node *current);
  /* Description:
   *   helps the min function, using recursion 
   *
   *    *current - pointer to current node 
   *
   */
  
  void max_Helper(Node *current);
  /* Description:
   *   helps the max function, using recursion 
   *
   *    *current - pointer to current node 
   *
   */
  
  void save_file_Helper(Node *current, string fileName);
  /* Description:
   *   helps the save_file function, using recursion 
   *
   *    *current - pointer to current node
   *    fileName - name of file to save to 
   *
   */
  
 public:
  
  BST();
  /* Description:
   *   Defualt  BST constructor.  Initializes an empty tree.
   *
   * Post-conditions:
   *    root equals null
   */
  
  ~BST();
  /* Description:
   *    Destructor.  Deletes tree
   *
   * Postconditions:
   *  root equals null
   */
  
  void set(string s, int value);
  /* Description:
   *    stores a string and value in the BST, overwriting the current value if it is already in the tree
   *
   * Parameters:
   *    string - the string to be put in the tree
   *    value - a number to be associated with the string to be put in the tree
   *
   * Postconditions:
   *    the pair are stored in tree
   *
   */
  
  int find(string s);
  /* Description:
   *   takes an string parameter, and returns the value is already in the BST
   *
   * Parameters:
   *    string - the string value to be returned
   *
   * Postconditions:
   *    string value is returned
   *
   */
  
  
  void print();
  /* Description:
   *   prints the contents of the BST in order to the user as (key, value) pairs
   *
   * Postconditions:
   *   contents are printed
   *
   */
  
  void min();
  /* Description:
   *   finds and prints the smallest (leftmost) key in the tree
   *
   * Postconditions:
   *   smallest key is found and printed
   *
   */
  
  void max();
  /* Description:
   *   finds and prints the largest (rightmost) key in the tree
   *
   * Postconditions:
   *   largest key is found and printed
   *
   */
  
  void save_file(string fileName);
  /* Description:
   *   takes the name of a file as a parameter, and stores the contents of the tree in order in the file
   *
   * Parameters:
   *    fileName - the name of the file to be saved as
   *
   * Postconditions:
   *    a new file is saved with tree contents
   *
   */
  
  void remove(string s);
  /* Description:
   *   takes a string parameter, and removes the first instance of that value from the BST
   *
   * Parameters:
   *    s - the name of the first instance string in tree to be removed
   *
   * Postconditions:
   *    first instance of string is removed is removed
   *
   */

};


#endif  //BINARY_SEARCH_TREE_H

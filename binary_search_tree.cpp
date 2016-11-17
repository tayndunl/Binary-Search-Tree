/*Author: Taylor Dunlap
 *Date: Nov 17, 2016
 *File: binary_search_tree.cpp
 *Description: implements the BST & Node class header files
 */

#include <iostream>
#include <string>
#include <fstream>
#include "binary_search_tree.h"


Node::Node(string keyValue, int dataValue){

  left = NULL;
  right = NULL;
  data = dataValue;
  key = keyValue;
}


Node::~Node(){

  delete left;
  delete right;
}


BST::BST(){

  root = NULL;
}


BST::~BST(){

  //calls helper function
  destructor_Helper(root);
}


void BST::destructor_Helper(Node *current){

  //if the current node exists
  if(current != NULL){
    
    //calls helper functions
    destructor_Helper(current->left);
    destructor_Helper(current->right);

    //deletes current node
    delete current;
  }
}


void BST::set(string s, int value){

  //if first node doesn't exist, create a new node
  if(root != NULL){
    root = new Node(s, value);
  }
  else{
    //calls helper function
    set_Helper(root, s, value);
  }
}


void BST::set_Helper(Node *current, string s, int value){ 

  //if the value is smaller than the current integer in tree
  if(value < current->data){

    //if the current left node does not exist, create a new one
    if(current->left == NULL){
      current->left = new Node(s, value);
    }
    else{
      //calls helper function
      set_Helper(current->left,s ,value);
    }
  }
  
  else{

    //if the current right node does not exist, create a new one
    if(current->right == NULL){
      current->right = new Node(s, value);
      }
      else{
	//calls helper function
	set_Helper(current->right,s, value);
      }
    }
}


void BST::print(){
  
  //calls helper function
  print_Helper(root);
  cout << endl;
}


void BST::print_Helper(Node *current){

  //if the current node exists
  if(current != NULL){
    //calls helperfunction to the current left node in tree
    print_Helper(current->left);
    cout << current->data << " ";
    //calls helperfunction to the current right node in tree
    print_Helper(current->right);
  }
}


void BST::min(){
  
  //calls helper function
  min_Helper(root);
}


void BST::min_Helper(Node *current){

  //if the first node exists
  if(root != NULL){
    
    //if the current left node in tree exists
    if(current->left != NULL){
      //call helper function
      min_Helper(current->left);
    }
    
    //print out the smallest left most key
    cout << current->data << endl;
  }
}


void BST::max(){

  //calls helper function
  max_Helper(root);
}


void BST::max_Helper(Node *current){

  //if the first node exists
  if(root != NULL){

     //if the current right node in tree exists
    if(current->right != NULL){
      //call helper function
      max_Helper(current->right);
    }

    //print out the largest right most key
    cout << current->data << endl;
  }
}


void BST::save_file(string fileName){

  //calls helper functions
  save_file_Helper(root, fileName);
}


void BST::save_file_Helper(Node *current, string fileName){

  //makes file a text file from file name
  fileName.append(".txt");

  ofstream outFile;
  outFile.open(fileName.c_str());

  //if the first node does not exist, return
  if(root == NULL){
    return;
  }
  //otherwise write the tree to file
  else{
    outFile << current->data << " ";
    save_file_Helper(current->left, fileName);
    save_file_Helper(current->right, fileName);
  }

  //closes file
  outFile.close();   
}


void remove(Node* &current, string s){

  //remove_helper
}


void remove_Helper(Node* &current, int value){

  //If Node does not exist, returns
 if(current == NULL){
   return;
 }

 //If value is less than current node's value, go left
 if(value < current->data){
   remove_Helper(current->left, value);
}

 //If value is great than current node's value, go right
 if(value > current->data){
   remove_Helper(current->right,value);
 }

 //If current is a leaf node, delete current and then reassign it
 if(current->left == NULL && current->right == NULL){
   delete current;
   current = NULL;
 }
 
 //If no left subtree
 if(current->left == NULL){
   current = current->right;
 }
 
 //If no right subtree
 if(current->right == NULL){
   current = current->left;
 }
 /*
 //If left and right subtrees exist
 if(current->right && current->left != NULL){
   max_Helper(current->left);
   delete   }
 
 */
} 


   
 
 

 

 

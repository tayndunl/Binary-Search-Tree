#include <iostream>
#include <string>
#include <fstream>
#include "binary_search_tree.h"

Node::Node(string key, int data){

  left = NULL;
  right = NULL;
  // data = key;
}

Node::~Node(){

  delete left;
  delete right;
}


BST::BST(){

  root = NULL;
}


BST::~BST(){

  destructor_Helper(root);
}


void BST::destructor_Helper(Node *current){

  if(current != NULL){
    destructor_Helper(current->left);
    destructor_Helper(current->right);
    delete current;
  }
}

void BST::set(string s, int value){

  if(root != NULL){
    root = new Node(s, value);
  }
  else{
    set_Helper(root,s,value);
  }

  cout << root;
}

void BST:: set_Helper(Node *current, string s, int value){ 

  if(value < current->data){

    if(current->left == NULL){
      current->left = new Node(s, value);
    }
    else{
      set_Helper(current ->left,s,value);
    }
  }
  
  else{
      
    if(current->right == NULL){
      current->right = new Node(s,value);
      }
      else{
	set_Helper(current->right,s, value);
      }
    }
}


void BST::print(){

  print_Helper(root);
  cout << endl;
}


void BST::print_Helper(Node *current){

  if(current != NULL){
    print_Helper(current->left);
    cout << current->data << " ";
    print_Helper(current->right);
  }
}


void BST::min(){

  min_Helper(root);
}


void BST::min_Helper(Node *current){

  if(root != NULL){

    if(current->left != NULL){
      min_Helper(current->left);
    }

    cout << current->data << " ";
  }
}



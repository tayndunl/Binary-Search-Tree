#include <iostream>
#include <string>
#include <fstream>
#include "binary_search_tree.h"

using namespace std;

int main(){

  BST tree;

  tree.set("the",5);
  tree.set("best",2);
  tree.set("of",4);
  tree.set("times",7);

  tree.print();

  return 0;

}

#include "node.hpp"

node::node (node* childL, node* childR){
  this.child_ptr.push_back(childL);
  this.child_ptr.push_back(childR);
  this.hash_str = childL->getHash() + childR->getHash();
}

node::node (string hash_str){
  this.hash_str = hash_str;
  this.child_ptr.push_back(NULL);
  this.child_ptr.push_back(NULL);
}

node* node::getChild(int pos){
  return this.child_ptr[pos];
}

void node::setChild(node* child, int pos){
    this.child_ptr[pos] = child;
}

string node::getHash(){
    return this.hash_str;
}


virtual node::~node ();

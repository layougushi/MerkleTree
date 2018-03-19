#include "node.h"
#include "picosha2.h"


node::node (){
  this->parent = NULL;
  this->children[0] = NULL;
  this->children[1] = NULL;
}

void node::setHash(string hash_str){
  this->hash_str = picosha2::hash256_hex_string(hash_str);
}

node* node::getParent(){
  return this->parent;
}

void node::setParent(node* parent){
  this->parent = parent;
}

void node::setChildren(node* children_l, node* children_r){
  this->children[0] = children_l;
  this->children[1] = children_r;
}

node* node::getSibling(){
  node* parent = this->getParent();
  return parent->getChildren(0) == this ? parent->getChildren(1) : parent->getChildren(0);

}

node* node::getChildren(int index){
  return index <= 1 ? children[index] : NULL;
}

string node::getHash(){
    return this->hash_str;
}

int node::checkDir(){
  return parent->getChildren(0) == this ? 0 : 1;
}



node::~node () {}

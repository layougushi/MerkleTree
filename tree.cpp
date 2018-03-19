#include "tree.h"
#include <iostream>

tree::tree () {}


int tree::makeBinary(vector<node*> &node_vector){

  int vectSize = node_vector.size();

  if((vectSize%2) != 0){
    node_vector.push_back(node_vector.end()[-1]);
    vectSize++;
  }
  return vectSize;
}

void tree::buildTree(){

  do {
    vector<node*> new_nodes;
    makeBinary(this->base.end()[-1]);

    for (int i = 0; i < this->base.end()[-1].size(); i = i+2) {
      node* new_parent = new node;
      this->base.end()[-1][i]->setParent(new_parent);
      this->base.end()[-1][i+1]->setParent(new_parent);

      new_parent->setHash(this->base.end()[-1][i]->getHash() + this->base.end()[-1][i+1]->getHash());
      new_parent->setChildren(this->base.end()[-1][i],this->base.end()[-1][i+1]);
      new_nodes.push_back(new_parent);
      std::cout << "Hash together: " << this->base.end()[-1][i]->getHash() << " and " << this->base.end()[-1][i+1]->getHash() << " attached: " << &new_parent << endl;
    }

    //printTreeLevel(new_nodes);

    this->base.push_back(new_nodes);
    std::cout << "Hashed level with: " << this->base.end()[-1].size() << '\n';

  } while(this->base.end()[-1].size() > 1);

  this->merkleRoot = this->base.end()[-1][0]->getHash();

}

void tree::printTreeLevel(vector<node*> v){

  cout << endl;

  for (node* el : v) {
      cout << el->getHash() << endl;
  }
}


void tree::buildBaseLeafes(vector<string> base_leafs){

  vector<node*> new_nodes;

  for (auto leaf : base_leafs){
    node* new_node = new node;
    new_node->setHash(leaf);
    new_nodes.push_back(new_node);
  }
  this->base.push_back(new_nodes);
}

string tree::getMerkleRoot() {
  return merkleRoot;
}


int tree::verify(string hash){

  node* el_node = NULL;
  string act_hash = hash;

  for (int i = 0; i < this->base[0].size(); i++) {
    if(this->base[0][i]->getHash() == hash)
      el_node = this->base[0][i];
  }

  do {

    if(el_node->checkDir() == 0)
      act_hash += el_node->getSibling()->getHash();
    else
      act_hash = el_node->getSibling()->getHash() + act_hash;

    el_node = el_node->getParent();
  }while ((el_node->getParent()) != NULL);

  return act_hash == merkleRoot ? 1 : 0;
}

void tree::iterateUp(int element){
  node* el_node = this->base[0][element];

  do {
    std::cout << "Current Hash: " << el_node->getHash() << '\n';
    /*std::cout << "Next Node: " << el_node << '\n';
    std::cout << "Next Parent: " << el_node->getParent() << '\n';*/
  }while ((el_node = el_node->getParent()) != NULL);
  //std::cout << "Done iterating" << '\n';
}

tree::~tree () {}

#include "tree.hpp"

tree::tree(std::vector<string> leaf){
  this.leafs = leaf;
}


int makeBinary(std::vector<*node> &node_vector){

  int vectSize = node_vector.size();

  if((node_vector.size()%2) != 0){
    node_vector.push_back(node_vector.back());
    vectSize++;
  }
  return vectSize;
}

void tree::buildTree(){
  buildBaseLeafes();

  std::vector<*node> act_work_vect = base_childs;
  printTreeLevel(act_work_vect, act_work_vect.size());

  for (int i = act_work_vect.size(); i >= 0; i/2) {
    std::vector<*node> next_vect;
    for (int j = 0; j < act_work_vect.size(); j+=2) {

      node childL = act_work_vect[0];
      node childR = act_work_vect[1];

      node *new_node = new node(&childL,&childR)

      next_vect.push_back(new_node);
    }

    i = makeBinary(next_vect);
    act_work_vect.swap(next_vect);
    printTreeLevel(act_work_vect, i);
  }
}


void printTreeLevel(vector<*node> v, int level){
  for (node* el : v) {
      cout << el->getHash() << endl;
  }
  cout << level << endl << endl;
}


void tree::buildBaseLeafes(){

  for (auto leaf : leafs){
    base_childs.push_back(leaf);
  }
}


virtual tree::~tree();

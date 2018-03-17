#include "node.h"


using namespace std;

class tree{
private:
  vector<string> leafs;
  string merkleRoot;
  vector<node*> base_childs;
  void buildBaseLeafes();
  int makeBinary(std::vector<node*> node_vector);
  void printTreeLevel(vector<node*> v, int level);


public:
  tree(std::vector<string> leaf);
  void buildTree();
  string getMerkleRoot();
  virtual ~tree();
};

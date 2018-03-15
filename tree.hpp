#include "node.hpp"

using namespace std;

class tree{
private:
  vector<string> leafs;
  string merkleRoot;
  vector<node> base_childs;
  void buildBaseLeafes();
  int makeBinary(std::vector<*node> node_vector);

public:
  tree(std::vector<string> leaf);
  void buildTree();
  string getMerkleRoot() {return merkleRoot};
  virtual ~tree();
}

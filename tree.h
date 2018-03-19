#include "node.h"


using namespace std;

class tree{
private:
  string merkleRoot;
  int makeBinary(vector<node*> &node_vector);
  void printTreeLevel(vector<node*> v);
  vector<vector<node*>> base;

public:
  tree();
  void buildTree();
  string getMerkleRoot();
  void buildBaseLeafes(vector<string> base_leafs);
  void iterateUp(int element);
  int verify(string hash);
  virtual ~tree();
};

#include <string>
#include <vector>

using namespace std;

class node {
private:
  string hash_str;
  node* parent;
  node* children[2];

public:
  node ();
  node* getParent();
  void setChildren(node* children_l, node* children_r);
  node* getChildren(int index);
  void setParent(node* parent);
  string getHash();
  int checkDir();
  node* getSibling();
  void setHash(string hash_str);
  virtual ~node ();
};

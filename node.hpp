#include <string>
#include <vector>

using namespace std;

class node {
private:
  string hash_str;
  vector<node*> child_ptr;

public:
  node::node (node* childL, node* childR);
  node::node (string hash_str);
  node* getChild(int pos);
  string getHash();
  string setHash(string hash_str);
  virtual ~node ();
};

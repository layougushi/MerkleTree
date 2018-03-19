#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[]) {


  string check_str = "";

  cin >> check_str;

  std::vector<string> v;

  v.push_back("1");
  v.push_back("2");
  v.push_back("3");
  v.push_back("4");
  v.push_back("5");
  v.push_back("6");


  tree ntree;

  ntree.buildBaseLeafes(v);
  ntree.buildTree();

  std::cout << "Check if: " << check_str << " is contained in tree" << '\n';

  if(ntree.verify(check_str)){
    std::cout << "All Clear" << '\n';
  } else {
      std::cout << "Nope something is wrong" << '\n';
  }



  return 0;
}

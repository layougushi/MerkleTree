#include <iostream>
#include "tree.h"
#include "picosha2.h"

using namespace std;

int main(int argc, char const *argv[]) {


  string check_str = "";

  std::cout << "Enter Merkle Leafes: " << '\n';
  std::vector<string> v;

  while(1) {
    string str;
    std::cin >> str;
    if(str != ";")
      v.push_back(str);
    else
      break;
  }

  std::cout << "Enter Leaf to verify: " << '\n';

  cin >> check_str;

  check_str = picosha2::hash256_hex_string(check_str);


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

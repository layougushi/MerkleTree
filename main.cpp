#include <iostream>

#include "tree.hpp"


int main(int argc, char const *argv[]) {

  std::vector<string> v;

  v.push_back("1");
  v.push_back("2");
  v.push_back("3");
  v.push_back("4");
  v.push_back("5");
  v.push_back("6");

  tree tr(v);


  return 0;
}

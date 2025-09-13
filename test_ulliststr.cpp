#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr * list = new ULListStr();
  list->push_back("abc");
  list->push_back("def");
  list->push_front("ghi");
  list->pop_back();
  std::cout << list->front() << " " << list->back() << std::endl;
  list->pop_front();
  std::cout << list->front() << std::endl;
}

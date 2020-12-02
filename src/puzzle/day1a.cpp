#include<aoc2020/input/reader.h>
#include<iostream>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<int>();

  for(auto it = v.begin(); it != v.end() - 1; ++it) {
    for(auto jt = it + 1; jt != v.end(); ++jt) {
      if((*it + *jt) == 2020) {
        std::cout << *it * *jt  << std::endl;
        return 0;
      }
    }
  }
}


#include<aoc2020/input/reader.h>
#include<iostream>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<int>();

  for(auto it = v.begin(); it != v.end() - 2; ++it) {
    for(auto jt = it + 1; jt != v.end() - 1; ++jt) {
      for(auto kt = jt + 1; kt != v.end(); ++kt) {
        if((*it + *jt + *kt) == 2020) {
          std::cout << *it * *jt * *kt << std::endl;
          return 0;
        }
      }
    }
  }
}


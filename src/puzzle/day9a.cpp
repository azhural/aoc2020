#include<aoc2020/input/reader.h>
#include<iostream>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<int>();

  for(size_t i = 25; i < v.size(); ++i) {
    bool hit = false;
    for(size_t j = i - 25; (j < i - 1) && !hit; ++j) {
      for(size_t k = j + 1; k < i; ++k) {
        if((v.at(j) + v.at(k)) == v.at(i)) {
          hit = true;
          break;
        }
      }
    }
    if(!hit) {
      std::cout << v.at(i) << std::endl;
      break;
    }
  }
}


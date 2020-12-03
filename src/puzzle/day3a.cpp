#include<aoc2020/input/reader.h>
#include<iostream>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  unsigned int cnt = 0;

  size_t idx = 0;

  for(const auto& s : v) {
    if(s.at(idx) == '#') ++cnt;

    idx += 3;
    if(idx >= s.size()) idx -= s.size();
  }

  std::cout << cnt << std::endl;

}


#include<aoc2020/input/reader.h>
#include<iostream>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  std::vector<std::pair<size_t, size_t>> slopes {{1,1}, {3,1}, {5,1}, {7,1}, {1,2}};

  unsigned long product = 1;

  for(const auto& slope : slopes) {
    unsigned int cnt = 0;
    size_t idx = slope.first;

    for(auto it = v.begin() + 1; it != v.end(); ++it) {
      if(std::distance(v.begin(), it) % slope.second != 0) continue;
      if(it->at(idx) == '#') ++cnt;

      idx += slope.first;
      if(idx >= it->size()) idx -= it->size();
    }

    std::cout << cnt << std::endl;
    product *= cnt;
  }
  std::cout << product << std::endl;
}


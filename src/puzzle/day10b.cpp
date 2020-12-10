#include<aoc2020/input/reader.h>
#include<algorithm>
#include<iostream>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<int>();
  v.push_back(0);
  std::sort(v.begin(), v.end());
  v.push_back(v.back() + 3);

  std::vector<size_t> paths {1};

  for(auto it = v.rbegin() + 1; it != v.rend(); ++it) {
    size_t sum = 0;
    for(size_t i = 1; i <= 3; ++i) {
      if(std::distance(v.rbegin(), it) < i) {
        break;
      }
      auto elem_to_check = it - i;
      if(*elem_to_check - *it <= 3) sum += paths.at(std::distance(v.rbegin(), elem_to_check));
    }
    paths.push_back(sum);
  }
  std::cout << paths.back() << std::endl;
}


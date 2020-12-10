#include<aoc2020/input/reader.h>
#include<algorithm>
#include<iostream>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<int>();
  v.push_back(0);
  std::sort(v.begin(), v.end());
  v.push_back(v.back() + 3);

  size_t one_cnt = 0;
  size_t three_cnt = 0;

  for(auto it = v.begin(); it != v.end() - 1; ++it) {
    auto diff = *(it + 1) - *it;
    if(diff == 1) ++one_cnt;
    else if(diff == 3) ++three_cnt;
  }
  std::cout << one_cnt * three_cnt << std::endl;
}


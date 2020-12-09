#include<aoc2020/input/reader.h>
#include<algorithm>
#include<iostream>
#include<numeric>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<int>();

  int target = 0;

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
      target = v.at(i);
      break;
    }
  }

  for(auto it = v.begin(); it != v.end(); ++it) {
    for(auto to_it = it; to_it != v.end(); ++to_it) {
      int sum = std::accumulate(it, to_it, 0);
      if(sum > target) break;
      if(sum == target) {
        std::vector<int> subvec (it, to_it);
        std::sort(subvec.begin(), subvec.end());
        std::cout << subvec.front() + subvec.back() << std::endl;
        return 0;
      }
    }
  }
}


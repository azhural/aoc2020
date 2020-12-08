#include<aoc2020/input/reader.h>
#include<iostream>
#include<set>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  unsigned int sum = 0;
  std::set<char> yes_answers;
  for(auto it = v.begin(); it != v.end(); ++it) {
    if(it->empty() || it == v.end() - 1) {
      sum += yes_answers.size();
      yes_answers.clear();
      continue;
    }
    for(const auto& c : *it){
      yes_answers.insert(c);
    }
  }

  std::cout << sum << std::endl;
}


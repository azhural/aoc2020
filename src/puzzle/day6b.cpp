#include<aoc2020/input/reader.h>
#include<iostream>
#include<map>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  unsigned int sum = 0;
  std::map<char, unsigned int> yes_answers;
  unsigned int cnt = 0;
  for(auto it = v.begin(); it != v.end(); ++it) {
    if(it->empty() || it == v.end() - 1) {
      for(auto mit = yes_answers.begin(); mit != yes_answers.end(); ++mit){
        if(mit->second == cnt) ++sum;
      }
      yes_answers.clear();
      cnt = 0;
      continue;
    }
    ++cnt;
    for(const auto& c : *it){
      auto answer_count = yes_answers.find(c);
      if(answer_count != yes_answers.end()) answer_count->second++;
      else yes_answers.insert({c, 1});
    }
  }
  std::cout << sum << std::endl;
}


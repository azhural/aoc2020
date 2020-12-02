#include<aoc2020/input/reader.h>
#include<iostream>
#include<regex>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  unsigned int cnt = 0;

  char delim = ' ';
  for(const auto& s : v) {
    std::string occ_range, req_char, password;
    std::regex rgx("(\\d+)-(\\d+)\\s+([a-z]):\\s+([a-z]+)");
    std::smatch matches;

    if(std::regex_search(s, matches, rgx) && matches.size() == 5) {
      int lower_limit = std::stoi(matches.str(1));
      int upper_limit = std::stoi(matches.str(2));

      size_t char_cnt = 0;
      for(const auto&c : matches.str(4)) if(matches.str(3).at(0) == c) ++char_cnt;
      if(char_cnt <= upper_limit && char_cnt >= lower_limit) ++cnt;
    }
  }

  std::cout << cnt << std::endl;

}


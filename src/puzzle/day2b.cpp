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
      int idx_0 = std::stoi(matches.str(1)) - 1;
      int idx_1 = std::stoi(matches.str(2)) - 1;

      char c = matches.str(3).at(0);
      if((c == matches.str(4).at(idx_0)) != (c == matches.str(4).at(idx_1))) ++cnt;
    }
  }

  std::cout << cnt << std::endl;

}


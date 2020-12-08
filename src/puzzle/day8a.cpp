#include<aoc2020/input/reader.h>
#include<iostream>
#include<regex>
#include<set>


int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  std::regex rgx("(nop|acc|jmp) ([+-]\\d+)");
  std::smatch matches;

  std::set<size_t> visited_instructions;
  int acc = 0;

  auto it = v.begin();
  while(it != v.end()) {
    size_t instruction = std::distance(v.begin(), it);
    if(visited_instructions.find(instruction) != visited_instructions.end()) break;
    visited_instructions.insert(instruction);

    std::regex_search(*it, matches, rgx);

    if(matches.str(1) == "nop") ++it;
    else if(matches.str(1) == "jmp") it += std::stoi(matches.str(2));
    else if(matches.str(1) == "acc") {
      acc += std::stoi(matches.str(2));
      ++it;
    }
  }
  std::cout << acc << std::endl;
}


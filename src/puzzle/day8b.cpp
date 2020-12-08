#include<aoc2020/input/reader.h>
#include<iostream>
#include<regex>
#include<set>


int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v_orig = r.get<std::string>();

  std::regex rgx("(nop|acc|jmp) ([+-]\\d+)");
  std::smatch matches;


  for(size_t i = 0; i < v_orig.size(); ++i) {
    auto v = v_orig;
    std::regex_search(v.at(i), matches, rgx);
    if(matches.str(1) == "acc") continue;
    else if(matches.str(1) == "jmp") v.at(i) = "nop " + matches.str(2);
    else if(matches.str(1) == "nop") v.at(i) = "jmp " + matches.str(2);

    bool aborted = false;
    int acc = 0;
    std::set<size_t> visited_instructions;
    auto it = v.begin();
    while(it != v.end()) {
      size_t instruction = std::distance(v.begin(), it);
      if(visited_instructions.find(instruction) != visited_instructions.end()) {
        aborted = true;
        break;
      }
      visited_instructions.insert(instruction);

      std::regex_search(*it, matches, rgx);

      if(matches.str(1) == "nop") ++it;
      else if(matches.str(1) == "jmp") it += std::stoi(matches.str(2));
      else if(matches.str(1) == "acc") {
        acc += std::stoi(matches.str(2));
        ++it;
      }
    }
    if(!aborted) std::cout << acc << std::endl;
  }
}


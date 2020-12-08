#include<aoc2020/input/reader.h>
#include<iostream>
#include<limits>
#include<regex>


int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  std::regex rgx("([FB]{7})([LR]{3})");
  std::smatch matches;

  int highest_id = std::numeric_limits<int>::min();

  std::vector<int> ids;

  for(const auto& s : v) {
    std::regex_search(s, matches, rgx);
    int row_low = 0;
    int row_high = 127;
    int column_low = 0;
    int column_high = 7;

    for(const auto& c : matches.str(1)){
      auto partition = (row_high - row_low) / 2 + row_low;
      if(c == 'F') row_high = partition;
      else if(c == 'B') row_low = partition + 1;
    }

    for(const auto& c : matches.str(2)){
      auto partition = (column_high - column_low) / 2 + column_low;
      if(c == 'L') column_high = partition;
      else if(c == 'R') column_low = partition + 1;
    }

    int id = row_low * 8 + column_low;
    ids.push_back(id);
  }

  std::sort(ids.begin(), ids.end());
  for(auto it = ids.begin(); it != ids.end() - 1; ++it) {
    if(*(it + 1) == (*it) + 2){
      auto seat_id = (*it) + 1;
      std::cout << seat_id << " " << seat_id / 8 << " " << seat_id % 8 << std::endl;
      break;
    }
  }
}


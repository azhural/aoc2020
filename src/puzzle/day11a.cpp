#include<aoc2020/input/reader.h>
#include<iostream>

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  const char floor = '.';
  const char occupied = '#';
  const char empty = 'L';

  for(auto & s : v) {
    s.insert(s.begin(), floor);
    s.push_back(floor);
  }
  size_t cols = v.at(0).size();
  const std::string floor_row(cols, floor);
  v.insert(v.begin(), floor_row);
  v.push_back(floor_row);
  size_t rows = v.size();

  while(true) {
    std::vector<std::string> new_state;
    new_state.push_back(floor_row);

    for(size_t r = 1; r < rows - 1; ++r) {
      std::string new_row (1, floor);
      for(size_t c = 1; c < cols - 1; ++c) {
        const auto& seat = v.at(r).at(c);
        if(seat == floor) {
          new_row.push_back(floor);
          continue;
        }

        size_t neighbors = 0;
        for(int i = -1; i <= 1; ++i) {
          for(int j = -1; j <= 1; ++j) {
            if(i == 0 && j == 0) continue;
            if(v.at(r + i).at(c + j) == occupied) ++neighbors;
          }
        }

        if(seat == empty && neighbors == 0) new_row.push_back(occupied);
        else if(seat == occupied && neighbors >= 4) new_row.push_back(empty);
        else new_row.push_back(seat);
      }
      new_row.push_back(floor);
      new_state.push_back(new_row);
    }
    new_state.push_back(floor_row);

    if(new_state == v) break;
    v = new_state;
  }

  size_t cnt = 0;
  for(const auto& row : v) {
    for(const auto& col : row) {
      if(col == occupied) ++cnt;
    }
  }

  std::cout << cnt << std::endl;
}


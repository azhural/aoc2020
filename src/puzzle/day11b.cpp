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
        std::vector<std::pair<int, int>> directions {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        for(auto direction : directions) {
          size_t vp_r = r;
          size_t vp_c = c;
          while(true) {
            vp_r += direction.second;
            vp_c += direction.first;

            if(vp_r == 0 || vp_r == rows - 1 || vp_c == 0 || vp_c == cols - 1) break;

            const auto& viewpoint = v.at(vp_r).at(vp_c);
            if(viewpoint == floor) continue;
            if(viewpoint == occupied) {
              ++neighbors;
            }
            break;
          }
        }

        if(seat == empty && neighbors == 0) new_row.push_back(occupied);
        else if(seat == occupied && neighbors >= 5) new_row.push_back(empty);
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


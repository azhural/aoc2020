#include<aoc2020/input/reader.h>
#include<stdexcept>

namespace aoc {
  namespace input {

    Reader::Reader(const std::string& file) {
      fs.open(file);
      if(!fs.is_open()) throw std::runtime_error("Unable to open file.");
    }
  }
}

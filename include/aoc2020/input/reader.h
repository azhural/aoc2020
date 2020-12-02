#pragma once

#include<fstream>
#include<sstream>
#include<string>
#include<vector>

namespace aoc {
  namespace input {

    class Reader {
      public:
        Reader(const std::string& file);

        template<class T>
          std::vector<T> get();

      private:
        std::ifstream fs;
    };

    template<class T>
      std::vector<T> Reader::get() {
        std::vector<T> v;
        std::string s;
        T value;
        while(std::getline(fs, s)) {
          std::stringstream iss{s};
          iss >> value;
          v.push_back(value);
        }

        return v;
      }

    template<>
      inline std::vector<std::string> Reader::get<std::string>() {
        std::vector<std::string> v;
        std::string s;
        while(std::getline(fs,s)) {
          v.push_back(s);
        }
        return v;
      }
  }
}



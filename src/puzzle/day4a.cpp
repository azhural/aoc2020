#include<aoc2020/input/reader.h>
#include<iostream>
#include<regex>

enum Fields {BYR=1<<0, IYR=1<<1, EYR=1<<2, HGT=1<<3, HCL=1<<4, ECL=1<<5, PID=1<<6, CID=1<<7};

int main(int argc, char** argv) {
  aoc::input::Reader r{argv[1]};

  auto v = r.get<std::string>();

  uint8_t valid_mask = Fields::BYR | Fields::IYR | Fields::EYR | Fields::HGT | Fields::HCL | Fields::ECL | Fields::PID;

  std::regex byr("byr:");
  std::regex iyr("iyr:");
  std::regex eyr("eyr:");
  std::regex hgt("hgt:");
  std::regex hcl("hcl:");
  std::regex ecl("ecl:");
  std::regex pid("pid:");
  std::regex cid("cid:");
  std::smatch matches;

  std::vector<uint8_t> passports {0};

  for(const auto& s : v) {
    if(s.empty()) {
      passports.push_back(0);
      continue;
    }
    if(std::regex_search(s, matches, byr)) passports.back() |= Fields::BYR;
    if(std::regex_search(s, matches, iyr)) passports.back() |= Fields::IYR;
    if(std::regex_search(s, matches, eyr)) passports.back() |= Fields::EYR;
    if(std::regex_search(s, matches, hgt)) passports.back() |= Fields::HGT;
    if(std::regex_search(s, matches, hcl)) passports.back() |= Fields::HCL;
    if(std::regex_search(s, matches, ecl)) passports.back() |= Fields::ECL;
    if(std::regex_search(s, matches, pid)) passports.back() |= Fields::PID;
    if(std::regex_search(s, matches, cid)) passports.back() |= Fields::CID;
  }

  size_t cnt = 0;
  for(const auto& passport : passports) {
    if((passport & valid_mask) == valid_mask) ++cnt;
  }
  std::cout << cnt << std::endl;
}


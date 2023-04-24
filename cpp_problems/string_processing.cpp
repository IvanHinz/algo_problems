#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
  std::unordered_map < char, int > first_map;
  bool flag = true;
  std::string str, str2;

  std::getline(std::cin, str);

  for (const char & s: str) {
    if (s != ' ') {
      ++first_map[tolower(s)];
    }
  }

  std::getline(std::cin, str2);
  for (const char & s: str2) {
    if (s != ' ') {
      --first_map[tolower(s)];
    }
  }

  for (std::pair < char, int > element: first_map) {
    if (element.second != 0) {
      std::cout << "No";
      flag = false;
      break;
    }
  }

  if (flag) std::cout << "Yes";
}

#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
  int length, first_ind, second_ind; //initial indices
  std::vector < int > main_vec;
  std::unordered_map < int, int > sol_map; //unordered_map for making check's with O(1)
  std::cin >> length;

  for (int i = 0; i < length; ++i) {
    int value;
    std::cin >> value;
    main_vec.push_back(value);
    sol_map[value] = i + 1;
  }

  std::cin >> first_ind;
  std::cin >> second_ind;

  int sum = main_vec[first_ind] + main_vec[second_ind];

  for (int i = 0; i < main_vec.size(); ++i) {
    //for checking if there is a pair for element to make a sum;
    if (sol_map[sum - main_vec[i]] != 0 && i != first_ind && i != second_ind) {
      first_ind = i;
      second_ind = --sol_map[sum - main_vec[i]];
      break;
    }
  }

  std::cout << first_ind << " " << second_ind;
}

#include <iostream>
#include <vector>

//creating vector
std::vector < int > CreateVector(int number) {
  std::vector < int > main_vec;
  for (int i = 0; i < number; ++i) {
    int value;
    std::cin >> value;
    main_vec.push_back(value);
  }
  return main_vec;
}

//searching for borders
void Search(std::vector < int > main_vec, int sr_value) {
  int l = 0, r = main_vec.size(), mid = 0;
  bool found = false;
  //for left corner;
  while ((l <= r) && (found != true)) {
    mid = (l + r) / 2;

    if (main_vec[mid] == sr_value) found = true;
    if (main_vec[mid] > sr_value) r = mid - 1;
    else l = mid + 1;
  }

  int left_number = mid, right_number = mid;
  
  if (left_number - 1 >= 0){
    while (main_vec[left_number - 1] == sr_value) {
    --left_number;
    }
  }
  while (main_vec[right_number + 1] == sr_value) {
    ++right_number;
  }
  if (found == false) {
    std::cout << -1 << " " << -1;
  } else {
    left_number = mid, right_number = mid;
    while (main_vec[left_number - 1] == sr_value) {
      --left_number;
    }
    while (main_vec[right_number + 1] == sr_value) {
      ++right_number;
    }
    std::cout << left_number << " " << right_number;
  }

}

int main() {
  std::vector < int > main_vec;
  int num_elem, sr_value;
  std::cin >> num_elem;
  main_vec = CreateVector(num_elem);
  std::cin >> sr_value;
  Search(main_vec, sr_value);
}
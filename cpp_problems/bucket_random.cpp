#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <algorithm>

class LotteryBox {
  public:

    bool insert(std::string s) {
      if (_container[s] == true) {
        return false;
      } else {
        _container[s] = true;
        _rand_con.insert(s);
        return true;
      }
    }

  bool remove(std::string s) {
    if (_container[s] == false) {
      return false;
    } else {
      _container[s] = false;
      _rand_con.erase(s);
      return true;
    }

  }

  std::string takeWinner() {
    if (_rand_con.empty()) {
      return "0";
    };
    int rand_buckets = _rand_con.bucket_count();
    int choose_bucket = rand() % rand_buckets;
    int size_bucket = 0;

    for (int i = 0; i < rand_buckets; ++i) {
      int size_bucket = _rand_con.bucket_size(choose_bucket);
      if (size_bucket > 0)
        break;

      choose_bucket = (choose_bucket + 1) % rand_buckets;
    }

    int ind = rand() % (size_bucket - 1);

    auto it = _rand_con.cbegin(choose_bucket);

    for (int i = 0; i < ind; ++i) {
      it++;
    }

    return *it;
  }

  private:
    std::unordered_map < std::string, bool > _container;
  //our container
  std::unordered_set < std::string > _rand_con;
};

int main() {
  std::string symb;
  LotteryBox monBox;
  while (std::cin >> symb && symb != "q") {
    if (symb == "+") {
      std::string name;
      std::cin >> name;
      if (monBox.insert(name)) std::cout << "true" << std::endl;
      else std::cout << "false" << std::endl;
    } else if (symb == "-") {
      std::string name;
      std::cin >> name;
      if (monBox.remove(name)) std::cout << "true" << std::endl;
      else std::cout << "false" << std::endl;
    } else if (symb == "?") {
      std::cout << monBox.takeWinner() << std::endl;
    }
  }
}
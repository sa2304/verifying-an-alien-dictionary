#include <cassert>
#include <string_view>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool charLess(char lhs, char rhs, string_view order) {
    return order.find(lhs) < order.find(rhs);
  }

  bool wordLessOrEq(string_view lhs, string_view rhs, string_view order) {
    while (not lhs.empty() and not rhs.empty()) {
      char l = lhs.front();
      char r = rhs.front();
      if (l != r) {
//        std::cout << l << " < "s << r << " is "s << charLess(l, r, order) << endl;
        return charLess(l, r, order);
      }
      lhs.remove_prefix(1);
      rhs.remove_prefix(1);
    }

    return lhs.empty();
  }

 public:
  bool isAlienSorted(vector<string> &words, string order) {
    for (int i = 0; i + 1 < words.size(); ++i) {
      if (not wordLessOrEq(words[i], words[i + 1], order)) {
        return false;
      }
    }

    return true;
  }
};

void TestIsAlienSorted() {
  Solution s;
  {
    {
      vector<string> words{"hello"s, "leetcode"s};
      assert(s.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz"s));
    }
    {
      vector<string> words{"word"s, "world"s, "row"s};
      assert(not s.isAlienSorted(words, "worldabcefghijkmnpqstuvxyz"s));
    }
    {
      vector<string> words{"apple"s, "app"s};
      assert(not s.isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz"s));
    }
  }
}

int main() {
  TestIsAlienSorted();
  cout << "Ok!"s << endl;
  return 0;
}
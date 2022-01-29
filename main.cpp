#include <cassert>
#include <string_view>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    // FIXME
    return false;
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
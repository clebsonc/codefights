#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
  int max = 0;
  std::unordered_map<int, std::vector<std::string>> hash_size;
  for (std::string word : inputArray){
    if (static_cast<int>(word.size()) >= max){
      max = static_cast<int>(word.size());
      auto it = hash_size.find(max);
      if (it == hash_size.end()){  // element not in the hash
        std::vector<std::string> v = {word};
        hash_size.emplace(max, v);
      } else {
        hash_size[max].push_back(word);
      }
    }
  }
  return hash_size.at(max);
}


int main(){
  int n = 0;
  std::cin >> n;
  std::vector<std::string> input_array(n);

  for (int i = 0; i < n; i++){
    std::cin >> input_array.at(i);
  }

  std::vector<std::string> long_strings = allLongestStrings(input_array);

  std::cout << "\nStrings: " << std::endl;
  for (std::string s : long_strings){
    std::cout << s << std::endl;
  }

  return 0;
}


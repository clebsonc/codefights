#include <iostream>
#include <string>
#include <unordered_map>


int commonCharacterCount(std::string s1, std::string s2){
  std::unordered_map<char, int> map;
  for (char c : s1){
    auto it = map.find(c);
    if (it == map.end()){
      map.emplace(c, 1);
    }
    else{
      it->second++;
    }
  }

  int common = 0;
  for (char c : s2){
    auto it = map.find(c);
    if (it != map.end()){  // character is common
      common++;
      it->second--;
      if (it->second == 0)
        map.erase(it);
    }
  }
  
  return common;
}



int main(){
  std::string a="", b="";

  std::cin >> a >> b;

  int common_characters = commonCharacterCount(a, b);
  
  std::cout << common_characters << std::endl;

  return 0;
}




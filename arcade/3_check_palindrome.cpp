#include <iostream>

bool checkPalindrome(std::string inputString) {
  for (int i = 0, j = inputString.size()-1; 
      i != j; i++, j--){
    if(i > j) break;
    if (inputString.at(i) != inputString.at(j)){
      return false;
    }
  }
  return true;
}


int main(){
  std::string s = "";
  std::cin >> s;

  bool is_palindrome = checkPalindrome(s);

  if (is_palindrome)
    std::cout << "Is palindrome." << std::endl;
  else
    std::cout << "Is not a palindrome." << std::endl;


  return 0;
}


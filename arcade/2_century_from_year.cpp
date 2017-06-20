#include <iostream>

int centuryFromYear(int year) {
  int century = year / 100;
  int rest = year % 100;
  return (rest == 0 ? century : century + 1);
}




int main(){
  int year = 0;
  std::cin >> year;
  std::cout << centuryFromYear(year) << std::endl;

  return 0;
}


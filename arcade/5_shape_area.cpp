#include <iostream>


int shapeArea(int n) {
  int area= 1;
  for (int i = 0; i < n; i++){
    area += i * 4;
  }
  return area;
}


int main(){
  int n = 0;
  std::cin >> n;

  std::cout << shapeArea(n) << std::endl;

  return 0;
}


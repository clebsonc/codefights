#include <iostream>
#include <vector>
#include <limits>


int adjacentElementsProduct(std::vector<int> inputArray) {
  int max = std::numeric_limits<int>::min();
  for (int i = 0; i < inputArray.size()-1; i++){
    int prod = inputArray.at(i) * inputArray.at(i+1);
    if (prod > max) max = prod;
  }
  return max;
}



int main(){
  int n = 0;
  std::cin >> n;

  std::vector<int> v(n, 0);


  for (int i = 0; i < n; i++){
    std::cin >> v.at(i);
  }

  int max = adjacentElementsProduct(v);
  
  std::cout << max << std::endl;

  return 0;
}


#include <iostream>
#include <vector>
#include <limits>

bool almostIncreasingSequence(std::vector<int> sequence) {
  int count = 0;
  int max1 = std::numeric_limits<int>::min();
  int max2 = std::numeric_limits<int>::min();

  for (auto val : sequence){
    if (val > max1){
      max2 = max1;
      max1 = val;
    }
    else if (val > max2){
      max1 = val;
      count++;
    }
    else{
      count++;
    }
  }
  return count < 2;
}



int main(){
  int n = 0;
  std::cin >> n;
  std::vector<int> v(n, 0);

  for (int i = 0; i < n; i++){
    std::cin >> v.at(i);
  }

  bool is_increase_sequence = almostIncreasingSequence(v);

  if (is_increase_sequence)
    std::cout << "Is increasing." << std::endl;
  else
    std::cout << "Is not increasing." << std::endl;

  return 0;
}


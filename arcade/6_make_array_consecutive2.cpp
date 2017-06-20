#include <iostream>
#include <vector>
#include <algorithm>

int makeArrayConsecutive2(std::vector<int> statues) {
  std::sort(statues.begin(), statues.end());
  int count = 0;
  for (int i = 1; i < static_cast<int>(statues.size()); i++){
    int diff = statues.at(i) - statues.at(i-1)-1;
    if (diff > 0){
      count += diff;
    }
  }
  return count;
}




int main(){
  int n = 0;
  std::cin >> n;
  std::vector<int> v(n, 0);
  for (int i = 0; i < n; i++){
    std::cin >> v.at(i);
  }

  int insertions = makeArrayConsecutive2(v);
  std::cout << insertions << std::endl;


  return 0;
}


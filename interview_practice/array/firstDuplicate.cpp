#include <iostream>
#include <vector>
#include <unordered_set>


int firstDuplicate(const std::vector<int> & a){
  std::unordered_set<int> set;

  for (int val : a){
    auto it = set.find(val);
    if (it == set.end()){
      set.emplace(val);
    }
    else{
      return val;
    }
  }
  return -1;
}


int main(){
  int n = 0;
  std::cin >> n;
  std::vector<int> v(n, 0);

  for (int i = 0; i < n; i++){
    std::cin >> v.at(i);
  }

  int fd = firstDuplicate(v);

  std::cout << fd << std::endl;


  return 0;
}


#include <iostream>

int add(int param1, int param2) {
    return (param1 + param2);
}


int main(){
	int a=0, b=0;
	std::cin >> a >> b;
  std::cout << add(a, b) << std::endl;

	return 0;
}


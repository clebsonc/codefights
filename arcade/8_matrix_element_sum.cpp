#include <iostream>
#include <vector>


int matrixElementsSum(std::vector<std::vector<int>> matrix) {
  int total_price = 0;
  for (int col = 0; col < static_cast<int>(matrix.at(0).size()); col++){
    for (int line = 0; line < static_cast<int>(matrix.size()); line++){
      if (matrix.at(line).at(col) == 0)
        break;
      total_price += matrix.at(line).at(col);
    }
  }
  return total_price;
}



int main(){
  int lines = 0, columns;
  std::cin >> lines >> columns;

  std::vector<std::vector<int>> matrix(lines, std::vector<int>(columns, 0));

  for (int i = 0; i < lines; i++){
    for (int j = 0; j < lines; j++){
      std::cin >> matrix.at(i).at(j);
    }
  }

  int price = matrixElementsSum(matrix);

  std::cout << price << std::endl;

  return 0;
}


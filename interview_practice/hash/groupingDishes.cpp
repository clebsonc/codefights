/**
 * You have a list of dishes. Each dish is associated with a list of ingredients
 * used to prepare it. You want to group the dishes by ingredients, so that for 
 * each ingredient you'll be able to find all the dishes that contain it (if 
 * there are at least 2 such dishes).
 *
 * Return an array where each element is a list with the first element equal to 
 * the name of the ingredient and all of the other elements equal to the names 
 * of dishes that contain this ingredient. The dishes inside each list should be
 * sorted lexicographically. The result array should be sorted lexicographically
 * by the names of the ingredients in its elements.
 *  
 * input:
 * dishes = [["Salad", "Tomato", "Cucumber", "Salad", "Sauce"],
 *             ["Pizza", "Tomato", "Sausage", "Sauce", "Dough"],
 *             ["Quesadilla", "Chicken", "Cheese", "Sauce"],
 *             ["Sandwich", "Salad", "Bread", "Tomato", "Cheese"]]
 *
 * output: 
 * groupingDishes(dishes) = [["Cheese", "Quesadilla", "Sandwich"],
 *                           ["Salad", "Salad", "Sandwich"],
 *                           ["Sauce", "Pizza", "Quesadilla", "Salad"],
 *                           ["Tomato", "Pizza", "Salad", "Sandwich"]]
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

bool compare(const std::vector<std::string> & v1,
    const std::vector<std::string> & v2){
  return v1.at(0) < v2.at(0);
}


void build_hash(const std::vector<std::vector<std::string>> & dishes,
    std::unordered_map<std::string, std::vector<std::string>> & ingredients){
  for (auto line : dishes){
    for (int i = 1; i < static_cast<int>(line.size()); i++){
      auto it = ingredients.find(line.at(i));
      if (it != ingredients.end()){ // hash already contains the index
        it->second.emplace_back(line.at(0));  // insert the dish name to vector
      }
      else {
        ingredients.emplace(line.at(i), std::vector<std::string>());
        ingredients[line.at(i)].emplace_back(line.at(i));
        it = ingredients.find(line.at(i));    // find the inserted element
        it->second.emplace_back(line.at(0));  // name of the dish
      }
    }
  }
}


void print_hash(
    const std::unordered_map<std::string, std::vector<std::string>> & hash){
  for (auto it = hash.begin(); it != hash.end(); it++){

    std::cout << it->first << ": "; 
    for (auto vec : it->second){
      std::cout << vec << " ";
    }
    std::cout << std::endl;
  }
}


std::vector<std::vector<std::string>> sort_and_transform(
    std::unordered_map<std::string, std::vector<std::string>> & hash){
  std::vector<std::vector<std::string>> matrix;

  auto it = hash.begin();
  while (it != hash.end()){
    if (it->second.size() > 2){
      std::sort(it->second.begin()+1, it->second.end());
      matrix.emplace_back(it->second);
    }
    it++;
  }

  std::sort(matrix.begin(), matrix.end(), compare);
  return matrix;
}


std::vector<std::vector<std::string>> groupDishes(
    std::vector<std::vector<std::string>> dishes){
  std::vector<std::vector<std::string>> output;
  std::unordered_map<std::string, std::vector<std::string>> ingredients;
  build_hash(dishes, ingredients);
  output = sort_and_transform(ingredients);
  
  return output;
}


int main(){
  int line_number = 0;
  std::cin >> line_number;

  std::vector<std::vector<std::string>> dishes;
  for (int i = 0; i < line_number; i++){
    int word_number = 0;
    std::cin >> word_number;
    std::vector<std::string> words(word_number);
    for (int j = 0; j < word_number; j++){
      std::cin >> words.at(j);
    }
    dishes.emplace_back(words);
  }

  std::vector<std::vector<std::string>> groups = groupDishes(dishes);

  for (auto g : groups){
    for (auto s : g){
      std::cout << s << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}


#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <stdlib.h>

#include "homework_4/sort.h"

std::string slurp(const std::string& filepath) {
  std::ifstream input(filepath);
  std::stringstream sstr;
  sstr << input.rdbuf();
  return sstr.str();
}

void slurp_vector(const std::string& filepath,
                  std::vector<int>* output) {
  std::string file_content = slurp(filepath);
  std::string delimiter = " ";
  size_t pos = 0;
  while ((pos = file_content.find(delimiter)) != std::string::npos) {
    std::string token = file_content.substr(0, pos);
    output->push_back(atoi(token.c_str()));
    file_content.erase(0, pos + delimiter.length());
  }
  if (!file_content.empty()) {
    output->push_back(atoi(file_content.c_str()));
  }
}

bool vector_equality(const std::vector<int>& left, 
                     const std::vector<int>& right) {
  assert(left.size() == right.size());
  for (uint32_t i = 0; i < left.size(); i++) {
    if (left[i] != right[i]) {
      return false;
    }
  }
  return true;
}

void testSortingFunction(void(*sort_f)(std::vector<int>*)) {
  std::vector<int> testdata_one;
  slurp_vector("homework_4/1.txt", &testdata_one);
  sort_f(&testdata_one);
  std::vector<int> testdata_one_sorted;
  slurp_vector("homework_4/1_sorted.txt", &testdata_one_sorted);
  assert(vector_equality(testdata_one, testdata_one_sorted));

  std::vector<int> testdata_two;
  slurp_vector("homework_4/2.txt", &testdata_two);
  sort_f(&testdata_two);
  std::vector<int> testdata_two_sorted;
  slurp_vector("homework_4/2_sorted.txt", &testdata_two_sorted);
  assert(vector_equality(testdata_two, testdata_two_sorted));
 
  std::vector<int> testdata_three;
  slurp_vector("homework_4/3.txt", &testdata_three);
  sort_f(&testdata_two);
  std::vector<int> testdata_three_sorted;
  slurp_vector("homework_4/3_sorted.txt", &testdata_three_sorted);
  assert(vector_equality(testdata_three, testdata_three_sorted));
 
  std::vector<int> testdata_four;
  slurp_vector("homework_4/4.txt", &testdata_four);
  sort_f(&testdata_two);
  std::vector<int> testdata_four_sorted;
  slurp_vector("homework_4/4_sorted.txt", &testdata_four_sorted);
  assert(vector_equality(testdata_four, testdata_four_sorted));

  std::vector<int> testdata_five;
  slurp_vector("homework_4/5.txt", &testdata_five);
  sort_f(&testdata_two);
  std::vector<int> testdata_five_sorted;
  slurp_vector("homework_4/5_sorted.txt", &testdata_five_sorted);
  assert(vector_equality(testdata_five, testdata_five_sorted));
}

int main(int argc, char** argv) {
  std::cout << "Testing BubbleSort" << std::endl;
  testSortingFunction(&homework_4::BubbleSort);
  std::cout << "Testing InsertionSort" << std::endl;
  testSortingFunction(&homework_4::InsertionSort);
  std::cout << "Testing QuickSort" << std::endl;
  testSortingFunction(&homework_4::QuickSort);
  std::cout << "Testing MergeSort" << std::endl;
  testSortingFunction(&homework_4::MergeSort);
  return 0;
}

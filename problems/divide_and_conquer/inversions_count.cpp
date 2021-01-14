/*
 Problem Description:

  Given an array, find the count of inversions in it.

  Inversion Count for an array indicates – how far (or close) the array is from being sorted.
  If array is already sorted then inversion count is 0.
  If array is sorted in reverse order that inversion count is the maximum.
  Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

  Example:

    Input: arr[] = {8, 4, 2, 1}
    Output: 6

    Explanation: Given array has six inversions:
    (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


    Input: arr[] = {3, 1, 2}
    Output: 2

    Explanation: Given array has two inversions:
    (3, 1), (3, 2)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int inversion_count = 0;

vector<int> merge_arrays_and_count_inversions(
    vector<int> first_array,
    vector<int> second_array
  ) {

  int first_array_length = first_array.size(),
      second_array_length = second_array.size();
  int final_array_length = first_array_length + second_array_length;
  vector<int> merged_array;
  int first_array_counter = 0, second_array_counter = 0;

  for (int i = 0; i < final_array_length; i++) {
    if (
      first_array_counter < first_array_length &&
      (
        second_array_counter >= second_array_length ||
        first_array[first_array_counter] < second_array[second_array_counter]
      )
    ) {
      merged_array.push_back(first_array.at(first_array_counter));
      ++first_array_counter;
    } else {
      merged_array.push_back(second_array.at(second_array_counter));
      ++second_array_counter;
      if (first_array_counter < first_array_length) {
        inversion_count = inversion_count + first_array_length - first_array_counter;
      }
    }
  }

  return merged_array;
}

vector<int> slice_array_in_half(
    vector<int> array_to_be_sliced,
    bool first_half = true
  ) {

  int array_length = array_to_be_sliced.size();
  int start, end, middle = array_length / 2;

  if (first_half) {
    start = 0;
    end = middle;
  } else {
    start = middle;
    end = array_length;
  }

  return vector<int>(
    array_to_be_sliced.begin() + start,
    array_to_be_sliced.begin() + end
  );
}

vector<int> merge_sort(vector<int> original_array) {
  int array_size = original_array.size();
  if (array_size <= 1) {
    return original_array;
  }
  vector<int> first_array_parition, second_array_partition;

  first_array_parition = slice_array_in_half(
    original_array
  );
  second_array_partition = slice_array_in_half(
    original_array,
    false
  );

  first_array_parition = merge_sort(first_array_parition);
  second_array_partition = merge_sort(second_array_partition);

  return merge_arrays_and_count_inversions(
    first_array_parition,
    second_array_partition
  );
}

int main() {
  vector<int> original_array, sorted_array;
  int array_element;
  string input_line;
  getline(cin, input_line);
  istringstream iss(input_line);

  while (iss >> array_element) {
    original_array.push_back(array_element);
  }

  merge_sort(original_array);

  cout << "Number of Inversions are " << inversion_count << " \n";
}

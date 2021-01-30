#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void print_vector(vector<int> vector_array) {
  for (auto i = vector_array.begin(); i != vector_array.end() ; ++i) {
    cout << *i << " ";
  }
  cout << "\n";
}

vector<int> merge_arrays_in_order(
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

  return merge_arrays_in_order(
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

  sorted_array = merge_sort(original_array);

  cout << "The above array when sorted is \n";
  print_vector(sorted_array);
}

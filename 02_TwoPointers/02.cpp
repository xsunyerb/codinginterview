/**
 * Given an array of sorted numbers, separate all duplicates from it in-place. You should not use any extra space; move all duplicates at the end of the array and after moving return the length of the subarray that has no duplicate in it.
 * 
 */

using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    int nextNonDuplicate = 1;  // index of the next non-duplicate element
    for (int i = 0; i < arr.size(); i++) {
      if (arr[nextNonDuplicate - 1] != arr[i]) {
        arr[nextNonDuplicate] = arr[i];
        nextNonDuplicate++;
      }
    }

    return nextNonDuplicate;
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;

  arr = vector<int>{2, 2, 2, 11};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;
}

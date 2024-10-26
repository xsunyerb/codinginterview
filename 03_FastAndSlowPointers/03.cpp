/**
 * Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.
 * 
 * Example 1: 23 
 * Output: true (23 is a happy number)
 * Steps -> 23 - 13 - 10 -1
 * 
 * Example 2: 12
 * Output: false (12 is not a happy number)
 * Steps -> 12 - 5 - 25 - 29 - 85 - 89 - 145 - 42 - 20 - 4 - 16 - 37 - 58 - 89
 * 
 * The process, to find out if a number is a happy number or not, always ends in a cycle. If the number is a happy number, the process will be stuck in a cycle on number ‘1,’ and if the number is not a happy number then the process will be stuck in a cycle with a set of numbers. As we saw in Example-2 while determining if ‘12’ is a happy number or not, our process will get stuck in a cycle with the following numbers: 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89
 */

using namespace std;

#include <iostream>

class HappyNumber {
 public:
  static bool find(int num) {
    int slow = num, fast = num;
    do {
      slow = findSquareSum(slow);                 // move one step
      fast = findSquareSum(findSquareSum(fast));  // move two steps
    } while (slow != fast);                       // found the cycle

    return slow == 1;  // see if the cycle is stuck on the number '1'
  }

 private:
  static int findSquareSum(int num) {
    int sum = 0, digit;
    while (num > 0) {
      digit = num % 10;
      sum += digit * digit;
      num /= 10;
    }
    return sum;
  }
};

int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}
/*Q3: Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may
not use the same element twice.You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].*/

#include <iostream>
using namespace std;
int main() {
    int arr[4], target, total = 0;
    cout << "enter target: ";
    cin >> target;
    for (int i = 0; i < 5; i++) {
        cout << "enter element " << i <<" in array: ";
        cin >> arr[i];
    }
    int count = -1;
    while (total < target) {
        count++;
        total = total + arr[count];
    }

    for (int i = 0; i < count ; i++)
    {
        cout << i << ", ";
    }
    cout << count;
}
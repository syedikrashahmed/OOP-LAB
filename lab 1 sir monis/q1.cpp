/*1. Write a program that finds the second highest number in a float type array of 20 elements using pointer. */
#include <iostream>
using namespace std;
void bubbleSort(float arr[], int size);
int main() {
    float arr[20];
    float highest, sechighest;
    // input of array elements
    for (int i = 0; i < 20; i++) {
        cout << "Enter array element " << i << ": ";
        cin >> arr[i];
    }
    bubbleSort(arr, 20);
    highest = arr[0];
    for (int i = 0; i < 20; i++) {
        if (arr[i] != highest) {
            sechighest = arr[i];
            break;
        }
    }
    cout << "second highest element in array is " << sechighest;
}

void bubbleSort(float arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
#include <iostream>
#include <vector>
using namespace std;

int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}

int binarySearch(int* arr, int n, int target) {
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
        
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1; 
}

int* generateSortedArray(int n) {
    if (n <= 0) return nullptr;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }
    return arr;
}

void runTests(int n) {
    cout << "--- Testing Array Size n = " << n << " ---" << endl;
    int* arr = generateSortedArray(n);

    int targetExist = arr[n / 2];
    int linRes1 = linearSearch(arr, n, targetExist);
    int binRes1 = binarySearch(arr, n, targetExist);

    cout << "Target " << targetExist << " (exists):" << endl;
    cout << "  Linear Search Index: " << linRes1 << endl;
    cout << "  Binary Search Index: " << binRes1 << endl;
    cout << "  Matches: " << (linRes1 == binRes1 ? "YES" : "NO") << endl;

    int targetMissing = 1; 
    int linRes2 = linearSearch(arr, n, targetMissing);
    int binRes2 = binarySearch(arr, n, targetMissing);

    cout << "Target " << targetMissing << " (missing):" << endl;
    cout << "  Linear Search Index: " << linRes2 << endl;
    cout << "  Binary Search Index: " << binRes2 << endl;
    cout << "  Matches: " << (linRes2 == binRes2 ? "YES" : "NO") << endl << endl;

    delete[] arr;
}

int main() {
    int sizes[] = {10, 100, 1000};

    for (int n : sizes) {
        runTests(n);
    }

    return 0;
}
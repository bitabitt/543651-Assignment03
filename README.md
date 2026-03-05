# Linear vs. Binary Search Implementation

This program compares the behavior of **Linear Search** and **Binary Search** algorithms across different data set sizes.



## Algorithm Overview

### Linear Search
* **Method**: Sequentially checks each element.
* **Time Complexity**: $O(n)$
* **Requirement**: None (works on unsorted data).

### Binary Search
* **Method**: Divide-and-conquer approach on a range.
* **Time Complexity**: $O(\log n)$
* **Requirement**: Data **must** be sorted.
* **Midpoint Calculation**: Uses the formula $mid = lo + \frac{hi - lo}{2}$ to ensure no integer overflow occurs during addition.



[Image of binary search algorithm flow diagram]


## Test Methodology
The program generates a sorted array of even integers: $\{0, 2, 4, \dots, 2(n-1)\}$.
For each array size ($n = 10, 100, 1000$), it performs:
1.  **Successful Search**: Locates the element at the midpoint of the array.
2.  **Unsuccessful Search**: Attempts to find the value `1`, which is not present in the even-only array.
3.  **Validation**: Prints both indices to confirm both algorithms return identical results.

## Execution
Compile using a standard C++ compiler:
```bash
g++ problem3.cpp -o search_demo
./search_demo

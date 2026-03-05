#include <iostream>

using namespace std;

// Struktur data sesuai permintaan soal
struct DynArray {
    int* data;      // pointer ke heap-allocated buffer
    int size;       // jumlah elemen yang sedang digunakan
    int capacity;   // total slot yang dialokasikan
};

// 1. // O(1)
void initArray(DynArray& a) {
    a.capacity = 2;
    a.size = 0;
    a.data = new int[a.capacity];
}

// 2. // O(1)
void freeArray(DynArray& a) {
    delete[] a.data;
    a.data = nullptr;
    a.size = 0;
    a.capacity = 0;
}

// 3. // O(n) saat resize, rata-rata (amortized) O(1)
void pushBack(DynArray& a, int value) {
    if (a.size == a.capacity) {
        // Double the capacity
        a.capacity *= 2;
        int* newData = new int[a.capacity];
        
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        
        delete[] a.data;
        a.data = newData;
    }
    a.data[a.size] = value;
    a.size++;
}

// 4. // O(n) karena harus menggeser elemen ke kanan
void insertAt(DynArray& a, int index, int value) {
    if (index < 0 || index > a.size) return;

    if (a.size == a.capacity) {
        a.capacity *= 2;
        int* newData = new int[a.capacity];
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        delete[] a.data;
        a.data = newData;
    }

    for (int i = a.size; i > index; i--) {
        a.data[i] = a.data[i - 1];
    }
    
    a.data[index] = value;
    a.size++;
}

// 5. // O(n) karena harus menggeser elemen ke kiri
void removeAt(DynArray& a, int index) {
    if (index < 0 || index >= a.size) return;

    for (int i = index; i < a.size - 1; i++) {
        a.data[i] = a.data[i + 1];
    }
    a.size--;
}

// 6. // O(1)
int getAt(const DynArray& a, int index) {
    return a.data[index];
}

// 7. // O(1)
void setAt(DynArray& a, int index, int value) {
    a.data[index] = value;
}

// 8. // O(n)
void printDynArr(const DynArray& a) {
    cout << "[";
    for (int i = 0; i < a.size; i++) {
        cout << a.data[i];
        if (i < a.size - 1) cout << ", ";
    }
    cout << "] (size=" << a.size << ", cap=" << a.capacity << ")" << endl;
}

int main() {
    DynArray arr;
    initArray(arr);

    for (int i = 1; i <= 5; i++) {
        pushBack(arr, i * 10);
    }
    printDynArr(arr);

    insertAt(arr, 2, 25);
    printDynArr(arr); 

    removeAt(arr, 0);
    printDynArr(arr); 

    cout << "Element at index 2: " << getAt(arr, 2) << "\n"; 
    setAt(arr, 2, 99);
    printDynArr(arr); 

    freeArray(arr);

    return 0;
}
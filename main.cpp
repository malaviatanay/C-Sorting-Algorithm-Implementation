#include <iostream>
#include <vector>
#include <time.h>

using namespace::std;

void bubbleSort(vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        swap(array[i], array[min_idx]);
    }
}

void insertionSort(vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i-1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& array, int l, int r) {
    if (l < r) {
        int pivot = partition(array, l, r);
        quickSort(array, l, pivot - 1);
        quickSort(array, pivot + 1, r);
    }
}

void quickSort(vector<int>& array){
    quickSort(array, 0, array.size() - 1);
}


void merge(vector<int>& array, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& array, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(array, l, mid);
        mergeSort(array, mid + 1, r);
        merge(array, l, mid, r);
    }
}

void mergeSort(vector<int>& array){
    mergeSort(array, 0, array.size() - 1);
}


int main() {
    int N = 10000000;
    vector<int> InitV(N);
    for (int i = 0; i < N; i++) {
        InitV[i] = rand() % 1000000000;
    }

    for(int x = 1; x <= 5; x++){
        int M = x * 20000;
        vector<int> sub_vector(InitV.begin(), InitV.begin() + M);

        clock_t start, end;
        double cpu_time_taken;

        cout << "----------------------------" << endl;
        cout << "M => " << M << endl << endl;


        cout << "Quick Sort Algorithm\n\n";
        cout << "Before sorting: \n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }

        start = clock();
        quickSort(sub_vector);
        end = clock();

        cout << "\n\nAfter sorting: \n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }

        cpu_time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << "\n\nTime taken by the algorithm: " << cpu_time_taken << " seconds\n\n";

        // ----------------------------------------------------
        sub_vector = vector<int>(InitV.begin(), InitV.begin() + M);
        cout << "Insertion Sort Algorithm\n\n";
        cout << "Before sorting: \n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }

        start = clock();
        insertionSort(sub_vector);
        end = clock();

        cout << "\n\nAfter sorting: \n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }

        cpu_time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << "\n\nTime taken by the Algorithm: " << cpu_time_taken << " seconds" << endl << endl;


        // ----------------------------------------------------
        sub_vector = vector<int>(InitV.begin(), InitV.begin() + M);
        cout << "Merge Sort Algorithm\n";
        cout << "Before sorting: \n\n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }

        start = clock();
        mergeSort(sub_vector);
        end = clock();

        cpu_time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate the time used

        cout << "\n\nAfter sorting: \n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }

        cout << "\n\nTime Taken by the algorithm: " << cpu_time_taken << " seconds\n\n";


        // ----------------------------------------------------
        sub_vector = vector<int>(InitV.begin(), InitV.begin() + M);
        cout << "Selection Sort Algorithm\n\n";
        cout << "Before sorting: \n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }
        start = clock();
        selectionSort(sub_vector);
        end = clock();

        cout << "\n\nAfter sorting: \n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }

        cpu_time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << "\n\nTime taken by the algorithm: " << cpu_time_taken << " seconds\n\n";


        // ----------------------------------------------------
        sub_vector = vector<int>(InitV.begin(), InitV.begin() + M);
        cout << "Bubble Sort Algorithm\n" << endl;
        cout << "Before sorting: " << endl;
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }
        start = clock();

        bubbleSort(sub_vector);
        end = clock();
        cout << "\n\nAfter sorting: \n";
        for(int i = 0; i<100; i++){
            cout << sub_vector[i] << ", ";
        }

        cpu_time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << "\n\nTime taken by the algorithm: " << cpu_time_taken << " seconds\n\n";

    }

    return 0;
}

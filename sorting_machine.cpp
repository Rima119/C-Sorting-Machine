#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include<functional>

using namespace std;

template<typename T>
class Sort {
public:
    void swap(T *e, T *l) {
        T temp = *e;
        *e = *l;
        *l = temp;
    }

    void selectionSort_Ascending(vector<T> &array) {
        for (int t = 0; t < array.size() - 1; t++) {
            int min_idx = t;
            for (int i = t + 1; i < array.size(); i++) {
                if (array[i] < array[min_idx])
                    min_idx = i;
            }
            swap(&array[min_idx], &array[t]);
        }
    }
    void selectionSort_Descending(vector<T> &array) {
        for (int t = 0; t < array.size() - 1; t++) {
            int min_idx = t;
            for (int i = t + 1; i < array.size(); i++) {
                if (array[i] > array[min_idx])
                    min_idx = i;
            }
            swap(&array[min_idx], &array[t]);
        }
    }
    void insertionSort_Ascending(vector<T> &array) {
        for (int t = 1; t < array.size(); t++) {
            T rs = array[t];
            int j = t - 1;
            while (rs < array[j] && j >= 0) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = rs;
        }
    }
    void insertionSort_Descending(vector<T> &array) {
        for (int t = 1; t < array.size(); t++) {
            T rs = array[t];
            int j = t - 1;
            while (rs > array[j] && j >= 0) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = rs;
        }
    }
    void bubbleSort_Ascending(vector<T> &array) {
        for (int t = 0; t < array.size()-1; ++t) {
          for (int i = 0; i < array.size() - t - 1; ++i) {
            if (array[i] > array[i + 1]) {
              T tp = array[i];
             array[i] = array[i + 1];
             array[i + 1] = tp;
      }
    }
  }
    }
    void bubbleSort_Descending(vector<T> &array) {
  for (int t = 0; t < array.size()-1; ++t) {
    for (int i = 0; i < array.size() - t - 1; ++i) {
      if (array[i] < array[i + 1]) {
        T tp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tp;
      }
    }
  }
}
};
size_t GetElapsedTimeInNanoseconds(function<void()>fn)
{
    auto start = chrono::steady_clock::now();
    fn();
    auto end = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}
template<typename T>
void readInput(const string &filename, vector<T> &arr) {
    ifstream MyReadFile(filename);
    T myText;
    arr.clear();
    while (MyReadFile >> myText) {
        arr.push_back(myText);
    };
}
template<typename T>
void showOutput(const T &arr, size_t ns) {
    cout << "The final sorted list is :" << endl;
    char delim = ' ';
    for (auto x : arr) {
        cout << delim << x;
        delim = ',';
    }
    cout << endl;
    cout<<"The time spent on sorting is: "<< ns << " nanoseconds."<<endl;
}
int main() {
    int n, x, y;
    cout << "Welcome to the Sorting Machine!" << endl;
    cout << "This machine is capable of sorting integers and strings in 3 different sorting algorithms in both ascending and descending order with printing out the time spent on sorting." << endl;
    cout << "What is the name of the file you want to sort?\n 1.file1 (integers file)                  2.file2 (strings file)\n";
    cin >> n;
    cout << "Which sorting algorithm you want to use?\n 1.Selection Sort           2.Insertion Sort        3.Bubble Sort\n";
    cin >> x;
    cout << "Which sorting order you want to display?\n 1.Ascending order         2.Descending oder" << endl;
    cin >> y;
    if (n == 1 && x == 1 && y == 1) {
        Sort<int> sorter;
        vector<int> arr;
        readInput<int>("file1.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.selectionSort_Ascending(arr);});
        showOutput(arr, ms);
    } else if (n == 1 && x == 1 && y == 2) {
        Sort<int> sorter;
        vector<int> arr;
        readInput<int>("file1.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.selectionSort_Descending(arr);});
        showOutput(arr, ms);
    } else if (n == 1 && x == 2 && y == 1) {
        Sort<int> sorter;
        vector<int> arr;
        readInput<int>("file1.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.insertionSort_Ascending(arr);});
        showOutput(arr, ms);
    } else if (n == 1 && x == 2 && y == 2) {
        Sort<int> sorter;
        vector<int> arr;
        readInput<int>("file1.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.insertionSort_Descending(arr);});
        showOutput(arr, ms);
    }
    else if(n == 2 && x == 1 && y == 1)
    {
        Sort<string> sorter;
        vector<string> arr;
        readInput<string>("file2.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.selectionSort_Ascending(arr);});
        showOutput(arr, ms);
    }
    else if(n == 2 && x == 1 && y == 2)
    {
        Sort<string> sorter;
        vector<string> arr;
        readInput<string>("file2.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.selectionSort_Descending(arr);});
        showOutput(arr, ms);
    }
     else if (n == 2 && x == 2 && y == 1) {
        Sort<string> sorter;
        vector<string> arr;
        readInput<string>("file2.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.insertionSort_Ascending(arr);});
        showOutput(arr, ms);
    } else if(n == 2 && x == 2 && y == 2)
    {
        Sort<string> sorter;
        vector<string> arr;
        readInput<string>("file2.txt", arr);
       auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.insertionSort_Descending(arr);});
        showOutput(arr, ms);
    } else if(n == 1 && x == 3 && y == 1)
    {
       Sort<int> sorter;
        vector<int> arr;
        readInput<int>("file1.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.bubbleSort_Ascending(arr);});
        showOutput(arr, ms);
    } else if(n == 1 && x == 3 && y == 2)
    {
        Sort<int> sorter;
        vector<int> arr;
        readInput<int>("file1.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.bubbleSort_Descending(arr);});
        showOutput(arr, ms);
    } else if(n == 2 && x == 3 && y == 1)
    {
        Sort<string> sorter;
        vector<string> arr;
        readInput<string>("file2.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.bubbleSort_Ascending(arr);});
        showOutput(arr, ms);
    } else if(n == 2 && x == 3 && y == 2)
    {
        Sort<string> sorter;
        vector<string> arr;
        readInput<string>("file2.txt", arr);
        auto ms = GetElapsedTimeInNanoseconds([&](){
        sorter.bubbleSort_Descending(arr);});
        showOutput(arr, ms);
    }
return 0;
}

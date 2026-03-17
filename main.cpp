#include <iostream>
using namespace std;

// Метод бульбашки
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Метод Шелла
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

// Метод вставки
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Метод вилучення (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Розбиття для методу Хоара
int partitionHoare(int arr[], int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    return i;
}

// Метод Хоара (Quick Sort)
void quickSortHoare(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int index = partitionHoare(arr, left, right);

    quickSortHoare(arr, left, index - 1);
    quickSortHoare(arr, index, right);
}

// Вивід масиву
void printArray(int arr[], int n) {
    cout << "Відсортований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int n = 5;
    int choice;

    cout << "Оберіть метод сортування:\n";
    cout << "1 - Бульбашка\n";
    cout << "2 - Шелла\n";
    cout << "3 - Хоара\n";
    cout << "4 - Вставки\n";
    cout << "5 - Вилучення\n";
    cout << "Ваш вибір: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            cout << "\nМетод бульбашки\n";
            break;
        case 2:
            shellSort(arr, n);
            cout << "\nМетод Шелла\n";
            break;
        case 3:
            quickSortHoare(arr, 0, n - 1);
            cout << "\nМетод Хоара\n";
            break;
        case 4:
            insertionSort(arr, n);
            cout << "\nМетод вставки\n";
            break;
        case 5:
            selectionSort(arr, n);
            cout << "\nМетод вилучення\n";
            break;
        default:
            cout << "Неправильний вибір!\n";
            return 1;
    }

    printArray(arr, n);

    return 0;
}
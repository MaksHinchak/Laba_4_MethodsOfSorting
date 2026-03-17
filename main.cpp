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
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = { 5, 2, 9, 1, 3 };
    int n = 5;

    int choice;

    cout << "Оберіть метод сортування:\n";
    cout << "1 - Бульбашка\n";
    cout << "2 - Шелла\n";
    cout << "Ваш вибір: ";
    cin >> choice;

    if (choice == 1) {
        bubbleSort(arr, n);
        cout << "\nМетод бульбашки\n";
    }
    else if (choice == 2) {
        shellSort(arr, n);
        cout << "\nМетод Шелла\n";
    }
    else {
        cout << "Неправильний вибір!\n";
        return 1;
    }

    cout << "Відсортований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
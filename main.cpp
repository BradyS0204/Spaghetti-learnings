#include <iostream>
using namespace std;

// code works for the most part but the delete option seems to bug out when I try to delete multiple elements
// not sure what to do.

class arrayInfo {
public:
    int size;
    int *arr;
    arrayInfo() {
        size = 0;
        arr = nullptr;
    }
};

void print() {
    cout << "1: Create/Reinitialize number list" << endl;
    cout << "2: Add number number list" << endl;
    cout << "3: Delete number number list" << endl;
    cout << "4: print number list" << endl;
    cout << "5: Exit" << endl;
}



int size = 0;

int main(){
    arrayInfo arr;
    print();
    int repeat = 0;

    //forces user to input 1 as first option
    while (true) {
        cin >> repeat;
        if (repeat == 1) {
            break;
        }
        print();
    }

    cout << "what is the size of the array: " << endl;
    cin >> arr.size;
    if (arr.size <= 0) {
        arr.size = 3;
    }
    arr.arr = new int[arr.size];

    for (int i = 0; i < arr.size; i++) {
        cout << "Enter number: ";
        cin >> arr.arr[i];
        cout << endl;
    }

    while (true) {
        print();
        cin >> repeat;
        if (repeat == 5) {
            break;
        }

        if (repeat == 3) {
            int deleteNum, delCounter = 0;
            cout << "Enter number you would like to delete from the list: " << endl;
            cin >> deleteNum;

            for (int i = 0; i < arr.size; i++) {
                if (arr.arr[i] == deleteNum) {
                    arr.arr[i] = 0;
                    delCounter++;
                }
            }

            int *tempDelete = new int[arr.size];

            for (int i = 0; i < arr.size; i++) {
                tempDelete[i] = arr.arr[i];
            }
            delete[] arr.arr;
            arr.size = arr.size - delCounter;
            arr.arr = new int[arr.size];

            for (int i = 0; i < arr.size; i++) {
                if (tempDelete[i] == 0) {
                    continue;
                }
                arr.arr[i] = tempDelete[i];
            }

            delete[] tempDelete;
        }

        if (repeat == 2) {
            int *temp = new int[arr.size];
            for (int i = 0; i < arr.size; i++) {
                temp[i] = arr.arr[i];
            }

            delete[] arr.arr;
            arr.size = arr.size + 1;
            arr.arr = new int[arr.size];

            for (int i = 0; i < arr.size-1; i++) {
                arr.arr[i] = temp[i];
            }
            arr.arr[arr.size-1] = 0;

            cout << "give me a number:" << endl;
            cin >> arr.arr[arr.size-1];

            delete[] temp;
            continue;
        }

        if (repeat == 4) {
            for (int i = 0; i < arr.size; i++) {
                cout << arr.arr[i] << " ";
            }
            cout << endl;
        }

        if (repeat == 1) {
            for (int i = 0; i < arr.size; i++) {
                arr.arr[i] = 0;
            }
            for (int i = 0; i < arr.size; i++) {
                cout << "Enter number: ";
                cin >> arr.arr[i];
            }
        }
    }
    delete[] arr.arr;
    return 0;
}
}

#include <iostream>
using namespace std;

void print() {
    cout << "1: Create/Reinitialize number list" << endl;
    cout << "2: Add number number list" << endl;
    cout << "3: Delete number number list" << endl;
    cout << "4: print number list" << endl;
    cout << "5: Exit" << endl;
}

int main(){
    print();
    int repeat = 0;

    //forces user to input 1 as first option
    while (true) {
        cin >> repeat;
        if (repeat == 1) {
            break;
        }
        else {
            print();
        }
    }

    int size;
    cout << "what is the size of the array: " << endl;
    cin >> size;
    if (size <= 0) {
        size = 3;
    }
    int *p;
    p = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter number: ";
        cin >> p[i];
        cout << endl;
    }

    while (true) {
        print();
        cin >> repeat;
        if (repeat == 5) {
            return 0;
        }
        else if (repeat == 4) {
            for (int i = 0; i < size; i++) {
                cout << p[i] << " ";
            }
            cout << endl;
        }
        if (repeat == 1) {
            for (int i = 0; i < size; i++) {
                p[i] = 0;
            }
            for (int i = 0; i < size; i++) {
                cout << "Enter number: ";
                cin >> p[i];
            }
        }

    }


    delete[] p;
    return 0;
}
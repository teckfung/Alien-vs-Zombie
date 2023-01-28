#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    while (rows % 2 == 0) {
        cout << "Please enter an odd number for the number of rows: ";
        cin >> rows;
    }
    cout << "Enter the number of columns: ";
    cin >> columns;
    while (columns % 2 == 0) {
        cout << "Please enter an odd number for the number of columns: ";
        cin >> columns;
    }
    int middleRow = rows / 2 + 1;
    int middleColumn = columns / 2 + 1;
    for (int i = 1; i <= rows; i++) {
        if (i == 1) {
            for (int j = 1; j <= columns; j++) {
                cout << "+";
                if (j != columns) {
                    cout << "-";
                }
            }
        } else {
            if (i != middleRow) {
                cout << i-1 << " |";
            } else {
                cout << i-1 << " |";
            }
            for (int j = 1; j <= columns; j++) {
                if (j == middleColumn && i == middleRow) {
                    cout << " A |";
                } else {
                    cout << "   |";
                }
                if (j != columns) {
                    cout << "+";
                }
            }
        }
        cout << endl;
        if (i != rows) {
            for (int j = 1; j <= columns; j++) {
                cout << "+-";
            }
            cout << "+" << endl;
        }
    }
    return 0;
}





//  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//1 |   |   |   |   |   |   |   |   |   |
//  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//2 |   |   |   |   | A |   |   |   |   |
//  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//3 |   |   |   |   |   |   |   |   |   |
//  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
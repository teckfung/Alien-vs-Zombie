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
        for (int j = 1; j <= columns; j++) {
            if (i == 1 || i == rows) {
                cout << "+";
            } else if (j == 1) {
                if (i != middleRow) {
                    cout << i-1 << " |";
                } else {
                    cout << i-1 << " |";
                }
            } else if (j == columns) {
                cout << "   |";
            } else if (j == middleColumn && i == middleRow) {
                cout << " A |";
            } else {
                cout << "   |";
            }
            if (j != columns) {
                cout << "-";
            }
        }
        cout << endl;
    }
    return 0;
}

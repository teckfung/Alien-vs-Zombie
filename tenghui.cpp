// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT8L
// Names: Tan Teng Hui | Ho Teck Fung | Au Ji Hin
// IDs: 1211102289 | 1211102399 | 1211308797
// Emails: 1211102289@student.mmu.edu.my | 1211102399@student.mmu.edu.my | 1211308797@student.mmu.edu.my
// Phones: 01110600910 | 0123690301 | 0193361628
// *********************************************************
#include <iostream>
#include <string> //for string
#include <stdlib.h>// the header of the general purpose standard library of c languange
#include <iomanip> // for setw()
#include <vector> //for vector
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
using namespace std;

class Boards
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int diX_, diY_;          // to indicate private data
public:
    Boards(int diX = 9, int diY = 5);
    void init(int diX, int diY);
    void display() const;

    //int getDimX() const;
    //int getDimY() const;
    //char getObject(int x, int y) const;
    //void setObject(int x, int y, char ch);
    // bool isEmpty(int x, int y);
    // bool isInsideMap(int x, int y);
};

class GameObject
{
private:
    string name;

    string description;

public:
    GameObject(string name, string description)
    {
        this->name = name;
        this->description = description;
    }
    void print()
    {
        cout << left << setw(20) << name << description << endl;
    }
};


Boards::Boards(int diX, int diY)
{
    init(diX, diY);
}

void Boards::init(int diX, int diY)
{
    diX_ = diX;
    diY_ = diY;
    char objects[] = {' ', ' ', '<', '>', 'v', '^', 'r', 'h', 'p', ' '};
    int noOfObjects = 10; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(diY_); // create empty rows
    for (int i = 0; i < diY_; ++i)
    {
        map_[i].resize(diX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < diY_; ++i)
    {
        for (int j = 0; j < diX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

void Boards::display() const
{
    
    //system("cls");  
    cout << " --__--__--__--__--__--__" << endl;
    cout << "   Welcome to the game   " << endl;
    cout << " __--__--__--__--__--__--" << endl << endl << endl;
    // for each row
    for (int i = 0; i < diY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < diX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(0) << (diY_ - i);

        // display cell content and border of each column
        for (int j = 0; j < diX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < diX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // display column number
    cout << " ";
    for (int j = 0; j < diX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < diX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

void test1_1()
{
    Boards boards;
    boards.display();
}

void menulist()
{
    system("cls");
    cout << "***************************************************" << endl;
    cout << "*            Welcome to Alien VS Zombie           *" << endl;
    cout << "***************************************************" << endl
         << endl;

    cout << "===================================================" << endl;
    cout << "|               Select your option                |" << endl;
    cout << "===================================================" << endl
         << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "|     Enter number '1' to Start the Game          |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|     Enter number '2' to change the game setting |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|     Enter number '3' to view the game commands  |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|     Enter number '4' to view the game objects   |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|     Enter number '5' to quit the game           |" << endl;
    cout << "---------------------------------------------------" << endl
                                                                  << endl
                                                                  << endl;
    cout << "Please enter a number: ";                                                             
}

void command()
{

    cout << left << setw(12) << "Command"
         << "Description" << endl;
    cout << "--------------------------------" << endl;
    cout << left << setw(12) << "1.up"
         << "Move up" << endl << endl;
    cout << left << setw(12) << "2.down"
         << "Move down" << endl << endl;
    cout << left << setw(12) << "3.left"
         << "Move left" << endl << endl;
    cout << left << setw(12) << "4.right"
         << "Move right" << endl << endl;
    cout << left << setw(12) << "5.arrow"
         << "Switch the direction of an arrow object" << endl << endl;
    cout << left << setw(12) << "6.help"
         << "List and describe the commands" << endl << endl;
    cout << left << setw(12) << "7.save"
         << "Save the current game" << endl << endl;
    cout << left << setw(12) << "8.load"
         << "Load saved game" << endl << endl;
    cout << left << setw(12) << "9.quit"
         << "Quit the game" << endl << endl;
	
}
void defaultsetting(int rows ,int columns ,int zombie)
{
    
    char choice;
    cout << "DEFAULT GAME SETTINGS" << endl;
    cout << "---------------------" << endl;
    cout << "Board Rows  : " << rows << endl;
    cout << "Board Column: " << columns << endl;
    cout << "Zombie Count: " << zombie << endl
         << endl;

    do
    {
        cout << "Do you wish to change the game settings (y/n)? => ";
        cin >> choice;
        switch (choice)
        {
        case 'y':
            //changesetting(rows,columns,zombie);
            break;

        case 'n':
            test1_1();
            break;

        default:
            cout << "Invalid selection" << endl;
            continue;
        }
    } while (choice != 'y' && choice != 'n');
}

void changesetting(int rows, int columns , int zombie)
{
    cout << "Board Setting" << endl;
    cout << "-------------" << endl;
    cout << "Enter the new rows: ";
    cin >> rows; 
    while (rows % 2 == 0)
    {
        cout << "Please enter an odd number for the number of rows: ";
        cin >> rows;
    }
    cout << "Enter the new columns: ";
    cin >> columns;
    while (columns % 2 == 0)
    {
        cout << "Please enter an odd number for the number of columns: ";
        cin >> columns;
    }
    cout << "Enter the new zombies: ";
    cin >> zombie;
    cout << "Settings Updated.";
   



}


void gameObject()
{
    cout << "GameObjects         Description" << endl;
    cout << "--------------------------------------------------" << endl;
    GameObject arrow("1. Arrow(^,v,>,<)", "Change direction of movement and adds 20 attack");
    arrow.print();
    cout << endl;
    GameObject health("2. Health(h)", "Adds 20 life to Alien");
    health.print();
    cout << endl;
    GameObject Pod("3. Pod(p)", "Instantly inflicts 10 damage to Zombie when hit by Alien");
    Pod.print();
    cout << endl;
    GameObject Rock("4. Rock(r)", "Hides a game object,Reveals the hidden object when hit by Alien and Stop the Alien from moving");
    Rock.print();
    cout << endl;
    GameObject Empty("5. Empty(space)", "An empty space on the board");
    Empty.print();
    cout << endl;
    GameObject Trail("6. Trail(.)", "Left by Alien when it moves and reset a random game object");
    Trail.print();
    cout << endl << endl;

	

}

int main()
{
    int selection;
    bool done = false;
    int rows = 5, columns = 9, zombie = 1;
    srand(1); // use this for fixed map during testing
    srand(time(NULL)); // try this for random map
    
    
    //changesetting(rows,columns,zombie);

    do
    {
        menulist();
        
        cin >> selection;

        switch (selection)
        {
        case 1:
            test1_1();
            break;
        case 2:
            defaultsetting(5,9,1);
            break;
        case 3:
            command();
            break;
        case 4:
            gameObject();
            break;
        case 5:
            done = true;
            break;
        default:
            cout << "Invalid selection, try again" << endl;
            cout << endl;
            break;
        }
        system("pause");
    } while (!done);

    cout << endl;
    cout << "Good Bye!" << endl;
}

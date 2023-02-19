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
#include <string>   // for string
#include <stdlib.h> // the header of the general purpose standard library of c languange
#include <iomanip>  // for setw()
#include <vector>   // for vector
#include <cstdlib>  // for system()
#include <ctime>    // for time() in srand( time(NULL) );
#include <chrono>   // for working with time
#include <thread>   // for creating and managing threads
#include <conio.h>  // for _kbhit() & _getch()
using namespace std;

class Boards
{
private:
    vector<vector<char>> map_;   // convention to put trailing underscore
    int diX_, diY_, numZombies_; // to indicate private data
    int alienX_, alienY_;        // new private variable for alien position
    void placeZombies();

public:
    Boards(int diX = 9, int diY = 5, int numzombies = 1);
    void init(int diX, int diY, int numzombies);
    void display() const;
    void changesetting();
    void defaultsetting();
    void setNumZombies(int numZombies);
    void moveAlien();
    void playGame();
    void test2();
    void gameAttribute() const;
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

Boards::Boards(int diX, int diY, int numzombies)
{
    init(diX, diY, numzombies);
}

void Boards::init(int diX, int diY, int numzombies)
{
    diX_ = diX;
    diY_ = diY;
    numZombies_ = numzombies;

    // set alien position in the middle of the gameboard
    alienX_ = diX_ / 2;
    alienY_ = diY_ / 2;

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
            // check if the current cell is the alien's position
            if (i == alienY_ && j == alienX_)
                map_[i][j] = 'A'; // set cell content to "A"
            else
                map_[i][j] = objects[objNo];
        }
    }

    placeZombies();
}

void Boards::placeZombies()
{
    for (int i = 0; i < numZombies_; ++i)
    {
        int x, y;
        do
        {
            x = rand() % diX_;
            y = rand() % diY_;
        } while (x == alienX_ && y == alienY_); // The do-while loop will keep generating random positions until a position that is not the middle
        map_[y][x] = 'Z';
    }
}

void Boards::setNumZombies(int numZombies)
{
    numZombies_ = numZombies;
    placeZombies();
}

void Boards::test2()
{
    Boards boards;
    boards.changesetting();
    boards.display();
    boards.gameAttribute();
}

void testDisplay()
{
    Boards boards;
    boards.display();
    boards.gameAttribute();
    boards.moveAlien();
}

void Defaultset()
{
    Boards boards;
    boards.defaultsetting();
}
void Boards::playGame()
{
    Boards boards;
    boards.test2();
    boards.moveAlien();
}

void Boards::display() const
{

    system("cls");
    cout << " --__--__--__--__--__--__" << endl;
    cout << "   Welcome to the game   " << endl;
    cout << " __--__--__--__--__--__--" << endl
         << endl
         << endl;
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

void Boards::gameAttribute() const
{
    // Set attributes for Alien
    int alienHealth = 100;
    int alienAttack = 0;

    // Set random attributes for Zombies
    srand(time(NULL)); // seed the random number generator with current time
    // Print out the character attributes for the Alien
    cout << left << setw(5) << "Alien       :  "
         << left << setw(5) << "Life: " << alienHealth
         << left << "   " << setw(5) << "Attack: " << alienAttack << endl;
    cout << endl;
    for (int i = 0; i < numZombies_; i++)
    {
        int zombieHealth;
        int zombieAttack;
        int zombieRange;

        do
        {
            zombieHealth = rand() % 201 + 100; // zombie health maximum 250

        } while (zombieHealth % 5 != 0);

        zombieHealth = zombieHealth / 5 * 5; // make it divisible by 5
        zombieAttack = (rand() % 26) + 5;
        ;                                    // Zombie attack maximum 30
        zombieAttack = zombieAttack / 5 * 5; // make it divisible by 5
        zombieRange = rand() % 10 + 1;       // zombie range maximum 10

        // Print out the character attributes for each zombie
        cout << left << setw(9) << "Zombie " << i + 1 << "  "
             << ":  "
             << "Life: " << left << setw(4) << zombieHealth << "  "
             << "Attack: " << left << setw(2) << zombieAttack << "  "
             << "Range: " << left << setw(2) << zombieRange << endl;
        cout << endl;
    }
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
    cout << "|     Enter number '2' to view the game commands  |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|     Enter number '3' to view the game objects   |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|     Enter number '4' to view the game story     |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|     Enter number '5' to quit the game           |" << endl;
    cout << "---------------------------------------------------" << endl
         << endl
         << endl;
    cout << "Please enter a number: ";
}

void command()
{

    system("cls");
    cout << left << setw(12) << "Command"
         << "Description" << endl;
    cout << "--------------------------------" << endl;
    cout << left << setw(12) << "1.up"
         << "Move up" << endl
         << endl;
    cout << left << setw(12) << "2.down"
         << "Move down" << endl
         << endl;
    cout << left << setw(12) << "3.left"
         << "Move left" << endl
         << endl;
    cout << left << setw(12) << "4.right"
         << "Move right" << endl
         << endl;
    cout << left << setw(12) << "5.arrow"
         << "Switch the direction of an arrow object" << endl
         << endl;
    cout << left << setw(12) << "6.help"
         << "List and describe the commands" << endl
         << endl;
    cout << left << setw(12) << "7.save"
         << "Save the current game" << endl
         << endl;
    cout << left << setw(12) << "8.load"
         << "Load saved game" << endl
         << endl;
    cout << left << setw(12) << "9.quit"
         << "Quit the game" << endl
         << endl;
}

void Boards::defaultsetting()
{
    system("cls");
    char choice;
    cout << "DEFAULT GAME SETTINGS" << endl;
    cout << "---------------------" << endl;
    cout << "Board Rows  : " << diY_ << endl;
    cout << "Board Column: " << diX_ << endl;
    cout << "Zombie Count: " << numZombies_ << endl
         << endl;

    do
    {
        cout << "Do you wish to change the game settings (y/n)? => ";
        cin >> choice;
        switch (choice)
        {
        case 'y':
            playGame();
            break;

        case 'n':
            testDisplay();
            break;

        default:
            cout << "Invalid selection" << endl;
            continue;
        }
    } while (choice != 'y' && choice != 'n');
}

void Boards::changesetting()
{
    system("cls");
    cout << "Board Setting" << endl;
    cout << "-------------" << endl;
    cout << "Enter the new rows: ";
    cin >> diY_;
    while (diY_ % 2 == 0)
    {
        cout << "Please enter an odd number for the number of rows: ";
        cin >> diY_;
    }
    cout << "Enter the new columns: ";
    cin >> diX_;
    while (diX_ % 2 == 0)
    {
        cout << "Please enter an odd number for the number of columns: ";
        cin >> diX_;
    }
    cout << "Enter the new zombies: ";
    cin >> numZombies_;
    while (numZombies_ >= 10)
    {
        cout << "The number of zombies cannot exceed 9. Please enter again the amount of zombies: ";
        cin >> numZombies_;
    }
    init(diX_, diY_, numZombies_);
    cout << endl;
    cout << endl;
    cout << "Settings Updated." << endl;
    system("pause");
}

void Boards::moveAlien()
{
    bool done = false;
    do
    {
        Boards boards;
        // boards.display();

        char direction;
        cout << "Enter the direction of the alien (v, ^, >, <): ";
        cin >> direction;
        switch (direction)
        {
        case 'v':
            if (alienY_ + 1 < diY_)
            {
                map_[alienY_][alienX_] = ' ';
                alienY_++;
                map_[alienY_][alienX_] = 'A';
            }
            else
            {
                cout << "Warning: Alien cannot move further down!" << endl;
            }

            display();
            boards.gameAttribute();
            break;
        case '^':
            if (alienY_ - 1 >= 0)
            {
                map_[alienY_][alienX_] = ' ';
                alienY_--;
                map_[alienY_][alienX_] = 'A';
            }
            else
            {
                cout << "Warning: Alien cannot move further up!" << endl;
            }
            display();
            boards.gameAttribute();
            break;
        case '>':
            if (alienX_ + 1 < diX_)
            {
                map_[alienY_][alienX_] = ' ';
                alienX_++;
                map_[alienY_][alienX_] = 'A';
            }
            else
            {
                cout << "Warning: Alien cannot move further to the right!" << endl;
            }
            display();
            boards.gameAttribute();
            break;
        case '<':
            if (alienX_ - 1 >= 0)
            {
                map_[alienY_][alienX_] = ' ';
                alienX_--;
                map_[alienY_][alienX_] = 'A';
            }
            else
            {
                cout << "Warning: Alien cannot move further to the left!" << endl;
            }
            display();
            boards.gameAttribute();
            break;
        case 'q':
            done = true;
            break;

        default:
            cout << "Invalid Direction, try again" << endl;
            cout << endl;
            break;
        }
    } while (!done);
}

void gameObject()
{
    system("cls");
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
    cout << endl
         << endl;
}

void gamestory()
{
    system("cls");
    cout << "Press 'Q' to stop reading" << endl
         << endl;
    const char *story = "Once upon a time, on a distant planet,\nthere lived a peaceful and technologically advanced alien race.\nThey lived harmoniously, exploring the universe and discovering new worlds.\nOne day, as they were exploring a new planet,\nthey stumbled upon a strange virus that turned its hosts into\nMindless, Flesh-Eating Zombies.\nThe virus quickly spread, infecting most of the planet's population\nturning it into a post-apocalyptic wasteland.\nThe aliens, being the technologically advanced beings they were,\ntried to find a cure for the virus but to no avail.\nThey realized that the only way to contain the virus\nwas to eliminate all the zombies and prevent it from spreading to other planets.\nSo, the aliens sent one of their best soldiers -> YOU\nto the infected planet, armed with their most advanced weapons and technology.\nThe commander assigned you a secret mission: \"Eliminate All Zombies\".\nThey hoped that you would be able to eliminate all of the zombies and return safely to your home planet.";

    for (const char *c = story; *c != '\0'; ++c)
    {
        cout << *c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(50));

        if (_kbhit() && _getch() == 'q')
        {
            break;
        }
    }

    cout << endl
         << endl;
}

int main()
{
    int selection;
    bool done = false;

    srand(1);          //  for fixed map during testing
    srand(time(NULL)); //  for random map

    do
    {
        menulist();

        cin >> selection;

        switch (selection)
        {
        case 1:
            Defaultset();
            break;
        case 2:
            command();
            break;
        case 3:
            gameObject();
            break;
        case 4:
            gamestory();
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
    system("cls");
    cout << endl;
    cout << "Good Bye!" << endl;
}

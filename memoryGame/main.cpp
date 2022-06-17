
#include <random>
#include <iostream>
#include <algorithm>
#include <conio.h>
using namespace std;
void game();
int sX = 0;
int sY = 0;
bool exitG = false;
vector<int> startArr()
{

    /*cout << "  Enter the size of the X and Y field\nAttention: the field must have an even size!\n";
    cin >> sX >> sY;*/

    int P;
    do
    {
        cout << "  Enter the size of the X and Y field\nAttention: the field must have an even size!\n";
        cin >> sX >> sY;
        P = (sX * sY) % 2;
    } while (P);

    size_t arSize = sX * sY;

    vector<int>v;

    for (int i = 0; i < arSize / 2; i++)
    {
        int ti = i + 33;
        v.push_back(ti);
        v.push_back(ti);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);

    return v;
};
void menu()
{

    char mChoise, exit;
    do
    {
        do
        {
            system("cls");
            cout << "*********** MEMORY GAME ***********" << endl << endl;
            cout << "(1) START GAME" << endl << "(0) EXIT" << endl << endl;
            mChoise = _getch();
        } while (mChoise != '1' && mChoise != '0');

        switch (mChoise)
        {
        case '1':
            game();
            break;

        case '0':

            break;
        }
        cout << endl << "Do you want go to menu or exit? (1 - yes, 0 - no)" << endl;
        fflush(stdin);
        exit = _getch();
    } while (exit != '0');
}
void displayField(vector<int>v)
{
    system("cls");
    cout << "*********** MEMORY GAME ***********" << endl << endl;
    cout << "Field size: " << sX << "X" << sY << endl << endl;
    for (int j = 0; j < sY; j++)
    {
        for (int i = 0; i < sX; i++)
        {
            cout << (char)v[i + (sX)*j] << " ";
        }
        cout << endl;
    }

}
vector<int> closeField()
{
    size_t arSize = sX * sY;

    vector<int>vC;

    for (int i = 0; i < arSize; i++)
    {
        vC.push_back(254);
    }
    return vC;
}
bool displayElementOnCloseField(vector<int>& v, vector<int>& vC, int x, int y)
{
    system("cls");
    cout << "*********** MEMORY GAME ***********" << endl << endl;
    cout << "Field size: " << sX << "X" << sY << endl << endl;

    for (int j = 0; j < sY; j++)
    {
        for (int i = 0; i < sX; i++)
        {
            if (i == x - 1 && j == y - 1) { cout << (char)v[i + (sX)*j] << " "; }

            else cout << (char)vC[i + (sX)*j] << " ";
        }
        cout << endl;
    }

    system("pause");

    if (v == vC)
    {
        exitG = true;
    }
    return exitG;
}
bool displayElementOnCloseField(vector<int>& v, vector<int>& vC, int x, int y, int x1, int y1)
{
    system("cls");
    cout << "*********** MEMORY GAME ***********" << endl << endl;
    cout << "Field size: " << sX << "X" << sY << endl << endl;
    if (x == x1 && y == y1) { cout << "ATTENTION: you choose 1 card\n"; }
    else if (v[(x - 1) + (sX) * (y - 1)] == v[(x1 - 1) + (sX) * (y1 - 1)]) 
    {
        vC[(x - 1) + (sX) * (y - 1)] = v[(x - 1) + (sX) * (y - 1)];
        vC[(x1 - 1) + (sX) * (y1 - 1)] = v[(x1 - 1) + (sX) * (y1 - 1)];

        for (int j = 0; j < sY; j++)
        {
            for (int i = 0; i < sX; i++)
            {
                cout << (char)vC[i + (sX)*j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int j = 0; j < sY; j++)
        {
            for (int i = 0; i < sX; i++)
            {
                if (i == x - 1 && j == y - 1) { cout << (char)v[i + (sX)*j] << " "; }
                else if (i == x1 - 1 && j == y1 - 1) { cout << (char)v[i + (sX)*j] << " "; }
                else cout << (char)vC[i + (sX)*j] << " ";
            }
            cout << endl;
        }
    }
    system("pause");

    if (v == vC)
    {
        exitG = true;
    }
    return exitG;
}
void game()
{
    exitG = false;
    int count = 0;
    vector<int> v{ startArr() };
    vector<int> vC{ closeField() };

    displayField(v);
    system("pause");
    displayField(vC);
    while (!exitG)
    {
        char ex = ' ';
        int x, y, x1, y1;
        int P;
        do
        {
            cout << "Enter coord first card (X Y)" << endl;
            cin >> x >> y;
            if ((x < 1 || x > sX) || (y < 1 || y > sY))
            {
                P = 1;
            }
            else P = 0;
        } while (P);
        //cout << "Enter coord first card (X Y)" << endl;
        //cin >> x >> y;
        displayElementOnCloseField(v, vC, x, y);
        
        do
        {
            cout << "Enter coord second card (X1 Y1)" << endl;
            cin >> x1 >> y1;
            if ((x1 < 1 || x1 > sX) || (y1 < 1 || y1 > sY))
            {
                P = 1;
            }
            else P = 0;
        } while (P);

        //cout << "Enter coord second card (X1 Y1)" << endl;
        //cin >> x1 >> y1;
        displayElementOnCloseField(v, vC, x, y, x1, y1);
        displayField(vC);
        count++;
        cout << endl << endl << "to continue enter 1 to exit enter 0\n";
        cin >> ex;
        cout << endl;
        if (ex == '0') exitG = true;
    }

    cout << "Game over in " << count << " steps";
};
int main()
{
    int count = 0;
    vector<int> v;
    vector<int> vC;
    menu();
    return 0;
}
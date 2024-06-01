#include <iostream>
using namespace std;

// X-O Game With 3*3 Board
void DrawBoard(char Board[3][3]);
char CheckWinner(char Board[3][3]);
void Play1();

// X-O Game With 5*5 Board
void DrawBoard2(char Board2[5][5]);
char CheckWinner2(char Board2[5][5]);
void Play2();

// Function To Choose Dimention of X_O Game if 3*3 or 5*5
void chooseBoardDimention();

int main()
{
    chooseBoardDimention();

    return 0;
}

//////// X_O Game 3*3 Board ////////

void DrawBoard(char Board[3][3])
{

    for (int i = 0; i < 7; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 12; ++j)
            {
                cout << '-';
            }
        }
        else
        {
            for (int j = 0; j < 4; ++j)
            {
                if (Board[i / 2][j] != ' ' && j < 3)
                {
                    cout << "| " << Board[i / 2][j] << " ";
                }
                else
                {
                    cout << "|  " << " ";
                }
            }
        }
        cout << "\n";
    }
}

char CheckWinner(char Board[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        // check vertically
        if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ')
        {
            return Board[i][0];
        }
    }
    // check Horizontally
    for (int j = 0; j < 3; ++j)
    {
        if (Board[0][j] == Board[1][j] && Board[1][j] == Board[2][j] && Board[0][j] != ' ')
        {
            return Board[0][j];
        }
    }
    // check Diagonal
    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0] != ' ')
    {
        return Board[0][0];
    }
    if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][0] != ' ')
    {
        return Board[0][2];
    }

    return ' ';
}

void Play1()
{
    char Board[3][3] = {};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            Board[i][j] = ' ';
        }
    }
    DrawBoard(Board);
    int Placed = 0;
    char role;
    bool who = true;
    char gameOver = ' ';

    do
    {
        if (who)
        {
            role = 'X';
        }
        else
        {
            role = 'O';
        }
        cout << "Hey Player ( " << role << " ) Choose Which Block : ";
        int ICoordinate, JCoordinate;
        cin >> ICoordinate >> JCoordinate;
        while (Board[ICoordinate][JCoordinate] != ' ')
        {
            cout << "Invalid Block ! Choose Again ";
            cin >> ICoordinate >> JCoordinate;
        }
        Board[ICoordinate][JCoordinate] = role;
        DrawBoard(Board);
        gameOver = CheckWinner(Board);
        Placed++;
        who = !who;
        if (gameOver == ' ' && Placed == 9)
        {
            cout << "Game Over And No One Won";
            break;
        }

        if (gameOver != ' ')
        {
            if (gameOver == 'X')
            {
                cout << "Player X Won";
                break;
            }
            else
            {
                cout << "Player O Won";
                break;
            }
        }

    } while (Placed < 9);
}

//////// X_O Game 5*5 Board ////////

void DrawBoard2(char Board2[5][5])
{
    for (int i = 0; i < 11; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 25; ++j)
            {
                cout << '-';
            }
        }
        else
        {
            for (int j = 0; j < 6; ++j)
            {
                if (Board2[i / 2][j] != ' ' && j < 5)
                {
                    cout << "|  " << Board2[i / 2][j] << " ";
                }
                else
                {
                    cout << "|    ";
                }
            }
        }
        cout << "\n";
    }
}

char CheckWinner2(char Board2[5][5])
{
    for (int i = 0; i < 5; ++i)
    {
        // check vertically
        if (Board2[i][0] == Board2[i][1] && Board2[i][1] == Board2[i][2] && Board2[i][2] == Board2[i][3] && Board2[i][3] == Board2[i][4] && Board2[i][0] != ' ')
        {
            return Board2[i][0];
        }
    }
    // check Horizontally
    for (int j = 0; j < 3; ++j)
    {
        if (Board2[0][j] == Board2[1][j] && Board2[1][j] == Board2[2][j] && Board2[2][j] == Board2[3][j] && Board2[3][j] == Board2[4][j] && Board2[0][j] != ' ')
        {
            return Board2[0][j];
        }
    }
    // check Diagonal
    if (Board2[0][0] == Board2[1][1] && Board2[1][1] == Board2[2][2] && Board2[2][2] == Board2[3][3] && Board2[3][3] == Board2[4][4] && Board2[0][0] != ' ')
    {
        return Board2[0][0];
    }
    if (Board2[0][4] == Board2[1][3] && Board2[1][3] == Board2[2][2] && Board2[2][2] == Board2[3][1] && Board2[3][1] == Board2[4][0] && Board2[2][2] != ' ')
    {
        return Board2[0][2];
    }

    return ' ';
}

void Play2()
{
    char Board2[5][5] = {};
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            Board2[i][j] = ' ';
        }
    }
    DrawBoard2(Board2);
    int Placed = 0;
    char role;
    bool who = true;
    char gameOver = ' ';

    do
    {
        if (who)
        {
            role = 'X';
        }
        else
        {
            role = 'O';
        }
        cout << "Hey Player ( " << role << " ) Choose Which Block : ";
        int ICoordinate, JCoordinate;
        cin >> ICoordinate >> JCoordinate;
        while (Board2[ICoordinate][JCoordinate] != ' ')
        {
            cout << "Invalid Block ! Choose Again ";
            cin >> ICoordinate >> JCoordinate;
        }
        Board2[ICoordinate][JCoordinate] = role;
        DrawBoard2(Board2);
        gameOver = CheckWinner2(Board2);
        Placed++;
        who = !who;
        if (gameOver == ' ' && Placed == 25)
        {
            cout << "Game Over And No One Won";
            break;
        }

        if (gameOver != ' ')
        {
            if (gameOver == 'X')
            {
                cout << "Player X Won";
            }
            else
            {
                cout << "Player O Won";
            }
        }

    } while (Placed < 9);
}

// Function To Choose Dimention of X_O Game if 3*3 or 5*5
void chooseBoardDimention()
{
    cout << "Choose\n";
    cout << "Press 1 To Play ( 3 * 3 ) X_O Game\n";
    cout << "Press 2 To Play ( 5 * 5 ) X_O Game\n";
    int choose = 0;
    cin >> choose;
    switch (choose)
    {
    case 1:
        Play1();
        break;
    case 2:
        Play2();
        break;
    default:
        break;
    }
}

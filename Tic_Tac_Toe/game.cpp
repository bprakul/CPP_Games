#include <iostream>
#include <vector>
using namespace std;

bool tie = false;
void pattern(char grid[3][3])
{
    cout << "   |     |   \n";
    cout << " " << grid[0][0] << " |  " << grid[0][1] << "  | " << grid[0][2] << "\n";
    cout << "___|_____|___\n";

    cout << "   |     |   \n";
    cout << " " << grid[1][0] <<" |  " << grid[1][1] << "  | " << grid[1][2] << "\n";
    cout << "___|_____|___\n";

    cout << "   |     |   \n";
    cout << " " << grid[2][0] << " |  " << grid[2][1] << "  | " << grid[2][2] << "\n";
    cout << "   |     |   \n\n";
}

void fill(char token, int row, int col, char grid[3][3], string n1, string n2)
{
    int digit;

    if (token == 'x') {
        cout << n1 << " please enter = ";
        cin >> digit;
    }

    if (token == '0') {
        cout << n2 << " please enter = ";
        cin >> digit;
    }

    if (digit == 1) {
        row = 0;
        col = 0;
    }

    if (digit == 2) {
        row = 0;
        col = 1;
    }

    if (digit == 3) {
        row = 0;
        col = 2;
    }

    if (digit == 4) {
        row = 1;
        col = 0;
    }

    if (digit == 5) {
        row = 1;
        col = 1;
    }

    if (digit == 6) {
        row = 1;
        col = 2;
    }

    if (digit == 7) {
        row = 2;
        col = 0;
    }

    if (digit == 8) {
        row = 2;
        col = 1;
    }

    if (digit == 9) {
        row = 2;
        col = 2;
    }

    else if(digit < 1 || digit > 9){
        cout << "Invalid!!" << endl;
    }

    if (token == 'x' && grid[row][col] != 'x' && grid[row][col] != '0') {
        grid[row][col] = 'x';
    }

    else if (token == '0' && grid[row][col] != 'x' && grid[row][col] != '0') {
        grid[row][col] = '0';
    }

    else {
        cout << "There is no empty space!" << endl;
        fill(token, row, col, grid, n1, n2);
    }

    pattern(grid);
}

bool check(char grid[3][3]) 
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] || grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return true;
        }
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] || grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            if (grid[i][j] != '0' && grid[i][j] != 'x') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main()
{
    char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int row;
    int col;
    char token = 'x';

    string n1, n2;
    cout << "Enter Name of First Player = " ;
    cin >> n1;
    cout << "Enter Name of Second Player = " ;
    cin >> n2;

    cout << n1 << " is the first player so he/she will play first \n";
    cout << n2 << " is the second player so he/she will play second \n";
    pattern(grid);

    while(!check(grid))
    {
        fill(token, row, col, grid, n1, n2);
        if(token == 'x') token = '0';
        else token = 'x';
        check(grid);
    }

    if (token == 'x' && tie == false) {
        cout << n2 << " Wins" << endl;
    } 

    else if (token == '0' && tie == false) {
        cout << n1 << " Wins" << endl;
    }

    else {
        cout << "Game is a Draw";
    }
}
#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int rows = 10;
const int elements = 10;
int maxships = 10;
vector<vector<int>> matrix(rows, vector<int>(elements));

void Clear()
{
    for (auto &row : matrix)
    {
        std::fill(row.begin(), row.end(), 0);
    }
}

void Draw()
{
    for (const auto &row : matrix)
    {
        for (const auto &element : row)
            cout << element << " ";
        cout << endl;
    }
}

int NumberOfShips()
{
    int c = 0;
    for (const auto &row : matrix)
    {
        for (const auto &element : row)
        {
            if (element == 1)
                c++;
        }
    }
    return c;
}

void SetShips()
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, rows - 1);

    int s = 0;
    while (s < maxships)
    {
        int x = distribution(generator);
        int y = distribution(generator);
        if (matrix[x][y] != 1)
        {
            s++;
            matrix[x][y] = 1;
        }
    }
}

bool Attack(int x, int y)
{
    if (x < 0 || y < 0 || x >= rows || y >= elements)
    {
        cout << "Invalid coordinates." << endl;
        return false;
    }

    if (matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}

int main()
{
    Clear();
    SetShips();
    int x, y;
    while (true)
    {
        cout << "Input x,y: ";
        cin >> x >> y;
        if (Attack(x, y))
            cout << "\nYou hit a ship" << endl;
        else
            cout << "\nMiss" << endl;
        cout << "\nNumber of ships left: " << NumberOfShips() << endl;
        Draw();
        if (NumberOfShips() == 0)
            break;
    }
    return 0;
}

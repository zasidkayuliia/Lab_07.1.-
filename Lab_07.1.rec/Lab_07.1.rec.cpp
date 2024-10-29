#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** q, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** q, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** q, const int col1, const int col2, const int rowCount, int i = 0);
void Calc(int** q, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -26;
    int High = 23;
    int rowCount = 8;
    int colCount = 6;
    int** q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        q[i] = new int[colCount];

    Create(q, rowCount, colCount, Low, High);
    Print(q, rowCount, colCount);
    Sort(q, rowCount, colCount);
    Print(q, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(q, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(q, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] q[i];
    delete[] q;
    return 0;
}

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i < rowCount)
    {
        if (j < colCount)
        {
            q[i][j] = Low + rand() % (High - Low + 1);
            Create(q, rowCount, colCount, Low, High, i, j + 1);
        }
        else
        {
            Create(q, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** q, const int rowCount, const int colCount, int i, int j)
{
    if (i == 0 && j == 0)
        cout << endl;

    if (i < rowCount)
    {
        if (j < colCount)
        {
            cout << setw(4) << q[i][j];
            Print(q, rowCount, colCount, i, j + 1);
        }
        else
        {
            cout << endl;
            Print(q, rowCount, colCount, i + 1, 0);
        }
    }
    else if (i == rowCount && j == 0)
        cout << endl;
}

void Sort(int** q, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 < colCount - 1)
    {
        if (i1 < colCount - i0 - 1)
        {
            if ((q[0][i1] > q[0][i1 + 1]) ||
                (q[0][i1] == q[0][i1 + 1] && q[1][i1] > q[1][i1 + 1]) ||
                (q[0][i1] == q[0][i1 + 1] && q[1][i1] == q[1][i1 + 1] && q[2][i1] > q[2][i1 + 1]))
            {
                Change(q, i1, i1 + 1, rowCount);
            }
            Sort(q, rowCount, colCount, i0, i1 + 1);
        }
        else
        {
            Sort(q, rowCount, colCount, i0 + 1, 0);
        }
    }
}

void Change(int** q, const int col1, const int col2, const int rowCount, int i)
{
    if (i < rowCount)
    {
        int tmp = q[i][col1];
        q[i][col1] = q[i][col2];
        q[i][col2] = tmp;
        Change(q, col1, col2, rowCount, i + 1);
    }
}

void Calc(int** q, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i < rowCount)
    {
        if (j < colCount)
        {
            if (!(q[i][j] > 0 && q[i][j] % 2 == 0))
            {
                S += q[i][j];
                k++;
                q[i][j] = 0;
            }
            Calc(q, rowCount, colCount, S, k, i, j + 1);
        }
        else
        {
            Calc(q, rowCount, colCount, S, k, i + 1, 0);
        }
    }
}

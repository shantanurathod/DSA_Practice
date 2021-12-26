#include <iostream>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n = 3;
    // cin >> n;

    int size = 2 * n - 1;

    int matrix[size][size];
    int b = 0;
    while (n >= 1)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == b || i == size - 1 - b || j == b || j == size - 1 - b)
                {
                    matrix[i][j] = n;
                }

                else
                {
                    matrix[i][j] = 0;
                }
            }
        }

        b++;
        n--;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cin.get();
    return 0;
}
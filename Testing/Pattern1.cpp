#include <iostream>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    cin >> n;

    int l = 2 * n - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            //for (int k = n; k >= 1; k--)
            {
                if (i == 1 || i == l || j == 1 || j == l)
                {
                    cout << n << " ";
                }

                else
                {
                    cout << n - i + 1 << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

void solve()
{
   int N, k = 2, result = 1;
        cin >> N;

        if(N > 2)
        {
            result++;
        }

        while ( k <= N/2)
        {
            int m = N;
            // while (m > k)
            // {
            //     m -= k;
            // }

            if(m%k == 1)
            {
                result++;
            }

            k++;
        }

        cout << result << endl; 
}
int main()
{
    int testcase;
    cin >> testcase;

    while(testcase--)
    {
        solve();
    }

    cin.get();
    return 0;
}
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// int main()
//{
//     int n;
//     cin >> n;
//
//     vector<int> heightsBallons(n);
//     multiset<int, greater<int>> heightsBallonsSet;
//
//     for (int i = 0; i < n; i++)
//     {
//         int height;
//         cin >> heightsBallons[i];
//         heightsBallonsSet.insert(heightsBallons[i]);
//     }
//
//     int j = n;
//     int amountArrows = 0;
//
//     while (n > 0)
//     {
//         amountArrows++;
//         // Extract the more high ballon
//         int heightArrow = *heightsBallonsSet.begin();
//         for (int i = 0; i < n; i++)
//         {
//             if (heightsBallons[i] == -1)
//             {
//                 continue;
//             }
//
//             if (heightsBallons[i] == heightArrow)
//             {
//                 heightsBallonsSet.erase(heightsBallonsSet.find(heightArrow));
//
//                 heightsBallons[i] = -1;
//
//                 heightArrow--;
//                 n--;
//             }
//         }
//     }
//
//     cout << amountArrows << endl;
//
//     return 0;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> heightsBallons(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heightsBallons[i];
    }

    int bustedBalloons = 0;
    int amountArrows = 0;
    while (bustedBalloons < n)
    {
        amountArrows++;
        int heightArrow = *max_element(heightsBallons.begin(), heightsBallons.end());
        for (int i = 0; i < n; i++)
        {
            int init = i;
            while (heightsBallons[i] == heightArrow)
            {
                heightsBallons[i] = -1;
                heightArrow--;
                bustedBalloons++;
                i++;
            }
            if (init != i)
            {
                heightsBallons.erase(heightsBallons.begin() + init, heightsBallons.begin() + i);
                i = init;
            }
            if (heightArrow == 0)
            {
                break;
            }
        }
    }
    cout << amountArrows << endl;
}
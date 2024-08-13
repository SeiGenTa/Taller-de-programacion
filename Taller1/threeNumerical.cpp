#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        vector<int> solOnlyInpar(3, -1);
        int indexSolOnlyInpar = 0;

        vector<int> solTwoParAndOneInpar(3, -1);
        int indexSolTwoParAndOneInpar = 0;
        bool withOneInpar = false;

        bool found = false;

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] % 2 != 0)
            {
                solOnlyInpar[indexSolOnlyInpar] = i + 1;
                indexSolOnlyInpar++;
                if (indexSolOnlyInpar == 3)
                {
                    found = true;
                    break;
                }
                if (!withOneInpar)
                {
                    solTwoParAndOneInpar[indexSolTwoParAndOneInpar] = i + 1;
                    withOneInpar = true;
                    indexSolTwoParAndOneInpar++;
                    if (indexSolTwoParAndOneInpar == 3)
                    {
                        found = true;
                        break;
                    }
                }
            }
            else
            {
                if (withOneInpar)
                {
                    solTwoParAndOneInpar[indexSolTwoParAndOneInpar] = i + 1;
                    indexSolTwoParAndOneInpar++;
                    if (indexSolTwoParAndOneInpar == 3)
                    {
                        found = true;
                        break;
                    }
                }
                else if (indexSolOnlyInpar < 2)
                {
                    solOnlyInpar[indexSolOnlyInpar] = i + 1;
                    indexSolOnlyInpar++;
                    if (indexSolOnlyInpar == 3)
                    {
                        found = true;
                        break;
                    }
                }
            }
        }

        if (!found)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            if (indexSolOnlyInpar == 3)
            {
                cout << solOnlyInpar[0] << " " << solOnlyInpar[1] << " " << solOnlyInpar[2] << endl;
            }
            else
            {
                cout << solTwoParAndOneInpar[0] << " " << solTwoParAndOneInpar[1] << " " << solTwoParAndOneInpar[2] << endl;
            }
        }
    }

    return 0;
}

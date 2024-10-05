#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    int sum_total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum_total += a[i];
    }

    if (sum_total % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    int mitad = sum_total / 2;

    // Caso sin tener que mover nada
    int sum_left = 0;
    int i = 0;
    while (i < n)
    {
        sum_left += a[i];
        if (sum_left == mitad)
        {
            cout << "YES" << endl;
            return 0;
        }
        if(sum_left > mitad){
            break;
        }
        i++;
    }

    // Caso en que se tiene que mover un elemento
    int diference = sum_left - mitad;
    for (int j = 0; j <= i; j++)
    {
        if (a[j] == diference)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    int sum_right = 0;
    i = n - 1;
    while (i > 0)
    {
        sum_right += a[i];
        if (sum_right == mitad)
        {
            cout << "YES" << endl;
            return 0;
        }
        if(sum_right > mitad){
            break;
        }
        i--;
    }

    diference = sum_right - mitad;
    for (int j = n - 1; j >= i; j--)
    {
        if (a[j] == diference)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
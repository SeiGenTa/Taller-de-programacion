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
    int sum_right = 0;
    int i = 0;
    while (i < n)
    {
        sum_left += a[i];
        if (sum_left == mitad)
        {
            cout << "YES" << endl;
            return 0;
        }
        if (sum_left > mitad)
        {
            sum_right = sum_total - (sum_left - a[i]); // Este es el caso en que se tiene que mover un elemento desde la derecha
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
    diference = sum_right - mitad;
    for(int j = i+1; j < n; j++){
        if(a[j] == diference){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
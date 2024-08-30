#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> booksDuration(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> booksDuration[i];
    }

    int howeverMax = 0;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right)
    {
        sum += booksDuration[right];

        // Contrae la ventana si la suma excede `t`
        while (sum > t)
        {
            sum -= booksDuration[left];
            left++;
        }

        // Calcula el número máximo de libros que se pueden leer
        howeverMax = max(howeverMax, right - left + 1);
    }

    cout << howeverMax << endl;

    return 0;
}

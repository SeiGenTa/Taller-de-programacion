#include <iostream>
#include <vector>
#include <list>

//PASA
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // Ignorar el salto de línea después de leer `n`

    for (int i = 0; i < n; i++)
    {
        string m;
        getline(cin, m);

        vector<char> resultado;
        list<int> minusculas;
        list<int> mayusculas;
        int amoutbs = 0;

        // Iterar sobre cada caracter de la cadena
        for (int i = 0; i < m.size(); i++)
        {
            char c = m[i];
            if (c == 'b')
            {
                // obtenemos el ultimo indice en minusculas y luego eliminamos el valor que esta en result con ese indice
                if (!minusculas.empty())
                {
                    resultado[minusculas.back()] = ' ';
                    minusculas.pop_back();
                }
                amoutbs++;
                continue;
            }
            if (c == 'B')
            {
                if (!mayusculas.empty())
                {
                    resultado[mayusculas.back()] = ' ';
                    mayusculas.pop_back();
                }
                amoutbs++;
                continue;
            }

            resultado.push_back(c);
            if (c >= 'a' && c <= 'z')
            {
                minusculas.push_back(i - amoutbs);
            }
            else if (c >= 'A' && c <= 'Z')
            {
                mayusculas.push_back(i - amoutbs);
            }
        }

        // Imprimir el resultado final
        for (char c : resultado)
        {
            if (c != ' ')
                cout << c;
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> mapa1(N);
    vector<string> mapa2(M);

    // Leer el primer mapa (de tamaño N×M)
    for (int i = 0; i < N; i++)
    {
        cin >> mapa1[i];
    }

    // Leer el segundo mapa (de tamaño M×N)
    for (int i = 0; i < M; i++)
    {
        cin >> mapa2[i];
    }

    // Encontrar la primera letra que no sea 'x' en el primer
    // Vamos saltando de N en N para encontrar la primera letra que no sea 'x'
    int i = 0;
    while (i < N && mapa1[i][0] == 'x')
    {
        i++;
    }

    // Encontrar la primera letra que no sea 'x' en el segundo
    // Para eso, vamos a comenzar desde la primera columna de cada fila
    // y iremos desde 0 hasta N - M + 1 buscando la primera letra que no sea 'x'
    int j = 0;
    while (j < N - M && mapa2[0][j] == 'x')
    {
        j++;
    }

    // Imprimir la posición de la primera letra que no sea 'x' en ambos mapas
    cout << i + 1 << " " << j + 1 << endl;

    return 0;
}

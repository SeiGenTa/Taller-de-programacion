#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heightsBallons(n);
    unordered_map<int, int> arrows; // Guarda cuántas flechas están disponibles para cada altura

    for (int i = 0; i < n; ++i) {
        cin >> heightsBallons[i];
    }

    int amountArrows = 0;

    for (int i = 0; i < n; ++i) {
        int height = heightsBallons[i];

        // Si ya existe una flecha en esta altura, la usamos para explotar este globo
        if (arrows[height] > 0) {
            arrows[height]--;  // Usamos la flecha
            arrows[height - 1]++;  // Esta flecha ahora puede explotar globos en altura - 1
        } else {
            // Si no hay flecha disponible, disparamos una nueva flecha
            amountArrows++;
            arrows[height - 1]++;  // Esta nueva flecha ahora puede explotar globos en altura - 1
        }
    }

    cout << amountArrows << endl;

    return 0;
}

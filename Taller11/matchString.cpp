#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Función para construir el arreglo de prefijos (o LPS - Longest Prefix Suffix)
vector<int> buildLPSArray(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Función para contar las ocurrencias del patrón en la cadena usando KMP
int countOccurrences(const string& str, const string& pattern) {
    int n = str.size();
    int m = pattern.size();

    // Si el patrón es más largo que la cadena, no puede haber ocurrencias
    if (m > n) return 0;

    // Construir el arreglo LPS para el patrón
    vector<int> lps = buildLPSArray(pattern);

    int i = 0;  // Índice para str
    int j = 0;  // Índice para pattern
    int count = 0;

    while (i < n) {
        if (str[i] == pattern[j]) {
            i++;
            j++;

            if (j == m) {
                count++;
                j = lps[j - 1];  // Continuar buscando en el resto de la cadena
            }
        } else {
            if (j > 0) {
                j = lps[j - 1];  // Utilizar el LPS para evitar comparaciones innecesarias
            } else {
                i++;
            }
        }
    }

    return count;
}

int main() {
    string str, pattern;

    cin >> str;
    cin >> pattern;

    int result = countOccurrences(str, pattern);

    cout << result << endl;

    return 0;
}

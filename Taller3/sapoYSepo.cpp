#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool checkWordAgainstLabel(const string& word, const vector<int>& label) {
    if (word.length() != label.size())
        return false;

    unordered_map<char, int> charToNumber;
    unordered_map<int, char> numberToChar;

    for (size_t i = 0; i < word.length(); ++i) {
        char ch = word[i];
        int num = label[i];

        if (charToNumber.find(ch) != charToNumber.end()) {
            if (charToNumber[ch] != num)
                return false;
        }

        if (numberToChar.find(num) != numberToChar.end()) {
            if (numberToChar[num] != ch)
                return false;
        }

        charToNumber[ch] = num;
        numberToChar[num] = ch;
    }

    return true;
}

int main() {
    int c;
    cin >> c;  // Número de cajas

    for (int i = 0; i < c; ++i) {
        int n;
        cin >> n;  // Cantidad de números en la etiqueta

        vector<int> label(n);
        for (int j = 0; j < n; ++j) {
            cin >> label[j];  // Elementos de la etiqueta
        }

        int m;
        cin >> m;  // Número de moldes

        for (int j = 0; j < m; ++j) {
            string word;
            cin >> word;

            if (checkWordAgainstLabel(word, label)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}

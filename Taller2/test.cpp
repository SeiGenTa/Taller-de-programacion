// test_program.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

void test_case(const std::string& input, const std::string& expected_output) {
    // Escribe la entrada en un archivo temporal
    std::ofstream input_file("input.txt");
    input_file << input;
    input_file.close();

    // Ejecuta el programa principal redirigiendo la entrada y salida
    std::system("./main_program < input.txt > output.txt");

    // Lee la salida generada
    std::ifstream output_file("output.txt");
    std::string output((std::istreambuf_iterator<char>(output_file)),
                        std::istreambuf_iterator<char>());
    output_file.close();

    // Compara la salida con la esperada
    if (output == expected_output) {
        std::cout << "Test Passed!\n";
    } else {
        std::cout << "Test Failed!\n";
        std::cout << "Expected: " << expected_output;
        std::cout << "Got: " << output;
    }
}

int main() {
    // Define tus casos de prueba
    test_case("5\n3 2 1 5 4\n", "3\n");
    test_case("6\n1 2 3 4 5 6\n", "6\n");
    test_case("7\n4 4 4 4 4 4 4\n", "1\n");
    test_case("5\n1 3 2 3 1\n", "3\n");
    test_case("8\n7 1 2 2 1 5 5 7\n", "4\n");

    return 0;
}
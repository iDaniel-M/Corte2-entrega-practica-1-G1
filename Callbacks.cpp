#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>
using namespace std;

// Definición de callbacks (ahora con float para soportar decimales)
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divideOp(float a, float b) { return a / b; }

// Función que recibe un callback y dos operandos
void performOperation(function<float(float, float)> callback, float x, float y) {
    cout << "Resultado: " << callback(x, y) << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Error: Debe ingresar exactamente 3 argumentos." << endl;
        cerr << "Uso: ./programa <operando1> <operador> <operando2>" << endl;
        return 1;
    }

    // Convertir operandos a float
    float op1 = atof(argv[1]);
    string operador = argv[2];
    float op2 = atof(argv[3]);

    // Declarar el callback
    function<float(float, float)> operation;

    // Selección de la operación
    if (operador == "+") {
        operation = add;
    } else if (operador == "-") {
        operation = subtract;
    } else if (operador == "*" || operador == "x" || operador == "X") {
        operation = multiply;
    } else if (operador == "/") {
        if (op2 == 0) {
            cerr << "Error: División entre cero no permitida." << endl;
            return 1;
        }
        operation = divideOp;
    } else {
        cerr << "Error: Operador no válido. Use +, -, *, x o /." << endl;
        return 1;
    }

    performOperation(operation, op1, op2);

    return 0;
}

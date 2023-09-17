#include <iostream>
using namespace std;
#include <string>
#include <cstring>

void angrystudents(string cadena);

void word(string cadena);

void sticks();

int main() {
    cout << "Bienvenido, elige una opcion" << endl;
    cout << "1. Angry Students" << endl;
    cout << "2. Word" << endl;
    cout << "3. Sticks" << endl;
    int opcion;
    cin >> opcion;
    switch (opcion)
    {
        case 1: {
            cout << "Ingresa la cadena" << endl;
            string cadena;
            cin >> cadena;
            angrystudents(cadena);
            break;
        }
        case 2: {
            cout << "Ingresa la cadena" << endl;
            string cadena;
            cin >> cadena;
            word(cadena);
            break;
        }
        case 3: {
            sticks();
            break;
        }
        default:
            cout << "Opcion no valida" << endl;
            break;
    }
    return 0;
}

void sticks() {
    cout << "Cuantos sticks deseas ingresar?" << endl;
    int snumber;
    cin >> snumber;
    int sticks[snumber];
    for (int i = 0; i < snumber; ++i) {
        cout << "Ingresa el valor del stick " << i << endl;
        cin >> sticks[i];
    }
    int aux;
    // Initialize lado1 and lado2 to distinct values
    int lado1 = 0;
    int lado2 = 0;

// Find two pairs of equal numbers on the array "sticks"
    for (int i = 0; i < snumber; ++i) {
        for (int j = i + 1; j < snumber; ++j) {
            if (sticks[i] == sticks[j]) {
                if (lado1 == 0) {
                    lado1 = sticks[i];
                    //cout << "Lado 1: " << lado1 << endl;
                    //cout << "Found in: " << sticks[i] << " and " << sticks[j] << endl;
                } else if (lado2 == 0 && sticks[i] != lado1) {
                    lado2 = sticks[i];
                    //cout << "Lado 2: " << lado2 << endl;
                    //cout << "Found in: " << sticks[i] << " and " << sticks[j] << endl;
                }
                if(lado1 != 0 && lado2 != 0 && sticks[i]>lado1){
                    lado1 = sticks[i];
                }else if(lado1 != 0 && lado2 != 0 && sticks[i]>lado2){
                    lado1 = sticks[i];
                }
            }
        }
    }

    cout << "Lado 1: " << lado1 << endl;
    cout << "Lado 2: " << lado2 << endl;
    cout << "Area: " << lado1 * lado2 << endl;
}

void word(string cadena) {
    cout << "Cadena: " << cadena << endl;
    cout << "Longitud: " << cadena.length() << endl;
    char char_array[cadena.length() + 1];
    int mayus = 0;
    int minus = 0;
    string final;
    strcpy(char_array, cadena.c_str());
    for (int i = 0; i < sizeof char_array; ++i) {
        if (isupper(char_array[i]) == true) {
            mayus++;
        } else {
            minus++;
        }
    }
    if (mayus > minus) {
        //convert the string cadena to uppercase and store that string into final
        for (int i = 0; i < cadena.size(); i++) {
            final += toupper(cadena[i]);
        }
        cout << "String en mayusculas: " << final << endl;
    } else {
        for (int i = 0; i < cadena.size(); ++i) {
            final += tolower(cadena[i]);
        }
        cout << "String en minusculas: " << final << endl;
    }
}

void angrystudents(string cadena) {
    cout << "Cadena: " << cadena << endl;
    cout << "Longitud: " << cadena.length() << endl;
    char char_array[cadena.length() + 1];
    strcpy(char_array, cadena.c_str());
    int turnos = 0;
    int aux = 0;
    for (int i = 0; i < sizeof char_array; ++i) {
        if (char_array[i] == 'A') {
            //cout << "A found in : " << i << endl;
            for (int j = i+1; j < sizeof char_array; ++j) {
                if (char_array[j] == 'P') {
                    //cout << "P found in : " << j << endl;
                    turnos++;
                }else{
                    if(aux<turnos){
                        aux = turnos;
                    }
                    turnos = 0;
                    break;
                }
            }
        }
    }
    cout << "Turnos totales: " << aux << endl;
}
#include <iostream>
using namespace std;
#include "personaje.hpp"
#include "arreglo.hpp"

Personaje capturarPersonaje() {
    Personaje p;
    string temp_s;
    float temp_f;

    cout << "Nombre: ";
    getline(cin, temp_s);
    p.setNombre(temp_s);

    cout << "Tipo: ";
    getline(cin, temp_s);
    p.setTipo(temp_s);

    cout << "Fuerza: ";
    cin >> temp_f;
    p.setFuerza(temp_f);

    cout << "Salud: ";
    cin >> temp_f;
    p.setSalud(temp_f);

    return p;
}
size_t capturarPosicion() {
    size_t pos;
    cout << "Posicion: ";
    cin >> pos; cin.ignore();

    return pos;
}
int main() {
    size_t tam;
    cout << "Cantidad: ";
    cin >> tam;

    Arreglo<Personaje> pers(tam);

    string op;
    while (true)
    {
        cout << "1) Agregar al final" << endl;
        cout << "2) Agregar al inicio" << endl;
        cout << "3) Insertar" << endl;
        cout << "4) Mostrar" << endl;
        cout << "5) Eliminar al final" << endl;
        cout << "6) Eliminar al inicio" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Cantidad" << endl;
        cout << "9) Capacidad" << endl;
        cout << "10) Estado" << endl;
        cout << "11) Frente" << endl;
        cout << "12) Ultimo" << endl;
        cout << "13) Buscar" << endl;
        cout << "14) Ordenar" << endl;
        cout << "0) Salir" << endl;
        cin >> op; cin.ignore();

        if (op == "1") {
            Personaje p = capturarPersonaje();
            pers.push_back(p);
        }
        else if (op == "2") {
            Personaje p = capturarPersonaje();
            pers.push_front(p);
        }
        else if (op == "3") {
            size_t pos = capturarPosicion();
            Personaje p = capturarPersonaje();
            pers.insert(p, pos);
        }
        else if (op == "4") {
            for (size_t i = 0; i < pers.size(); i++)
            {
                cout << pers[i] << endl;
            }
        }
        else if (op == "5") {
            pers.pop_back();
        }
        else if (op == "6") {
            pers.pop_front();
        }
        else if (op == "7") {
            size_t pos = capturarPosicion();
            pers.erase(pos);
        }
        else if (op == "8") {
            cout << "Cantidad: " << pers.size() << endl;
        }
        else if (op == "9") {
            cout << "Capacidad: " << pers.max_size() << endl;
        }
        else if (op == "10") {
            cout << "Lleno: " << pers.full() << endl;
            cout << "Vacio: " << pers.empty() << endl;
        }
        else if (op == "11") {
            cout << "Frente: " << pers.front() << endl;
        }
        else if (op == "12") {
            cout << "Ultimo" << pers.back() << endl;
        }
        else if (op == "13") {
            Personaje p = capturarPersonaje();
            Personaje* encontrado = pers.find(p);
            if (encontrado) {
                cout << "Encontrado" << endl;
                encontrado->setFuerza(0);
            } else {
                cout << "No encontrado" << endl;
            }
        }
        else if (op == "14") {
            size_t asc;
            cout << "Ascendente 1, Descendente 0: ";
            cin >> asc;
            pers.sort(asc);
        }
        else if (op == "0") {
            break;
        }
    }
    

    return 0;
}
#include <iostream>
#include <windows.h>
#include <wininet.h>

#pragma comment(lib, "wininet.lib")

using namespace std;

// XOR
string xorDecrypt(string data, char key) {
    for (int i = 0; i < data.size(); i++) {
        data[i] ^= key;
    }
    return data;
}

// STAGER
void connectToServer() {
    cout << "\n[+] Intentando conectar a servidor local\n";

    HINTERNET hInternet = InternetOpenA("agent", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    HINTERNET hConnect = InternetOpenUrlA(hInternet, "http://127.0.0.1:8080", NULL, 0, INTERNET_FLAG_RELOAD, 0);

    if (hConnect) {
        cout << "[+] Conexion exitosa (stager simulado)\n";
        InternetCloseHandle(hConnect);
    } else {
        cout << "[-] No se pudo conectar\n";
    }

    InternetCloseHandle(hInternet);
}

// INYECCION
void simulateInjection() {
    cout << "\n[+] Simulando inyeccion de memoria\n";

    LPVOID mem = VirtualAlloc(NULL, 1024, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    if (mem) {
        cout << "[+] Memoria RWX reservada correctamente\n";
    } else {
        cout << "[-] Error al reservar memoria\n";
    }
}

// POWERSHELL
void runPowerShell() {
    cout << "\n[+] Ejecutando PowerShell codificado (benigno)\n";
    system("powershell -EncodedCommand UwB0AGEAcgB0AC0AUAByAG8AYwBlAHMAcwAgAGMAYQBsAGMALgBlAHgAZQA=");
}

// ACCION VISIBLE
void openCalculator() {
    cout << "\n[+] Abriendo calculadora\n";
    WinExec("calc.exe", SW_SHOW);
}

// XOR DEMO
void runXOR() {
    cout << "\n[+] Ejecutando descifrado XOR\n";

    string encrypted = "\x1f\x0c\x17\x17\x0a";
    string decrypted = xorDecrypt(encrypted, 0x55);

    cout << "[+] Resultado: " << decrypted << endl;
}

// MENU
void showMenu() {
    cout << "\n TEAM5 PAYLOAD MENU \n";
    cout << "1. Descifrado XOR\n";
    cout << "2. Stager (conexion local)\n";
    cout << "3. Simulacion de inyeccion\n";
    cout << "4. PowerShell fileless\n";
    cout << "5. Abrir calculadora\n";
    cout << "0. Salir\n";
    cout << "Selecciona una opcion: ";
}

int main() {
    int option;

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                runXOR();
                break;
            case 2:
                connectToServer();
                break;
            case 3:
                simulateInjection();
                break;
            case 4:
                runPowerShell();
                break;
            case 5:
                openCalculator();
                break;
            case 0:
                cout << "\n[+] Saliendo...\n";
                break;
            default:
                cout << "\n[-] Opcion invalida\n";
        }

        if (option != 0) {
            cout << "\nPresiona ENTER para volver al menu...";
            cin.ignore();
            cin.get();
        }

    } while (option != 0);

    return 0;
}
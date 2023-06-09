#include <iostream>


using namespace std;

int main()
{    
    cout << "WSTI" << " --GRUPA-- " << 2 << "DZI " << "Damian" << " " << "Potoczny" << endl;
    cout << "Modul 3 "<< "Tablice " << "Zadanie 3"<< endl;
    int count;
    char character;
    char tab_ASCII[127];

    for(count = 0; count < 127 ; count++)
    {
        character = count;
        tab_ASCII[count] = character;
    }
    cout << "Aby wydrukowac tablice, ";
    system("pause");
    cout << endl;
    for(count = 0; count < 127 ; count++)
    {
        cout << count << ": " << tab_ASCII[count] << endl;
    }
    system("pause");
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int rowsMatrixA, rowsMatrixB;
int columnsMatrixA, columnsMatrixB;
vector<int> matrixA, matrixB, matrixProduct;

void print(vector<int> matrix, int columns, int rows)
{
    for (int row = 0; row < rows; row++) {
        cout << "\t";
        for (int col = 0; col < columns; col++) {
            cout << matrix.at((row*columns)+col) << "\t";
        }
        cout << endl;
    }
}

bool checkMatrix()
{
    return (rowsMatrixB==columnsMatrixA) && (rowsMatrixB !=0);
}

void loadMatrix()
{
    cout << "Podaj ilosc kolumn Macierzy A" << endl;
    cin >> columnsMatrixA;
    cout << "Podaj ilosc wierszy Macierzy A" << endl;
    cin >> rowsMatrixA;
    if(columnsMatrixA&&rowsMatrixA)
    {
        for(int r=0; r< rowsMatrixA ; r++)
            for(int c= 0; c< columnsMatrixA ; c++)
            {
                int value;
                cout << "Podaj wartosc " << c+1 << " kolumny i " << r+1 << " wiersza" << endl;
                cin >> value;
                matrixA.emplace_back(value);
            }
    cout << "Podaj ilosc kolumn Macierzy B" << endl;
    cin >> columnsMatrixB;
    cout << "Podaj ilosc wierszy Macierzy B" << endl;
    cin >> rowsMatrixB;
    if(columnsMatrixB&&rowsMatrixB)
    {
        for(int r=0; r< rowsMatrixB ; r++)
            for(int c= 0; c< columnsMatrixB ; c++)
            {
                int value;
                cout << "Podaj wartosc " << c+1 << " kolumny i " << r+1 << " wiersza" << endl;
                cin >> value;
                matrixB.emplace_back(value);
            }
    }
    if(checkMatrix())
    {
        int range = (columnsMatrixB<rowsMatrixA)? columnsMatrixB: rowsMatrixA;
        for (int row = 0; row < range; row++) {
            for (int col = 0; col < range; col++) {
                int vProduct=0;
                for (int inner = 0; inner < columnsMatrixA; inner++) {
                    vProduct += matrixA.at((row*columnsMatrixA)+inner) * matrixB.at((inner*columnsMatrixB)+col);
                }
                matrixProduct.emplace_back(vProduct);
            }
        }
        cout << endl << endl << endl;
        print(matrixA, columnsMatrixA, rowsMatrixA);
        cout << endl << endl << "\t*" << endl << endl;
        print(matrixB, columnsMatrixB, rowsMatrixB);
        cout << endl << endl << "\t=" << endl << endl;
        print(matrixProduct, range, range);

    }
    else
        cout << "Mnozenie nie moze zostac wykonane" << endl; 
    }
}

int main()
{    
    cout << "WSTI" << " --GRUPA-- " << 2 << "DZI " << "Damian" << " " << "Potoczny" << endl;
    cout << "Modul 3 "<< "Tablice " << "Zadanie 4"<< endl;

    cout << "Mnozenie dwoch macierzy" << endl;
    char exit = 'n';
    
    while(exit == 'n')
    {
        loadMatrix();

        cout << "Nacisnij 'n' aby wykonac jeszcze raz mnozenie macierzy" << endl;
        cin >> exit;

        matrixA.clear();
        matrixB.clear();
        matrixProduct.clear();
    };
}
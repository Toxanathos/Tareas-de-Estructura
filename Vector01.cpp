/****************
     TAREA 1

- Emanuel Hernán Cabeza Lucas
-Anderson Alexis Varillas saldaña

*****************/

#include <iostream>
using namespace std;

int gVect[100];
int gnCount = 0;


void Insert(int elem)
{
    if (gnCount < 100)
        gVect[gnCount++] = elem;
}


int Search(int elem)
{
    for (int i = 0; i < gnCount; i++)
    {
        if (gVect[i] == elem)
            return i;
    }
    return -1;
}

void Delete(int elem)
{
    int index = Search(elem);
    if (index != -1)
    {
        for (int i = index; i < gnCount - 1; i++)
        {
            gVect[i] = gVect[i + 1];
        }
        gnCount--;
        cout << "Elemento " << elem << " eliminado correctamente.\n";
    }
    else
    {
        cout << "Elemento " << elem << " no encontrado.\n";
    }
}

void Display()
{
    cout << "Elementos en el arreglo: ";
    for (int i = 0; i < gnCount; i++)
    {
        cout << gVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << gnCount << endl;
}

int main(int argc, char* argv[])
{
    Insert(10);
    Insert(20);
    Insert(30);

    cout << "Antes de borrar:\n";
    Display();

    Delete(20);

    cout << "Despues de borrar:\n";
    Display();  /

    return 0;
}

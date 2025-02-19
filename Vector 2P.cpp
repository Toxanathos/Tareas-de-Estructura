#include <iostream>
using namespace std;

/****************
     TAREA 1
ANDERSON ALEXIS VARILLAS SALDAÑA
EMANUEL HERNÁN CABEZA LUCAS

*****************/

int *gpVect = NULL;
int gnCount = 0;
int gnMax = 0;

void Resize();

void Insert(int elem)
{
	if( gnCount == gnMax )
		Resize();
	gpVect[gnCount++] = elem;
}

void Resize()
{
	const int delta = 5;
	int *pTemp, i;
	pTemp = new int[gnMax + delta];
	for(i = 0 ; i < gnMax ; i++)
		pTemp[i] = gpVect[i];
	delete [ ] gpVect;
	gpVect = pTemp;
	gnMax += delta;
}

bool Search(int elem, int *pos) 
{
    *pos=-1;
    for (int i=0; i<gnCount; i++) 
	{
        if (gpVect[i]==elem) 
		{
            *pos=i;
            return true;
        }
    }
    return false;
}

void Delete(int elem) 
{
    int pos;
    if (Search(elem, &pos)) 
	{
        for (int i=pos+1; i<gnCount; i++) 
		{ 
            gpVect[i-1]=gpVect[i];
        }
        gnCount--;
        cout<<"Elemento "<<elem<<" eliminado exitosamente."<<endl;
    } 
	    else 
	    {
        cout<<"Elemento "<<elem<<" no existe."<<endl;
        }
}

void Display()
{
	cout << "Elementos en el arreglo: ";
	for (int i = 0; i < gnCount; i++) 
	{
		cout << gpVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << gnCount <<endl;
}



int main(int argc, char *argv[]) 
{
	Insert(10);
	Insert(20);
	Insert(30);
	Insert(40);
	Insert(50);
	
	Display();

	Delete(40);
	
	Display();

	Insert(60);

	Display();
	
	return 0;
}
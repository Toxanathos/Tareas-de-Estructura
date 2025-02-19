#include <iostream>
using namespace std;

/****************
     TAREA 1
ANDERSON ALEXIS VARILLAS SALDAÑA
EMANUEL HERNÁN CABEZA LUCAS

*****************/

struct Vector
{
	int*m_pVect,
		m_nCount,
		m_nMax,
		m_nDelta;
};

void Resize(Vector *pThis);


void Insert(Vector *pThis, int elem)
{
	if( pThis->m_nCount == pThis->m_nMax )
		Resize(pThis);
	
	pThis->m_pVect[pThis->m_nCount++] = elem;
}
void Resize(Vector *pThis)
{
	
	const int delta = 5;
	int *pTemp, i;
	pTemp = new int[pThis->m_nMax + pThis->m_nDelta];
	for(i = 0 ; i < pThis->m_nMax ; i++)
		pTemp[i] = pThis->m_pVect[i];
	delete [ ] pThis->m_pVect;
	pThis->m_pVect = pTemp;
	pThis->m_nMax += pThis->m_nDelta;
	
}

bool Search(Vector *pThis, int elem, int &pt) 
{
    for (int i=0; i<pThis->m_nCount; i++) 
	{
        if (pThis->m_pVect[i]==elem) 
		{
            pt=i;
            return true;
        }
    }
    pt=-1;
    return false;
}

void Delete(Vector *pThis, int elem) 
{
    int pt;
    if (Search(pThis, elem, pt)) 
	{
        for (int i=pt+1; i<pThis->m_nCount; i++) 
		{
            pThis->m_pVect[i-1]=pThis->m_pVect[i];
        }
        pThis->m_nCount--;
        cout<<"Elemento eliminado exitosamente."<<endl;
    } 
	    else 
		{
        cout<<"Elemento "<<elem<<" no encontrado en el arreglo."<<endl;
        }
}

void Display(Vector *pThis)
{
	cout << "Elementos en el arreglo: ";
	for (int i = 0; i < pThis->m_nCount; i++) 
	{
		cout << pThis->m_pVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << pThis->m_nCount <<endl;
}



int main(int argc, char *argv[]) 
{
	Vector myVect;
	myVect.m_nCount = 0;
	myVect.m_nMax = 0;
	myVect.m_nDelta = 5;
	
		
	Insert(&myVect, 10);
	Insert(&myVect, 20);
	Insert(&myVect, 30);
		
	Display(&myVect);

	Delete(&myVect, 30);

	Display(&myVect);
	
	return 0;
}
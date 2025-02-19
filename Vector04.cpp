/****************
     TAREA 4

- Emanuel Hernán Cabeza Lucas
-Anderson Alexis Varillas saldaña

*****************/

#include <iostream>
using namespace std;

class CVector {
private:
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Init(int delta);
    void Resize();

public:
    CVector(int delta = 10);
    ~CVector();
    void Insert(int elem);
    void Display() const;
};

void CVector::Init(int delta) {
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}


CVector::CVector(int delta) {
    Init(delta);


CVector::~CVector() {
    delete[] m_pVect;
}


void CVector::Resize() {
    int* pTemp = new int[m_nMax + m_nDelta];
    for (int i = 0; i < m_nMax; i++) {
        pTemp[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}


void CVector::Insert(int elem) {
    if (m_nCount == m_nMax) {
        Resize();
    }
    m_pVect[m_nCount++] = elem;
}


void CVector::Display() const {
    cout << "Elementos en el vector: ";
    for (int i = 0; i < m_nCount; i++) {
        cout << m_pVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << m_nCount << endl;
}

int main(int argc, char* argv[]) {
    CVector myVector(5);

    myVector.Insert(10);
    myVector.Insert(20);
    myVector.Insert(30);
    myVector.Insert(40);
    myVector.Insert(50);
    myVector.Insert(60);

    myVector.Display();

    return 0;
}

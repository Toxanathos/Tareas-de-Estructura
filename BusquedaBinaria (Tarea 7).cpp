#include <iostream>
using namespace std;
/****************
     TAREA 7 BUSQUEDA BINARIA
ANDERSON ALEXIS VARILLAS SALDAÑA
EMANUEL HERNÁN CABEZA LUCAS

*****************/

class CVector {
	private:
		int* m_pVect; 
		int m_nCount; 
		int m_nMax;  
		int m_nDelta; 
		

		void Init(int delta) {
			m_nCount = 0;
			m_nMax = delta;
			m_nDelta = delta;
			m_pVect = new int[m_nMax];
		}
		

		void Resize() {
			m_nMax += m_nDelta; 
			int* temp = new int[m_nMax]; 
			for (int i = 0; i < m_nCount; i++) {
				temp[i] = m_pVect[i]; 
			}
			delete[] m_pVect;
			m_pVect = temp;
		}
		
	public:
			
			CVector(int delta = 10) {
				Init(delta);
			}
			
			
			void Insert(int elem) {
				if (m_nCount == m_nMax) { 
					Resize(); 
				}
				m_pVect[m_nCount++] = elem; 
			}
			
			
			void Display() {
				for (int i = 0; i < m_nCount; i++) {
					cout << m_pVect[i] << " ";
				}
				cout << endl;
			}
			
			
			int BinarySearchRecursive(int left, int right, int target) 
			{
				if (left <= right) 
				{
					int mid = left + (right - left) / 2;
					
					
					if (m_pVect[mid] == target) 
					{
						return mid; 
					}
					
					
					if (m_pVect[mid] > target) 
					{
						return BinarySearchRecursive(left, mid - 1, target);
					}
					
					
					return BinarySearchRecursive(mid + 1, right, target);
				}
				
				return -1; 
			}
			
			int SearchBinIter(int key) 
			{
				int begin=0;
				int fin=m_nCount-1;

				while (begin<=fin) 
				{
					int mid=begin+(fin-begin)/2;
					if (m_pVect[mid]==key)
						return mid;
					else if (m_pVect[mid]>key)
						fin=mid-1;
					else
						begin=mid+1;
				}
				return -1;
			}
			
			
			int GetCount() const 
			{
				return m_nCount;
			}
			
			
			~CVector() {
				delete[] m_pVect;
			}
	};
	
	
	int main() {
		CVector gVect; 
		
		
		gVect.Insert(5);
		gVect.Insert(10);
		gVect.Insert(15);
		gVect.Insert(20);
		gVect.Insert(30);
		gVect.Insert(50);
		
		cout << "Elementos en el vector: ";
		gVect.Display();
		
		
		int target = 20;
		int target2=30;
		int result = gVect.BinarySearchRecursive(0, gVect.GetCount() - 1, target);
		
		
		if (result != -1) 
		{
			cout << "Elemento " << target << " encontrado en la posición: " << result << endl;
		} 
		else 
		{
			cout << "Elemento " << target << " no encontrado." << endl;
		}

		int result2=gVect.SearchBinIter(target2);
		
		if (result2!=-1) 
		{
			cout << "Elemento " << target2 << " encontrado en la posición: " << result2 << endl;
		} 
		else 
		{
			cout << "Elemento " << target2 << " no encontrado." << endl;
		}
		
		return 0;
	}
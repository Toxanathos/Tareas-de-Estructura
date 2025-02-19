#include <iostream>
using namespace std;


class CVector
{
private:
	int* m_pVect;
	int m_nCount;
	int m_nMax;
	int m_nDelta;


	void Init(int delta)
	{
		m_nCount = 0;
		m_nMax   = delta;
		m_nDelta = delta;
		m_pVect  = new int[m_nMax];
	}


	void Resize()
	{
		m_nMax += m_nDelta;
		int* temp = new int[m_nMax];
		for (int i = 0; i < m_nCount; i++)
		{
			temp[i] = m_pVect[i];
		}
		delete[] m_pVect;
		m_pVect = temp;
	}

public:

		CVector(int delta = 10)
		{
			Init(delta);
		}

		void Insert(int elem)
		{
			if (m_nCount == m_nMax)
			{
				Resize();
			}
			m_pVect[m_nCount++] = elem; r
		}


		void Display()
		{
			for (int i = 0; i < m_nCount; i++)
			{
				cout << m_pVect[i] << " ";
			}
			cout << endl;
		}

		void BubbleSort()
		{
			bool swapped;
			for (int i = 0; i < m_nCount - 1; i++)
			{
				swapped = false;
				for (int j = 0; j < m_nCount - i - 1; j++)
				{
					if (m_pVect[j] > m_pVect[j + 1])
					{

						int temp = m_pVect[j];
						m_pVect[j] = m_pVect[j + 1];
						m_pVect[j + 1] = temp;
						swapped = true;
					}
				}

				if (!swapped) break;
			}
		}


		void SelectionSort()
		{
			for (int i = 0; i < m_nCount - 1; i++)
			{
				int min_idx = i;
				for (int j = i + 1; j < m_nCount; j++)
				{
					if (m_pVect[j] < m_pVect[min_idx])
						min_idx = j;
				}
				if (min_idx != i)
				{
					int temp = m_pVect[i];
					m_pVect[i] = m_pVect[min_idx];
					m_pVect[min_idx] = temp;
				}
			}
		}


		~CVector()
		{
			delete[] m_pVect;
		}
};


int main()
{
	CVector gVect;


	gVect.Insert(10);
	gVect.Insert(20);
	gVect.Insert(30);
	gVect.Insert(5);
	gVect.Insert(50);
	gVect.Insert(15);

	cout << "Antes de ordenar: ";
	gVect.Display();


	gVect.SelectionSort();

	cout << "Después de ordenar: ";
	gVect.Display();

	return 0;
}

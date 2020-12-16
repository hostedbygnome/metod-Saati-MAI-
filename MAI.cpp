#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int m; //���-�� ���������
	cout << "������� ���-�� ���������: ";
	cin >> m;
	double** dinamic_array2 = new double* [m + 2];   // ������� ��������� ������
	for (int i = 0; i < m + 2; i++) {         
		dinamic_array2[i] = new double[m + 2]; 
	}
	for (int i = 0; i < m; i++) // ���� ������� ������
	{
		for (int j = i + 1; j < m; j++)
		{
			cout << "������� �����������" << "(" << i + 1 << ")" << "(" << j + 1 << ")"  ":";
			cin >> dinamic_array2[i][j];
		}
	}
	for (int i = 0; i < m; i++) // 1 �� ���������
	{
		for (int j = 0; j < m; j++)
		{
			dinamic_array2[i][i] = 1;
		}
	} 
	for (int j = 0; j < m; j++) // ������ ��������� �������������
	{
		for (int i = j + 1; i < m; i++)
		{
			dinamic_array2[i][j] = 1 / dinamic_array2[j][i];
		}
	} 
	

	for (int i = 0; i < m; i++) //������ ����� �� ������
	{
		dinamic_array2[i][m] = 0;
		for (int j = 0; j < m; j++)
		{
			dinamic_array2[i][m] += dinamic_array2[i][j];
		}
	}
	double summ = 0;
	double summcoef = 0;
	for (int i = 0; i < m; i++) //������ ����� ���� ���������
	{

		for (int j = 0; j < m; j++)
		{
		}
		summ += dinamic_array2[i][m];
	}
	
	for (int i = 0; i < m; i++) //������ ������� �������������
	{
		for (int j = 0; j < m; j++)
		{
			dinamic_array2[i][m + 1] = dinamic_array2[i][m] / summ;
		}
	}

	for (int i = 0; i < m; i++) //������ ����� ������� �������������
	{

		for (int j = 0; j < m; j++)
		{
		}
		summcoef += dinamic_array2[i][m + 1];
	}

	cout << endl;
	//����� 
	for (int i = 0; i < m; i++)
	{	
		
		for (int j = 0; j < m + 2; j++)
		{
			if (j == m + 1)
			{
				cout << setw(5) << round(dinamic_array2[i][j] * 100) / 100;
			}
			else
			{
				cout << setw(5) << round(dinamic_array2[i][j] * 100) / 100 << " | ";
			}

		}
		cout << endl;
	}
	cout << "\n����� ���� ��������� = " << round(summ * 100) / 100 << endl; 
	cout << "\n����� ���� ������� �������������  = " << round(summcoef * 100) / 100 << endl;

	return 0;
}
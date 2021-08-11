#include <iostream>
using namespace std;
const int rows = 3;
int rows1 = rows;
float Matrix_2x2det(float a, float b, float c, float d)
{
	return (a*d)-(b*c);
}

float Calculate_Determinant(float arr[][rows], int rows)
{
	float *arr1 = new float [rows];

	int i = 0, j = 0, k = 0, m = 0, det = 0, n = 0, determinant = 0, temp = 0, count = 0;
	float temp1 = 0;
	for (int i = 0; i<rows; i++)
	{
		for (m = 0; m<rows; m++)
		{
			arr1 [m] = m/*+i*/;
		}

		j = i+1;
		k = i+2;
		if (j>=rows)
			j -= rows;
		if (k>=rows)
			k -= rows;
		if (arr1 [j]>=rows)
			arr1 [j] -= rows;
		if (arr1 [k]>=rows)
			arr1 [k] -= rows;
		j = arr1 [j];
		k = arr1 [k];
		/*temp = i;*/
		if (rows1>3)
		{
			rows1--;
			count++;
		}
		else
		{
			temp1 += arr [temp][i]*Matrix_2x2det(arr [temp+1][j], arr [temp+1][k], arr [temp+2][j], arr [temp+2][k]);
			n++;
		}
	}
	return temp1;
}

int main()
{
	float arr [rows][rows] = {};
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<rows; j++)
			cin>>arr [i][j];
	}
	cout<<Calculate_Determinant(arr, rows);
	system("pause");
	return 0;
}
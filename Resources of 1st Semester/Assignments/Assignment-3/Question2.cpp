#include <iostream>
using namespace std;

int main()
{
	const int size1 = 8, size2 = 5, size3 = 13;
	int i = 0, j = 0, k = 0, temp1 = 0, temp2 = 0;
	bool found = false;
	int arr1 [size1] = {}, arr2 [size2] = {}, arr3 [size3] = {};
	cout<<"\n\t\tInput "<<size1<<" integer(s) for first array in descending order.\n";
	cout<<"Enter the number : ";
	cin>>arr1 [i];
	for (i = 1; i<size1;)
	{
		cout<<"Enter the number : ";
		cin>>arr1 [i];
		if (arr1 [i]<=arr1 [i-1])
			i++;
		else
			cout<<"\nEnter correct Input!\n";
	}
	cout<<"\n\t\tInput "<<size2<<" integer(s) for second array in descending order.\n";
	i = 0;
	cout<<"Enter the number : ";
	cin>>arr2 [i];
	for (i = 1; i<size2;)
	{
		cout<<"Enter the number : ";
		cin>>arr2 [i];
		if (arr2 [i]<=arr2 [i-1])
			i++;
		else
			cout<<"\nEnter correct Input!\n";
	}

	for (i = size1-1, j = size2-1; ((temp1==0)||(temp2==0))&&(k<size3);)
	{
		if ((((arr1 [i]<=arr2 [j])||(temp2==-1)))&&(temp1==0))
		{
			arr3 [k++] = arr1 [i--];	
			if (i==-1)
			{
				temp1 = -1;
				i = 0;
			}
		}
		else if (((j>=0)||(temp1==-1)||(arr1 [i]>=arr2 [j]))&&(temp2==0))
		{
			arr3 [k++] = arr2 [j--];
			if (j==-1)
			{
				temp2 = -1;
				j = 0;
			}
		}
	}
	cout<<"\n\nData is copied and merged in third array successfully!\n\n\tCopied data is given by ;\n";
	for (i = 0; i<(size3); i++)
		cout<<arr3 [i]<<" ";
	cout<<endl<<endl;

	system("pause");
	return 0;
}
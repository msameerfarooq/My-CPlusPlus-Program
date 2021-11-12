#include <iostream>
using namespace std;

int main()
{
	const int size = 50;
	int size1, searchValue = 0, i = 0, l, r, m1 = 0, m2 = 1;
	bool found = false,flag=true;
	int arr [size];
	cout<<"Enter the size of array : ";
	cin>>size1;
	cout<<"Enter the number : ";
	cin>>arr [i++];
	for (i = 1; i<size1; i++)
	{
		flag = true;
		while (flag==true)
		{
			cout<<"Enter the number : ";
			cin>>arr [i];
			if (arr [i]>=arr [i-1])
				cout<<"\nInput terms in descending order.\n";
			else
				flag = false;
		}
	}
	cout<<"\nEnter the search value : ";
	cin>>searchValue;
	l = arr [0];
	r = arr [0];
	for (i = 0; i<size1; i++)
	{
		if (l>arr [i])
			l = arr [i];
		if (r<arr [i])
			r = arr [i];
	}
	for (i = 0; (found==false)&&(m1<m2)&&(i<size); i++)
	{
		m1 = l+(r-l)/3;
		m2 = r-(r-l)/3;

		if (searchValue==m1||searchValue==m2)
			found = true;
		else if (searchValue<m1)
			r = m1-1;
		else if (searchValue>m2)
			l = m2+1;
	}

	if (found==true)
		cout<<"\nValue is Found!\n";
	else
		cout<<"\nValue not found!\n";

	system("pause");
	return 0;
}


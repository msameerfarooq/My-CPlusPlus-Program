#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void Print(int terms, int deg[], int coef[])
{
	bool flag = true, isPolynomial = false;
	for (int i = 0; !((deg [i]==-1)&&(coef [i]==-1))&&(i<terms); i++)
	{
		if (coef [i]!=0)
		{
			isPolynomial = true;
			if (i!=0)
			{
				if (coef [i]>0)
				{
					cout<<" + ";
					flag = true;
				}
				else
				{
					coef [i] *= -1;
					cout<<" - ";
					flag = false;
				}
			}
			if (coef [i]!=1)		//If coefficient is 1 then it will not display it.
				cout<<coef [i];
			if (flag==false)		//It returns the original value to array.
				coef [i] *= -1;
			if (deg [i]>0)			//If degree is 0 then only coefficient is displayed.
				cout<<"x^"<<deg [i];
		}
	}
	if (isPolynomial = false)
		cout<<"0";
	cout<<endl<<endl;
}

void Input(int terms, int deg[], int coef[])
{
	int i = 0, j = 0;
	bool flag = true;
	while (i<1)
	{
		cout<<"Enter the coefficients of term : ";
		cin>>coef [i];
		while (i<1)
		{
			cout<<"Enter the degree of term : ";
			cin>>deg [i];
			if (deg [i]<0)
				cout<<"\nInvalid Input.\tDegree of Polynomial equation can not be negative.\n";
			else if (deg [i]<=15)
			{
				i++;
			}
			else
				cout<<"Invalid Input.\tDegree of Polynomial should be less than 16.\n";
		}
	}
	j = i;
	while (i<terms)
	{
		if (deg [i-1]==0)
		{
			i = terms;
			cout<<"\nSince degree is zero therefore further more no terms can be entered.\n";
		}
		else
		{
			cout<<"Enter the coefficients of term : ";
			cin>>coef [i];
			while (flag==true)
			{
				{
					cout<<"Enter the degree of term : ";
					cin>>deg [i];
					if (deg [i]>=deg [i-1])
						cout<<"\nInput degree of terms in descending order.\n";
					else if (deg [i]<0)
						cout<<"\nDegree of Polynomial equation can not be negative.\n";
					else
						flag = false;
				}

			}
			flag = true;
			i++;	 // i is used to control the loop.
			j++;	// j is used to count the number of enteries.
		}
	}
	if (j<15)
	{
		coef [j] = -1;		//assigning -1 is to sentinal the loop.
		deg [j] = -1;
	}
}

void FileInput(int &terms, int deg[], int coef[])
{
	ifstream fin;
	fin.open("Polynomial.txt");
	int i = 0, reader = 0;
	fin>>reader;
	terms = reader;
	for (i = 0; i<terms; i++)
	{
		fin>>reader;
		coef [i] = reader;
	}
	for (i = 0; i<terms; i++)
	{
		fin>>reader;
		deg [i] = reader;
	}
	if (terms<15)
	{
		coef [terms] = -1;
		deg [terms] = -1;
	}
	cout<<"\nInput has been taken from file!\n";
	fin.close();
}

int Solve(int terms, int deg[], int coef[], int variable)
{
	int result = 0, i = 0, j = 0;
	Input(terms, deg, coef);
	for (i = 0; i<terms; i++)
	{
		result += (coef [i]*pow(variable, deg [i]));
	}
	return result;
}

void Add(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[])
{
	int i = 0, j = 0, k = 0;
	bool flag1 = true, flag2 = true;

	for (j = 0, i = 0; (i<aterms)||(j<bterms);)
	{
		if (adeg [i]==bdeg [j])
		{
			rcoef [k] = acoef [i]+bcoef [j];
			rdeg [k] = adeg [i];
			i++;
			j++;
			k++;
		}
		else if ((((adeg [i]>bdeg [j])||(flag2==false))&&(flag1==true)))
		{
			rcoef [k] = acoef [i];
			rdeg [k] = adeg [i];
			i++;
			k++;
		}
		else if (flag2==true)
		{
			rcoef [k] = bcoef [j];
			rdeg [k] = bdeg [j];
			j++;
			k++;
		}
		if ((acoef [i]==-1)&&(adeg [i]==-1))
			flag1 = false;
		if ((bcoef [j]==-1)&&(bdeg [j]==-1))
			flag2 = false;
	}
	if (k<15)
	{
		rcoef [k] = -1;
		rdeg [k] = -1;
	}
}

void Multiply(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[])
{
	rterms = aterms*bterms;
	int i = 0, j = 0, k = 0;
	for (i = 0; i<aterms; i++)
	{
		for (j = 0; j<bterms; j++)
		{
			rcoef [k] = acoef [i]*bcoef [j];
			rdeg [k] = adeg [i]+bdeg [j];
			k++;
		}
	}
	rcoef [k] = -1;
	rdeg [k] = -1;

	int temp = 0;
	for (int h = 0, k = 0; h<5; h++)
	{
		for (i = 0; i<rterms; i++)
		{
			for (j = i+1; j<(rterms); j++)
			{
				if (!((rdeg [j-1]==-1)&&(rcoef [j-1]==-1)))
				{
					if (rdeg [i]==rdeg [j])
					{
						rcoef [i] += rcoef [j];
						rdeg [j] = -1;
						rcoef [j] = -1;
						for (; j<rterms; j++)
						{
							rcoef [j] = rcoef [j+1];
							rdeg [j] = rdeg [j+1];
						}
						k++;
					}
				}
			}
		}
	}
}

void Subtract(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[])
{
	int i = 0, j = 0, k = 0;
	bool flag1 = true, flag2 = true;

	for (j = 0, i = 0; (i<aterms)&&(j<bterms);)
	{
		if (adeg [i]==bdeg [j])
		{
			rcoef [k] = acoef [i]-bcoef [j];
			rdeg [k] = adeg [i];
			i++;
			j++;
			k++;
		}
		else if ((adeg [i]>bdeg [j])||(flag2==false)&&(flag1==true))
		{
			rcoef [k] = acoef [i];
			rdeg [k] = adeg [i];
			i++;
			k++;
		}
		else if (flag2==true)
		{
			rcoef [k] = -1*bcoef [j];
			rdeg [k] = bdeg [j];
			j++;
			k++;
		}
		if ((acoef [i]==-1)&&(adeg [i]==-1))
			flag1 = false;
		if ((bcoef [j]==-1)&&(bdeg [j]==-1))
			flag2 = false;
	}
	if (k<15)
	{
		rcoef [k] = -1;
		rdeg [k] = -1;
	}
}

bool Equal(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[])
{
	int i = 0, j = 0, k = 0;
	bool flag1 = true, flag2 = true, isEqual = true;;
	for (i = 0, j = 0; (flag1==true)&&(flag2==true)&&(j<16)&&(i<16); i++, j++)
	{
		if (adeg [i]!=bdeg [i])
			isEqual = false;
		if (acoef [i]!=bcoef [i])
			isEqual = false;

		if ((acoef [i]==-1)&&(adeg [i]==-1))
			flag1 = false;
		if ((bcoef [i]==-1)&&(bdeg [i]==-1))
			flag2 = false;
	}
	return isEqual;
}

void Menu()
{
	int var = 0;
	char choice = '0';
	bool flag = false, counter = true;
	int terms = 0, deg [16], coef [16], variable = 0, temp = 0;
	int aterms = 0, adeg [16], acoef [16], bterms = 0, bdeg [16], bcoef [16], rterms = 0, rdeg [256], rcoef [256];
	while (counter==true)
	{
		/*system("CLS");*/
		cout<<"\tThis calculator is designed by M Sameer Farooq.\n";
		cout<<"\n\n";
		cout<<"0-->Exit the program\n1-->Input Polynomial Equation\n2-->Input from File\n3-->Solve the Function\n4-->Add two Polynomials\n5-->Multiply two Polynomials\n6-->Subtract two Polynomials\n7-->Print the Polynomial\n8-->Equal Function\n\n\t\tEnter your choice : ";
		cin>>choice;

		if (choice=='0')
		{
			counter = false;
		}
		else if (choice=='1')
		{
			while (flag==false)
			{
				cout<<"Enter the number of terms : ";
				if (temp%2==0)
					cin>>aterms;
				else
					cin>>bterms;
				if ((aterms<=16)&&(aterms>0))
					flag = true;
				else
					cout<<"\n\t\tInvalid Input\nNumber of terms should be less than equals to 16.\n\n";
			}

			if (temp%2==0)
			{
				Input(aterms, adeg, acoef);
				cout<<"\nPolynomial equation has been entered successfully!\n";
			}
			else
			{
				FileInput(bterms, bdeg, bcoef);
				flag = false;
			}
			temp++;
		}
		else if (choice=='2')
		{
			FileInput(bterms, bdeg, bcoef);
			temp++;
		}
		else if (choice=='3')
		{
			cout<<"Input the variable : ";
			cin>>var;
			cout<<Solve(aterms, adeg, acoef, var);
		}
		else if (choice=='4')
		{
			rterms = aterms+bterms;
			Add(aterms, adeg, acoef, bterms, bdeg, bcoef, rterms, rdeg, rcoef);
			Print(rterms, rdeg, rcoef);
		}
		else if (choice=='5')
		{
			rterms = aterms*bterms;
			Multiply(aterms, adeg, acoef, bterms, bdeg, bcoef, rterms, rdeg, rcoef);
			Print(rterms, rdeg, rcoef);
		}
		else if (choice=='6')
		{
			rterms = aterms+bterms;
			Subtract(aterms, adeg, acoef, bterms, bdeg, bcoef, rterms, rdeg, rcoef);
			Print(rterms, rdeg, rcoef);
		}
		else if (choice=='7')
		{
			if (temp%2!=0)
				Print(aterms, adeg, acoef);
			else
				Print(bterms, bdeg, bcoef);
		}
		else if (choice=='8')
		{
			bool flag = true;
			flag = Equal(aterms, adeg, acoef, bterms, bdeg, bcoef);
			if (flag==true)
				cout<<"Both polynomial are same.";
			else
				cout<<"Both are different.";
			cout<<endl;
		}
		system("pause");
	}
}

int main()
{
	Menu();
	system("pause");
	return 0;
}
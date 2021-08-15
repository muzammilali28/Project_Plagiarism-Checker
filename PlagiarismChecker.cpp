#include<iostream>
using namespace std;

//Ignore the commented codes in this file

void intake(char[],int);

void RemoveNonAlphabets(char[],int);

void checkSizeofNonAlpha(char[],int,int&);

void GeneratingSubString(char[],int,int&,int[],int&);

void SumofSubArr(char[],int,int&,int[],int&);

void DiffofIndexValues(int[],int,int[],int,int&,int&,int&,int&,int&,int&,float&,float&);

void AddingTheDiffValueofIndexes(int[],int,int[],int,int&,int&,int&,int&,int&,int&,float&,float&);

int main()
{
	char mainarray1[100]={'\0'}; int size=100,m1size=0,index1=0;
	int copyarray1[100]={0};
	
	float plgcheck=0,comparison=0;
	int diff1=0,diff2=0,diff3=0,diff4=0;
	
	cout<<"Array 1 : "; intake(mainarray1,size); //takes input for array
	RemoveNonAlphabets(mainarray1,size); //remove the non alphabets
	checkSizeofNonAlpha(mainarray1,size,m1size); //check the size of array
	
	/*cout<<mainarray1;
	cout<<endl<<"Size : "<<m1size<<endl;*/
	
	GeneratingSubString(mainarray1,size,m1size,copyarray1,index1);
	
	//cout<<endl<<endl<<"The Int Array size is: "<<m1size-4;
	cout<<endl<<endl<<endl;
	
	char mainarray2[100]={'\0'}; int Size=100,m2size=0,index2=0;
	int copyarray2[100]={0};
	
	cout<<"Array 2 : "; intake(mainarray2,Size); //takes input for array
	RemoveNonAlphabets(mainarray2,Size); //remove the non alphabets
	checkSizeofNonAlpha(mainarray2,Size,m2size); //check the size of array

	/*cout<<mainarray2;
	cout<<endl<<"Size : "<<m2size<<endl;*/
	
	GeneratingSubString(mainarray2,Size,m2size,copyarray2,index2);
	
	//cout<<endl<<endl<<"The Int Array size is: "<<m2size-4;
	cout<<endl<<endl<<endl;
	
	char mainarray3[100]={'\0'}; int SIZE=100,m3size=0,index3=0;
	int copyarray3[100]={0};
	
	cout<<"Array 3 : "; intake(mainarray3,SIZE); //takes input for array
	RemoveNonAlphabets(mainarray3,SIZE); //remove the non alphabets
	checkSizeofNonAlpha(mainarray3,SIZE,m3size); //check the size of array
	
	/*cout<<mainarray3;
	cout<<endl<<"Size : "<<m3size<<endl;*/
	
	GeneratingSubString(mainarray3,SIZE,m3size,copyarray3,index3);
	
	//cout<<endl<<endl<<"The Int Array size is: "<<m3size-4;
	cout<<endl<<endl<<endl;
	
	char value='\0';
	
	cout<<"1. Compare Pledge between Array 1 & Array 2"<<endl;
	cout<<"2. Compare Pledge between Array 2 & Array 3"<<endl;
	cout<<"3. Compare Pledge between Array 1 & Array 3"<<endl<<endl;
	
	cout<<"Enter Choice : ";
	cin>>value;
	cout<<endl;
	
	if(value=='a' || value=='1')
	{
		DiffofIndexValues(copyarray1,size,copyarray2,Size,diff1,diff2,diff3,diff4,m1size,m2size,plgcheck,comparison);
		
		if(plgcheck >= 0 && plgcheck <= comparison)
		{
			cout<<"Pledge % found : "<<(plgcheck/comparison)*100.0<<"%"<<endl;
			cout<<"Comparisons made : "<<comparison;
		}
	}
	else if(value=='b' || value=='2')
	{
		DiffofIndexValues(copyarray2,Size,copyarray3,SIZE,diff1,diff2,diff3,diff4,m2size,m3size,plgcheck,comparison);
		
		if(plgcheck >= 0 && plgcheck <= comparison)
		{
			cout<<"Pledge % found : "<<(plgcheck/comparison)*100.0<<"%"<<endl;
			cout<<"Comparisons made : "<<comparison;
		}
	}
	else if(value=='c' || value=='3')
	{
		DiffofIndexValues(copyarray1,size,copyarray3,SIZE,diff1,diff2,diff3,diff4,m1size,m3size,plgcheck,comparison);
		
		if(plgcheck >= 0 && plgcheck <= comparison)
		{
			cout<<"Pledge % found : "<<(plgcheck/comparison)*100.0<<"%"<<endl;
			cout<<"Comparisons made : "<<comparison;
		}
	}
	else
	{
		cout<<"Inavlid Selection !";
	}
	
	return 0;
}
void intake(char array[],int size)
{	
	cin.getline(array,size);
}
void RemoveNonAlphabets(char array[],int size)
{
	int j=0;
	
	for(int i=0; array[i]!='\0'; i++)
	{
		if((array[i]>='a' && array[i]<='z'))
		{
			array[j]=array[i];
			j++;
		}
	}
	array[j]='\0';
}
void checkSizeofNonAlpha(char array[],int size,int &csize)
{
	for(int i=0; array[i]!='\0'; i++)
	{
		csize++;
	}
}
void GeneratingSubString(char array[],int size,int &csize,int copyarray[],int &index)
{
	int Size=5,k=0;
	
	for(int i=0; i<csize-4; i++)
	{
		char ss_i[Size]={'\0'};

		for(int j=0; j<Size; j++)
		{
			ss_i[j]=array[k];
			k++;	
		}
		k=i+1;
		
		/*for(int l=0; l<Size; l++)
		{
			cout<<ss_i[l];
		}
		cout<<" ";*/
		
		SumofSubArr(ss_i,Size,csize,copyarray,index);
		
		//cout<<copyarray[i]<<" ";
	}
}
void SumofSubArr(char array[],int Size,int &csize,int copyarray[],int &index)
{
	int sum=0;
	
	for(int i=0; i<Size; i++)
	{		
		sum=sum+array[i];
		copyarray[index]=sum;
	}
	
	index++;
}

void DiffofIndexValues(int copyarray1[],int size,int copyarray2[],int Size,int &diff1,int &diff2,int &diff3,int &diff4,int &m1size,int &m2size,float &plgcheck,float &comparison)
{
	int Size1=m1size-4;
	int Size2=m2size-4;
	
	if(Size2 < Size1 || Size1 > Size2)
	{
		for(int i=0; i<Size2-4; i++)
		{
			if(copyarray2[i] <= copyarray1[i])
			{
				diff1=copyarray1[i]-copyarray2[i];
			}
			else if(copyarray2[i] >= copyarray1[i])
			{
				diff1=copyarray2[i]-copyarray1[i];
			}
			
			if(copyarray2[i+1] <= copyarray1[i+1])
			{
				diff2=copyarray1[i+1]-copyarray2[i+1];
			}
			else if(copyarray2[i+1] >= copyarray1[i+1])
			{
				diff2=copyarray2[i+1]-copyarray1[i+1];
			}
			
			if(copyarray2[i+2] <= copyarray1[i+2])
			{
				diff3=copyarray1[i+2]-copyarray2[i+2];
			}
			else if(copyarray2[i+2] >= copyarray1[i+2])
			{
				diff3=copyarray2[i+2]-copyarray1[i+2];
			}
			
			if(copyarray2[i+3] <= copyarray1[i+3])
			{
				diff4=copyarray1[i+3]-copyarray2[i+3];
			}
			else if(copyarray2[i+3] >= copyarray1[i+3])
			{
				diff4=copyarray2[i+3]-copyarray1[i+3];
			}
			
			AddingTheDiffValueofIndexes(copyarray1,size,copyarray2,Size,diff1,diff2,diff3,diff4,m1size,m2size,plgcheck,comparison);
			
			comparison++;
			
			diff1=0;
			diff2=0;
			diff3=0;
			diff4=0;
			
		}	
	}
	
	if(Size2 > Size1 || Size1 < Size2)
	{
		for(int i=0; i<Size1-4; i++)
		{
			if(copyarray1[i] <= copyarray2[i])
			{
				diff1=copyarray2[i]-copyarray1[i];
			}
			else if(copyarray1[i] >= copyarray2[i])
			{
				diff1=copyarray1[i]-copyarray2[i];
			}
			
			if(copyarray1[i+1] <= copyarray2[i+1])
			{
				diff2=copyarray2[i+1]-copyarray1[i+1];
			}
			else if(copyarray1[i+1] >= copyarray2[i+1])
			{
				diff2=copyarray1[i+1]-copyarray2[i+1];
			}
			
			if(copyarray1[i+2] <= copyarray2[i+2])
			{
				diff3=copyarray2[i+2]-copyarray1[i+2];
			}
			else if(copyarray1[i+2] >= copyarray2[i+2])
			{
				diff3=copyarray1[i+2]-copyarray2[i+2];
			}
			
			if(copyarray1[i+3] <= copyarray2[i+3])
			{
				diff4=copyarray2[i+3]-copyarray1[i+3];
			}
			else if(copyarray1[i+3] >= copyarray2[i+3])
			{
				diff4=copyarray1[i+3]-copyarray2[i+3];
			}
			
			AddingTheDiffValueofIndexes(copyarray1,size,copyarray2,Size,diff1,diff2,diff3,diff4,m1size,m2size,plgcheck,comparison);
			
			comparison++;
			
			diff1=0;
			diff2=0;
			diff3=0;
			diff4=0;
		}	
	}
	
	if(Size2 == Size1 || Size1 == Size2)
	{
		for(int i=0; i<Size1-4; i++)
		{
			if(copyarray1[i] <= copyarray2[i])
			{
				diff1=copyarray2[i]-copyarray1[i];
			}
			else if(copyarray1[i] >= copyarray2[i])
			{
				diff1=copyarray1[i]-copyarray2[i];
			}
			
			if(copyarray1[i+1] <= copyarray2[i+1])
			{
				diff2=copyarray2[i+1]-copyarray1[i+1];
			}
			else if(copyarray1[i+1] >= copyarray2[i+1])
			{
				diff2=copyarray1[i+1]-copyarray2[i+1];
			}
			
			if(copyarray1[i+2] <= copyarray2[i+2])
			{
				diff3=copyarray2[i+2]-copyarray1[i+2];
			}
			else if(copyarray1[i+2] >= copyarray2[i+2])
			{
				diff3=copyarray1[i+2]-copyarray2[i+2];
			}
			
			if(copyarray1[i+3] <= copyarray2[i+3])
			{
				diff4=copyarray2[i+3]-copyarray1[i+3];
			}
			else if(copyarray1[i+3] >= copyarray2[i+3])
			{
				diff4=copyarray1[i+3]-copyarray2[i+3];
			}
			
			AddingTheDiffValueofIndexes(copyarray1,size,copyarray2,Size,diff1,diff2,diff3,diff4,m1size,m2size,plgcheck,comparison);
			
			comparison++;
			
			diff1=0;
			diff2=0;
			diff3=0;
			diff4=0;
		}	
	}

}
void AddingTheDiffValueofIndexes(int copyarray1[],int size,int copyarray2[],int Size,int &diff1,int &diff2,int &diff3,int &diff4,int &m1size,int &m2size,float &plgcheck,float &comparison)
{
	int sum=0;
	
	sum=diff1+diff2+diff3+diff4;
	
	if(sum<60)
	{
		plgcheck++;
	}
}

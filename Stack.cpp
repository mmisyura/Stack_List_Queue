#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Stack
{
private:
	int * ptr;
	int lgth;
public:
	Stack():ptr(NULL), lgth(0)
{
	;
}
bool blank()
{
	if (lgth==0)
		return true;
	return false;
}
void input()
{
	int number;
	cout<<"������� �����: ";
	cin>>number;
	cout<<endl;
	if(blank())
	{
		ptr=new int[1];
		ptr[0]=number;
		lgth++;
	}
	else
	{
		int * temp=new int [lgth+1];
		for(int g=0;g<lgth;g++)
		{
			temp[g]=ptr[g];
		}
		delete [] ptr;
		temp[lgth]=number;
		ptr=temp;
		lgth++;
	}
}
void Take()
{
	if(blank())
	{
		cout<<"\n���� ����\n"<<endl;
	}
	else
	{
		int el;
		int * temp=new int [lgth-1];
		for(int g=0;g<lgth-1;g++)
		{
			temp[g]=ptr[g];
		}
		el=ptr[lgth-1];
		delete [] ptr;
		ptr=temp;
		cout<<"\n��������� �������: "<<el<<endl<<endl;
		lgth--;
	}
}
void out()
{
	if(blank())
	{
		cout<<"\n���� ����\n"<<endl;
	}
	else
	{
		cout<<endl;
		for(int g=lgth-1;g>=0;g--)
		{
			cout<<ptr[g]<<endl;
		}
		cout<<endl;
	}
}
~Stack()
{
	delete [] ptr;
}
};


char message()
{
	char * mes="�������� ��������:\n"
		"1)�������� �������\n"
		"2)��������� ���� �� �������\n"
		"3)������� �������\n"
		"4)������� ���� �� �����\n"
		"5)�����\n";
	cout<<mes;
	char message;
	cin.clear();
	message=getch();
	system("CLS");
	return message;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("color 1c");
	system("title ����");
	Stack First;
	char off=1;
	while(off)
	{
		switch(message())
		{
		case '1':
			{
				First.input();
				break;
			}
		case '2':
			{
				if(First.blank())
					cout<<"���� ������"<<endl<<endl;
				else
					cout<<"���� �� ������"<<endl<<endl;
				break;
			}
		case '3':
			{
				First.Take();
				break;
			}
		case '4':
			First.out();
			break;
		case '5':
			off=0;
			break;
		default:
			cout<<"\n�������� ����. ��������� ����.\n\n";
			break;
		}
	}
	system("pause");
}
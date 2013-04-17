#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Queue
{
private:
	int * ptr;
	int proportions;
	int lgth;
	int first;
	int last;
public:
	Queue():lgth(0), first(0), last(-1)
{
	cout<<"������� ������ �������:";
	cin>>proportions;
	while (proportions<=0)
	{
		cout<<"\n�������� ������ �������\n"<<endl;
		cout<<"������� ������ �������:";
		cin>>proportions;
	}
	ptr=new int [proportions];
}
bool not_full()
{
	if (lgth<proportions) 
		return true;
	else
		return false;
}
bool not_empty()
{
	if (lgth>0)
		return true;
	else
		return false;
}
void input()
{
	if(not_full())
	{
		int number;
		cout<<"\n������� �����: ";
		cin>>number;
		last=(last+1)%proportions;
		ptr[last]=number;
		lgth++;
		cout<<endl;
	}
	else
		cout<<"\n������� �����\n"<<endl;
}
void Take()
{
	if (not_empty())
	{
		cout<<"\n��������� �������: "<<ptr[first]<<endl<<endl;
		first=(first+1)%proportions;
		lgth--;
	}
	else
		cout<<"\n������� �����\n"<<endl;
}
void out()
{
	if (not_empty())
	{
		int numberber=0;
		cout<<"\n������� ����� ��������:";
		cin>>numberber;
		while (!((0<numberber)&&(numberber<=lgth)))
		{
			cout<<
				"\n����� �������� ������ ���� ������ ����"
				"� �� �������� �� ������� �������\n"
				    <<endl;
			cout<<"������� ����� ��������:";
			cin>>numberber;
		}
		cout<<endl<<ptr[(first+numberber-1)%proportions]<<endl<<endl;
	}
	else
		cout<<"\n������� �����\n"<<endl;
}
~Queue()
{
	delete [] ptr;
}
};


char message()
{
	char * mes="�������� ��������:\n"
		"1)�������� �������\n"
		"2)������� �������\n"
		"3)������� i-� �������\n"
		"4)�����\n";
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
	system("title �������");
	Queue First;
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
				First.Take();
				break;
			}
		case '3':
			{
				First.out();
			}
			break;
		case '4':
			off=0;
			break;
		default:
			cout<<"\n�������� ����. ��������� ����.\n\n";
			break;
		}
	}
	system("pause");
}
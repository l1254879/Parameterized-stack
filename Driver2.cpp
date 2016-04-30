#include<iostream>
#include<cstdlib>
#include"stack.h"
using namespace std;

int main(){

	Stack <int> s;
	Stack <double> s2;
	int i;
	double j;


	for(i=0;i<10;i++){

		s.Push(i);
		cout<<"Top is in "<<s.Top()<<endl;
	}
	s.ClearStack();
	for(i=0;i<23;i++){
		s.Push(i);
		cout<<"Top is in "<<s.Top()<<endl;
	}
	for(i=0;i<23;i++){
		cout<<s.Pop()<<endl;
		cout<<"Top is in "<<s.Top()<<endl;
	}
	if(s.IsStackEmpty())
		cout<<"Stack is empty"<<endl;
	for(i=0;i<10;i++){
		j=i*1.1;
		s2.Push(j);
	}
	for(i=0;i<10;i++)
		cout<<s2.Pop()<<endl;
	if(s2.IsStackEmpty())
		cout<<"Stack is Empty"<<endl;

	return 0;

}

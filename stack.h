#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
const int MaxStackSize = 2; // initial value of _stackSizeT>
template <class DataType>
class Stack {
	private:
		DataType *_stackList;// array of DataTypes
		int _stackSize;// the size of _stackList
		int _top;// the index of the top element


		// push item on top of the stack and extend the
		// stack if necessary
		void PushExtend(const DataType& item);
	public:
		Stack(void);// constructor the stack
		~Stack(void);//destructor

		// push item on top of the stack
		void Push(const DataType& item);

		DataType Pop(void);// pop the stack
		void ClearStack(void);// reset the value of _top to -1

		// return item on top of the stack
		DataType Top(void) const;

		// check if the stack is empty
		bool IsStackEmpty(void) const;
		bool IsStackFull(void) const;// check if the stack is full
};
template<class DataType>
Stack<DataType>::Stack(void){
	_stackSize = MaxStackSize; // initial
	_stackList = new DataType[_stackSize];//new a stack
	_top = -1;//top initial
}
template<class DataType>
void Stack<DataType>::Push(const DataType& item){
	if(IsStackFull()){ //before _top move should check the stack
		PushExtend(item);//if full call the extend
	}
	else{
		_top++;//top move
		*(_stackList+_top) = item;//throw the item to stack
	}
}
template<class DataType>
DataType Stack<DataType>::Pop(void){
	if(IsStackEmpty()){//before move should check the stack
		ClearStack();
	}
	else{
		//return *(_stackList+_top);
		_top--;
		return *(_stackList+_top+1);
	}
}
template<class DataType>
void Stack<DataType>::ClearStack(void){
	_top = -1;

}
template<class DataType>
void Stack<DataType>::PushExtend(const DataType &item){
	DataType *TmpArray = new DataType [_stackSize];//new a stack to get the item of _stackList
	memcpy(TmpArray,_stackList,sizeof(DataType)*_stackSize);//memory copy
	delete[] _stackList;//delete old stack
	_stackSize = 2*_stackSize;//stacksize become twice
	_stackList = new DataType[_stackSize];//new a new stack
	memcpy(_stackList,TmpArray,sizeof(DataType)*_stackSize);//get feom  the tmp arry item to new stack
	_top++;//top move 
	*(_stackList+_top)=item;//throw item to new stack
	//_stackSize = 2*_stackSize;
	delete[] TmpArray;//delete tmp arry to release memory
}
template<class DataType>
DataType Stack<DataType>::Top(void)const{
	return *(_stackList+_top);

}
template<class DataType>
bool Stack<DataType>::IsStackEmpty(void)const{
	if(_top == -1){
		return true;
	}
	else{
		return false;
	}
}
template<class DataType>
bool Stack<DataType>::IsStackFull(void)const{
	if(_top+1 == _stackSize){
		return true;
	}
	else{
		return false;
	}
}
template<class DataType>
Stack<DataType>::~Stack(void){
	delete[] _stackList;//free the memory
}

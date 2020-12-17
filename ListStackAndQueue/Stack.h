#pragma once
#include "List.h"
#include <iostream>

using namespace std;

template <class ValType>
class ClassStack
{
private:
	TList<ValType> list;
public:
	ClassStack();
	ClassStack(const ClassStack& v);
	~ClassStack();

	ClassStack<ValType>& operator = (const ClassStack<ValType>& v);

	void PushStack(const ValType& elem);
	ValType GetStack();

	bool IsEmpty();
	bool IsFull();

	template <class ValType1>
	friend ostream& operator << (ostream& ostr, const ClassStack<ValType1>& v);
	template <class ValType1>
	friend istream& operator >> (istream& istr, ClassStack<ValType1>& v);
};

template<class ValType1>
ostream& operator<<(ostream& ostr, const ClassStack<ValType1>& v) {
	return ostr << v.list;
}

template<class ValType1>
istream& operator>>(istream& istr, ClassStack<ValType1>& v) {
	return istr >> v.list;
}

template<class ValType>
ClassStack<ValType>& ClassStack<ValType>::operator=(const ClassStack<ValType>& v) {
	if (this = &v)
		return *this;

	this->list = v.list;
	return *this;
}

template<class ValType>
ValType ClassStack<ValType>::GetStack() {
	if (list.IsEmpty())
		throw logic_error("Input error: invalide value of ClassStack length in GetStack");

	ValType tmp = list.GetFirst()->GetList();
	list.DelFirst();
	return tmp;
}

template<class ValType>
void ClassStack<ValType>::PushStack(const ValType& elem) {
	list.InsFirst(elem);
}

template<class ValType>
ClassStack<ValType>::ClassStack(){}

template<class ValType>
ClassStack<ValType>::ClassStack(const ClassStack& v){
	this->list = v.list;
}

template<class ValType>
ClassStack<ValType>::~ClassStack(){}

template<class ValType>
bool ClassStack<ValType>::IsEmpty(){
	return list.IsEmpty();
}

template<class ValType>
bool ClassStack<ValType>::IsFull(){
	return list.IsFull();
}


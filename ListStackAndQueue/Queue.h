#pragma once
#include "List.h"
#include <iostream>
using namespace std;

template <class ValType>
class ClassQueue
{
private:
	TList<ValType> list;
public:
	ClassQueue();
	ClassQueue(const ClassQueue& v);
	~ClassQueue();
	ClassQueue<ValType>& operator = (const ClassQueue<ValType>& v);

	void PushQueue(const ValType& elem);
	ValType GetQueue();

	bool IsEmpty();
	bool IsFull();

	template <class ValType1>
	friend ostream& operator << (ostream& ostr, const ClassQueue<ValType1>& v);
	template <class ValType1>
	friend istream& operator >> (istream& istr, ClassQueue<ValType1>& v);
};

template<class ValType1>
ostream& operator<<(ostream& ostr, const ClassQueue<ValType1>& v) {
	return ostr << v.list;
}

template<class ValType1>
istream& operator>>(istream& istr, ClassQueue<ValType1>& v) {
	return istr >> v.list;
}

template<class ValType>
ClassQueue<ValType>& ClassQueue<ValType>::operator=(const ClassQueue<ValType>& v) {
	if (this = &v)
		return *this;

	this->list = v.list;
	return *this;
}

template<class ValType>
void ClassQueue<ValType>::PushQueue(const ValType& elem) {
	list.InsLast(elem);
}

template<class ValType>
ValType ClassQueue<ValType>::GetQueue() {
	if (list.IsEmpty())
		throw logic_error("Input error: invalide value of ClassQueue length in GetQueue");

	ValType tmp = list.GetFirst()->GetList();
	list.DelFirst();
	return tmp;
}

template<class ValType>
ClassQueue<ValType>::ClassQueue(){}

template<class ValType>
ClassQueue<ValType>::ClassQueue(const ClassQueue& v){
	list = v.list;
}

template<class ValType>
ClassQueue<ValType>::~ClassQueue(){}

template<class ValType>
bool ClassQueue<ValType>::IsEmpty(){
	return list.IsEmpty();
}

template<class ValType>
bool ClassQueue<ValType>::IsFull(){
	return list.IsFull();
}


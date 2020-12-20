#ifndef _LIST_
#define _LIST_
#include <iostream>

using namespace std;

template <class ValType>
class ListElem {
protected:
	ValType list;
	ListElem* next;
	ListElem* previous;
public:
	ListElem(ValType list);
	~ListElem();

	ValType GetList();
	ListElem* GetNext();
	ListElem* GetPrevious();

	void SetList(ValType list);
	void SetNext(ListElem* next);
	void SetPrevious(ListElem* previous);

	template <class ValType1>
	friend ostream& operator<<(ostream& ostr, const ListElem<ValType1>& v);
	template <class ValType1>
	friend istream& operator>>(istream& istr, ListElem<ValType1>& v);
};

template<class ValType>
inline ListElem<ValType>::ListElem(ValType list) {
	this->list = list;
	next = nullptr;
	previous = nullptr;
}

template<class ValType>
inline ListElem<ValType>::~ListElem() {
	next = nullptr;
	previous = nullptr;
}

template<class ValType>
inline ValType ListElem<ValType>::GetList() {
	return list;
}

template<class ValType>
inline ListElem<ValType>* ListElem<ValType>::GetNext() {
	return next;
}

template<class ValType>
inline ListElem<ValType>* ListElem<ValType>::GetPrevious() {
	return previous;
}

template<class ValType>
inline void ListElem<ValType>::SetList(ValType list) {
	this->list = list;
}

template<class ValType>
inline void ListElem<ValType>::SetNext(ListElem<ValType>* next) {
	this->next = next;
}

template<class ValType>
inline void ListElem<ValType>::SetPrevious(ListElem* previous) {
	this->previous = previous;
}

template<class ValType1>
inline ostream& operator<<(ostream& ostr, const ListElem<ValType1>& v) {
	ostr << v.list;
	return ostr;
}

template<class ValType1>
inline istream& operator>>(istream& istr, ListElem<ValType1>& v) {
	istr >> v.list;
	return istr;
}



template<class ValType>
class TList {
protected:
	ListElem<ValType>* first;
	ListElem<ValType>* last;
	int length;
public:
	TList();
	TList(TList<ValType>& v);
	~TList();

	TList<ValType>& operator= (TList<ValType>& v);

	void InsFirst(ValType temp);
	void InsLast(ValType temp);
	void InsAfter(ListElem<ValType>* element, ValType temp);

	void DelFirst();
	void DelLast();
	void DelAfter(ListElem<ValType>* element);

	ListElem<ValType>* GetFirst();
	ListElem<ValType>* GetLast();
	int GetLength() { return length; }
	bool IsEmpty(void) const;
	bool IsFull(void) const;
	template <class ValType1>
	friend ostream& operator<<(ostream& ostr, const TList<ValType1>& v);
	template <class ValType1>
	friend istream& operator>>(istream& istr, TList<ValType1>& v);
	void DelDenominator(ValType p);
	void together(TList<ValType>& v);
	void part(TList<ValType>& v);
};
template<class ValType>
inline void TList<ValType>::DelDenominator(ValType p) {
	ListElem<ValType>* temp = nullptr;
	while (first != nullptr) {
		temp = first->GetNext();
		temp->SetPrevious(first);
		if (temp->GetPrevious()->GetList() % p == 0) {
			DelFirst();
		}
		else {
			cout << *first << " ";
			first = first->GetNext();
		}

	}
}

template<class ValType>
inline void TList<ValType>::together(TList<ValType>& v) {
	ListElem<ValType>* tmp = nullptr;
	int temp = length + v.length;

	for (int i = 0; i < length - 1; i++) {
		tmp = first->GetNext();
		tmp->SetPrevious(first);
		tmp->GetPrevious()->GetList();
		cout << *first << " ";
		first = first->GetNext();
	}

	tmp = v.first;
	tmp->SetPrevious(first);
	tmp->GetPrevious()->GetList();
	cout << *first << " ";
	first = v.first;

	for (int i = 0; i < v.length - 1; i++) {
		tmp = v.first->GetNext();
		tmp->SetPrevious(v.first);
		tmp->GetPrevious()->GetList();
		cout << *v.first << " ";
		v.first = v.first->GetNext();
	}
	cout << *v.first << " ";
}

template<class ValType>
void TList<ValType>::part(TList<ValType>& v) {
	ListElem<ValType>* tmp = first;
	ListElem<ValType>* temp = v.first;


	tmp->SetNext(first->GetNext());

	while (first != nullptr) {
		while (first == v.first) {
			first = first->GetNext();
			v.first = v.first->GetNext();
		}
		if (v.first == nullptr)
			cout << "yes";
		else
			if (first != v.first) {
				first = tmp->GetNext();
				v.first = temp;
			}
	}

}





template <class ValType>
TList<ValType>::TList() {
	length = 0;
	first = nullptr;
	last = nullptr;
}

template <class ValType>
TList<ValType>::TList(TList<ValType>& v) {
	this->length = v.length;
	ListElem<ValType>* list1 = this->first;
	ListElem<ValType>* list2 = v.first;
	ListElem<ValType>* list3 = nullptr;
	while (list2 != nullptr) {
		list1 = new ListElem<ValType>(*list2);
		list1->SetNext(nullptr);
		if (list3 != nullptr) {
			list3->SetNext(list1);
			list1->SetPrevious(list3);
		}
		list3 = list1;
		if (first == nullptr) first = list1;
		last = list1;
		list2 = list2->GetNext();
	}
}

template <class ValType>
TList<ValType>::~TList() {
	if (this->first != nullptr) {
		ListElem<ValType>* list1 = this->first;
		ListElem<ValType>* list3 = nullptr;
		while (list1 != nullptr) {
			list3 = list1;
			list1 = list1->GetNext();
			delete list3;
		}
		this->first = nullptr;
		this->last = nullptr;
		length = 0;
	}
}

template <class ValType>
TList<ValType>& TList<ValType>:: operator= (TList<ValType>& v)
{
	if (this == &v)
		return (*this);
	if (this->first != nullptr) {
		ListElem<ValType>* list1 = this->first;
		ListElem<ValType>* list3 = nullptr;
		while (list1 != nullptr) {
			list3 = list1;
			list1 = list1->GetNext();
			delete list3;
		}
		this->first = nullptr;
		this->last = nullptr;
		length = 0;
	}
	this->length = v.length;
	ListElem<ValType>* list1 = this->first;
	ListElem<ValType>* list2 = v.first;
	ListElem<ValType>* list3 = nullptr;
	while (list2 != nullptr) {
		list1 = new ListElem<ValType>(*list2);
		list1->SetNext(nullptr);
		if (list3 != nullptr) {
			list3->SetNext(list1);
			list1->SetPrevious(list3);
		}
		list3 = list1;
		if (this->first == nullptr) this->first = list1;
		last = list1;
		list2 = list2->GetNext();
	}
}

template <class ValType>
void TList<ValType>::InsFirst(ValType temp) {
	ListElem<ValType>* tmp = new ListElem<ValType>(temp);
	tmp->SetNext(first);
	first = tmp;
	if (last == 0)
		last = tmp;
	length++;
}

template <class ValType>
void TList<ValType>::DelFirst() {
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of List length in DelFirst");
	ListElem<ValType>* list1 = first;
	first = first->GetNext();
	delete list1;
	length--;
}

template <class ValType>
void TList<ValType>::DelLast() {
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of List length in DelLast");
	ListElem<ValType>* list2 = first;
	if (list2->GetNext() != 0) {
		while (list2->GetNext()->GetNext() != 0)
			list2 = list2->GetNext();
		delete list2->GetNext();
		list2->SetNext(0);
		return;
	}
	delete list2;
	first = 0;
	length--;
}

template<class ValType>
void TList<ValType>::DelAfter(ListElem<ValType>* element) {
	element->GetPrevious()->SetNext(element->GetNext());
	element->GetNext()->SetPrevious(element->GetPrevious());
	delete element;
	length--;
}

template <class ValType>
void TList<ValType>::InsLast(ValType temp) {
	if (this->IsEmpty()) InsFirst(temp);
	else {
		ListElem<ValType>* tmp = new ListElem<ValType>(temp);
		if (!IsEmpty()) last->SetNext(tmp);
		tmp->SetPrevious(last);
		tmp->SetNext(nullptr);
		last = tmp;
		length++;
	}
}

template<class ValType>
inline void TList<ValType>::InsAfter(ListElem<ValType>* element, ValType temp) {
	ListElem<ValType>* tmp = new ListElem<ValType>(temp);
	tmp->SetNext(element->GetNext());
	tmp->SetPrevious(element);
	element->GetNext()->SetPrevious(tmp);
	element->SetNext(tmp);
	length++;
}

template<class ValType>
ListElem<ValType>* TList<ValType>::GetFirst() {
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of List length in GetFirst");
	return first;
}

template<class ValType>
ListElem<ValType>* TList<ValType>::GetLast() {
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of List length in GetLast");
	return last;
}

template <class ValType>
bool TList<ValType>::IsEmpty(void) const {
	return (length == 0);
}

template <class ValType>
bool TList<ValType>::IsFull(void) const {
	try {
		ListElem<ValType>* tmp = new ListElem<ValType>(nullptr);
		tmp->SetPrevious(last);
		delete tmp;
		return false;
	}
	catch ("List Isfull") {
		return true;
	}
}

template<class ValType1>
ostream& operator<<(ostream& ostr, const TList<ValType1>& v) {
	ListElem<ValType1>* tmp = v.first;
	while (tmp != nullptr) {
		ostr << *tmp << endl;
		tmp = tmp->GetNext();
	}
	return ostr;
}

template<class ValType1>
istream& operator>>(istream& istr, TList<ValType1>& v) {
	int count;
	istr >> count;
	for (int i = 0; i < count; i++) {
		ValType1 time;
		istr >> time;
		v.InsLast(time);
	}
	return istr;
}




#endif   
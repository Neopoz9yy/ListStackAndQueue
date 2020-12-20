#include <iostream>
#include "List.h"
#include "Queue.h"
#include "Stack.h"


int main() {
	ClassQueue<int> queue;

	cout << "queue:" << endl;
	for (int i = 0; i < 5; i++) {
		queue.PushQueue(rand());
		cout << queue.GetQueue() << endl;
	}




	ClassStack<int> stack;
	cout << "stack:" << endl;
	for (int i = 0; i < 5; i++) {
		stack.PushStack(rand());
		cout << stack.GetStack() << endl;
	}




}
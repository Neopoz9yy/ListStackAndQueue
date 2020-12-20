#include <../gtest/gtest.h>
#include "Queue.h"



TEST(ClassQueue, PushQueue) {
	ClassQueue<int> queue;
	ASSERT_NO_THROW(queue.PushQueue(6865));
}

TEST(ClassQueue, GetQueue) {
	ClassQueue<int> queue;
	queue.PushQueue(34);
	queue.PushQueue(75);
	queue.PushQueue(48);
	queue.PushQueue(74);
	queue.PushQueue(178);

	ASSERT_NO_THROW(queue.GetQueue());
	ASSERT_NO_THROW(queue.GetQueue());
	ASSERT_NO_THROW(queue.GetQueue());
	ASSERT_NO_THROW(queue.GetQueue());
	ASSERT_NO_THROW(queue.GetQueue());
	
}

TEST(ClassQueue, ClassQueue) {
	ASSERT_NO_THROW(ClassQueue<int> queue);
}

TEST(ClassQueue, IsEmpty) {
	ClassQueue<int> queue;
	ASSERT_ANY_THROW(queue.GetQueue());
}





#include <../gtest/gtest.h>
#include "Stack.h"



TEST(ClassStack, GetStack) {
	ClassStack<int> queue;
	queue.PushStack(34);
	queue.PushStack(75);
	queue.PushStack(48);
	queue.PushStack(74);
	queue.PushStack(178);

	EXPECT_EQ(178, queue.GetStack());
	EXPECT_EQ(74, queue.GetStack());
	EXPECT_EQ(48, queue.GetStack());
	EXPECT_EQ(75, queue.GetStack());
	EXPECT_EQ(34, queue.GetStack());
}

TEST(ClassStack, PushStack) {
	ClassStack<int> stack;
	ASSERT_NO_THROW(stack.PushStack(6865));
}



TEST(ClassStack, ClassStack) {
	ASSERT_NO_THROW(ClassStack<int> stack);
}

TEST(ClassStack, IsEmpty) {
	ClassStack<int> stack;
	ASSERT_ANY_THROW(stack.GetStack());
}
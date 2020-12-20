#include <../gtest/gtest.h>
#include "List.h"

TEST(TList, TList){
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, OperatorEQ) {
	TList<int> list;
	list.InsFirst(6);
	list.InsFirst(78);
	list.InsFirst(46);

	TList<int> list2;
	ASSERT_NO_THROW(list2 = list);

	EXPECT_EQ(46, list2.GetFirst()->GetList());
	EXPECT_EQ(6, list2.GetLast()->GetList());
}

TEST(TList, InsFirts){
	TList<int> list;
	ASSERT_NO_THROW(list.InsFirst(79));
	EXPECT_EQ(79, list.GetFirst()->GetList());
}

TEST(TList, DelFirst){
	TList<int> list;
	
	list.InsFirst(548);
	list.InsFirst(747);
	list.InsFirst(856);
	list.InsFirst(6896);
	list.InsFirst(24);

	ASSERT_NO_THROW(list.DelFirst());
	EXPECT_EQ(6896, list.GetFirst()->GetList());
}

TEST(TList, DelLast){
	TList<int> list;
	list.InsLast(9760);
	list.InsLast(7);
	list.InsLast(47);
	list.InsLast(83);
	list.InsLast(74);

	ASSERT_NO_THROW(list.DelLast());
}

TEST(TList, InsLast){
	TList<int> list;
	ASSERT_NO_THROW(list.InsLast(75));
}

TEST(TList, GetFirst){
	TList<int> list;
	list.InsFirst(9760);
	list.InsFirst(7);
	list.InsFirst(47);
	list.InsFirst(83);
	list.InsFirst(74);

	EXPECT_EQ(74, list.GetFirst()->GetList());
}

TEST(TList, GetLast) {
	TList<int> list;
	list.InsLast(9760);
	list.InsLast(7);
	list.InsLast(47);
	list.InsLast(83);
	list.InsLast(74);

	EXPECT_EQ(74, list.GetLast()->GetList());
}

TEST(TList, IsEmpty){
	TList<int> list;

	ASSERT_ANY_THROW(list.DelFirst());
	ASSERT_ANY_THROW(list.DelLast());
}


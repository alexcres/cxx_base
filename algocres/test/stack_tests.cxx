#include "algocres/array_stack.hxx"
#include "gtest/gtest.h"

using namespace std;


class StackTest : public ::testing::Test {
protected:
	void SetUp() override {
		for (int i = 0; i != 8; ++i) {
			arrayStack.push(i);
		}
	};

	void TearDown() override {
	};

	algocres::ArrayStack<int> arrayStack;
};

TEST_F(StackTest, ArrayStack) {
	EXPECT_EQ(arrayStack.getSize(), 8);
	for (int i = 0; i != 6; ++i) {
		arrayStack.pop();
	}
	EXPECT_EQ(arrayStack.getSize(), 4);
	try {
		for (int i = 0; i != 3; ++i) {
			arrayStack.pop();
		}
	}
	catch(std::out_of_range const &err) {
		EXPECT_EQ(err.what(), std::string("ArrayStack Underflow"));
	}
	EXPECT_EQ(arrayStack.getSize(), 2);
}
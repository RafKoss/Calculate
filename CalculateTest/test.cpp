#include "pch.h"
#include "../Calculate/Functions.cpp"

TEST(isNumberTest, Numbers)
{
	EXPECT_TRUE(isNumber("2"));
	EXPECT_TRUE(isNumber("452"));
	EXPECT_TRUE(isNumber("12"));
}

TEST(isNumberTest, NonNumbers)
{
	EXPECT_FALSE(isNumber("a"));
	EXPECT_FALSE(isNumber("4h4"));
	EXPECT_FALSE(isNumber("-"));
}

TEST(calculate2ArgExpressionTest, Expressions)
{
	ASSERT_EQ(6, calculate2ArgExpression("3+3"));
	ASSERT_EQ(15, calculate2ArgExpression("3*5"));
	ASSERT_EQ(6, calculate2ArgExpression("36/6"));
}

TEST(reduceExpressionTest, Expressions)
{
	ASSERT_EQ("3+4", reduceExpression("3+(2*2)"));
	ASSERT_EQ("11*(2/2)", reduceExpression("(3+8)*(2/2)"));
	ASSERT_EQ("3+(2*(2+4))", reduceExpression("3+(2*(2+(6-2)))"));
}
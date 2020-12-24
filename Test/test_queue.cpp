#include "../Queue/Queue.h"
#include "gtest.h"

TEST(queue, ne_vikidivaet_throw)
{
  ASSERT_NO_THROW(Queue<int> q(3));
}

TEST(queue, ne_sozdaet_otritcatelniy_razmer)
{
	ASSERT_ANY_THROW(Queue<int> q(-3));
}

TEST(queue, prisvaivaet_c_raznim_razmerom)
{
	Queue<int> q(3);
	Queue<int> q1(4);
	q.push(1);
	q1.push(2);
	q = q1;
	EXPECT_EQ(q.pop(),2);
}

TEST(queue, prisvaivaet_c_odinakovim_razmerom)
{
	Queue<int> q(3);
	Queue<int> q1(3);
	q.push(1);
	q1.push(2);
	q = q1;
	EXPECT_EQ(q.pop(), 2);
}

TEST(queue, kopiryet)
{
	Queue<int> q(3);
	q.push(1);
	Queue<int> q1(q);
	EXPECT_EQ(q1.pop(), 1);
}

TEST(queue, cravnenie_raznix_razmerov)
{
	Queue<int> q(3);
	Queue<int> q1(4);
	q.push(1);
	q1.push(1);
	EXPECT_EQ(q==q1, 0);
}

TEST(queue, cravnenie_raznix_razmerov_1)
{
	Queue<int> q(3);
	Queue<int> q1(4);
	q.push(1);
	q1.push(1);
	EXPECT_EQ(q != q1, 1);
}

TEST(queue, cravnenie_raznix_znacheniy)
{
	Queue<int> q(3);
	Queue<int> q1(3);
	q.push(1);
	q1.push(2);
	EXPECT_EQ(q == q1, 0);
}

TEST(queue, cravnenie_raznix_znacheniy_1)
{
	Queue<int> q(3);
	Queue<int> q1(3);
	q.push(1);
	q1.push(2);
	EXPECT_EQ(q != q1, 1);
}

TEST(queue, pokazivaet_nachalo)
{
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	EXPECT_EQ(q.front(), 1);
}

TEST(queue, pokazivaet_konec)
{
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	EXPECT_EQ(q.back(),2);
}

TEST(queue, pokazivaet_chto_full)
{
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	EXPECT_EQ(q.full(), 1);
}

TEST(queue, pokazivaet_chto_empty)
{
	Queue<int> q(3);
	EXPECT_EQ(q.empty(), 1);
}

TEST(queue, ybiraet_iz_ocheredi_perviy_element)
{
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	EXPECT_EQ(q.pop(), 1);
}

TEST(queue, ybiraet_iz_ocheredi_perviy_element_and_osvobogdaet_pozitiu)
{
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	int q1=q.pop();
	EXPECT_EQ(q.front(), 2);
}

TEST(queue, zakolcovivaet)
{
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	int q1=q.pop();
	q1=q.pop();
	q.push(4);
	EXPECT_EQ(q.back(), 4);
}

TEST(queue, ne_dobadlaet_elementov_bolshe_razmera)
{
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	ASSERT_ANY_THROW(q.push(4));
}

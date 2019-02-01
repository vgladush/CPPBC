/*
 * coder_gTest.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: vitalii.lysenko
 *
 * Unit tests for Coder class.
 *
 * You may change this file, but it will be restored on Jenkins CI side
 * before each build.
 *
 * Try to figure out the business logic of Coder class by the logic of the
 * unit tests.
 *
 * If you are not familiar with Google Test, please follow the link:
 * https://github.com/google/googletest/blob/master/googletest/docs/primer.md
 *
 */

#include "coder.h"

#include "gtest/gtest.h"

#include <limits>
#include <vector>
#include <ctime>

const char* buf_hello = "Hello Global World!";

const char* buf_company = "As a full-lifecycle product development services company, \
						  we offer the opportunity to work on amazing projects, using \
						  the latest disruptive technologies, with other designer and \
						  engineers who are experts in their field. We offer competitive \
						  salaries, the stability of a global company, and customized \
						  professional development that gives you exposure to a variety \
						  of interesting, hands-on projects.";

TEST(Coder, sizeof)
{
	typedef struct { char* b; int s; } coder_t;
	EXPECT_EQ(sizeof(coder_t), sizeof(Coder));
}

TEST(Coder, set)
{
	Coder coder;
	coder.set(buf_hello, strlen(buf_hello) + 1);

	EXPECT_STREQ(buf_hello, coder.buf());
}

TEST(Coder, buf)
{
	Coder coder;
	coder.set(buf_company, strlen(buf_company) + 1);

	EXPECT_NE(buf_company, coder.buf());
	EXPECT_STREQ(buf_company, coder.buf());
}

TEST(Coder, init_buf)
{
	Coder coder;

	EXPECT_THROW(coder.set(0, 1), std::logic_error);
}

TEST(Coder, init_len)
{
	Coder coder;

	EXPECT_THROW(coder.set(buf_hello, 0), std::logic_error);
	EXPECT_THROW(coder.set(buf_hello, std::numeric_limits<unsigned int>::max()), std::logic_error);
}

TEST(Coder, init_values)
{
	Coder* pCoder = new Coder;

	EXPECT_EQ(0, pCoder->buf());
	EXPECT_EQ(0, pCoder->size());

	delete pCoder;
}

TEST(Coder, two_coders)
{
	Coder coder;
	coder.set(buf_company, strlen(buf_company) + 1);

	Coder coder2 = coder;

	EXPECT_NE(coder.buf(), coder2.buf());
	EXPECT_EQ(coder.size(), coder2.size());
	EXPECT_STREQ(coder.buf(), coder2.buf());
}

TEST(Coder, two_coders2)
{
	Coder* pCoder = new Coder;
	pCoder->set(buf_hello, strlen(buf_hello) + 1);

	Coder coder;
	coder = *pCoder;

	EXPECT_NE(coder.buf(), pCoder->buf());
	EXPECT_EQ(coder.size(), pCoder->size());
	EXPECT_STREQ(coder.buf(), pCoder->buf());

	delete pCoder;
}

TEST(Coder, encode)
{
	const int size = strlen(buf_hello) + 1;

	Coder coder;
	coder.set(buf_hello, size);

	EXPECT_STREQ(buf_hello, coder.buf());

	coder.encode();

	EXPECT_STRNE(buf_hello, coder.buf());

	char buf[size];
	memcpy(buf, buf_hello, size);

	::encode(buf, size);

	EXPECT_STREQ(buf, coder.buf());
}

TEST(Coder, decode)
{
	Coder coder;
	coder.set(buf_company, strlen(buf_company) + 1);

	EXPECT_STREQ(buf_company, coder.buf());

	coder.encode();

	EXPECT_STRNE(buf_company, coder.buf());

	coder.decode();

	EXPECT_STREQ(buf_company, coder.buf());
}

void test(const char* buf, int size)
{
	Coder coder;
	coder.set(buf, size);

	for(int i=0; i<size; i++)
	{
		ASSERT_EQ(buf[i], *(coder.buf()+i)) << "i is: " << i;
	}

	coder.encode();

	std::vector<char> vect(size);
	memcpy(&vect[0], buf, size);

	::encode(&vect[0], size);

	for(int i=0; i<size; i++)
	{
		ASSERT_EQ(vect[i], *(coder.buf()+i)) << "i is: " << i;
	}

	coder.decode();

	for(int i=0; i<size; i++)
	{
		ASSERT_EQ(*(buf+i), coder.buf()[i]) << "i is: " << i;
	}
}

TEST(Coder, test_1)
{
	char buf[] = {1};
	test(buf, sizeof(buf));
}

TEST(Coder, test_2)
{
	char buf[] = {1, 2};
	test(buf, sizeof(buf));
}

TEST(Coder, test_3)
{
	char buf[] = {1, 2, 3};
	test(buf, sizeof(buf));
}

TEST(Coder, test_rand)
{
	srand( time(0) );
	int size = 10000;
	char* buf = new char[size];

	for( int i=0; i<size; i++)
	{
		buf[i] = rand();
	}

	test(buf, size);

	delete[] buf;
}


int main(int argc, char **argv)
{
  printf("Running main() from Coder_gTest.cpp\n");

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

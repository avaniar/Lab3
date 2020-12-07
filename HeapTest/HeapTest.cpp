#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3/HeaderLab3.h"
#include "../Lab3/HeaderLab3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HeapTest
{
	TEST_CLASS(HeapTest)
	{
	public:
		Binaryheap tree1;
		TEST_METHOD(correct_contains)
		{
			tree1.insert(1);
			tree1.insert(3);
			tree1.insert(6);
			tree1.insert(8);
			Assert::IsTrue(tree1.contains(6));
		}
		TEST_METHOD(incorrect_contains)
		{
			tree1.insert(1);
			tree1.insert(3);
			tree1.insert(6);
			tree1.insert(8);
			Assert::IsFalse(tree1.contains(16));
		}
		TEST_METHOD(correct_insert)
		{
			tree1.insert(1);
			tree1.insert(3);
			tree1.insert(6);
			tree1.insert(0);
			Iterator* test = tree1.create_dft_iterator();
			Assert::AreEqual(test->next(), 0);
		}
		TEST_METHOD(correct_remove)
		{
			tree1.insert(1);
			tree1.insert(3);
			tree1.insert(6);
			tree1.insert(0);
			tree1.remove(0);
			Iterator* test = tree1.create_dft_iterator();
			Assert::AreEqual(test->next(), 1);
		}
		TEST_METHOD(correct_dft_iterator)
		{
			tree1.insert(1);
			tree1.insert(2);
			tree1.insert(3);
			tree1.insert(6);
			Iterator* test = tree1.create_dft_iterator();
			Assert::AreEqual(test->next(), 1);
			Assert::AreEqual(test->next(), 2);
			Assert::AreEqual(test->next(), 6);
			Assert::AreEqual(test->next(), 3);
		}
		TEST_METHOD(correct_bft_iterator)
		{
			tree1.insert(1);
			tree1.insert(2);
			tree1.insert(3);
			tree1.insert(6);
			Iterator* test2 = tree1.create_bft_iterator();
			Assert::AreEqual(test2->next(), 1);
			Assert::AreEqual(test2->next(), 2);
			Assert::AreEqual(test2->next(), 3);
			Assert::AreEqual(test2->next(), 6);
		}


	};
}

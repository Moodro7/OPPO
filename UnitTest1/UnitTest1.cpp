#include "pch.h"
#include <vector>
#include "CppUnitTest.h"
#include "..\ИмамутдиновИК_3\data.cpp"
#include "..\ИмамутдиновИК_3\data.h"
#include "..\ИмамутдиновИК_3\tovar.cpp"
#include "..\ИмамутдиновИК_3\tovar.h"
#include "..\ИмамутдиновИК_3\main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(LoadTest)
	{
	public:

		TEST_METHOD(Load)
		{
			date data;
			tovar tovars;
			std::istringstream input("15.10.2023 XJleb 20");
			data.date::read(input);
			tovars.tovar::read(input);;
			Assert::AreEqual(data.yyyy, 2023);
			Assert::AreEqual(data.mm, 10);
			Assert::AreEqual(data.dd, 15);
			string tovarname = "XJleb";
			Assert::AreEqual(tovars.name, tovarname);
			int tovarquant = 20;
			Assert::AreEqual(tovars.quant, tovarquant);
		}
	};
	TEST_CLASS(DateTest)
	{
	public:

		TEST_METHOD(ValidDate)
		{
			date d;
			std::istringstream input("09.11.2001");
			d.date::set_date(input, d);

			Assert::AreEqual(d.yyyy, 2023);
			Assert::AreEqual(d.mm, 10);
			Assert::AreEqual(d.dd, 15);
		}
		TEST_METHOD(InvalidDate)
		{
			date d;
			std::istringstream input("40.15.2023");

			Assert::ExpectException<std::runtime_error>([&] {
				d.date::set_date(input, d);
				});

		}
	};
	TEST_CLASS(QuantTest)
	{
	public:

		TEST_METHOD(ValidQuant)
		{
			tovar tovars;
			std::istringstream input("15.10.2023 XJleb 20");
			tovars.tovar::read(input);
			Assert::IsTrue(tovars.quant >= 0);
		}
		TEST_METHOD(InvalidQuant)
		{
			tovar tovars;
			std::istringstream input("15.10.2023 XJleb -20");
			tovars.tovar::read(input);
			Assert::IsFalse(tovars.quant < 0);

		}
	};
}

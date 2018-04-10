#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
#include <complex>
#include <gtest/gtest.h>

using std::complex;
using namespace std::complex_literals;

TEST(Creation, NoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		Fraction<int> noArgumentsInt;
		//EXPECT_EQ(noArgumentsInt._numerator, 1);
		//EXPECT_EQ(noArgumentsInt._denominator, 1);
	});
}

TEST(Creation, NoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		Fraction<std::complex<double>> noArgumentsComplex;
		//EXPECT_EQ(noArgumentsComplex._numerator, 1. + 0i);
		//EXPECT_EQ(noArgumentsComplex._denominator, 1. + 0i);
	});
}

TEST(Creation, OneArgumentConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		Fraction<int> oneArgumentInt = Fraction<int>(integerNumerator);
		EXPECT_EQ(oneArgumentInt._numerator, integerNumerator);
		//EXPECT_EQ(oneArgumentInt._denominator, 1);
	});
}

TEST(Creation, OneArgumentConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		Fraction<std::complex<double>> oneArgumentComplex = Fraction<std::complex<double>>(complexNumerator);
		EXPECT_EQ(oneArgumentComplex._numerator, complexNumerator);
		//EXPECT_EQ(oneArgumentComplex._denominator, 1. + 0i);
	});
}

TEST(Creation, TwoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -21;
		Fraction<int> twoArgumentsInt = Fraction<int>(integerNumerator, integerDenominator);
		EXPECT_EQ(twoArgumentsInt._numerator, integerNumerator);
		EXPECT_EQ(twoArgumentsInt._denominator, integerDenominator);
	});
}

TEST(Creation, TwoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		std::complex<double> complexDenominator = 2. + 3i;
		Fraction<std::complex<double>> twoArgumentsComplex = Fraction<std::complex<double>>(complexNumerator, complexDenominator);
		EXPECT_EQ(twoArgumentsComplex._numerator, complexNumerator);
		EXPECT_EQ(twoArgumentsComplex._denominator, complexDenominator);
	});
}

TEST(Operator, IntEqualInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		first = second;
		EXPECT_EQ(first._numerator, second._numerator);
		EXPECT_EQ(first._denominator, second._denominator);
	});
}

TEST(Operator, ComplexEqualComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		first = second;
		EXPECT_EQ(first._numerator, second._numerator);
		EXPECT_EQ(first._denominator, second._denominator);
	});
}

TEST(Operator, IntEqualEqualInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		int integerNumerator3 = 5;
		int integerDenominator3 = 3;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> third = Fraction<int>(integerNumerator3, integerDenominator3);
		EXPECT_TRUE(first == third);
		EXPECT_FALSE(first == second);
		EXPECT_FALSE(second == third);
	});
}

TEST(Operator, ComplexEqualEqualComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> complexNumerator3 = 1. + 2i;
		std::complex<double> complexDenominator3 = 2. + 3i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> third = Fraction<complex<double>>(complexNumerator3, complexDenominator3);
		EXPECT_TRUE(first == third);
		EXPECT_FALSE(first == second);
		EXPECT_FALSE(second == third);
	});
}

TEST(Operator, IntPlusInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> result = first + second;
		EXPECT_EQ(result._numerator, 23);
		EXPECT_EQ(result._denominator, 21);
	});
}

TEST(Operator, ComplexPlusComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = -12. + 30i;
		std::complex<double> referenceDenominator = -7. + 22i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> reference = Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> result = first + second;
		EXPECT_EQ(result._numerator, reference._numerator);
		EXPECT_EQ(result._denominator, reference._denominator);
	});
}

TEST(Operator, IntMinusInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> result = first - second;
		EXPECT_EQ(result._numerator, 47);
		EXPECT_EQ(result._denominator, 21);
	});
}

TEST(Operator, ComplexMinusComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = 0. - 4i;
		std::complex<double> referenceDenominator = -7. + 22i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> reference = Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> result = first - second;
		EXPECT_EQ(result._numerator, reference._numerator);
		EXPECT_EQ(result._denominator, reference._denominator);
	});
}

TEST(Operator, IntMultipliedByInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> result = first * second;
		EXPECT_EQ(result._numerator, -20);
		EXPECT_EQ(result._denominator, 21);
	});
}

TEST(Operator, ComplexMultipliedByComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = -5. + 10i;
		std::complex<double> referenceDenominator = -7. + 22i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> reference = Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> result = first * second;
		EXPECT_EQ(result._numerator, reference._numerator);
		EXPECT_EQ(result._denominator, reference._denominator);
	});
}

TEST(Operator, IntDividedByInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> result = first / second;
		EXPECT_EQ(result._numerator, 21);
		EXPECT_EQ(result._denominator, -20);
	});
}

TEST(Operator, ComplexDividedByComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = -7. + 22i;
		std::complex<double> referenceDenominator =  -5. + 10i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> reference = Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> result = first / second;
		EXPECT_EQ(result._numerator, reference._numerator);
		EXPECT_EQ(result._denominator, reference._denominator);
	});
}

int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
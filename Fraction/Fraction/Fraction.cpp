#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
#include <complex>
#include <gtest/gtest.h>

using std::complex;
using namespace std::complex_literals;

template <class T>
Fraction<T>::Fraction() //no arguments constructor
{
}

template <class T>
Fraction<T>::Fraction(T numerator) //one argument construtor
{
	_numerator = numerator;
}

template <class T>
Fraction<T>::Fraction(T numerator, T denominator) //two arguments constructor
{
	_numerator = numerator;
	_denominator = denominator;
}

template <class T>
Fraction<T>::~Fraction() //destructor
{
}

template <class T>
Fraction<T>* operator + (Fraction<T> & lhs, Fraction<T> & rhs) // + operator
{
	T numerator1 = lhs._numerator;
	T denominator1 = lhs._denominator;
	T numerator2 = rhs._numerator;
	T denominator2 = rhs._denominator;
	T denominatorR = denominator1 * denominator2;
	T numeratorR = numerator1 * denominator2 + numerator2 * denominator1;
	return new Fraction<T>(numeratorR, denominatorR);
}

TEST(Creation, NoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		Fraction<int> *noArgumentsInt = new Fraction<int>();
		//EXPECT_EQ(noArgumentsInt->_numerator, 1);
		//EXPECT_EQ(noArgumentsInt->_denominator, 1);
		delete noArgumentsInt;
	});
}

TEST(Creation, NoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		Fraction<std::complex<double>> *noArgumentsComplex = new Fraction<std::complex<double>>();
		//EXPECT_EQ(noArgumentsComplex->_numerator, 1. + 0i);
		//EXPECT_EQ(noArgumentsComplex->_denominator, 1. + 0i);
		delete noArgumentsComplex;
	});
}

TEST(Creation, OneArgumentConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		Fraction<int> *oneArgumentInt = new Fraction<int>(integerNumerator);
		EXPECT_EQ(oneArgumentInt->_numerator, integerNumerator);
		//EXPECT_EQ(oneArgumentInt->_denominator, 1);
		delete oneArgumentInt;
	});
}

TEST(Creation, OneArgumentConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		Fraction<std::complex<double>> *oneArgumentComplex = new Fraction<std::complex<double>>(complexNumerator);
		EXPECT_EQ(oneArgumentComplex->_numerator, complexNumerator);
		//EXPECT_EQ(oneArgumentComplex->_denominator, 1. + 0i);
		delete oneArgumentComplex;
	});
}

TEST(Creation, TwoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -21;
		Fraction<int> *twoArgumentsInt = new Fraction<int>(integerNumerator, integerDenominator);
		EXPECT_EQ(twoArgumentsInt->_numerator, integerNumerator);
		EXPECT_EQ(twoArgumentsInt->_denominator, integerDenominator);
		delete twoArgumentsInt;
	});
}

TEST(Creation, TwoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		std::complex<double> complexDenominator = 2. + 3i;
		Fraction<std::complex<double>> *twoArgumentsComplex = new Fraction<std::complex<double>>(complexNumerator, complexDenominator);
		EXPECT_EQ(twoArgumentsComplex->_numerator, complexNumerator);
		EXPECT_EQ(twoArgumentsComplex->_denominator, complexDenominator);
		delete twoArgumentsComplex;
	});
}

TEST(Operator, IntPlusInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> *first = new Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> *second = new Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> *result = *first + *second;
		EXPECT_EQ(result->_numerator, 23);
		EXPECT_EQ(result->_denominator, 21);
		delete result;
	});
}

int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
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
Fraction<T>::Fraction(T numerator) //one argument 
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

TEST(Creation, NoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		Fraction<int> *noArgumentsInt = new Fraction<int>();
		delete noArgumentsInt;
	});
}

TEST(Creation, NoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		Fraction<std::complex<double>> *noArgumentsComplex = new Fraction<std::complex<double>>();
		delete noArgumentsComplex;
	});
}

TEST(Creation, OneArgumentConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		Fraction<int> *oneArgumentInt = new Fraction<int>(integerNumerator);
		EXPECT_EQ(oneArgumentInt->_numerator, integerNumerator);
		delete oneArgumentInt;
	});
}

TEST(Creation, OneArgumentConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		Fraction<std::complex<double>> *oneArgumentComplex = new Fraction<std::complex<double>>(complexNumerator);
		EXPECT_EQ(oneArgumentComplex->_numerator, complexNumerator);
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

int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
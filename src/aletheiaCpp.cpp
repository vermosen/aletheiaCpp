//============================================================================
// Name        : aletheiaCpp.cpp
// Author      : Jean-Mathieu Vermosen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <mlpack/core.hpp>

using namespace mlpack;

int main() {

	try
	{
		// load data set
		arma::mat data;

		std::cout << data << std::endl;

		return 0;
	}
	catch (std::exception & ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
}

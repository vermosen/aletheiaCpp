//============================================================================
// Name        : aletheiaCpp.cpp
// Author      : Jean-Mathieu Vermosen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <mlpack/core.hpp>

#include "loggers/consoleLogger.hpp"
#include "timeSeries.hpp"

#include "database/aletheia.hpp"

using namespace mlpack;

int main() {

	int retVal = 0;

	boost::shared_ptr<logger> log(new loggers::consoleLogger(logger::verbosity::low));

	try
	{
		// step 1: open connection
		boost::shared_ptr<db::database> db(new db::aletheiaDatabase(log));

		db->connect("user=postgres password=1234 host=localhost port=5432 dbname=aletheia");

		// load data set
		arma::mat data;

		std::cout << data << std::endl;

		retVal = 0;
	}
	catch (soci::postgresql_soci_error & e)
	{
		log->add("PostgreSQL error: " + e.sqlstate() + " " + e.what(),
			logger::messageType::error, logger::verbosity::high);
		retVal = 1;
	}
	catch (std::exception & e)
	{
		log->add("an error occurred: " + std::string(e.what()),
			logger::messageType::error, logger::verbosity::high);
		retVal = 1;
	}
	catch (...)
	{
		log->add("an unknown error occurred...",
			logger::messageType::error, logger::verbosity::high);
		retVal = 1;
	}

	return retVal;
}

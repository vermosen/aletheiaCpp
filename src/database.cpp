/*
 * database.cpp
 *
 *  Created on: Jul 3, 2016
 *      Author: vermosen
 */

#include "database.hpp"

namespace db
{
	connector::connector(boost::shared_ptr<logger> log) : log_(log) {}

	connector::~connector() {}

	boost::shared_ptr<soci::session> connector::session()
	{
		return session_;
	}

	database::database(boost::shared_ptr<logger> & log) : log_(log) {}

	database::~database() {}

	void database::connect(const std::string & connectionString)
	{
		connector_->connect(connectionString);
	}

	boost::shared_ptr<connector> database::dbConnector() { return connector_; }
}

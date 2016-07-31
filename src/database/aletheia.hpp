/*
 * aletheiaDatabase.hpp
 *
 *  Created on: Jul 3, 2016
 *      Author: vermosen
 */

#ifndef ALETHEIA_HPP_
#define ALETHEIA_HPP_

#include <soci.h>
#include <postgresql/common.h>

#include <boost/tuple/tuple.hpp>
#include <boost/optional/optional.hpp>

#include <soci.h>

#include "timeSeries.hpp"
#include "recordset.hpp"
#include "database.hpp"
#include "logger.hpp"

namespace db
{
	class aletheiaConnector : public connector
	{
	public:
		aletheiaConnector(boost::shared_ptr<logger>);
		virtual void connect(const std::string & connectionString);
	};

	class aletheiaDatabase : public database
	{
	public:
		aletheiaDatabase(boost::shared_ptr<logger> &);
	};

	class timeSeriesRecordset : public recordset<long long, boost::tuple<long, timeSeries<double> > >
	{
	public:
		timeSeriesRecordset(boost::shared_ptr<connector> conn, boost::shared_ptr<logger> log);

		virtual std::vector<keyType> insert(const std::vector<recordType> & records);
		virtual void update(const recordType & record);
		virtual void remove(const recordType & record);
		virtual void select(std::vector<recordType> & ret, const std::string & filter);
		virtual void select(const std::vector<keyType> & keys, std::vector<recordType> & ret);
	};
}

#endif /* ALETHEIA_HPP_ */

/*
 * aletheiaDatabase.cpp
 *
 *  Created on: Jul 3, 2016
 *      Author: vermosen
 */

#include <database/aletheia.hpp>
#include <soci/session.h>

namespace db
{
	aletheiaConnector::aletheiaConnector(boost::shared_ptr<logger> log) : connector(log)
	{
		// TODO Auto-generated constructor stub

	}

	void aletheiaConnector::connect(const std::string & connectionString)
	{
		session_ = boost::shared_ptr<soci::session>(
			new soci::session(soci::postgresql, connectionString));
	}

	aletheiaDatabase::aletheiaDatabase(boost::shared_ptr<logger> & log) : database(log)
	{
		// TODO Auto-generated constructor stub
		connector_ = boost::shared_ptr<connector>(new aletheiaConnector(log));
	}

	timeSeriesRecordset::timeSeriesRecordset(boost::shared_ptr<connector> conn, boost::shared_ptr<logger> log)
		: recordset<long long, recordType>(conn, log) {}

	std::vector<long long> timeSeriesRecordset::insert(const std::vector<recordType> & records)
	{
		// TODO: batch insert
		for (auto it = records.cbegin(); it != records.cend(); ++it)
		{
			connector_->session()->begin();

			try
			{
				timeSeries<double>::const_iterator jt;

				/* TODO: conversion ptime -> db
				soci::statement st = (connector_->session()->prepare
					<< "INSERT INTO timeseries(index, date, value)"
					<< " VALUES (:idx, :dat, :val)",
						soci::use(it->get<0>(), "idx"),
						soci::use(jt->first, "dat"),
						soci::use(jt->second, "val"));
				*/
				for (jt = it->get<1>().cbegin(); jt != it->get<1>().cend(); ++jt)
				{
					//st.execute(false);
				}

				connector_->session()->commit();
			}
			catch (std::exception & ex)
			{
				connector_->session()->rollback();
			}
		}

		return std::vector<long long>();
	}
	void timeSeriesRecordset::update(const recordType & record) {}
	void timeSeriesRecordset::remove(const recordType & record) {}
	void timeSeriesRecordset::select(std::vector<recordType> & ret, const std::string & filter) {}
	void timeSeriesRecordset::select(const std::vector<keyType> & keys, std::vector<recordType> & ret) {}
}


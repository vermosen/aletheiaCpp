/*
 * database.hpp
 *
 *  Created on: Jul 31, 2016
 *      Author: vermosen
 */

#ifndef DATABASE_HPP_
#define DATABASE_HPP_

#include <boost/shared_ptr.hpp>

#include <soci.h>

#include "logger.hpp"

namespace db
{
	class connector
	{
	public:
		connector(boost::shared_ptr<logger> log);
		virtual ~connector();
		virtual void connect(const std::string & connectionString) = 0;
		boost::shared_ptr<soci::session> session();

		void begin		() {session_->begin		(); }
		void commit		() {session_->commit	(); }
		void rollback	() {session_->rollback	(); }

	protected:
		boost::shared_ptr<soci::session> session_;
		boost::shared_ptr<logger> log_;
	};

	class database
	{
	public:
		database(boost::shared_ptr<logger> &);
		virtual ~database();

		void connect(const std::string & connectionString);
		boost::shared_ptr<connector> dbConnector();

		virtual bool checkStatus() const = 0;
		virtual bool rebuild() = 0;

	protected:
		boost::shared_ptr<connector> connector_;
		boost::shared_ptr<logger> log_;
	};
}

#endif /* DATABASE_HPP_ */

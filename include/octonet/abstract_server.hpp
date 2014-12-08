//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

class octonet_notifier;

class abstract_server
{
	protected:
		octonet_notifier* notifier_;

	public:
		abstract_server(octonet_notifier* _notifier) : notifier_(_notifier) {}
		virtual abstract_server(void) {}
		virtual void start(void) = 0;
		virtual void stop(void) = 0;
		virtual const std::string& server_id(void) const = 0;
};

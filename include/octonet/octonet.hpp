//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef OCTONET_HPP
#define OCTONET_HPP

#include <set>

#include "octopeer.hpp"
#include "octopeer_observer.hpp"
#include "octoquery.hpp"
#include "octoquery_observer.hpp"

class octonet : public octopeer
{
public:

    octonet(void) {}

    ~octonet(void) {}

	 std::set<octopeer>& peers(std::set<octopeer>& _peers)
	 {
         return _peers;
	 }

    bool add_query_observer(octoquery_observer* _query_observer)
    {
        return false;
    }

    bool rem_query_observer(octoquery_observer* _query_observer)
    {
        return false;
    }

    bool add_peer_observer(octopeer_observer* _peer_observer)
    {
        return false;
    }
    
    bool rem_peer_observer(octopeer_observer* _peer_observer)
    {
        return false;
    }

    void start(void)
    {
        ;
    }

    void stop(void)
    {
        ;
    }

    void send_query(const octopeer& _peer, const octoquery& _query)
    {
        ;
    }
};

#endif

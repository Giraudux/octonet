//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef OCTONET_HPP
#define OCTONET_HPP

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/thread/thread.hpp>
#include <set>

#include "octonet_notifier.hpp"
#include "octopeer.hpp"
#include "octopeer_observer.hpp"
#include "octoquery.hpp"
#include "octoquery_observer.hpp"

class octonet : public octonet_notifier
{
private:
    void add_peer(const octopeer& _peer) {}

    void rem_peer(const octopeer& _peer) {}

    void receive_query(const octopeer& _peer, const octoquery& _query) {}

public:

    octonet(void) : octonet_notifier(boost::uuids::random_generator()()) {}

    ~octonet(void) {}

    bool add_query_observer(octoquery_observer* _query_observer)
    {
        boost::lock_guard<boost::mutex> guard(this->query_observers_set_mtx_);
        return this->query_observers_set_.insert(_query_observer).second;
    }

    bool rem_query_observer(octoquery_observer* _query_observer)
    {
        boost::lock_guard<boost::mutex> guard(this->query_observers_set_mtx_);
        return this->query_observers_set_.erase(_query_observer) > 0;
    }

    bool add_peer_observer(octopeer_observer* _peer_observer)
    {
        boost::lock_guard<boost::mutex> guard(this->peer_observers_set_mtx_);
        return this->peer_observers_set_.insert(_peer_observer).second;
    }

    bool rem_peer_observer(octopeer_observer* _peer_observer)
    {
        boost::lock_guard<boost::mutex> guard(this->peer_observers_set_mtx_);
        return this->peer_observers_set_.erase(_peer_observer) > 0;
    }

    void start(void)
    {
        ;
    }

    void stop(void)
    {
        ;
    }
};

#endif

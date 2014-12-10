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

#include "octopeer.hpp"
#include "octopeer_observer.hpp"
#include "octoquery.hpp"
#include "octoquery_observer.hpp"

class octonet : public octopeer
{
private:
    boost::mutex peers_set_mtx_;
    boost::mutex query_observers_set_mtx_;
    boost::mutex peer_observers_set_mtx_;

    std::set<octopeer> peers_set_;
    std::set<octoquery_observer*> query_observers_set_;
    std::set<octopeer_observer*> peer_observers_set_;

protected:

    octonet(void) : octopeer(boost::uuids::random_generator()()) {}

    virtual ~octonet(void) {}

    void notify_peer_observers(const octopeer& _peer, octopeer_state _state)
    {
        boost::lock_guard<boost::mutex> guard(peer_observers_set_mtx_);
        for(std::set<octopeer_observer*>::const_iterator it=peer_observers_set_.begin(); it!=peer_observers_set_.end(); ++it)
        {
            (*it)->update_peer(_peer, _state);
        }
    }

    void notify_query_observers(const octopeer& _peer, const octoquery& _query)
    {
        boost::lock_guard<boost::mutex> guard(query_observers_set_mtx_);
        for(std::set<octoquery_observer*>::const_iterator it=query_observers_set_.begin(); it!=query_observers_set_.end(); ++it)
        {
            if((*it)->app_id().empty() || ((*it)->app_id() == _query.app_id))
            {
                (*it)->update_query(_peer, _query);
            }
        }
    }

public:

    bool add_query_observer(octoquery_observer* _query_observer)
    {
        boost::lock_guard<boost::mutex> guard(query_observers_set_mtx_);
        return query_observers_set_.insert(_query_observer).second;
    }

    bool rem_query_observer(octoquery_observer* _query_observer)
    {
        boost::lock_guard<boost::mutex> guard(query_observers_set_mtx_);
        return query_observers_set_.erase(_query_observer) > 0;
    }

    bool add_peer_observer(octopeer_observer* _peer_observer)
    {
        boost::lock_guard<boost::mutex> guard(peer_observers_set_mtx_);
        return peer_observers_set_.insert(_peer_observer).second;
    }

    bool rem_peer_observer(octopeer_observer* _peer_observer)
    {
        boost::lock_guard<boost::mutex> guard(peer_observers_set_mtx_);
        return peer_observers_set_.erase(_peer_observer) > 0;
    }

    std::set<std::string>& app_ids(std::set<std::string>& _app_ids)
    {
        boost::lock_guard<boost::mutex> guard(query_observers_set_mtx_);
        for(std::set<octoquery_observer*>::const_iterator it=query_observers_set_.begin(); it!=query_observers_set_.end(); ++it)
        {
            _app_ids.insert((*it)->app_id());
        }
        return _app_ids;
    }

    virtual std::set<octopeer>& peers(std::set<octopeer>& _peers) = 0;

    virtual void start(void) = 0;

    virtual void stop(void) = 0;

    virtual void send_query(octopeer& _peer, octoquery& _query) = 0;
};

#endif

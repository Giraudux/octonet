//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef OCTONET_NOTIFIER_HPP
#define OCTONET_NOTIFIER_HPP

#include <boost/uuid/uuid.hpp>
#include <set>

#include "octopeer.hpp"
#include "octopeer_observer.hpp"
#include "octoquery.hpp"
#include "octoquery_observer.hpp"

class octonet_notifier : public octopeer
{
private:
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

protected:
    boost::mutex peers_set_mtx_;
    boost::mutex query_observers_set_mtx_;
    boost::mutex peer_observers_set_mtx_;

    std::set<octopeer> peers_set_;
    std::set<octoquery_observer*> query_observers_set_;
    std::set<octopeer_observer*> peer_observers_set_;

    void start(void)
    {
        ;
    }

    void stop(void)
    {
        ;
    }

public:

    octonet_notifier(boost::uuids::uuid _uuid) : octopeer(_uuid) {}

    ~octonet_notifier(void) {}

    bool add_peer(const octopeer& _peer)
    {
        boost::lock_guard<boost::mutex> guard(peers_set_mtx_);
        if(peers_set_.find(_peer) == peers_set_.end())
        {
            if(peers_set_.insert(_peer).second);
            {
                notify_peer_observers(_peer, online);
                return true;
            }
        }
        return false;
    }

    bool rem_peer(const octopeer& _peer)
    {
        boost::lock_guard<boost::mutex> guard(peers_set_mtx_);
        if(peers_set_.erase(_peer) > 0)
        {
            notify_peer_observers(_peer, offline);
            return true;
        }
        return false;
    }


    void receive_query(const octopeer& _peer, const octoquery& _query)
    {
        notify_query_observers(_peer, _query);
    }

    std::set<octopeer>& peers(std::set<octopeer>& _peers)
    {
        boost::lock_guard<boost::mutex> guard(peers_set_mtx_);
        _peers.insert(peers_set_.begin(), peers_set_.end());
        return _peers;
    }

    std::set<std::string>& app_ids(std::set<std::string>& _app_ids)
    {
        boost::lock_guard<boost::mutex> guard(query_observers_set_mtx_);
        return _app_ids;
    }
};

#endif

//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef OCTOQUERY_OBSERVER_HPP
#define OCTOQUERY_OBSERVER_HPP

#include <string>

#include "octopeer.hpp"
#include "octoquery.hpp"

class octoquery_observer
{
public:

    virtual void update_query(const octopeer& _peer, const octoquery& _query) = 0;

    virtual const std::string& app_id(void) const = 0;
};

#endif

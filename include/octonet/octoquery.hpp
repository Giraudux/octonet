//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef OCTOQUERY_HPP
#define OCTOQUERY_HPP

#include <string>

#include "octopeer.hpp"

struct octoquery
{
    std::string app_id;

    std::string content;

    octoquery(const std::string& _app_id, const std::string& _content) : app_id(_app_id), content(_content) {}

    octoquery(const octoquery& _query) : app_id(_query.app_id), content(_query.content) {}
};

#endif

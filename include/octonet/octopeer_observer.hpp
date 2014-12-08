//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef OCTOPEER_OBSERVER_HPP
#define OCTOPEER_OBSERVER_HPP

#include "octopeer.hpp"

class octopeer_observer
{
public:

    virtual void update_peer(const octopeer& _peer, octopeer_state _state) = 0;
};

#endif

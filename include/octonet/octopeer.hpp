//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef OCTOPEER_HPP
#define OCTOPEER_HPP

#include <boost/uuid/uuid.hpp>

enum octopeer_state { online, offline };

struct octopeer
{
	const boost::uuids::uuid uuid;

	octopeer(boost::uuids::uuid _uuid) : uuid(_uuid) {}
	octopeer(const octopeer& _peer)    : uuid(_peer.uuid) {}
};

inline bool operator==(const octopeer& lhs, const octopeer& rhs) { return lhs == rhs; }
inline bool operator!=(const octopeer& lhs, const octopeer& rhs) { return lhs != rhs; }
inline bool operator< (const octopeer& lhs, const octopeer& rhs) { return lhs <  rhs; }
inline bool operator> (const octopeer& lhs, const octopeer& rhs) { return lhs >  rhs; }
inline bool operator<=(const octopeer& lhs, const octopeer& rhs) { return lhs <= rhs; }
inline bool operator>=(const octopeer& lhs, const octopeer& rhs) { return lhs >= rhs; }

#endif

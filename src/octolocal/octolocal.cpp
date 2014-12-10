//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <octolocal/octolocal.hpp>

octolocal::octolocal(unsigned short _udp_port, unsigned short _tcp_port) : octonet(), udp_port_(_udp_port), tcp_port_(_tcp_port)
{
	;
}

octolocal::~octolocal(void)
{
	;
}

void octolocal::start(void)
{
	tcp_server_ptr_.reset(new tcp_server(this));
	tcp_server_ptr_->start();
	udp_server_ptr_.reset(new udp_server(this));
	udp_server_ptr_->start();
	io_service_.poll();
}

void octolocal::stop(void)
{
	io_service_.stop();
}

std::set<octopeer>& octolocal::peers(std::set<octopeer>& _peers)
{
	return _peers;
}

void octolocal::send_query(octopeer& _peer, octoquery& _query)
{
	;
}

void octolocal::send_broadcast(unsigned short _udp_port)
{
	;
}

void octolocal::check_peer(boost::asio::ip::address _address, unsigned short _tcp_port)
{
	;
}

udp_server::udp_server(octolocal* _local) : local_(_local), buffer_len_(octolocal_version.size()+octolocal_port_length), socket_(_local->io_service_, udp::endpoint(udp::v4(), _local->udp_port_))
{
	;
}

void udp_server::start(void)
{
	;//handle read
}

tcp_server::tcp_server(octolocal* _local) : local_(_local), acceptor_(_local->io_service_, tcp::endpoint(tcp::v4(), _local->tcp_port_))
{
	;
}

void tcp_server::start(void)
{
	;//handle accept
}

tcp_connection_ptr tcp_connection::new_tcp_connection(octolocal* _local)
{
	return tcp_connection_ptr(new tcp_connection(_local));
}

tcp::socket& tcp_connection::socket(void)
{
	return socket_;
}

void tcp_connection::start(void)
{
	;//handle read
}

tcp_connection::tcp_connection(octolocal* _local) : local_(_local), socket_(_local->io_service_)
{
	;
}

//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <octonet/octonet.hpp>

using boost::asio::ip::tcp;
using boost::asio::ip::udp;

class tcp_connection
{
    ;
};

class tcp_server
{
    ;
};

class udp_server
{
public:
    udp_server(boost::asio::io_service& _io_service, unsigned short _port) : socket_(_io_service, udp::endpoint(udp::v4(), _port)) {}

    void start_receive()
    {
        socket_.async_receive_from(
            boost::asio::buffer(recv_buffer_), remote_endpoint_,
            boost::bind(&udp_server::handle_receive, this,
                        boost::asio::placeholders::error));
    }

private:

    void handle_receive(const boost::system::error_code& error)
    {
        if (!error)
        {
            ;

        }
        start_receive();
    }

    udp::socket socket_;
    udp::endpoint remote_endpoint_;
    boost::array<char, 10> recv_buffer_;
};

class octolocal : public octonet
{
private:
    boost::asio::io_service io_service_;
    tcp_server tcp_server_;
    udp_server udp_server_;

public:

    void start(void)
    {
        ;
    }

    void stop(void)
    {
        ;
    }

    void send_query(octopeer& _peer, octoquery& _query)
    {
        ;
    }
};

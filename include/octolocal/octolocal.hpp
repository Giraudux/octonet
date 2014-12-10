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

class octolocal;

class tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
private:
    octolocal* local_;
    tcp::socket tcp_socket_;

    tcp_connection(octolocal* _local);

public:

    typedef boost::shared_ptr<tcp_connection> tcp_connection_ptr;

    static tcp_connection_ptr new_tcp_connection(octolocal* _local);

    tcp::socket& socket(void);

    void start(void);

};

class tcp_server
{
private:
    octolocal* local_;
    tcp::acceptor acceptor_;

public:

    tcp_server(octolocal* _local);

    void start(void);
};

class udp_server
{
private:
    octolocal* local_;
    udp::socket socket_;
    udp::endpoint remote_endpoint_;
    boost::array<char, 1> recv_buffer_;

public:

    udp_server(octolocal* _local);

    void start(void);
}:

class octolocal : public octonet
{
    friend class tcp_connection;
    friend class udp_server;

private:
    boost::asio::io_service io_service_;

public:

    void start(void);

    void stop(void);

    void send_query(octopeer& _peer, octoquery& _query);
};

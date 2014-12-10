//          Copyright Alexis Giraudet 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/smart_ptr.hpp>
#include <octonet/octonet.hpp>
#include <octonet/octopeer.hpp>
#include <octonet/octoquery.hpp>
#include <map>
#include <utility>

static const std::string octolocal_version = "OCTOLOCAL1";
static const unsigned short octolocal_default_udp_port = 4444;
static const unsigned short octolocal_default_tcp_port = 5555;
static const std::size_t octolocal_port_length = 4;

using boost::asio::ip::tcp;
using boost::asio::ip::udp;

class octolocal;

class tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
private:
    octolocal* local_;
    tcp::socket socket_;

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
    const std::size_t buffer_len_;
    boost::scoped_array<char> buffer_;
    udp::socket socket_;
    udp::endpoint remote_endpoint_;

public:

    udp_server(octolocal* _local);

    void start(void);
};

class octolocal : public octonet
{
    friend class tcp_connection;
    friend class udp_connection;
    friend class udp_server;

private:
    boost::asio::io_service io_service_;
    unsigned short udp_port_;
    unsigned short tcp_port_;
    boost::scoped_ptr<udp_server> udp_server_ptr_;
    boost::scoped_ptr<tcp_server> tcp_server_ptr_;
    std::map< octopeer, std::pair<boost::asio::ip::address, unsigned short> > local_peers_;

public:

    octolocal(unsigned short _udp_port, unsigned short _tcp_port);

    ~octolocal(void);

    void start(void);

    void stop(void);

    std::set<octopeer>& peers(std::set<octopeer>& _peers);

    void send_query(octopeer& _peer, octoquery& _query);

    void send_broadcast(unsigned short _udp_port);

    void check_peer(boost::asio::ip::address _address, unsigned short _tcp_port);
};

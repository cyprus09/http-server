#include "http_tcpServer.h"

#include <iostream>
#include <sstream>
#include <unistd.h>

namespace
{
    void log(const std::string &message)
    {
        std::cout << message << std::endl;
    }

    void exitWithError(const std::string &errorMessage)
    {
        log("Error: " + errorMessage);
        exit(1);
    }

}
namespace http
{

    TcpServer ::TcpServer(std::string ip_address, int port) : m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket(), m_incoming_message(), m_socket_address(), m_socket_address_len(sizeof(m_socket_address)), m_server_message(buildRespone())
    {
        startServer();
    }

    TcpServer::~TcpServer()
    {
        closeServer();
    }

    int TcpServer::startServer()
    {
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket < 0)
        {
            exitWithError("Cannot create socket");
            return 1;
        }

        return 0;
    }

    void TcpServer::closeServer()
    {
        close(m_socket);
        close(m_new_socket);
        exit(0);
    }

}

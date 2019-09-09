
#include "Socket.h"

/**
* @file SocketClient.h
* @brief
*   This file contains the 'SocketClient' class.
* @class SocketClient
* @brief
*   'SocketClient' inherits form 'Socket' class and is specifically designed for client mode.
* @details
*   This class encapsulates some low-level client specific socket functionalities and provide an easy to use interface for handling the sockets.
*/
class SocketClient : public Socket
{
    /**
    * @brief
    *   Function which actually connects to the server.
    * @details
    *   First checks whether or not that server exists of that particular 'serverName' and then tries to connects to the server.
    * @param 'struct hostent *host ' : Socket on which data is to be sent.
    * @param 'string serverName ' : Name of the server to connect to.
    * @param 'int portNumber' : Port number of the server to connect on.
    * @return
    *   'int' : -1 on failure to connect, else 0.
    */
    int socket_connect(struct hostent *host , string serverName , int portNumber);    // Function which actually connects socket 
  public:
    
    /**
    * @brief
    *   Constructor of SocketClient Class
    */
    SocketClient();    
    
    /**
    * @brief
    *   Abstracted function to connects to the server.
    * @details
    *   Calls 'socket_connect' function which.
    * @param 'string serverName ' : Name of the server to connect to.
    * @param 'int portNumber' : Port number of the server to connect on.
    * @return
    *   'int' : returns what socket_connect returns.
    */
    int connectToServer(string serverName, int portNumber);                           // Autmatically does the name resolution and call socket_connect.
};

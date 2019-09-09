#include "Socket.h"

/**
* @file SocketServer.h
* @brief
*   This file contains the 'SocketServer' class.
* @class SocketServer
* @brief
*   'SocketServer' inherits form 'Socket' class and is specifically designed for server mode.
* @details
*   This class encapsulates some low-level server specific socket functionalities and provide an easy to use interface for handling the sockets.
*/
class SocketServer : public Socket
{
  public:
  
    /**
    * @brief
    *   Sets the socket file-descriptor to non-blocking.
    * @details
    *   Sets the server FD to non-blocking, mandatorily required in order for server to be asynchronous.
    * @param 'int fileDescriptor' : Socket to set non-blocking on.
    * @return
    *   void
    */
    static void set_nonblocking(int fileDescriptor);        

    /**
    * @brief
    *   Constructor of SocketServer Class
    */
    SocketServer();    
    
    /**
    * @brief
    *   Sets up the necessary socket options.
    * @return
    *   'int' : -1 if fails to setup , else 0.
    */
    int setSocketOptions();      

    /**
    * @brief
    *   Binds to the port on all interfaces.
    * @param 'int port' : Port number for the server to bind on.
    * @return
    *   'int' : -1 if fails to setup , else 0.
    */
    int socket_bind(int port); 

    /**
    * @brief
    *   Starts to listen for incoming connections on above set interfaces and port via file-descriptor(present in socket class).
    * @return
    *   'int' : -1 if fails to setup , else 0.
    */
    int socket_listen();         

    /**
    * @brief
    *   Accepts the incoming socket connection..
    * @return
    *   'int' :  The file-Descriptor for accepted connection.
    */
    int socket_accept();         
};


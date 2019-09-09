#include "SocketServer.h"

  /*
  * Accepts the incoming socket connection and returns the File-Descriptor for accepted connection.
  */
  int SocketServer::socket_accept() 
  {
    struct sockaddr in_addr;
    socklen_t in_addr_len = sizeof(in_addr);
    int client = accept(this->getFileDescriptor(), &in_addr, &in_addr_len);
    return client;
  }                  

  /*
  * This function is responsible to set the socket as non-blocking -> Only required at server side.
  */
  void SocketServer::set_nonblocking(int fileDescriptor) 
  {
    int flags = fcntl(fileDescriptor, F_GETFL, 0);
    if (flags == -1) 
    { 
      // Error in setting non-blocking
      perror("[#] fcntl() ");
      return;
    }
    
    if (fcntl(fileDescriptor, F_SETFL, flags | O_NONBLOCK) == -1) 
    {
      perror("[#] fcntl() ");
    }
    return;
  }


  SocketServer::SocketServer()
  {
    // Implicitly calls parent class's constructor i.e socket object is created by now.
    cout << "[*] Server Socket object ready"<<endl;
  }

  // Set up socket options and returns the response code which setsockopt returns.
  int SocketServer::setSocketOptions()
  {  
    int enable = 1;
    int responseCode = setsockopt(this->getFileDescriptor(), SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    if (responseCode == -1)    
    {
      perror("[#] setsockopt() ");
      return(RETURN_FAIL);
    }
    return responseCode;
  }

  int SocketServer::socket_bind(int port)
  {
    // Fill in the Socket structure.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);  //  INADDR_ANY  = "0.0.0.0"
    addr.sin_port = htons(port);
  
    // Bind the socket to the port via the FileDescriptor(m_socketFd : present in parent class).
    int responseCode = bind( this->getFileDescriptor() , (struct sockaddr *)&addr, sizeof(addr)); 
    if (responseCode == -1)
    {
      perror( "[#] bind() ");
    }
    return responseCode;
  }

  int SocketServer::socket_listen()
  {
    int responseCode = listen(this->getFileDescriptor() , SOMAXCONN);
    if ( responseCode < 0)    
    {
      perror("[#] Listen() ");
      return(RETURN_FAIL);
    }
    return responseCode;
  }

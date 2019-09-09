#include "SocketClient.h"


  SocketClient::SocketClient()
  {
    // Implicitly calls parent class's constructor i.e socket object is created by now.
    cout << "[*] Client Socket object ready"<<endl;
  }

  /*
  * Connect to the Ip:port specified in arugment.
  */
  int SocketClient::socket_connect(struct hostent *host , string serverName , int portNumber)
  {

    struct sockaddr_in serverStruct;         
    serverStruct.sin_family = AF_INET;    // Sets the  serverStruct family type

    // Copying into serverStruct the address of server returned from gethostbyname()
    memcpy((char*) &serverStruct.sin_addr.s_addr, host->h_addr_list[0], host->h_length); 
    serverStruct.sin_port = htons(portNumber);


    char ipAddress[INET_ADDRSTRLEN];    
    inet_ntop(AF_INET, &(serverStruct.sin_addr), ipAddress, INET_ADDRSTRLEN);
    cout << "[*] "<<serverName<<" resolved to : "<< ipAddress<<endl;

    int response = connect( this->getFileDescriptor(), (struct sockaddr * )&serverStruct, sizeof(serverStruct));
    if ( response == -1)
    {
      std::perror("[#] Error in connecting : ");
    }
    return response;
  }

  int SocketClient::connectToServer(string serverName, int portNumber)
  {
    struct hostent *hostStruct; // for hostname resolving etc.
  
    // Get IP of the hostname address
    bool response = Socket::getIpFromName(serverName , hostStruct);
    if ( response == false)
    {
      // close the socket you just opened for connecting, else you will run out of available open FDs.
      Socket::close_socket(this->getFileDescriptor());
      return -1;    
    }
    
    return socket_connect(hostStruct , serverName , portNumber);
  }

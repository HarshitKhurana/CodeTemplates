#include "Socket.h"

// No need to mention static function in the definition as already mentioned in the header file.
// If you mention it here too, the compiler will think that you want that particular "static" function's scope to be retricted to this file only.

  /*
  * Returns false on failure to get name from IP , else put the value in the host struct passed by reference.
  */
  bool Socket::getIpFromName(string hostname ,  struct hostent* &host )  
  {
    host = gethostbyname(hostname.c_str());
    if ( host == nullptr)
    {
      cerr << "[#] Host '"<<host<<"' not found "<<endl;
      return false;
    }
    return true;
  }

  /*
  * Returns false on failure to send.
  */
  bool Socket::send_data(int fileDescriptor , string dataToSend)
  {
    if (send(fileDescriptor, dataToSend.c_str(), strlen(dataToSend.c_str()) ,0) == -1)
      return false;
    else
      return true;
  }

  /*
  * Returns the length of string or -1 in case it returns 'EAGAIN ||EWOULDBLOCK' and the data is put in the argument string(pass by reference).
  */
  int Socket::recv_data(int fileDescriptor , string &recvDataHere)
  {
    char Data [BUFF_SIZE]; 
    ssize_t lengthOfData = recv(fileDescriptor, Data, sizeof(Data) , 0);
    Data[lengthOfData] = '\0';
    recvDataHere = string(Data);
    return lengthOfData;
  }                            

  /*
  * Closes the Socket.
  */
  int Socket::close_socket(int fileDescriptor)
  {
    return close(fileDescriptor);
  }
  
  
  /*
  * Returns the IP of the node.
  */
  string Socket::getNameFromFD(int fileDescriptor)
  {

    struct sockaddr_in tempAddr;
    socklen_t tempAddr_len = sizeof(tempAddr);
    // Try to print ip of client if not found then print FD.
    int err = getpeername(fileDescriptor, (struct sockaddr *) &tempAddr, &tempAddr_len);
    if (err == 0)  
      return string(inet_ntoa(tempAddr.sin_addr));
    else  
      return string("");
  }

  /*
  * Constructor simply creates the socket object.
  */
  Socket::Socket()
  {
    this->m_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketFd==RETURN_FAIL)
    {
      std::perror("[#] Error in creating Socket object ");
      cerr << endl;
      exit(RETURN_FAIL);      // Exit if unable to create socket object.
    }
  }

  /*
  * Destructor, to free up the socketfd and close it.
  */
  Socket::~Socket()
  {
    close_socket(m_socketFd);
  }

  /*
  * Returns the file descriptor pointed to by this object.
  */
  int Socket::getFileDescriptor()
  {
    return this->m_socketFd;
  }


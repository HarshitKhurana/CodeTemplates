
#include <netdb.h>            // for hostname resolving
#include <arpa/inet.h>        // for IP connection
#include <errno.h>            // For Errors setting and fetching
#include <fcntl.h>            // For Setting socket as Non-Blocking
#include <sys/socket.h>       // For sockets
#include <netinet/in.h>       // For name resolutions

#define RETURN_FAIL  -1

#pragma once 

/**
* @file Socket.h
* @brief
*   This file contains the 'Socket' class.
* @class Socket
* @brief
*   Class responsible for managin low-level sockets.
* @details
*   This class encapsulates some low-level socket functionalities and provide an easy to use interface for handling the sockets.
*   Some of the functions are static becuase  they doesn't require access to any class member and moreover need to be able to access these seperately.
*   This function will put the response in the host or else will nullptr.
*/
class Socket
{
  int m_socketFd;   /** int m_socketFd : The socket file-descriptor associated with the object of this class */
  
  public:

    /**
    * @brief
    *   Static function to fetch Ip address from domainName/hostName.
    * @details
    *   Fetch Ip from name and put in *host structure , passed via reference to the function.
    * @param 'string hostname' : Hostname to fetch IP of.
    * @param 'struct hostent* &host' : To store the value of resolved IP address into this argument(passed via reference).
    * @return
    *  'bool' : false if fails to resolve, else true.
    */
    static bool   getIpFromName(string hostname ,  struct hostent* &host);  


    /**
    * @brief
    *   Send data to other end of socket.
    * @param 'int fileDescriptor' : Socket on which data is to be sent.
    * @param 'string dataToSend' :  Data which is to be sent.
    * @return
    *   'bool' : false on failure to send, else true.
    */
    static bool   send_data(int fileDescriptor , string dataToSend);        

    /**
    * @brief
    *   Recive data from other end of socket.
    * @details
    *   Recieve the data and store it in the string argument which is passed by reference(MANDATORY).
    * @param 'int fileDescriptor' : Socket on which data is to be sent.
    * @param 'string &recvDataHere' :  Data which is to be recieved (pass by reference).
    * @return
    *   'int' : Returns the size of data. 
    */
    static int    recv_data(int fileDescriptor , string &recvDataHere);     

    /**
    * @brief
    *   Close the Socket.
    * @param 'int fileDescriptor' : Socket which is to be closed.
    * @return
    *   'int' : 0 on success, else -1.
    */
    static int    close_socket(int fileDescriptor);                         
    
    /**
    * @brief
    *   Returns the IP address from File-descriptor.  
    * @param 'int fileDescriptor' : Socket which is to be closed.
    * @return
    *  'string' : empty if fails to resolve, else IP address.
    */
    static string getNameFromFD(int fileDescriptor);                        

    /**
    * @brief
    *   Constructor of Socket Class
    * @details
    *   Creates/opens the low-level socket object.
    */
    Socket();
    
    /**
    * @brief
    *   Destructor of Socket Class
    * @details
    *   Closes the low-level socket object.
    */
    ~Socket();

    /**
    * @brief
    *   Returns the fileDescriptor held by the object.
    * @return
    *   'int' : Socket File-Descriptor.
    */
    int getFileDescriptor();                                                // Returns the socket File descriptor of this object (m_socketFd).
};


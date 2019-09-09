
### Socket Programming

* This is the Socket programming library in C++ for **Linux** based systems.

* It provides the interfaces defined in the respective header files `.h files`, with the implementation included in the `.cpp files` resp.

* It explicitly defines the **SocketClient** and **SocketServer** library, both of which inherits the **Socket** library which contains some of the coon functionalities.

* In order to generate code-documentation.

```bash
$ doxygen doxygen.conf

# It will create the `docs` directory which will contain the documentation(docs/html/index.html).
```

|S.No| FileName                           | Content                                                                                           |
|----| -----------------------------------|:-------------------------------------------------------------------------------------------------:|
|1.  | Socket.h                           | Header file for generic Socket functionalities.                                                   |
|2.  | SocketClient.h                     | Header file for Socket-Client functionalities.                                                    |
|3.  | SocketServer.h                     | Header file for Socket-Server functionalities.                                                    |


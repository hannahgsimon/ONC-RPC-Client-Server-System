# ONC RPC Client Server System

## 🧭 Overview
This project implements an **ONC RPC (Open Network Computing Remote Procedure Call)** client–server system in C. The system defines a remote procedure interface, implements the corresponding client and server logic, and validates correct multi-terminal communication on Linux.

The project demonstrates end-to-end implementation of an RPC-based client–server workflow and explores how RPC interfaces, protocol stubs, and runtime execution interact at the systems level.

## ⚙️ Project Background

ONC RPC enables a client to invoke procedures on a remote server as if they were local function calls. This system consists of:
- A defined RPC interface
- Client and server protocol stubs
- Application-level client and server implementations

The project focuses on implementing and refining a complete RPC-based client–server system, including interface definition, client/server behavior, and runtime validation.

## 🔧 Implementation Details

- Designed and implemented the RPC interface and associated data structures
- Implemented client-side and server-side logic for remote procedure invocation
- Integrated protocol stubs to support RPC communication
- Validated correct request–response behavior across multiple terminals
- Ensured stable client–server execution under Linux

## 📁 Files

- `hello.x` – RPC interface definition
- `hello.h` – generated RPC header
- `hello_clnt.c` – generated client stub
- `hello_svc.c` – generated server stub
- `hello_client.c` – client application logic
- `hello_server.c` – server application logic

---

## 🛠️ Build

On Linux or WSL, regenerate RPC code if needed:

```bash
rpcgen hello.x
```

Compile the server:
```bash
gcc -Wall -O2 hello_server.c hello_svc.c -o server
```

Compile the client:
```bash
gcc -Wall -O2 hello_client.c hello_clnt.c -o client
```

## ▶️ Run
Open two terminals.

Terminal 1 — start the server
```bash
./server
```

Terminal 2 — run the client
```bash
./client <server-hostname>
```
Replace <server-hostname> with localhost if running locally.

## ✅ Validation

- Server successfully registers RPC services
- Client connects and invokes remote procedures
- Responses are correctly returned and displayed
- Communication functions across separate terminals

---

## 📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

---

## 📬 Contact
For questions or feedback, please contact Hannah G. Simon at hgsimon2@gmail.com.

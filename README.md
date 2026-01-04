# ONC RPC Client–Server System Modification

## 🧭 Overview
This project modifies a basic **ONC RPC (Open Network Computing Remote Procedure Call)** client–server system written in C. Starting from code generated via `rpcgen`, unnecessary filler variables were removed, protocol stubs were rebuilt, and correct multi-terminal client–server communication was validated on Linux.

The goal of this project was to understand how RPC interfaces, generated stubs, and client–server execution interact at the systems level.

## ⚙️ Project Background

ONC RPC allows a client to invoke procedures on a remote server as if they were local function calls. The system consists of:
- An RPC interface definition (`.x` file)
- Generated client and server stubs
- Application-level client and server logic

This project focuses on **modifying and rebuilding** an existing RPC setup rather than creating one from scratch.

## 🔧 What Was Modified

- Cleaned up `rpcgen`-generated code by removing unnecessary filler variables
- Rebuilt RPC protocol stubs after interface changes
- Ensured consistency between interface definitions and generated code
- Verified correct request/response behavior across multiple terminals
- Confirmed stable client–server communication under Linux execution

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

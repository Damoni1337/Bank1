# Bank Client Management System (C++)

A modular and menu-driven **Bank Client Management System** written in
C++.\
This program allows you to view, add, update, delete, and search for
clients, all through a clean console interface.\
It uses file handling and a multi-file architecture for better structure
and scalability.

------------------------------------------------------------------------

## ✅ Features

### Main Menu Options

-   **Show Client List** -- Display all saved clients
-   **Add New Client** -- Insert a new client record
-   **Delete Client** -- Remove a client by account number
-   **Update Client Info** -- Edit details of an existing client
-   **Find Client** -- Search for a specific client in the database
-   **Exit** -- Close the program

------------------------------------------------------------------------

## 🧩 Program Flow

The main program follows this loop:

1.  Show the main menu
2.  Read user input
3.  Process the selected option
4.  Return to the main menu
5.  Repeat until the user chooses **Exit**

All operations are handled through external modules such as: -
`FstreamFunction` → File handling (load/save clients)\
- `SetFunctions` → CRUD logic\
- `Screen` → UI display screens\
- `UserInput` → Input validation and reading\
- `ClientFunction` → Client operations\
------------------------------------------------------------------------

## 📁 Project Structure

    /src
    │── main.cpp
    │── FstreamFunction.h / .cpp
    │── SetFunctions.h / .cpp
    │── Screen.h / .cpp
    │── UserInput.h / .cpp
    │── ClientFunction.h / .cpp
    │── clients.txt   (stores client records)

------------------------------------------------------------------------

## 🛠 Technologies Used

-   **C++**
-   **File Management using fstream**
-   **Vectors & Structs**
-   **Modular multi-file architecture**
-   **Console UI with system() functions**

Libraries used: - `<iostream>` - `<fstream>` - `<iomanip>` -
`<string>` - `<vector>` - `<limits>`

------------------------------------------------------------------------

## 🚀 How to Build & Run

### Compile with all source files:

``` bash
g++ main.cpp SetFunctions.cpp FstreamFunction.cpp Screen.cpp UserInput.cpp ClientFunction.cpp -o ClientManager
```

### Run the program:

``` bash
./ClientManager
```

Make sure `Client.txt` exists in the working directory.

------------------------------------------------------------------------

## 📌 Possible Future Improvements

-   Add user authentication (Admin login)
-   Replace text file storage with a database (SQLite / JSON / CSV)
-   Add colored UI menus and better formatting
-   Add export/import of client data
-   Add sorting and filtering functions

------------------------------------------------------------------------

## 👨‍💻 Author

**Damoni**  
🎓 Student of Mohammed Abu-Hadhoud’s C++ Course  
💬 Focused on learning algorithms, clean coding, and interactive console projects  

# 🏦 Bank System — C++ OOP Project

A fully functional console-based Bank Management System built in **C++ using Object-Oriented Programming (OOP)** principles.  
This project simulates a real-world banking system with multiple user roles, file storage, and a modular architecture.

---

## 🚀 Features

- 👤 3 User Roles (Client, Employee, Admin)
- 🔐 Role-Based Access Control
- 💾 File Persistence using `.txt` files
- ✅ Input Validation (name, password, balance, salary)
- ⚙️ Auto Setup (creates `data/` folder + default admin)
- 🧠 Clean and scalable OOP design
- 📂 Multi-file architecture for better organization

---

## 🔑 Default Admin Account

The system automatically initializes a default admin account on first launch to allow access to the system:

- 🆔 ID: `1`
- 🔐 Password: `Admin1234`

Users log in with their **ID** and password.

⚠️ For security reasons, it is strongly recommended to change the default password after first login.

---

## 👥 User Modules

### 🧑‍💼 Client
- Deposit money  
- Withdraw money  
- Transfer funds  
- Check balance  
- Change password  
- View account information  

---

### 👨‍💻 Employee
- Add new clients  
- Search clients  
- Edit client data  
- List all clients  
- Change password  

---

### 🧑‍🏫 Admin
(Admin inherits all Employee features)
- Full client management  
- Full employee management  
- System control access  
- View system data  

---

## 🧱 Project Structure
Bank_System
├── main.cpp
├── Validation.h
├── Person.h
├── Client.h
├── Employee.h
├── Employee.cpp
├── Admin.h
├── Admin.cpp
├── Parser.h
├── FilesHelper.h
├── DataSourceInterface.h
├── FileManager.h
├── ClientManager.h
├── ClientManager.cpp
├── EmployeeManager.h
├── EmployeeManager.cpp
├── AdminManager.h
├── AdminManager.cpp
└── Screens.h

---

## 🧠 OOP Concepts Used

| Concept | Implementation |
|--------|----------------|
| Encapsulation | Private attributes + getters/setters |
| Inheritance | Client → Person, Employee → Person, Admin → Employee |
| Polymorphism | Overridden methods in derived classes |
| Abstraction | DataSourceInterface |
| Static Methods | Manager classes |
| Pointers | Returning user objects after login |
| File Handling | Reading/Writing `.txt` files |

---

## 🎯 Project Purpose

This project was built to practice and demonstrate:

- Object-Oriented Programming in C++
- Multi-role system architecture
- File-based data persistence
- Modular and scalable code structure
- Real-world simulation of banking systems

---

## ⭐ Author

**Mohamed Eyara**  
GitHub: https://github.com/MohamedEyara

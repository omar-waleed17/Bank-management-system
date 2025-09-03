# 🏦 Bank Management System – Programming 1 Project

This project was developed as part of the **Programming 1** course in college.  
It is a **C-based Bank Management System** designed to simulate essential banking operations with proper **data validation** and **file handling**.  

---

## 📌 Features

### 🔐 Authentication
- **Login system** with validation.  
- Prevents unauthorized access.  

### 📂 File Handling
- **Load and read accounts** from a file on program start.  
- **Save all changes** back to file on exit.  

### 🔎 Account Management
- **Search by Account Number** → check if an account exists.  
- **Advanced Search** → enter a name and retrieve all accounts with matching names.  
- **Add Account** → create a new account with validation (email, phone, account number).  
- **Delete Account** → only if balance is ≥ 0.  
- **Modify Account** → update user details safely.  

### 💰 Banking Transactions
- **Withdraw** → within allowed range, prevents overdraft.  
- **Deposit** → maximum deposit limit of **10,000**.  
- **Transfer Money** → between accounts with balance checks.  
- **Reports** → view the **last 5 transactions** for any account.  

### 📊 Data Handling
- **Sorting Options** → print accounts sorted by:
  - Name  
  - Balance  
  - Date Opened  
- **Validation** for:
  - Email format  
  - Account number format  
  - Phone number format  

### 📋 Menu System
- Interactive **menu-based interface** for all operations.  
- User-friendly navigation.  

---

## 🛠️ Tech Stack & Implementation
- **Language:** C  
- **Concepts Used:**  
  - File handling  
  - Validation (email, phone, account number, transaction limits)  
  - Sorting and searching  
  - **Header files** to organize code and improve readability  
  - Structures, arrays, and functions for modularity  

---

## 🚀 How to Run
1. Download or clone this repository.  
2. Navigate to the project folder.  
3. Run the program by opening:  

   **`final.exe`**  

That’s it — no compilation required. 🎉  

---

## 📖 Notes
- Ensure the account data file exists before starting the program.  
- All inputs are validated (email, phone number, account number, transaction limits).  
- Data is automatically saved on exit.  

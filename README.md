# 🧠 Task Manager in C

A simple **command-line Task Manager** built in C using low-level Unix/Linux system calls. This project allows users to monitor and manage system processes directly from the terminal.

---

## 🚀 Features

### 📋 Show Running Processes (`showProcesses`)
Lists all active process IDs by reading from the `/proc` directory.

### ❌ Kill a Process (`killProcess`)
Terminate a process using its PID with the `kill()` system call.

### 🌳 Process Tree (`pctree`)
Displays the parent-child hierarchy of processes using the `pstree` command.

### ⚙️ Change Priority (`changePriority`)
Modify the priority (nice value) of a process using `setpriority()`.

---

## 🛠️ Tech Stack

- **Language:** C  
- **Concepts Used:**  
  - Process Management  
  - System Calls  
  - Directory Handling  

- **System Calls / Libraries:**  
  - `fork()`  
  - `execlp()`  
  - `wait()`  
  - `kill()`  
  - `setpriority()`  
  - `opendir()` / `readdir()`  

---

## ▶️ How to Run

```bash
gcc task_manager.c -o task_manager
./task_manager
```
---

## ▶️ How It Works

The program runs in a loop providing a menu-driven interface:

1. Show all running processes  
2. Kill a process using PID  
3. Display process parent-child tree  
4. Change process priority  
5. Exit the program  

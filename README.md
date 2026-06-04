# Course Management System (CMS)

A console-based **Course Management System** written in C++. Allows an authorized user to register and search student and teacher records, with data stored persistently in text files.

---

## Features

- Password-protected login (with retry on wrong password)
- **Student Section**
  - Register new students (name, registration number, class)
  - Search and display student records by first name
- **Teacher Section**
  - Register new teachers (name, qualification, experience, subject, lectures/week, pay, phone)
  - Search and display teacher records by first name
- Data is saved to `student.txt` and `teacher.txt` and persists across sessions
- Cross-platform — works on Windows and Linux

---

## How to Compile & Run

### On Windows (MinGW / g++)
```bash
g++ cms.cpp -o cms.exe
cms.exe
```

### On Linux / Mac
```bash
g++ cms.cpp -o cms
./cms
```

### Online Compiler
Paste `cms.cpp` into any online C++ compiler (e.g. [onlinegdb.com](https://www.onlinegdb.com), [replit.com](https://replit.com)). It will compile and run without any issues.

---

## Default Login Password

```
123
```

---

## Project Structure

```
cms.cpp          - Main source code (cross-platform)
student.txt      - Auto-generated: stores student records
teacher.txt      - Auto-generated: stores teacher records
CMS_Report.docx  - Project report with full source code
README.md        - This file
```

---

## Notes

- The original version used Windows-only headers (`conio.h`, `windows.h`). This version removes those dependencies and uses standard C++ only (`<iostream>`, `<fstream>`, `<string>`, `<limits>`).
- Search is case-sensitive and matches by first name only.
- Records are appended to files — no delete or update functionality in this version.

---

## Built With

- C++ (Standard: C++11 or later)
- File I/O via `fstream`
- No external libraries or frameworks

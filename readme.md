# File System Simulator with N-ary Tree and AVL Tree

This project implements a file system simulator using an N-ary tree to represent the directory structure and an AVL tree to index files for efficient searching. The implementation supports various operations such as creating directories, adding/deleting files and folders, merging folders, and traversing the file system and AVL tree in different orders.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Classes and Structures](#classes-and-structures)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Limitations](#limitations)
- [How to Run](#how-to-run)
- [Test Cases](#test-cases)
- [Future Improvements](#future-improvements)

## Overview

The code simulates a file system where:
- An **N-ary tree** represents the hierarchical structure of directories and files.
- An **AVL tree** indexes files based on their first letter (converted to uppercase) for quick lookup.
- The system supports operations like file/folder creation, deletion, merging, and traversal, along with file and folder size calculations.

The implementation is templated to allow flexibility in the data type used for file and folder names (typically `string`).

## Features

### N-ary Tree Operations
- Create a directory tree from a given root path.
- Add files and folders to specific paths.
- Delete files and folders.
- Merge two folders by moving contents from one to another.
- Display the tree structure (not fully implemented).
- Traverse the N-ary tree in pre-order, in-order, post-order, and level-order, returning a comma-separated string of node names.
- Calculate the size of files and folders.

### AVL Tree Operations
- Insert files into the AVL tree based on their first letter.
- Search for files by name, returning their full paths.
- Delete files from the AVL tree.
- Traverse the AVL tree in pre-order, in-order, post-order, and level-order (only level-order implemented).
- Maintain balance using left-left (LL) and right-left (RL) rotations.

### File System Operations
- Add files with a `.txt` extension to the AVL tree for indexing.
- Search for files and return their paths.
- Calculate file sizes using file streams.
- Calculate folder sizes by summing the sizes of all contained files.

## Classes and Structures

### 1. `Node<T>`
- Represents a node in the N-ary tree.
- Contains a vector of child pointers, a parent pointer, and data (file/folder name).
- Used to build the hierarchical file system structure.

### 2. `Queue<T>`
- A templated queue implemented using a linked list.
- Used for level-order traversal of both N-ary and AVL trees.

### 3. `AvlNode<T>`
- Represents a node in the AVL tree.
- Stores a character (first letter of a file name), a vector of N-ary tree nodes (files starting with that letter), and left/right child pointers.

### 4. `AVLTree<T>`
- Manages the AVL tree for file indexing.
- Provides methods for insertion, deletion, searching, balancing, and traversal.

### 5. `NaryTree<T>`
- Manages the N-ary tree representing the file system.
- Integrates with the AVL tree for file indexing.
- Supports file/folder operations and tree traversals.

## Usage

The code is designed to be used with a testing framework like Google Test (GTest) to verify functionality. Below are some key operations:

### Create a Tree
```cpp
NaryTree<string> tree;
tree.CreateTree("./root_directory");
```
This initializes the N-ary tree by reading the directory structure from the given path.

### Add a File
```cpp
tree.addFile("./root_directory/subfolder", "example.txt");
```
Adds a file named `example.txt` to the specified path and indexes it in the AVL tree.

### Delete a File
```cpp
tree.deleteFile("example.txt");
```
Removes the file from the N-ary tree and its entry from the AVL tree.

### Merge Folders
```cpp
tree.MergeFolder("./root_directory/folder1", "./root_directory/folder2");
```
Moves all contents from `folder2` to `folder1` and updates the AVL tree.

### Search for a File
```cpp
string* paths = tree.getAVL().searchFile("example.txt");
```
Returns an array of paths where `example.txt` is found, or `NULL` if not found.

### Traverse the Tree
```cpp
string levelOrder = tree.levelOrderTraversal();
string avlLevelOrder = tree.getAVL().levelOrderTraversal();
```
Returns a comma-separated string of node names in the specified traversal order.

### Calculate Sizes
```cpp
int fileSize = tree.sizeFile("example.txt");
int folderSize = tree.sizeFolder("./root_directory/subfolder");
```

## Dependencies

- C++ Standard Library (`<iostream>`, `<fstream>`, `<vector>`, `<sstream>`)
- POSIX directory handling (`<dirent.h>`) for reading directory contents
- Google Test (GTest) for unit testing (not included in the code but referenced for test cases)

Ensure a POSIX-compliant environment (e.g., Linux, macOS) for directory operations. Windows may require modifications or a different library (e.g., `<filesystem>`).

## Limitations

### Incomplete Implementations
- `preorderTraversal`, `postorderTraversal`, and `inorderTraversal` for the AVL tree are not implemented.
- `DisplayTreeForm` for the N-ary tree is not implemented.
- `AddFolder` is not fully implemented.

### Error Handling
- Limited error checking for invalid paths or file operations.
- Assumes valid input for paths and file names.

### Memory Management
- Manual memory management with `new` and `delete` may lead to memory leaks if not handled carefully.
- No destructor to clean up the N-ary or AVL trees.

### Assumptions
- File names with `.txt` extension are indexed in the AVL tree.
- Paths start with `./` and use `/` as the separator.
- AVL tree keys are uppercase first letters of file names.

### Platform Dependency
- Directory operations rely on `<dirent.h>`, which is POSIX-specific.

## How to Run

### 1. Compile the Code
Ensure you have a C++ compiler (e.g., `g++`) and a POSIX-compliant environment.
```bash
g++ -std=c++11 main.cpp -o filesystem_simulator
```
Replace `main.cpp` with a file containing the main function and test cases.

### 2. Run Tests
Use Google Test to run predefined test cases. Link the code with GTest libraries:
```bash
g++ -std=c++11 main.cpp -lgtest -lgtest_main -pthread -o test
./test
```

### 3. Directory Setup
Create a directory structure (e.g., `./root_directory`) with files and folders for testing. Ensure the program has read/write permissions.

## Test Cases

Refer to the GTest framework for detailed test cases. Examples of expected outputs:

### Level-Order Traversal (N-ary Tree)
- **Input**: Directory with `logs`, `powerLogs`, `timeUsageLog`, `voltageLogs`, `systemlog.txt`
- **Output**: `"logs,powerLogs,timeUsageLog,voltageLogs,systemlog.txt"`

### AVL Tree Level-Order Traversal
- **Input**: Files `systemlog.txt`, `sample.txt`
- **Output**: `"S"` (first letters of files in level-order)

### File Search
- **Input**: `searchFile("systemlog.txt")`
- **Output**: Array of paths, e.g., `[./logs/systemlog.txt]`

### File/Folder Deletion
- **Input**: `deleteFile("systemlog.txt")`
- **Output**: `true` if deleted successfully

### Folder Merge
- **Input**: `MergeFolder("./folder1", "./folder2")`
- **Output**: `true` if merged successfully

## Future Improvements

- Implement missing traversal methods (`preorderTraversal`, `postorderTraversal`, `inorderTraversal`) for the AVL tree.
- Complete the `AddFolder` and `DisplayTreeForm` functions.
- Add robust error handling for invalid paths, non-existent files, and permission issues.
- Implement a destructor to clean up memory for the N-ary and AVL trees.
- Support cross-platform directory operations using `<filesystem>` for Windows compatibility.
- Optimize memory usage and avoid redundant string operations.
- Add support for file extensions other than `.txt` in the AVL tree.

## License

This project is for educational purposes and does not include a specific license. Modify and use it as needed for learning or assignments.

---

This README provides an overview of the code, its functionality, and guidelines for usage. For further details, refer to the source code comments and test cases.
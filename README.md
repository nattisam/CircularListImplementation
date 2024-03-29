# Circular List Implementation

This repository contains an implementation of a Circular List data structure in C++, along with a demonstration of its usage.

## Overview

A Circular List is a linked list where the last node points back to the first node, creating a circular structure. This implementation provides functionalities to insert, delete, search, and manipulate elements in the list efficiently.

## Features

- Insertion and deletion operations
- Circular traversal and manipulation
- Search operations
- Memory management

## Usage

1. **Clone the Repository:**
   - Open your terminal or command prompt.
   - Clone the repository to your local machine:
     ```
     git clone https://github.com/nattisam/CircularListImplementation.git
     ```
   - Navigate to the cloned directory:
     ```
     cd CircularListImplementation
     ```

2. **Build the Project:**
   - Ensure Make is installed on your system.
   - Run the Makefile to build the project:
     ```
     make
     ```

3. **Run the Program:**
   - Execute the compiled program:
     ```
     ./cList > cListOutput.txt
     ```
   - This command generates the output in a text file named `cListOutput.txt`.

4. **View the Output:**
   - Open `cListOutput.txt` to view the program output.

5. **Clean Up:**
   - To remove compiled files, run:
     ```
     make clean
     ```

## Implementation and Usage Across Different Operating Systems

The implementation and usage of this code may vary slightly depending on your operating system.

- **Windows Users:** No modifications are typically needed. Follow the provided instructions to compile and run the code.

- **Mac or Linux Users:** In the Makefile, you may need to modify the `clean` target to ensure proper deletion of object files and executables. Replace `rm -f *.o cList` with `rm -f *.o cList cList.exe`. Additionally, ensure you have the necessary dependencies installed to compile the code, such as `make` and `g++`. Follow the provided instructions to clone the repository, compile the code, and run the executable.

## Contributing

Contributions are welcome! If you have any suggestions, improvements, or bug fixes, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

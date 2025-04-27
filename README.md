#*Matrix Operations with C++ (SquareMat)*

##***Description***
This project includes a class SquareMat that represents a square matrix 
and supports various matrix operations such as addition, subtraction, multiplication, division, negation, and matrix exponentiation. It includes the implementation of operators such as +, -, *, /, %, and more.

##***⚙️Project Structure***

    SquareMat.cpp: Implementation of the SquareMat class with all the matrix operations.

    SquareMat.h: Header file for the SquareMat class.

    main.cpp: Main program to demonstrate the use of the SquareMat class.

    Test.cpp: Contains tests for the SquareMat class to check the functionality.

    Makefile: Used to build and run the program, including the ability to run tests and use Valgrind.

##**🚀Running the Code**
To run the code and see a demo of how all operators work with square matrices,
simply compile and run the main.cpp file with:
--make Main

To run tests for the project:
--make test

To check for memory leaks or issues, you can use the Valgrind tool via the command:
--make valgrind

##***Notes:***

--All operators are implemented under the matrix namespace, 
specifically the SquareMat class.
--Standard Template Library (STL) containers are intentionally not used.
--The project is designed to run on Linux environments (Ubuntu).
--Memory management is handled manually, and memory leaks should be checked using Valgrind.
--Example use cases and operator executions are provided in the main.cpp file.



***Author***
--Eden Hassin
--Edenhassin@gmail.com
--Project completed: April-May 2025



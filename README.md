Get Next Line Project
The Get Next Line project is a fundamental C programming challenge designed to build proficiency in file input/output operations, memory management, and efficient string handling. This implementation adheres to the requirements of the 42 School curriculum and focuses on reading a file line by line.

📜 Project Overview
The goal of this project is to create a function get_next_line that reads a line from a file descriptor and returns it. The function must:

Handle multiple file descriptors simultaneously.
Be memory efficient, with no memory leaks.
Return each line, including the newline character \n if it exists.
Work seamlessly with files, standard input (stdin), and other file descriptors.
Function Prototype
c
Copy
Edit
char *get_next_line(int fd);
Key Features
Dynamic Buffer Management:

The function reads data using a user-defined BUFFER_SIZE to balance memory usage and performance.
Support for Multiple File Descriptors:

Static storage is used to handle multiple file descriptors simultaneously, enabling concurrent reading from multiple files or inputs.
Error Handling:

The function handles errors such as invalid file descriptors and memory allocation failures gracefully.
Custom Utility Functions:

Includes helper functions such as ft_strjoin, ft_strdup, and ft_strchr to manage strings efficiently.

🛠️ Implementation Details
File Structure
get_next_line.c: Main function implementation to read lines from a file descriptor.
get_next_line_bonus.c: Bonus implementation supporting multiple file descriptors.
get_next_line_utils.c: Helper functions for string manipulation and memory management.
get_next_line.h: Header file with function prototypes and necessary includes.
Function Behavior
Reads Data:
Reads from the file descriptor into a buffer of size BUFFER_SIZE.
Stores Data:
Dynamically allocates and manages memory to store the data until a full line is retrieved.
Returns Lines:
Returns the next line on each call and handles incomplete lines gracefully.
🏆 Bonus Features
Multiple File Descriptors: Simultaneously handle input from multiple file descriptors.
Robust Testing: Extensive edge case handling (e.g., empty files, extremely large files, and small buffer sizes).
🌟 Example
Input File: example.txt
kotlin
Copy
Edit
Hello, World!
Welcome to the 42 curriculum.
Get Next Line is fun!
Program Output:
c
Copy
Edit
int fd = open("example.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
Output:

kotlin
Copy
Edit
Hello, World!
Welcome to the 42 curriculum.
Get Next Line is fun!
🧩 Requirements
Language: C
Compiler: GCC
Standards: C99 or later
📝 License
This project is open source and available under the MIT License.

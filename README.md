# Custom Command-Line Device Manager - "Chacha" Shell

The "Chacha" Shell is a custom-built command-line interface designed to emulate core file and directory management functionalities within a simplified and intuitive shell environment. Implemented in C++, this project serves as a streamlined, cross-platform shell that allows users to manage their file system with ease. Whether creating directories, reading or writing files, moving between folders, or listing contents, "Chacha" Shell offers users a personalized, efficient experience tailored to common file operations. The design emphasizes simplicity, versatility, and user-friendly interaction, making it a powerful tool for anyone who regularly works with the command line.

# Key Features

  # Directory Navigation and Management:
  
    1) Move Between Directories: The mv_to command lets users change their current working directory seamlessly. Users can specify any absolute or 
       relative path, and the shell navigates to it, creating an interactive file management flow.
    2) Create Directories: The dir command enables users to create new directories at any specified path. With intelligent handling of input paths 
       (e.g., removing unnecessary quotes), users can create folders in both their current and specified directories without hassle.
    3) Delete Directories: A delete command allows users to delete directories or files, making it easy to clean up the file system. Robust error 
       handling ensures the command works safely without compromising other directories.
  
  # File Management:
  
    1) File Reading: With add_file, users can read any file, loading its contents into a buffer for easy manipulation or storage. This is ideal for 
       viewing or duplicating files.
    2) Save Files: The save_file function enables saving a buffer (or text string) as a file to any specified directory. This feature is designed to 
       streamline workflows for creating copies of data or transferring files between directories.
    3) Delete Files: Users can easily delete files with the delete command. This deletion feature not only removes specified files but also verifies 
       deletion success to avoid unexpected results.

  # List Directory Contents:
  
    The lst command provides a complete listing of files and folders within a given directory, including recursive navigation through 
    subdirectories. 
    This command is ideal for quick inventory checks or searching for specific files within nested structures.
  
  # Error Handling and Feedback:
  
    "Chacha" Shell is built with error handling and meaningful feedback for the user. For example, if a directory already exists, the shell notifies 
     the user instead of overwriting it, and if a file doesn’t exist, a clear error message is provided.
    
# Code Highlights
  
  # Path Handling:
   
     The remove_quotes helper function intelligently strips any leading or trailing quotes in user input paths, preventing common issues in path 
     management and simplifying user input.
     C++ Standard Library Use:
    
    Built on top of the C++ filesystem library, "Chacha" Shell leverages modern C++ for efficient, cross-platform file handling. By using objects 
    like filesystem::path, path management is streamlined, making it adaptable across different operating systems.
  
 # Interactive Shell Environment:
  
    The processCommand function parses and executes commands within an infinite loop, creating a real-time command-line environment. Commands are 
    checked for validity, and users are prompted with helpful usage information if they enter incorrect syntax.

# Example Usage

    Starting "Chacha" Shell:
    
    On startup, the user is greeted with the :) prompt, inviting them to interact with the shell. This welcoming prompt signifies that commands are 
    ready to be received.
    
    Commands:
    
    chacha mv_to "/home/user/Documents": Moves to the specified directory.
    chacha dir "Projects": Creates a new folder called "Projects" in the current directory.
    chacha add_file "notes.txt" "backup_notes.txt": Reads "notes.txt" and saves it as "backup_notes.txt" in the current directory.
    chacha delete "old_file.txt": Deletes "old_file.txt" from the current directory.
    chacha lst: Lists all files and folders recursively in the current directory.
    Potential Expansions
    Batch Command Processing: Adding support for multiple commands in a single line.
    Environment Variables: Custom shell variables for quickly navigating commonly used directories.
    Enhanced File Manipulation: Adding commands for file renaming, copying, and symbolic links.
    Command Aliases: Enabling alias creation for frequently used commands, making usage even faster.
# Conclusion
    The "Chacha" Shell is more than a basic command-line utility. It is a lightweight, intuitive file management tool designed to provide users 
    with seamless control over their directories and files. With error handling, intelligent path management, and an interactive environment, 
    "Chacha" Shell is an excellent project for command-line enthusiasts looking to streamline their workflow and manage files with minimal overhead.

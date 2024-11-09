#include "/home/chiranjeet/custom_shell/header_files/cmd.hpp"
#include "/home/chiranjeet/custom_shell/header_files/shell.hpp"

#include <iostream>
using namespace std;


#include <iostream>

int main() {
    shell myShell;
    cout << "" <<endl;
    cout << "=============================================================" <<endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<endl;
    cout << "Welcome to the custom shell! Type 'chacha' followed by commands to interact." <<endl;
    cout << "Available commands:\n"
    << "  chacha dir <directory_name>       - Create a new directory\n"
    << "  chacha mv_to <directory_path>     - Move to a specific directory\n"
    << "  chacha add_file <file_path> <file_name> - Add a file to the current directory\n"
    << "  chacha delete <file_name>         - Delete a file from the current directory\n"
    << "  chacha rmdir <directory_name>     - Delete a directory\n"
    << "  chacha lst                        - List items in the current directory\n"
    << "  exit                              - Exit the shell\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<endl;
    cout << "============================================================="<<endl;
    cout << "" <<endl;
    myShell.start();

    cout << "Exiting the shell. Goodbye!" << endl;
    return 0;
}


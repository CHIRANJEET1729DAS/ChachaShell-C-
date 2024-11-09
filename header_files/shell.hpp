#ifndef SHELL_COMMANDS_HPP
#define SHELL_COMMANDS_HPP

#include "/home/chiranjeet/custom_shell/header_files/shell.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class shell {
private:
  device shell_device;
  string current_path;

public:

  void start() {
    string command;
    while (true) {
      cout << ":) ";
      getline(cin, command);
      if (command == "exit") break;
      processCommand(command);
    }
  }

  void processCommand(const string& command) {
    string cmd, arg_1, arg_2;
    istringstream iss(command);

    iss >> cmd;
    if (cmd != "chacha") {
      cout << "Unknown command: " << command << endl;
      return;
    }
    iss >> cmd >> arg_1 >> arg_2;

    if (cmd == "dir") {
      if (arg_1.empty()) {
        cout << "Usage : dir <directory_name>" << endl;
        return;
      }
      try {
        shell_device.create_directory(current_path, arg_1);
        cout << current_path << "/" << arg_1 << endl;
      }
      catch (const runtime_error& e) {
        cerr << e.what() << endl;
      }
    }
    else if (cmd == "mv_to") {
      if (arg_1.empty()) {
        cout << "Usage : mv_to <directory_path>" << endl;
        return;
      }
      try {
        current_path = shell_device.move_to(arg_1);
      } catch (const runtime_error& e) {
        cerr << e.what() << endl;
      }
    }
    else if (cmd == "rmdir") {
      if (arg_1.empty()) {
        cout << "Usage : rmdir <directory_name>" << endl;
        return;
      }
      try {
        if (shell_device.delete_directory(current_path + "/" + arg_1)) {
          cout << "Directory deleted: " << arg_1 << endl;
        } else {
          cout << "Failed to delete directory: " << arg_1 << endl;
        }
      }
      catch (const runtime_error& e) {
        cerr << e.what() << endl;
      }
    }
    else if (cmd == "exit_dirs") {
      current_path.clear();
    }
    else if (cmd == "add_file") {
      if (arg_1.empty() || arg_2.empty()) {
        cout << "Usage : add_file <file_path> <file_name>" << endl;
        return;
      }
      try {
        string buffer_string = shell_device.read_file(arg_1);
        shell_device.save_file(buffer_string, current_path, arg_2);
      }
      catch (const runtime_error& e) {
        cerr << e.what() << endl;
      }
    }
    else if (cmd == "delete") {
      if (arg_1.empty()) {
        cout << "Usage : delete <file_name>" << endl;
        return;
      }
      try {
        shell_device.delete_off(current_path + "/" + arg_1);
      } catch (const runtime_error& e) {
        cerr << e.what() << endl;
      }
    }
    else if (cmd == "lst") {
      try {
        shell_device.list_items(current_path);
      } catch (const runtime_error& e) {
        cerr << e.what() << endl;
      }
    }
    else {
      cout << "Unknown command: " << cmd << endl;
    }
  }
};

#endif

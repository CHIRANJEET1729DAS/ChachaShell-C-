#ifndef DEVICE_REGULATOR
#define DEVICE_REGULATOR

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;

class device {
public:
  string move_to(const string& directory_path) {
    return directory_path;
  }

  string read_file(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
      throw runtime_error("File doesn't exist");
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
  }

  void save_file(const string& buffer, const string& repo_path, const string& file_name) {
    ofstream file(repo_path + "/" + file_name, ios::binary);
    if (file) {
      file.write(buffer.c_str(), buffer.size());
      file.close();
    }
  }

  bool delete_off(const string& file_path) {
    return filesystem::remove(file_path);
  }

  bool delete_directory(const string& directory_path) {
    return filesystem::remove_all(directory_path) > 0;
  }

  void create_directory(const string& file_system_path, const string& directory_name) {
    filesystem::path sandbox(file_system_path);
    filesystem::path full_path = sandbox / directory_name;

    if (!filesystem::create_directories(full_path)) {
      cerr << "Directory already exists or couldn't be created: " << full_path << endl;
    } else {
      cout << "Directory created at: " << full_path << endl;
    }
  }


  void list_items(const string& file_system_path) {
    filesystem::path sandbox{file_system_path};
    for (const auto& dir_entry : filesystem::recursive_directory_iterator{sandbox}) {
      cout << dir_entry.path() << endl;
    }
  }
};

#endif

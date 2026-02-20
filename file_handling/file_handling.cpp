#include <fstream> // used for creating streams to file (stream is an abstraction that represents data flow to and from the file)
#include <iostream>

using namespace std;

int main() {
  {
    fstream file(
        "venom.txt",
        ios::out); // 1. str is name given to the stream, modes can be ios::out,
                   // ios::binary, ios::ate, ios::app, ios::trunc 2. if we open
                   // in both read and write mode -> ios::in | ios::out then it
                   // won't create the file if it doesn't exists 3. ios::out by
                   // default include ios::trun which means if file exists erase
                   // all existing data, if we want to preserve previous state
                   // we must do ios::app

    // ifstream name("name.txt");
    // ofstream ...
    file << "We are VENOM!";
    file.close();
  }

  {
    fstream file(
        "venom.txt",
        ios::in); // takes input only until the first whitespace ouccers
    string s;
    file >> s;
    cout << s << endl;

    file.seekg(0); // to move the cursor
    getline(file, s);
    cout << s << endl;
    file.close(); // closes the stream and the resources being used
  }

  return 0;
}

#include "FileSystem.hpp"
#include <iostream>
#include <string>
#include <sstream> // Required for stringstream

// By adding this line, we tell the compiler that for any function or type
// like 'string', 'cout', etc., it should assume we mean the one
// from the standard (std) library.
using namespace std;

/**
 * @brief Prints instructions for the user.
 */
void printHelp() {
    cout << "--- Time-Travelling File System Commands ---" << endl;
    cout << "CREATE <filename>" << endl;
    cout << "READ <filename>" << endl;
    cout << "INSERT <filename> <content>" << endl;
    cout << "UPDATE <filename> <content>" << endl;
    cout << "SNAPSHOT <filename> <message>" << endl;
    cout << "ROLLBACK <filename> [versionID]" << endl;
    cout << "HISTORY <filename>" << endl;
    cout << "RECENT_FILES [count]" << endl;
    cout << "BIGGEST_TREES [count]" << endl;
    cout << "exit" << endl;
    cout << "-------------------------------------------" << endl;
}

int main() {
    // Create an instance of our file system.
    // This object will exist for the entire duration of the program.
    FileSystem fs;
    string line;

    printHelp();

    // This is the main command loop of the program.
    // It will continue to run until the user types "exit".
    while (true) {
        cout << "> "; // Prompt for user input
        getline(cin, line); // Read the entire line of input from the user.

        // Use a stringstream to easily parse the line.
        // A stringstream treats a string like an input stream (like cin).
        stringstream ss(line);
        string command;
        ss >> command; // The first word in the line is the command.

        if (command == "CREATE") {
            string filename;
            ss >> filename; // The second word is the filename.
            if (filename.empty()) {
                cout << "Error: CREATE requires a filename." << endl;
            } else {
                fs.createFile(filename);
            }
        } else if (command == "READ") {
            string filename;
            ss >> filename; // The second word is the filename.
            if (filename.empty()) {
                cout << "Error: READ requires a filename." << endl;
            } else {
                fs.readFile(filename);
            }
        } else if (command == "INSERT" || command == "UPDATE" || command == "SNAPSHOT") {
            string filename;
            ss >> filename;

            // CRITICAL FIX: Use getline to read the rest of the line as content/message.
            // This correctly handles inputs with spaces.
            string rest_of_line;
            //Source: The stringstream object ss. NOT cin.
            //Action: This is the key part. This getline reads from the stringstream, starting where the cursor is, and continues until the end of the stream.
            getline(ss, rest_of_line);
            if (!rest_of_line.empty() && rest_of_line[0] == ' ') {
                rest_of_line = rest_of_line.substr(1); // Remove leading space
            }

            if (filename.empty()) {
                cout << "Error: Command requires a filename." << endl;
            } else if (rest_of_line.empty()) {
                cout << "Error: Command requires content or a message." << endl;
            } else {
                if (command == "INSERT") fs.insertContent(filename, rest_of_line);
                if (command == "UPDATE") fs.updateContent(filename, rest_of_line);
                if (command == "SNAPSHOT") fs.snapshot(filename, rest_of_line);
            }
        }else if(command =="ROLLBACK"){
            string filename,id;
            ss >> filename>>id;
            if(filename.empty()){
                cout << "Error: ROLLBACK requires a filename." << endl;
            }else{
                fs.rollBack(filename,id);
            }
        }else if(command=="HISTORY"){
            string filename;
            ss >> filename;
            if(filename.empty()){
                cout << "Error: HISTORY requires a filename." << endl;
            }
            else{
                fs.history(filename);
            }

        }else if (command == "RECENT_FILES" || command == "BIGGEST_TREES") {
           
            string count_str;
            ss >> count_str;

            if (count_str.empty()) {
                cout << "Error: Command requires a number." << endl;
                continue; // Skip to the next command.
            }
            // --- SIMPLE AND ROBUST VALIDATION ---
            bool is_valid_number = true;
            for (char c : count_str) {
                if (!isdigit(c)) {
                    is_valid_number = false;
                    break; // Stop checking as soon as we find a non-digit
                }
            }

            if (is_valid_number) {
                int count = stoi(count_str);
                if (command == "RECENT_FILES") fs.recentFiles(count);
                if (command == "BIGGEST_TREES") fs.biggestTrees(count);
            } else {
                cout << "Error: Invalid count '" << count_str << "'. Please provide a whole number." << endl;
            }
        
        }else if (command == "exit") {
            cout << "Exiting file system." << endl;
            break; // Exit the while loop.
        } else if (command.empty()) {
            // User just pressed enter, do nothing.
        }
        else {
            cout << "Error: Unknown command '" << command << "'" << endl;
        }
    }

    // When main() ends, the 'fs' object goes out of scope.
    // This automatically calls the ~FileSystem() destructor, which
    // is responsible for cleaning up all allocated memory.
    return 0;
}

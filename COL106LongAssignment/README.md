Time-Travelling File System
---------------
Overview
This project is an in-memory version control system inspired by Git, implemented in C++. It manages files with version histories represented as trees. The core of the system is built on custom implementations of HashMaps, Max-Heaps, and Trees.

---------------
How to Compile and Run:

Prerequisites
A C++ compiler that supports C++11 or later (like g++).

Compilation
A shell script compile.sh is provided to compile the source code.

1.Open a terminal or command prompt in the project's root directory.

2.Make the script executable:

(Bash)

chmod +x compile.sh
3.Run the script:

(Bash)

./compile.sh
This will compile all .cpp files and create an executable named main.

Execution
To run the program, execute the following command in the terminal:

(Bash)

./main
You will be greeted with a > prompt, where you can enter commands.

---------------
Command Reference
The following commands are supported:

CREATE <filename>: Creates a new file with an initial empty version.


READ <filename>: Displays the content of the file's current active version.


INSERT <filename> <content>: Appends content to the active version. Creates a new version if the current one is a snapshot.


UPDATE <filename> <content>: Overwrites the content of the active version. Creates a new version if the current one is a snapshot.


SNAPSHOT <filename> <message>: Makes the active version's content immutable and attaches a descriptive message.


ROLLBACK <filename> [versionID]: Changes the active version.

If versionID is provided, it switches to that specific version.

If no versionID is provided, it reverts to the parent of the current version.


HISTORY <filename>: Lists all snapshotted versions on the path from the active version to the root, sorted chronologically.


RECENT_FILES <count>: Lists the <count> most recently modified files.


BIGGEST_TREES <count>: Lists the <count> files with the highest number of total versions.


exit: Shuts down the program and cleans up all allocated memory.

---------------

Command Output Examples
Below are examples of the expected output format for successful commands.

CREATE

> CREATE my_notes.txt
File 'my_notes.txt' created successfully.

INSERT / UPDATE

> INSERT my_notes.txt This is a test.
Inserted content.
> UPDATE my_notes.txt New content.
Content updated for 'my_notes.txt'.

READ

> READ my_notes.txt
New content.

SNAPSHOT

> SNAPSHOT my_notes.txt Version 1 finished
Snapshot created for 'my_notes.txt' with version ID 0.

HISTORY

> HISTORY my_notes.txt
--- History for 'my_notes.txt' ---
Version ID: 0
  Timestamp: Sun Sep 07 17:30:00 2025
  Message: Version 1 finished
-----------------------------------
Version ID: 1
  Timestamp: Sun Sep 07 17:31:15 2025
  Message: Added more details
-----------------------------------

RECENT_FILES

> RECENT_FILES 2
--- 2 Most Recently Modified Files ---
1. my_notes.txt (Modified: Sun Sep 07 17:35:10 2025)
2. another_file.log (Modified: Sun Sep 07 17:34:05 2025)

BIGGEST_TREES

> BIGGEST_TREES 2
--- 2 Files with Most Versions ---
1. my_notes.txt (15 versions)
2. code.cpp (8 versions)

---------------

Error Handling:

The system handles incorrect input as follows, with the following exact messages:

Unknown Commands: "Error: Unknown command '<command>'."

Missing Arguments:

"Error: CREATE requires a filename."

"Error: READ requires a filename."

"Error: Command requires a filename." (for INSERT, UPDATE, SNAPSHOT)

"Error: Command requires content or a message." (for INSERT, UPDATE, SNAPSHOT)

"Error: ROLLBACK requires a filename."

"Error: HISTORY requires a filename."

"Error: Command requires a number." (for RECENT_FILES, BIGGEST_TREES)

"File Not Found: NO SUCH FILE NAMED '<filename>'."

Invalid Analytics Count: "Error: Invalid count '<count_str>'. Please provide a whole number.."

Logical Errors:

Attempting to SNAPSHOT an already snapshotted version: "Error: Version <id> is already a snapshot."

Attempting to ROLLBACK to a non-existent version ID: "Error: Invalid version ID. Please provide an ID between 0 and <total_versions - 1>."

Attempting to ROLLBACK from the root to a parent: "Error: Cannot roll back. Active version is the root and has no parent."

---------------

Internal API Error Handling

Heap Operations: The custom MyMaxHeap data structure handles the case of attempting to pop() or top() from an empty heap. Instead of throwing an exception (which would terminate the program), these methods return false to indicate failure. The calling code in FileSystem.cpp checks this return value to handle the case gracefully. This design was chosen for simplicity and to avoid the overhead of exception handling.
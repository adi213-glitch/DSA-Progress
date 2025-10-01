#pragma once

#include "MyHashMap.hpp"
#include "File.hpp"
#include "MyMaxHeap.hpp"
#include <string>

using namespace std;

class FileSystem{
private:
    MyHashMap<string, File*, StringHasher> files;
    // --- Analytics Data Structures ---
     // Index maps to track position of a File* in the heaps
    // UPDATED: Now using the correct hasher for File* keys.
    // THE HEAP HOLDS A REFERENCE TO A HASHMAP IT DOESNT HAVE A MAP OF ITS OWN. THAT MAP IS DECLARED HERE.
    MyHashMap<File*, int, FilePointerHasher> timestamp_heap_indices;
    MyHashMap<File*, int, FilePointerHasher> versions_heap_indices;

    MyMaxHeap<File*, CompareByTimestamp,FilePointerHasher> recent_files_heap;
    MyMaxHeap<File*, CompareByVersions,FilePointerHasher> biggest_trees_heap;

    
public:
    FileSystem();
    ~FileSystem();
    void createFile(const string &filename);
    void readFile(const string& filename);
    void insertContent(const string& filename, const string& content);
    void updateContent(const string& filename, const string& content);
    void snapshot(const string& filename, const string& message);
    void rollBack(const string& filename, const string& versionid);
    void history(const string& filename);

    
     // Analytics Commands
    void recentFiles(int count);
    void biggestTrees(int count);
};
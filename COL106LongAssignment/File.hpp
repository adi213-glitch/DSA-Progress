#pragma once

#include "VersionNode.hpp"
#include <vector>
#include <string>
#include <ctime>

using namespace std;



class File{
public:
    string filename;//eg "inpput.txt"
    VersionNode* root; //a pointer to very first version in file's history every other version descends from this node
    VersionNode* active_version; // always points to our current version which we working on(insert/update) mein yahi modiffied hoga
    vector<VersionNode*> version_map;//[O(1) LOOKUP]   file specific hashmap becuase version ids are sequential integers so just use a vecotr (smart) 
    // eg version_map[5] gives pointer to versionNode with id =5
    int total_versions;// total number of versions created for this file
    time_t last_modification_time;//Stores the timestamp of the last modification (CREATE, INSERT, UPDATE). 
    //This is used for the RECENT_FILES analytics heap.

    // Constructor: Called when a file is created.
    File(const std::string& name);

    // Destructor: Called when a file is destroyed to clean up memory.
    ~File();
   
private:
    // A private helper function for the destructor.
    void delete_tree(VersionNode* node);
};

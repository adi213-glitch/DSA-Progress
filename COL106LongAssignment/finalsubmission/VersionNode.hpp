#pragma once

#include <string>
#include <vector>
#include <ctime>

using namespace std;

class VersionNode{
public:
    int version_id;
    string content;
    string message; // Empty if not a snapshot
    time_t created_timestamp;
    time_t snapshot_timestamp; // Null if not a snapshot
    VersionNode* parent;
    vector <VersionNode*> children;// stores the immediate children only of that node
    // /**
    //  * @brief Constructs a new VersionNode.
    //  * @param id The unique version ID for this node.
    //  * @param initial_content The starting content for this version.
    //  * @param p A pointer to the parent node (nullptr for the root).
    //  */

    VersionNode(int id,string initial_content, VersionNode *p){
        version_id=id;
        content = initial_content;
        parent =p;
        created_timestamp= time(nullptr); // attach systems default time
        snapshot_timestamp = 0;// 0 is just for represnting that this is Not a snapshot by default
        // The message is left empty by default. It's only set for snapshots.
    }
    bool isSnapshot( ){
        if(snapshot_timestamp == 0) return 0;
        return 1;
    }
};
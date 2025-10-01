#include "File.hpp"
#include <iostream>
using namespace std;
//happens when the user types the CREATE command. It sets up the file's initial state.
File::File(const string& name) {
    // 1. Assign initial values to the member variables.
    filename = name;
    total_versions = 1;
    last_modification_time = time(nullptr);
    
    // 2. Create the root version node.[DYNAMIC]
    root = new VersionNode(0, "", nullptr); 

    // 3. Mark the root as a snapshot.
    root->snapshot_timestamp = time(nullptr);
    root->message = "Initial commit";

    // 4. Set the active version to the root.
    active_version = root;

    // 5. Add the root to our version map. 
    //This gives me the required constant-time, O(1), access for the ROLLBACK command."
    version_map.push_back(root);
}



// --- Destructor Implementation ---
File::~File() {
    // Start the recursive deletion process from the root node.
    delete_tree(root);
}


// --- Private Helper Function Implementation ---
void File::delete_tree(VersionNode* node) {
    // Base case: If the node is null, stop the recursion.
    if (node == nullptr) {
        return;
    }

    // 1. Recursive Step: Delete all children first.(POST ORDER TRAVERSAL)
    for (VersionNode* child : node->children) {
        delete_tree(child);
    }

    // 2. Action Step: Now, delete the node itself.
    delete node;
}
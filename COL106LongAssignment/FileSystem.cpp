#include "FileSystem.hpp" // The corresponding header MUST be included first.

// Other necessary headers
#include "MergeSort.hpp"
#include "MyMaxHeap.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

FileSystem::FileSystem() 
    : recent_files_heap(timestamp_heap_indices), 
      biggest_trees_heap(versions_heap_indices) 
{
    // The body is empty because all initialization is complete.
    // The 'files' map and the two index maps are created automatically.
    // The two heaps are initialized via the list above, linking them to the maps.
    cout << "File system initialized." << endl;
}

FileSystem::~FileSystem(){
    //we are going to create file objects in dyanmic meoery so need to manually delete them in destrcutor
    for(auto bucket_list  : files.getTable()){
        for(auto p : bucket_list){
            delete p.second;
        }
    }
    cout << "FileSystem destroyed. All files cleaned up." << endl;
}

void FileSystem::createFile(const string &filename){

    // Step 1: Check if a file with the same name already exists.
    // We use the get() method of our hash map. If it returns anything other
    // than nullptr, it means a file with that key is already in the map.
    if (files.get(filename) != nullptr) {
        cout << "Error: File '" << filename << "' already exists." << endl;
        return; // Stop the function here.
    }

    // Step 2: If the file doesn't exist, create a new File object on the heap.
    // We use 'new' to allocate memory that will persist. The File constructor
    // handles the creation of the root VersionNode.
    File* newFile = new File(filename);

    // Step 3: Insert the new file pointer into our hash map.
    // The key is the filename, and the value is the pointer to the new object.
    files.insert(filename, newFile);
   // No full rebuild. Just insert the new file.
    recent_files_heap.insert(newFile);
    biggest_trees_heap.insert(newFile);
    // Step 4: Provide feedback to the user that the operation was successful.
    cout << "File '" << filename << "' created successfully." << endl;
  
}
void FileSystem::readFile(const string& filename){
    File ** fileptrptr = files.get(filename);
    if(fileptrptr==nullptr) {
        cout<< "NO SUCH FILE NAMED '"<<filename<<"'"<<endl;
        return;
    }
    File * fileptr = *fileptrptr;
    VersionNode* currentversion = (fileptr)->active_version;
    cout<< currentversion->content<<endl;
}
void FileSystem::insertContent(const string& filename, const string &content){
    File ** fileptrptr = files.get(filename);
    if(fileptrptr==nullptr) {
        cout<< "NO SUCH FILE NAMED '"<<filename<<"'"<<endl;
        return;
    }
    
    File * fileptr = *fileptrptr;
    VersionNode* currentversionptr = (fileptr)->active_version;
    bool versions_metric_changed = false;
    if(currentversionptr->isSnapshot()){
        //* use total versions as new id NOT THE OLD VERSION ID + 1 BECUASE BRANCHING WOULD CAUSE ERROS. totalversions counter doesnt go back only increases
        VersionNode * newvers = new VersionNode((fileptr->total_versions) , currentversionptr->content + content, currentversionptr);
        currentversionptr->children.push_back(newvers);
        fileptr->active_version=newvers;
        fileptr->total_versions++;
        fileptr->version_map.push_back(newvers);
        
        versions_metric_changed=true;
    }else {
        currentversionptr->content.append(content);
    }
    fileptr->last_modification_time=time(NULL); 
    
    // File metrics were modified, so update the heaps.
    int* timestamp_idx_ptr = timestamp_heap_indices.get(fileptr);
        if (timestamp_idx_ptr) {
            // the check confirms filewas actually found in heapmap
            recent_files_heap.updateheap(*timestamp_idx_ptr);
            //"I know the element at index *timestamp_idx_ptr has just changed its value. You don't need to search for it.
            // Just go directly to that spot and run your heapifyUp and heapifyDown logic to fix its position
        }
    if (versions_metric_changed) {
        // This is the new, efficient update logic
        int* versions_idx_ptr = versions_heap_indices.get(fileptr);
        if (versions_idx_ptr) {
            biggest_trees_heap.updateheap(*versions_idx_ptr);
        }
    }
    cout<<"Inserted content."<<endl;
}

void FileSystem::updateContent(const string& filename,const string &content){
    File ** fileptrptr = files.get(filename);
    if(fileptrptr==nullptr) {
        cout<< "NO SUCH FILE NAMED '"<<filename<<"'"<<endl;
        return;
    }
    
    File * fileptr = *fileptrptr;
    VersionNode* currentversionptr = (fileptr)->active_version;
    bool versions_metric_changed=false;
    if(currentversionptr->isSnapshot()){
        //* use total versions as new id NOT THE OLD VERSION ID + 1 BECUASE BRANCHING WOULD CAUSE ERROS. totalversions counter doesnt go back only increases
        VersionNode * newvers = new VersionNode((fileptr->total_versions)  ,  content, currentversionptr);
        currentversionptr->children.push_back(newvers);
        fileptr->active_version=newvers;
        fileptr->total_versions++;
        fileptr->version_map.push_back(newvers);

        versions_metric_changed=true;
    }else {
        currentversionptr->content=(content);
    }
    
    fileptr->last_modification_time=time(NULL); 
    
    // File metrics were modified, so update the heaps.
    int* timestamp_idx_ptr = timestamp_heap_indices.get(fileptr);
        if (timestamp_idx_ptr) {
            // the check confirms filewas actually found in heapmap
            recent_files_heap.updateheap(*timestamp_idx_ptr);
            //"I know the element at index *timestamp_idx_ptr has just changed its value. You don't need to search for it.
            // Just go directly to that spot and run your heapifyUp and heapifyDown logic to fix its position
        }
    if (versions_metric_changed) {
        // This is the new, efficient update logic
        int* versions_idx_ptr = versions_heap_indices.get(fileptr);
        if (versions_idx_ptr) {
            biggest_trees_heap.updateheap(*versions_idx_ptr);
        }
    }
    cout << "Content updated for '" << filename << "'." << endl;
}
void FileSystem::snapshot(const string & filename, const string &message){
    File ** fileptrptr = files.get(filename);
    if(fileptrptr==nullptr) {
        cout<< "NO SUCH FILE NAMED '"<<filename<<"'."<<endl;
        return;
    }
    
    File * fileptr = *fileptrptr;
    VersionNode* currentversionptr = (fileptr)->active_version;
    if (currentversionptr->isSnapshot()) {
        cout << "Error: Version " << currentversionptr->version_id << " is already a snapshot." << endl;
        return;
    }

    // 2. Perform the snapshot: set the timestamp and the message.
    // Setting the timestamp to a non-zero value makes it immutable.
    currentversionptr->snapshot_timestamp = time(nullptr);
    currentversionptr->message = message;

    // Note: Per TA clarification, snapshotting is NOT a modification.
    // Therefore, we DO NOT update file_ptr->last_modification_time.

    // 3. Provide feedback to the user.
    cout << "Snapshot created for '" << filename << "' with version ID " << currentversionptr->version_id << "." << endl;
}
void FileSystem::rollBack(const string& filename,const  string& versionid){
    File ** fileptrptr = files.get(filename);
    if(fileptrptr==nullptr) {
        cout<< "NO SUCH FILE NAMED '"<<filename<<"'."<<endl;
        return;
    }
    
    File * fileptr = *fileptrptr;
    VersionNode* currentversionptr = (fileptr)->active_version;
    if(versionid.empty()){
        //Path A: Rollback to Parent (no specific ID provided)
        if(currentversionptr->parent==nullptr){
            cout<<"Error: Cannot roll back. Active version is the root and has no parent."<<endl;
            return;
        }
        fileptr->active_version= currentversionptr->parent;
        cout << "Rolled back '" << filename << "'. Active version is now " << fileptr->active_version->version_id << "." << endl;
    }else{
        // --- Path B: Rollback to a specific version ID ---
        stringstream ss(versionid);
        int id;
        ss>>id;
        // 1. Validate the provided version_id.
        if (id < 0 || id >= fileptr->total_versions) {
            cout << "Error: Invalid version ID. Please provide an ID between 0 and " << fileptr->total_versions - 1 << "." << endl;
            return;
        }

        // 2. Get the target node from the version_map (O(1) access).
        VersionNode* target_node = fileptr->version_map[id];

        // 3. Perform the rollback.
        fileptr->active_version = target_node;
        cout << "Rolled back '" << filename << "'. Active version is now " << fileptr->active_version->version_id << "." << endl;
    }

}
void FileSystem::history(const string& filename){
    File ** fileptrptr = files.get(filename);
    if(fileptrptr==nullptr) {
        cout<< "NO SUCH FILE NAMED '"<<filename<<"'."<<endl;
        return;
    }
    cout << "--- History for '" << filename << "' ---" << endl;

    File * fileptr = *fileptrptr;
    VersionNode* currentversionptr = (fileptr)->active_version;
    // 1. Traverse from the active version up to the root, collecting snapshots.
    vector<VersionNode*> snapshottednodes;
    while(currentversionptr!=nullptr){
        if(currentversionptr->snapshot_timestamp!=0){
            snapshottednodes.push_back(currentversionptr);
        }
        currentversionptr=currentversionptr->parent;
    }
    
    // Sort the collected snapshots chronologically by their creation time.
    // This is required by the TA's clarification to handle branching correctly.
    CustomAlgorithms::sortHistory(snapshottednodes);
    
    // The vector is now sorted from oldest to newest.
    // We print it in forward order.

    for(VersionNode* i : snapshottednodes){
        VersionNode* curr =i;
        //2. format the timstamp 
        // snapshot_timestamp is a time_t (a large number). 
        //To make it human-readable, you can use the ctime() function from the <ctime> header.
        //ctime() takes a pointer to a time_t variable and returns a formatted string like "Sat Sep 06 18:41:00 2025\n".

        //Important: ctime() adds a newline character (\n) at the end.
        // You should remove this character (time_str.pop_back();) for cleaner formatting.
        time_t timestamp = curr->snapshot_timestamp;
        string time_str = ctime(&timestamp);
        time_str.pop_back(); // Remove the newline character added by ctime.
        
        //3.For each node, print its version_id, the newly formatted timestamp string, and its message
        cout << "Version ID: " << curr->version_id << endl;
        cout << "  Timestamp: " << time_str << endl;
        cout << "  Message: " << curr->message << endl;
        cout << "-----------------------------------" << endl;
    }
}
void FileSystem::recentFiles(int count) {
    cout << "--- " << count << " Most Recently Modified Files ---" << endl;
    
    if (recent_files_heap.isEmpty()) {
        cout << "No files in the system." << endl;
        return;
    }
    vector<File*> top_files;
    // CORRECTED: Extract, print, and store in a temporary vector.
    //This prevents errors if the user asks for more files than exist in the system.
    int num_to_show = min((int)recent_files_heap.size(), count); 
    File* currfile;
    for (int i = 0; (i < num_to_show)  && (recent_files_heap.pop(currfile)); i++) {
        
        top_files.push_back(currfile);
        time_t timestamp = currfile->last_modification_time;
        string time_str = ctime(&timestamp);
        time_str.pop_back();
        cout << i + 1 << ". " << currfile->filename << " (Modified: " << time_str << ")" << endl;
    }

    // CORRECTED: Re-insert the files to restore the heap.
    for (File* file_insert_back : top_files) {
        recent_files_heap.insert(file_insert_back);
    }
}

void FileSystem::biggestTrees(int count) {
    cout << "--- " << count << " Files with Most Versions ---" << endl;
    if (biggest_trees_heap.isEmpty()) {
        cout << "No files in the system." << endl;
        return;
    }

    vector<File*> top_files;
    int num_to_show = min((int)biggest_trees_heap.size(), count);

    // CORRECTED: Extract, print, and store.
    File* currfile; // Declare file pointer outside the loop
    for (int i = 0; i < num_to_show && biggest_trees_heap.pop(currfile); i++) {
        top_files.push_back(currfile);
        cout << i + 1 << ". " << currfile->filename << " (" << currfile->total_versions << " versions)" << endl;
    }

    // CORRECTED: Re-insert to restore the heap.
    for (File* file_insert_back : top_files) {
        biggest_trees_heap.insert(file_insert_back);
    }
}

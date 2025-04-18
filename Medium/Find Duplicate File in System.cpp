#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-duplicate-file-in-system/
// Difficulty : Medium 

/* HASH MAP + STRING */
class Solution {
public:
        vector<vector<string>> findDuplicate(vector<string>& paths) {
            
            unordered_map<string,vector<string>> content_to_filepaths;
            vector<vector<string>> dupeFilePaths;
    
            for (auto path : paths) {
                
                int i = 0, n = path.length();
                string directory = "";
    
                // Get Directory Path
                while (i<n and path[i] != ' ') { directory += path[i]; i++; }
                i++;
    
                // Find each file and its content and map them to each other to find duplicates.
                while (i<n) {
    
                    string filename = "", content = "";
    
                    // Get filenames and content of files inside this directory
                    while (i<n and path[i] != '(') { filename += path[i]; i++; }
                    i++;
                    while (i<n and path[i] != ')') { content += path[i]; i++; }
                    i+=2;
    
                    // Map the content to File Paths (Directory + filename) having it.
                    content_to_filepaths[content].push_back(directory+"/"+filename);
                }
    
            }
    
            // If there are filepaths containing same content, collect them.
            for (auto p : content_to_filepaths) {
                if (p.second.size() > 1) {
                    dupeFilePaths.push_back(p.second);
                }
            }
    
            return dupeFilePaths;
        }
};

/*
    PYTHON3 VERSION

    class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:

        content_to_filepaths = defaultdict(list)
        dupeFilePaths = []

        for path in paths :

            path_parts = path.split(' ')
            directory = path_parts[0]

            path_parts.pop(0)
            
            for part in path_parts :
                
                temp = part.split('(')
                filename = temp[0]
                content = temp[1][:-1]
                content_to_filepaths[content].append(f"{directory}/{filename}")


        for content in content_to_filepaths.keys() :
            if len(content_to_filepaths[content]) > 1 :
                dupeFilePaths.append(content_to_filepaths[content])


        return dupeFilePaths
        
*/

#include <iostream>
#include <string>
#include <vector>
#include "LinkedHashMap.hpp"

using namespace std;

int main() {
    // Test basic functionality
    int len;
    bool forEachByTime;
    
    // Read input format: first line contains array length and traversal method
    cin >> len >> forEachByTime;
    
    LinkedHashMap map(len, forEachByTime);
    
    string command;
    while(cin >> command) {
        if(command == "insert") {
            int key;
            string value;
            cin >> key >> value;
            map.insert(key, value);
        } else if(command == "remove") {
            int key;
            string value;
            cin >> key >> value;
            map.remove(key, value);
        } else if(command == "ask") {
            int key;
            cin >> key;
            vector<string> result = map.ask(key);
            for(size_t i = 0; i < result.size(); i++) {
                if(i > 0) cout << " ";
                cout << result[i];
            }
            cout << endl;
        } else if(command == "forEach") {
            vector<Data> result = map.forEach();
            for(size_t i = 0; i < result.size(); i++) {
                if(i > 0) cout << " ";
                cout << result[i].key << "," << result[i].value;
            }
            cout << endl;
        } else if(command == "end") {
            break;
        }
    }
    
    return 0;
}

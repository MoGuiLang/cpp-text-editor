//
//  main.cpp
//  Proje
//
//  Created by Muzaffer Tolga Yakar on 25.12.2020.
//

#include <iostream>
#include<string>
#include"editor.h"

void help(){
    cout << "-----Commands-----" << endl;
    cout << "open filename -> That command opens your file." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "save filename -> That command saves your file." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "insert n(number) -> That command addes a text that you typed on nth line." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "delete n(number) -> That command deletes nth line." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "move n(number) m(number) -> That command moves from nth line to mth line." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "replace n -> That command replaces text on nth line." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "next -> That command prints next page." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "prev -> That command prints previous page." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "undo -> That command undo." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "help -> That command showes the commands." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "quit -> That command quit from program." << endl; cout << "-------------------------------------------------------------------------" << endl;
}
int main(int argc, const char * argv[]) {
    
    Editor editor;
    cout << "Welcome to CSE-211 2020 Fall Project" << endl;
    cout << "-----Commands-----" << endl;
    cout << "open filename -> That command opens your file." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "save filename -> That command save your file." << endl;
    cout << "insert n(number) -> That command add a text that you typed on nth line." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "delete n(number) -> That command delete nth line." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "move n(number) m(number) -> That command move from nth line to mth line." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "replace n -> That command replace text on nth line." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "next -> That command print next page." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "prev -> That command print previous page." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "undo -> That command undo." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "help -> That command showes the commands." << endl; cout << "-------------------------------------------------------------------------" << endl;
    cout << "quit -> That command quit from program." << endl; cout << "-------------------------------------------------------------------------" << endl;
    while(1){
        cout << "command: ";
        string command;
        cin >> command;
        if(command == "open"){
            string filename;
            cin >> filename;
            editor.open(filename);
            
        }
        else if(command == "save"){
            string filename; cin >> filename;
            editor.save(filename);
            
        }
        else if(command == "insert"){
            int n; cin >> n;
            editor.insert(n);
        }
        else if(command == "delete"){
            int n; cin >> n;
            editor.del(n);
        }
        else if(command == "move"){
            int n, m; cin >> n >> m;
            editor.move(n,m);
            
        }
        else if(command == "replace"){
            int n; cin >> n;
            editor.replace(n);
            
        }
        else if(command == "next"){
            editor.next();
        }
        else if(command == "prev"){
            editor.prev();
        }
        else if(command == "undo"){
            editor.undo();
        }
        else if(command == "help"){
            help();
        }
        else if(command == "quit"){
            break;
        }
		else{
			cout << "Invalid Command. If you dont know commands, please type help and you can learn the commands" << endl;
		}
        editor.Print();
        cout << "The Number Of Lines: " << editor.numberOfLines() << endl;
    }
    return 0;
}

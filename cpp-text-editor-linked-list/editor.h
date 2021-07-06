//
//  Header.h
//  Proje
//
//  Created by Muzaffer Tolga Yakar on 25.12.2020.
//

#ifndef editor_h
#define editor_h
#include<iostream>
#include"genDLLList.h"
#include<string>
#include<stack>
#include<fstream>


class Editor{
private:
    DoublyLinkedList<string> root;
    stack<string> undoJob;
    stack<string> undoInfo;
    stack<int> undoLine;
    int currentPage;
    
public:
    void open(string);
    void save(string);
    void insert(const int &);
    void del(const int &);
    void move(const int &, const int &);
    void replace(const int &);
    void next();
    void prev();
    void Print(){
        root.print(currentPage);
    }
    void undo();
    int numberOfLines(){return root.getSize();}
};

void Editor::open(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            root.addToDLLTail(line);
        }
    }
    currentPage=1;
}
void Editor::save(string filename){
    ofstream file;
    file.open(filename);
    while(!root.isEmpty()){
        file << root.deleteFromDLLHead() << '\n';
    }
    file.close();
    while(!undoJob.empty()) {undoJob.pop();}
    while(!undoInfo.empty()) {undoInfo.pop();}
    while(!undoLine.empty()) {undoLine.pop();}
}
void Editor::insert(const int &n){
    if(n == 1){
        string data; cin.ignore(); getline(cin, data);
        root.addToDLLHead(data);
        undoInfo.push(data);
        undoJob.push("insert");
        undoLine.push(n);
        return;
    }
    else if(n == root.getSize()+1){
        string data; cin.ignore(); getline(cin, data);
        root.addToDLLTail(data);
        undoInfo.push(data);
        undoJob.push("insert");
        undoLine.push(n); 
        return;
    }
    else if(n > 1 && n <= root.getSize()){
        string data; cin.ignore(); getline(cin, data);
        root.addToDLLAny(data, n);
        undoInfo.push(data);
        undoJob.push("insert");
        undoLine.push(n); 
        return;
    }
    else if(n > root.getSize()+1){
        int m = root.getSize();
        for(int i = 0; i < n-1-m; i++){
            root.addToDLLTail(" ");
        }
        string data; cin.ignore(); getline(cin, data);
        root.addToDLLTail(data);
        undoInfo.push(data);
        undoJob.push("insert");
        undoLine.push(n);
        
        return;
    }
    return;
}
void Editor::del(const int &n){
    if(n == 1){
        string data =root.deleteFromDLLHead();
        undoInfo.push(data);
        undoJob.push("del");
        undoLine.push(n);
        return;
    }
    else if (n == root.getSize()){
        string data = root.deleteFromDLLTail();
        undoInfo.push(data);
        undoJob.push("del");
        undoLine.push(n);
        return;
    }
    else if(n > 1 && n < root.getSize()){
        string data = root.deleteFromDLLAny(n);
        undoInfo.push(data);
        undoJob.push("del");
        undoLine.push(n);
        return;
    }
}
void Editor::move(const int&n, const int &m){
    string el;
    if(n == 1){
        el = root.deleteFromDLLHead();
        if(m == root.getSize()+1){
            root.addToDLLTail(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m > 1 && m <= root.getSize()){
            root.addToDLLAny(el, m);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m == 1){
            root.addToDLLHead(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m > root.getSize()){
            for(int i = 0; i <= m - root.getSize(); i++){
                root.addToDLLTail(" ");
            }
            root.addToDLLTail(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
    }
    else if(n > 1 && n < root.getSize()){
        el = root.deleteFromDLLAny(n);
        if(m == 1){
            root.addToDLLHead(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m > 1 && m <= root.getSize()){
            root.addToDLLAny(el, m);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m > root.getSize()){
            for(int i = 0; i <= m-root.getSize(); i++){
                root.addToDLLTail(" ");
            }
            root.addToDLLTail(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m == root.getSize()+1){
            root.addToDLLTail(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
    }
    else if(n == root.getSize()){
        el = root.deleteFromDLLTail();
        if(m == 1){
            root.addToDLLHead(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m > 1 && m <= root.getSize()){
            root.addToDLLAny(el, m);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m == root.getSize()+1){
            root.addToDLLTail(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
        else if(m > root.getSize()){
            for(int i = 0; i <= m - root.getSize(); i++){
                root.addToDLLTail(" ");
            }
            root.addToDLLTail(el);
            undoInfo.push(el);
            undoJob.push("move");
            undoLine.push(m);
            undoLine.push(n);
            return;
        }
    }
}
void Editor::replace(const int &n){
    if(n > root.getSize()){
        cout << "You cant replace size of linked list is " << root.getSize() << endl;
        return;
    }
    string s;
    cin.ignore();
    getline(cin, s);
    string el = root.rep(n, s);
    undoInfo.push(el);
    undoJob.push("replace");
    undoLine.push(n); 
    return;
}
void Editor::next(){
    if(currentPage*10 <= root.getSize())
        {currentPage++; return;}
    else return;
}
void Editor::prev(){
    if(currentPage == 1){
        cout << "You cant go to prev page." << endl;
        return;
    }
    currentPage--;
}
void Editor::undo(){
	//if(undoJob.empty()){cout << "You cant undo " << endl; return;}
    string job = undoJob.top(); undoJob.pop();
    string info = undoInfo.top(); undoInfo.pop();
    int line = undoLine.top(); undoLine.pop();
    if(job == "insert"){
        if(line == 1) root.deleteFromDLLHead();
        else if(line == root.getSize()) root.deleteFromDLLTail();
        else if(line > 1 && root.getSize()) root.deleteFromDLLAny(line);
    }
    else if(job == "del"){
        if(line == 1) {root.addToDLLHead(info); return;}
        else if(line == root.getSize()+1) {root.addToDLLTail(info); return;}
        else if (line > 1 && line <= root.getSize()) {root.addToDLLAny(info,line); return;}
    }
    else if (job == "move"){
        int line2 = undoLine.top(); undoLine.pop();
        if(line == line2) return;
        else if(line == 1 && line2 == root.getSize()){root.deleteFromDLLTail(); root.addToDLLHead(info);return;}
        else if(line == 1&& line2 > 1 && line2 < root.getSize()){root.deleteFromDLLAny(line2); root.addToDLLHead(info);return;}
        else if(line > 1 && line2 > 1 && line < root.getSize() && line2 < root.getSize()){root.deleteFromDLLAny(line2); root.addToDLLAny(info,line);return;}
        else if(line > 1 && line < root.getSize() && line2 == 1){root.deleteFromDLLHead(); root.addToDLLAny(info,line);return;}
        else if(line > 1 && line < root.getSize() && line2 == root.getSize()){root.deleteFromDLLTail(); root.addToDLLAny(info,line);return;}
        else if(line == root.getSize() && line2 == 1){root.deleteFromDLLHead(); root.addToDLLTail(info);return;}
        else if(line == root.getSize() && line2 > 1 && line2 < root.getSize()){root.deleteFromDLLAny(line2); root.addToDLLTail(info);return;}
    }
    else if(job == "replace"){root.rep(line, info);return;}
}
#endif

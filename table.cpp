#include <stdio.h>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include "table.h"
#include "entry.h"
using namespace std;

//constructor
Table::Table(){
    length = entries*2-1;
    values = vector<vector<Entry> >(length);

}


//Another constructor that builds a Table designed to hold the number of entries specified by the first parameter, and puts that many entries into the Table by reading them one at a time from the input stream that is the second parameter:
/*
Table::Table(unsigned int entries, std::istream& input){
    this->entries = entries;
    length = entries*2-1;
    values = vector<vector_entry>(length);
    Entry temp;
    for(int i = 0; i < entries; i++){
        input >> temp;
        put(temp);
    }
}
*/
//functions
//The first of these functions creates a new Entry to put in the Table.
void Table::put(string key, int data){
    Entry en(key, data);
    put(en);
}

//The second one puts a copy of the parameter in the Table. In cases where the Table already contains an Entry with the given key, these functions act to update the Entry for that key.
void Table::put(Entry e){
    string key = e.get_key();
    int index = hash(key);
    if (values[index].empty()) {
        values[index].push_back(Entry(key, e.get_data()));
    }
    else{
        for (int i = 0; i < values[index].size();i++){
            if(values[index][i].get_key() == key){
                values[index][i].set_data(e.get_data());
            }
        }
        values[index].push_back(Entry(key, e.get_data()));
    }

}

//A constant member function named get that returns the string associated with the parameter:
//This function returns an empty string if the Table has no Entry with the given key.
int Table::search(string key){

    int index = hash(key);
    if(values[index].empty()){
        return -1;
    }
    else{
        for(int i = 0; i< values[index].size();i++){
            if(values[index][i].get_key()== key){
                return values[index][i].get_data();
                //return true;
            }
        }
        //return false;
        return -1;
    }

}

void Table::update_data(string key, int data){
    int index = hash(key);
    for (int i = 0; i < values[index].size();i++){
        if(values[index][i].get_key() == key){
            values[index][i].set_data(data);
        }
    } 

}
//A member function named remove that removes the Entry containing the given key:
//This function returns true if it removes an Entry, or false if the Table has no such Entry
void Table::remove(string key){

    int index = hash(key);
    if(values[index].empty()){
        cout<< "false\n";
    }
    else{
        for(int i = 0; i< values[index].size();i++){
            if(values[index][i].get_key()== key){
                values[index].erase(values[index].begin() + i);
                //return true;
            }
        }
        //return false;
    }

}

int Table::hash(string key) const{
    int sum(0);
    for (auto& elem : key)
    {
        if(isalpha(elem))
        {
            elem = toupper(elem);
            sum += static_cast<int>(elem - 'A' + 1);
        }
    }
    return sum % (entries-1);
}


//This function is expected to print each Entry in the Table to a separate line of the given output stream in the order of their key values.

std::ostream& operator<< (std::ostream& out, const Table& t){
    for(int i = 0; i< t.entries; i++){
        for(Entry e: t.values[i]){
            out << "Position: " << i << "; Entry: " << e << endl; 
        }
    }
    return out;
}

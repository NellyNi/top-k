#include "entry.h"
#include <iostream>
#include <string>
using namespace std;

unsigned int Entry::accesses = 0;
unsigned int Entry::instances = 0;

Entry::Entry(string key, int data)
: key(key), data(data) { ++instances; }

Entry::Entry(const Entry &other)
: key(other.key), data(other.data){ ++instances; }

Entry::~Entry() { --instances; }

string Entry::get_key() const
{ ++accesses; return key; }

int Entry::get_data() const
{ return data; }

unsigned int Entry::access_count()
{ return accesses; }

unsigned int Entry::instance_count()
{ return instances; }

void Entry::set_key(string k)
{ key = k; }

void Entry::set_data(int d)
{ data = d; }
    
Entry::operator string () const
{ return get_key(); }

/*
istream& operator>> (istream& inp, Entry &e) {
    inp >> e.key;
    // get data in two parts to handle white space
    string first_word, rest_of_line;
    inp >> first_word;
    getline(inp, rest_of_line);
    e.data = first_word + rest_of_line;
    return inp;
}
*/

ostream& operator<< (ostream& out, Entry &e) {
    out << e.get_key() << ": " << e.get_data();
    return out;
}
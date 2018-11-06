#ifndef table_h
#define table_h
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include "entry.h"
using namespace std;

class Table {
public:
	//constructor	
	//Table(unsigned int max_entries);
	//Table(unsigned int entries, std::istream& input);
    Table();

	//functions
	void put(string key, int data);
	void put(Entry e);
	int search(string key);
    void update_data(string key, int data);

	void remove(string key);

	friend ostream& operator<< (ostream& out, const Table &t);

private:
	vector<vector<Entry> > values;
	const int entries=16;
	int length;
	int hash(string key) const;
//        static unsigned int accesses;

};


#endif
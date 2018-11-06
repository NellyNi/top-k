#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <iosfwd>
using namespace std;

class Entry {

public:
    // constructors and destructor
    Entry(string key = "", int data = 0);
    Entry(const Entry &other);
    ~Entry();
    
    // access and mutator functions
    string get_key() const;
    int get_data() const;
    static unsigned int access_count();
    static unsigned int instance_count();
    void set_key(string k);
    void set_data(int d);
    
    // operator conversion function simplifies comparisons
    operator string () const;
    
    // input and output friends
   // friend std::istream& operator>>
     //   (std::istream& inp, Entry &e);
    friend std::ostream& operator<<
        (std::ostream& out, Entry &e);
    
private:
    string key;
    int data;
    static unsigned int accesses;
    static unsigned int instances;
};

#endif
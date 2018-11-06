#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "table.h"
#include "min.h"
using namespace std;

int main(){
    
    cout << "Demonstrate article_ta.txt: " << endl;
    ifstream input;
    input.open("article_ta.txt");
    if(!input.good()){
        cout<<"No such a file in current directory. Quitting\n";
        return 1;
    }
    string word;
    //MinHeap* mh = new MinHeap();
    MinHeap mh;
    while(input.good()){
        if (input >> word)
        {
            // read worked so you can processes the data
            //cout<<word<<endl;
            mh.insert(word);
            //mh.printHeap();
            //cout<<endl;

        }
    }    
    input.close();

    string c;

    do{
        cout<<"(1)Enter 1 to input extra words in new heapprint heap. (2)Enter 2 to print min heap. (3)Enter 3 to print hash table:\n";
        cout<<"Enter 0 for quit\n";
        int p;
        cin>>p;
        if (p==1){
            string d;
            do{
                cout<<"input the word: ";
                cin>>word;
                mh.insert(word);
                cout<<"Do you want to keep insert words? y/n\n";   
                cin>>d;

            } while((d=="y")||(d=="Y"));
        }
        
        if (p==2){
            mh.printHeap();
        }
        if (p==3){
            mh.printHashTable();
        }
        cout<<"Do you want to continue? y/n\n";
        cin>>c;
    }while ((c=="y")||(c=="Y"));

    return 0;

}
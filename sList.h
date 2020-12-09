#ifndef SLIST_H
#define SLIST_H

#include<string>

using namespace std;

//Please declare the struct type 
//SongType
struct SongType {
    int rank;
    string singer;
    string title;
    int year;
};

class sList {
    //Declaration a structure of the Nodes
private:
    struct Node {
        SongType song;
        struct Node *next;
       

    };
    public:
    // List head Pointer
    Node *head;
   
    //Constructor

    sList();


    //~Destructor
    ~sList();

    //Linked List Operations

    // Insertion Operations for the linked list
    void insertAtEnd(SongType);

    // Print out data in the list
    void displayList(int);

    // Search for the artist
    void lookUpArtist(string);

    //deletion operations for the linked list
    void deleteSong(string);


};

#endif

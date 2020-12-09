/* Description: This program will allow a user to add, delete, change,
//                 Search for artist, and search for songs by year.
/////////////////////////////////////////////////////////////////*/
#include<iostream>
#include"sList.h"
#include<iomanip>
#include<string>
#include<stdlib.h>

using namespace std;

//Constructor
//Please define your constructor here
sList::sList() 
{
    head = nullptr;
}


//~Destructor
sList::~sList() {
    Node *cur = head;
    while (cur != nullptr) {
        //delete the Node pointed to by head
        head = head->next; // move head to the next Node
        cur->next = nullptr;
        delete cur; //deallocate memory
        cur = head; //make cur point to the new Node
    }
}


//insertAtEnd method
/************************************
*Name: insertAtEnd
*Input: string
*Output: structure
*This method with take the data given for the songs and store them in a structure.
*/
void sList::insertAtEnd(SongType song)
{
    //create a new Node to hold the data
    Node *newNode = new Node;
    newNode->song.rank = song.rank;
    newNode->song.singer = song.singer;
    newNode->song.title = song.title;
    newNode->song.year = song.year;
    Node *tail = head;
    newNode->next = nullptr;
    // if the list is empty
    //make the new node as the head
    if (head == nullptr)
        head = newNode;
        //else
        //insert the new node to the end of the List
    else
    {
        while (tail->next != nullptr)
            tail = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}


//deleteSong method
/**************************************
*Name: deleteSong
*Input: string
*Output: string
*This method finds the given song and deletes it. If no song is found will retrun not found.
*/
void sList::deleteSong(string songname)
{
SongType song;
//cur will point to the item to delete
Node *cur = head;
    if(cur->next == nullptr)
      {
              cout << endl;
              cout << "===========================\n";
              cout << "Song information not found.\n";
              cout << "===========================\n";
        }

      while(cur->next != nullptr)
      {

           if(cur->next->song.title == songname)
          {
              Node *s = cur->next;
              cur->next = cur->next->next;
              delete s;
              cout << "========================================\n";
              cout << "Your song has been successfully deleted!\n";
              cout << "========================================\n";
              return;
              
          }
          cur = cur->next;
    }
}
   
//displayList() method
/**************************************
*Name: displayList()
*Input: int
*Output: song
*This method will print out all the songs from the given year.
*/
void sList::displayList(int year)
{
    SongType song;
    Node *cur = head;
    
    
//print the songs in given year
    cout << "Search results for: " << year << endl << endl;
    if (cur == nullptr)
          {
           cout << "===========================\n";
           cout << "Song information not found.\n";
           cout << "===========================\n";
         }
    
    while (cur != nullptr)
    {
        if (cur->song.year == year)
       {
           cout << left;
           cout << setw(8);
           cout << cur->song.rank << setw(40) <<
           cur->song.singer <<
           cur->song.title << setw(8) << endl;
       }
        cur = cur->next;
      
    }
}


//lookUpArtist method
/*************************************
*Name: lookUpArtist
*Input:  string
*Output: string
*This method looks up the artst and prints out all songs from the artist.
*/
void sList::lookUpArtist(string artistname)
{
    SongType song;
//use while loop to search the artist 
//display all songs of the artist
    Node *cur = nullptr;
    cur = head;
    cout << "Search results for: " << artistname << endl << endl;
    if (cur->song.singer != artistname)
    {
        cout << "=============================\n";
        cout << "Artist information not found.\n";
        cout << "=============================\n";
    }
  
    while (cur != nullptr)
    {
        if (cur->song.singer == artistname && cur != nullptr)
       {
           cout << left;
           cout << setw(8);
           cout << cur->song.year << setw(30) <<
           cur->song.title <<
           cur->song.rank << setw(8) << endl;
           
    
       }
        
        cur = cur->next;
       
    }
    
}

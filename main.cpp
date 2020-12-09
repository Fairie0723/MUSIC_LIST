#include<iostream>
#include<fstream>
#include"sList.h"
using namespace std;

void readSong(SongType &, ifstream &);
void mainMenu();

int main()

{
    SongType song;
	ifstream inFile;
	inFile.open("topsongs.dat");
    
	
	if(!inFile)
	{
		cout << "File Not Found!" << endl;
		exit(EXIT_FAILURE);
	}

	sList songList;
	//SongType song;
    int choice = 0;
    int year;
    string artistname;
    string songname;


    //prime reading
	readSong(song,inFile); // read the first song from the datafile
	while(inFile)
	{
        
		// insert the song to the end of songList
        songList.insertAtEnd(song);

        
		// read next song
        readSong(song,inFile);
	}

	do
	{
		mainMenu();
        cin >> choice;
        //switch case
        switch(choice)
        {
		case 1:
			//prompt the user to enter a new song (singer, song, year, rank)
            cout << "===================================" << endl;
                cout << "Please enter the artist name: \n";
                cin.ignore();
                getline(cin,song.singer);
                cout << "Please enter the song title: \n";
                getline(cin, song.title);
                cout << "Please enter the rank: \n";
                cin >> song.rank;
                cout << "Please enter the year: \n";
                cin >> song.year;
                cin.ignore();
			//call the insertAtEnd method to insert the song to the end of the songList
                songList.insertAtEnd(song);
                cout << "==========================\n";
                cout << "Your song has been added." << endl;
                cout << "==========================\n";
                break;
		case 2: 
			//prompt the user to enter the song to delete
            cout << "Please enter the song to delete: \n";
                cin.ignore();
                getline(cin,songname);
                //call the deleteSong method to delete the song
                songList.deleteSong(songname);
                break;
		case 3:
			//prompt the user to enter the artist name
            cout << "Please enter the artist name: \n";
                cin.ignore();
                getline(cin, artistname);
			//call the lookUpArtis method to search for the songs for artist
                cout << "===========================================================================\n";
                songList.lookUpArtist(artistname);
                cout << "===========================================================================\n";
                
                break;

            case 4:
			//prompt the user to enter the year
                cout << "Please enter the year: \n";
                cin >> year;
                //cin.ignore();
			//call the displayList method to search for the songs for year
                cout << "===========================================================================\n";
                songList.displayList(year);
                cout << "===========================================================================\n";
                break;
            case 5:
			cout << "Thank you!" << endl;
			break;
		default:
			cout << "Invalid Options." << endl;
			break;
		}
	}while(choice !=5);

	inFile.close();

	return 0;
}

//readsong method
/**************************************
*Name:  readsong
*Input:  inFile, song
*Output: song
*This method reads in all the songs from the file and stores them in a structure.
 */
void readSong(SongType &song,ifstream &inFile)
{
	//prompt
	// the user to enter four fields of the song
	//rank;
    inFile >> song.rank;
	//artist name:
    getline(inFile, song.singer);
    while (song.singer.empty())
        getline(inFile,song.singer);
	//song name;
    getline(inFile, song.title);
    while (song.title.empty())
           getline(inFile, song.title);
    //year
    inFile >> song.year;
   // inFile.ignore();
}
//mainmenu method
/**************************************
*Name: mainmenu
*Input:  none
*Output: none
*This method displays the main menu to the user until the program exits.
 */
void mainMenu()
{
	//display the menu to the user
    cout << "\n================================================";
    cout << "\nWelcome to Billboard Top Song (2015-2020) App";
    cout << "\n================================================";
    cout << "\n1. Add a song";
    cout << "\n2. Delete a song";
    cout << "\n3. Loop up an artist";
    cout << "\n4. Display";
    cout << "\n5. Exit";
    cout << "\n================================================\n";
}



/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;                            //creating a UtPod set to max memory of 512 MB

    //testing the add song function
    cout << "Testing addSong Function:" << endl;

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;


    Song s2("Angelica", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;


    Song s3("Doomsday", "Hey Jude4", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    Song s4("Doomsday", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Lemonzzz", "Hey Jude3", 216);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;


    t.showSongList();                   //testing show list function

    cout << endl;

    t.sortSongList();                   //testing sort list (will sort by artist, title, then size)
    cout << "Testing sortSongList Function:" << endl;

    t.showSongList();

    cout << endl;

    t.shuffle();                        //testing shuffle function
    cout << "Testing shuffle function:" << endl;
    t.showSongList();

    cout << endl;

    t.shuffle();                        //testing shuffle function again
    cout << "Testing shuffle function again:" << endl;
    t.showSongList();

    cout << endl;

    //testing remove song

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    cout<< endl;
    cout<< "Testing removing song from an empty list: " << endl;

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    cout << endl;


    t.showSongList();

    cout << endl;

    Song s6("Peanuts", "Hello", 285);               //add song
    result = t.addSong(s6);
    cout << "add result = " << result << endl;


    result = t.addSong(s4);
    cout << "add result = " << result << endl;


    result = t.addSong(s5);
    cout << "add result = " << result << endl;


    t.showSongList();

    Song s7("Frizzle Sizzle", "Crispy Tates", 416);    //testing adding a song without enough memory
    result = t.addSong(s7);
    cout << "result = " << result << endl;

    cout << endl;

    cout << "Remaining memory = " << t.getRemainingMemory() << "MB" << endl;

    cout << "Total memory = " << t.getTotalMemory() << "MB" << endl;

    //removing a song that is not present in list

    cout << endl;

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    t.clearMemory();

    cout << endl;

    t.showSongList();

    cout << endl;

    cout << "Remaining memory = " << t.getRemainingMemory() << "MB" << endl;

    cout << endl;
    cout << endl;
    cout << endl;


    //Creating and Testing a new UtPod "t2"
    cout << "Testing a new UtPod:" << endl;
    cout << endl;
    UtPod t2(50);          //creating a UtPod of max memory 50 MB

    //testing the add song function
    Song jam1("Beatles", "Here Comes the Sun", 4);
    result = t2.addSong(jam1);
    cout << "add result = " << result << endl;

    Song jam2("Beatles", "Drive my Car", 5);
    result = t2.addSong(jam2);
    cout << "add result = " << result << endl;

    Song jam3("Mr.Potatoe", "Tater Tots", 6);
    result = t2.addSong(jam3);
    cout << "add result = " << result << endl;

    Song jam4("Minty Breath", "Enlightenment", 7);
    result = t2.addSong(jam4);
    cout << "add result = " << result << endl;

    Song jam5("Axolotl Power Crew", "Freaky Fresh", 8);
    result = t2.addSong(jam5);
    cout << "add result = " << result << endl;

    t2.showSongList();

    cout << endl;
    cout << "Remaining memory = " << t2.getRemainingMemory() << "MB" << endl;

    cout << "Total memory = " << t2.getTotalMemory() << "MB" << endl;

    cout <<endl;
    Song jam6("Creeper Jeepers", "Funky Tunez", 25);      //testing add limit, not enough space
    result = t2.addSong(jam6);
    cout << "add result = " << result << endl;

    Song jam7("Beatles", "Drive my Car", 16);
    result = t2.addSong(jam7);
    cout << "add result = " << result << endl;

    t2.showSongList();
    cout << endl;
    t2.sortSongList();
    cout << "Testing sort: " << endl;
    t2.showSongList();

    cout << endl;


    result = t2.removeSong(jam7);
    cout << "delete result = " << result << endl;

    cout << endl;

    t2.sortSongList();                                  //testing sort and show functions
    t2.showSongList();

    cout << endl;

    result = t2.removeSong(jam6);                       //should result in song not found to be removed
    cout << "delete result = " << result << endl;

    result = t2.removeSong(jam5);                       //should remove jam5 from list
    cout << "delete result = " << result << endl;

    t2.showSongList();
    cout << endl;
    cout << "Remaining memory = " << t2.getRemainingMemory() << "MB" << endl;

    t2.clearMemory();

    cout << endl;

    t2.showSongList();
    cout << endl;
    cout << "Remaining memory = " << t2.getRemainingMemory() << "MB" << endl;


}

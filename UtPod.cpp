#include <ctime>
#include "UtPod.h"
#include <iostream>
#include <cstdlib>


using namespace std;

UtPod ::UtPod() {

    songs = 0;                  //SongNode head pointer to NULL
    memSize = MAX_MEMORY;       //default constructer sets memSize to MAX of 512MB

}

UtPod ::UtPod(int size) {
    songs = 0;
    if(size > MAX_MEMORY || size <=0)
        memSize = MAX_MEMORY;
    else
        memSize = size;
}

int UtPod ::addSong(Song const &s) {

    int remaining = getRemainingMemory();           //check if there is enough space to add song
    if((remaining - s.getSize()) < 0){
        cout << "Not enough memory available to add this song: " << s.getTitle() << endl;
        return NO_MEMORY;
    }

    SongNode *temp = new SongNode;
    temp->s = s;
    temp->next = songs;             //adding song to front of list
    songs = temp;                   //pointing to new head of list



    return SUCCESS;

}

int UtPod ::removeSong(Song const &s) {

    if(songs == 0){
        cout << "There are no songs in the list to be removed." << endl;
        return NOT_FOUND;
    }


    SongNode *p = songs;        //p, p2, p3 pointing to head of song list
    SongNode *p2 = songs;
    SongNode *p3 = songs;
    SongNode *ToBeRemoved;

    while(p != 0){              //finding the location of ToBeRemoved
        if(p->s == s)
            ToBeRemoved = p;
        p = p->next;

    }

    if(p3->s == s){                  //case where removal is at head of list
        songs = songs->next;          //song is pointing at new head
        delete(p3);


        return SUCCESS;

    }

    while(p2->next != 0 && p2->next!= ToBeRemoved) { //keep traversing until p2
        // is pointing to right before removal node
        p2 = p2->next;

    }

    if(p2->next == 0) {                             //if p2 made it to the end of list, then song is not present
        cout << "The song: " << s.getTitle() << " to be deleted is not in the list.\n";
        return NOT_FOUND;
    }

    p2->next = p2->next->next;          //skip over the node that is to be deleted

    delete(ToBeRemoved);                //free the memory of the node to be removed


    return SUCCESS;

}


void UtPod ::shuffle() {
    int total = 0;
    SongNode *p;

    p = songs;

    while (p != 0){         //finding total number of songs in list
        total++;
        p = p->next;
    }

    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);        //seeds the random number generator

    for (int i = 0; i < total; i++){
        SongNode *s1 = songs;
        SongNode *s2 = songs;
        SongNode *temp = new SongNode;

        int rand1 = rand() % total;      //creating two random spots within the range of the number of songs
        int rand2 = rand() % total;

        while(rand1 != 0){              //make s1 point to first random spot in list
            s1 = s1->next;
            rand1--;
        }
        while(rand2 != 0){              //make s2 point to second random spot in list
            s2 = s2->next;
            rand2--;
        }

        temp->s = s1->s;            //SWAP the two randomly chosen spots
        s1->s = s2->s;
        s2->s = temp->s;

        delete(temp);               //free the memory of the temp spot
    }

}

void UtPod ::showSongList() {
    SongNode *p = songs;        //p is pointing to head of song list
    if(songs == 0)
        cout << "There are no songs on this UtPod." << endl;
    while(p != 0){
        cout << "Song Title: " << p->s.getTitle() << "  Artist: " << p->s.getArtist()
             << "  Size: " << p->s.getSize() << endl;  //printing the song info
        p = p->next;
    }

}

void UtPod ::sortSongList() {

    if (songs == 0) {   //list is empty
        cout << "No songs in list to be sorted." << endl;
        return;

    }

    SongNode *t = songs;    //t is pointing to head of list

    int numSongs = 0;
    while (t != 0){
        numSongs++;         //counting number of total songs
        t = t->next;
    }

    //sorting the list
    for (int i = 0; i < numSongs; i++) {
        SongNode *p = songs;        //p is pointing to head of song list after each outside iteration
        for (int j = 0; j < numSongs - 1; j++) {

            if (p->s > (p->next->s)) {

                SongNode *temp = new SongNode;


                temp->s = p->s;            //SWAP if song is greater than next song (sorting by alpha)
                p->s = p->next->s;
                p->next->s = temp->s;

                delete(temp);               //free the mem of the temp used for the swap

            }

            p = p->next;                //move down list

        }


    }

}

void UtPod ::clearMemory() {

    SongNode *p = songs;


    while(p != 0){
        delete(p);            //free memory of each node
        p = p->next;
    }

    songs = 0;              //head pointer is pointing to null

}


int UtPod ::getRemainingMemory() {

    int memUsed = 0;
    SongNode *p = songs;
    while(p !=0){
        memUsed = memUsed + p->s.getSize();      //go through list and add up each size of song to find total
        p = p->next;
    }

    int remaining = getTotalMemory() - memUsed;     //find remaining mem by subtracting used from total

    return remaining;


}

UtPod::~UtPod() {

    clearMemory();          //delete and free mem of all songs in lit using the clear mem function
}





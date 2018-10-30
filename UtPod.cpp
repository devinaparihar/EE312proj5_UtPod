#include <ctime>
#include "UtPod.h"
#include <iostream>
#include <cstdlib>


using namespace std;

UtPod ::UtPod() {

    songs = 0;       //SongNode head pointer to NULL
    memSize = MAX_MEMORY;

}

UtPod ::UtPod(int size) {
    songs = 0;
    if(size > MAX_MEMORY || size <=0)
        memSize = MAX_MEMORY;
    else
        memSize = size;
}

int UtPod ::addSong(Song const &s) {

    int remaining = getRemainingMemory();
    if((remaining - s.getSize()) < 0){
        cout << "Not enough memory available to add this song." << endl;
        return NO_MEMORY;
    }

    SongNode *temp = new SongNode;
    temp->s = s;
    temp->next = songs;             //adding song to front of list
    songs = temp;           //pointing to new head of list

    int memDec = s.getSize();
    memSize = memSize - memDec;

    return SUCCESS;

}

int UtPod ::removeSong(Song const &s) {


    SongNode *p = songs;        //p pointing to head of song list
    SongNode *p2 = songs;
    SongNode *ToBeRemoved = songs;
    while(p != 0){
        if(p->s.getTitle() == s.getTitle())
            ToBeRemoved = p;
        p = p->next;

    }

    if(ToBeRemoved == songs){           //case where removal is at head of list
        songs = ToBeRemoved->next;      //song is pointing at new head
        delete(ToBeRemoved);

        int memAdd = s.getSize();
        memSize = memSize + memAdd;

        return SUCCESS;

    }

    while(p2->next != 0 && p2->next!= ToBeRemoved) { //keep traversing until p2
        // is pointing to right before removal node
        p2 = p2->next;

    }
    if(p2->next == 0) {
        cout << "The song to be deleted is not in the list.\n";
        return NOT_FOUND;
    }

    p2->next = p2->next->next;          //skip over the node that is to be deleted

    delete(ToBeRemoved);

    int memAdd = s.getSize();
    memSize = memSize + memAdd;

    return SUCCESS;

}


void UtPod ::shuffle() {
    int total = 0;
    SongNode *p;

    p = songs;

    while (p != 0){
        total++;
        p = p->next;
    }
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);        //seeds the random number generator

    for (int i = 0; i < total; i++){
        SongNode *s1 = songs;
        SongNode *s2 = songs;
        SongNode *temp = new SongNode;

        int rand1 = rand() % total;
        int rand2 = rand() & total;

        while(rand1 == 0){
            s1 = s1->next;
            rand1--;
        }
        while(rand2 == 0){
            s2 = s2->next;
            rand2--;
        }

        temp->s = s1->s;            //SWAP
        s1->s = s2->s;
        s2->s = temp->s;
    }

}

void UtPod ::showSongList() {
    SongNode *p = songs;        //p is pointing to head of song list
    if(songs == 0)
        cout << "There are no songs on this UtPod." << endl;
    while(p != 0){
        cout << "Song Title: " << p->s.getTitle() << " Artist: " << p->s.getArtist() << endl;  //printing the song info
        p = p->next;
    }

}

void UtPod ::sortSongList() {

    if (songs == 0)    //list is empty
        return;

    SongNode *t = songs;

    int numSongs = 0;
    while (t != 0){
        numSongs++;         //counting number of songs
        t = t->next;
    }


    for (int i = 0; i < numSongs; i++) {
        SongNode *p = songs;        //p is pointing to head of song list
        //SongNode *p2 = p->next;
        for (int j = 0; j < numSongs - 1; j++) {

            if (p->s.operator>(p->next->s)) {     //WORK IN PROGRESS

                SongNode *temp = p;             //swap if first pos is greater than second pos
                p = p->next;
                p->next = temp;
            }

            p = p->next;

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

    return memSize;

}

UtPod::~UtPod() {

    clearMemory();
}



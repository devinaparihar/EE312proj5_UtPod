#include <ctime>
#include "UtPod.h"
#include <iostream>


using namespace std;

UtPod ::UtPod() {

    songs = NULL;       //SongNode head pointer to NULL
    memSize = MAX_MEMORY;

}

UtPod ::UtPod(int size) {
    songs = NULL;
    memSize = size;
}

int UtPod ::addSong(Song const &s) {
    SongNode *temp = new SongNode;
    temp->s = s;
    temp->next = songs;             //adding song to front of list
    songs = temp;                   //pointing to new head of list

    return SUCCESS;

}

int UtPod ::removeSong(Song const &s) {
    SongNode *p = songs;        //p pointing to head of song list
    SongNode *p2 = songs;
    SongNode *ToBeRemoved = songs;
    while(p !=NULL){
        if(p->s.getTitle() == s.getTitle())
            ToBeRemoved = p;
        p = p->next;

    }
    while(p2->next !=NULL && p2->next!= ToBeRemoved) { //keep traversing until p2
                                                        // is pointing to right before removal node
        p2 = p2->next;

    }
    if(p2->next == NULL) {
        cout << "The song to be deleted is not in the list.\n";
        return NOT_FOUND;
    }
    p2->next = p2->next->next;          //skip over the node that is to be deleted

    delete(ToBeRemoved);
    return SUCCESS;

}

void UtPod ::shuffle() {
    int total = 0;
    SongNode *p;
    songs = p;
    while (p != NULL){
        total++;
        p->next;
    }

    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);        //seeds the random number generator

    for (int i = 0; i < total; i++){
        SongNode *temp1 = songs;
        SongNode *temp2 = songs;

        

        }

    }

}

void UtPod ::showSongList() {
    SongNode *p = songs;        //p is pointing to head of song list
    while(p != NULL){
        cout << "Song Title: " << p->s.getTitle() << " Artist: " << p->s.getArtist() << endl;  //printing the song info
        p = p->next;
    }

}

void UtPod ::sortSongList() {


}

int UtPod ::getRemainingMemory() {


}
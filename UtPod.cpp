#include <ctime>
#include "UtPod.h"


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

}

int UtPod ::removeSong(Song const &s) {


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


}

void UtPod ::sortSongList() {


}

int UtPod ::getRemainingMemory() {


}
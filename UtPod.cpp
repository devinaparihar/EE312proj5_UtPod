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


}

void UtPod ::showSongList() {


}

void UtPod ::sortSongList() {


}

int UtPod ::getRemainingMemory() {


}
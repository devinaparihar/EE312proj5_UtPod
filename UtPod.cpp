#include <ctime>
#include "UtPod.h"
#include <iostream>


using namespace std;

UtPod ::UtPod() {

    songs = nullptr;       //SongNode head pointer to NULL
    memSize = MAX_MEMORY;

}

UtPod ::UtPod(int size) {
    songs = nullptr;
    memSize = size;
}

int UtPod ::addSong(Song const &s) {
    SongNode *temp = new SongNode;
    temp->s = s;
    temp->next = songs;             //adding song to front of list
    songs = temp;           //pointing to new head of list

    int memDec = s.getSize();
    memSize = memSize - memDec;

    return SUCCESS;

    //ADD CHECK FOR IF OUT OF MEMORY

}

int UtPod ::removeSong(Song const &s) {

    int memAdd = s.getSize();
    memSize = memSize + memAdd;

    SongNode *p = songs;        //p pointing to head of song list
    SongNode *p2 = songs;
    SongNode *ToBeRemoved = songs;
    while(p != nullptr){
        if(p->s.getTitle() == s.getTitle())
            ToBeRemoved = p;
        p = p->next;

    }
    while(p2->next != nullptr && p2->next!= ToBeRemoved) { //keep traversing until p2
                                                        // is pointing to right before removal node
        p2 = p2->next;

    }
    if(p2->next == nullptr) {
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
    while (p != nullptr){
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
    while(p != nullptr){
        cout << "Song Title: " << p->s.getTitle() << " Artist: " << p->s.getArtist() << endl;  //printing the song info
        p = p->next;
    }

}

void UtPod ::sortSongList() {
    SongNode *p = songs;        //p is pointing to head of song list
    SongNode *p2 = songs->next;

    while(p != nullptr){
        while()
        if(p2->s.operator<(p->s)){     //WORK IN PROGRESS

        }




    }


}

int UtPod ::getRemainingMemory() {
    return memSize;                     //????? decrement/increment

}
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "playlistitem.h"

class Playlist
{
public:
    Playlist();

    bool isEmpty() const;
    size_t size() const;

    void popBack(); // should remove last entry
    void popFront(); // should remove first entry

    void pushFront(const PlaylistItem& item); // should add entry to the beginning
    void pushBack(const PlaylistItem& item); // should add entry to the end

    void remove(const PlaylistItem& item); // removing by value

    PlaylistItem* find(const PlaylistItem& value); // search by value

    void setCurrentTrack(const PlaylistItem& currentTrack);
    const PlaylistItem* currentTrack() const;
    void switchNextTrack();
    void switchPreviousTrack();
    void skipForward();
    void skipBack();

private:
    void remove(PlaylistItem* item);
    void insert(const PlaylistItem& value, PlaylistItem* position); // optional

    size_t m_size;
    PlaylistItem* m_head;
    PlaylistItem* m_tail;

    PlaylistItem* m_currentTrack;
};

#endif // PLAYLIST_H
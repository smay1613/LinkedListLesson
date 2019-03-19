#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H
#include <string>

struct PlaylistItem
{
    PlaylistItem(const std::string uri) : trackURI {uri} {}
    std::string trackURI;

private:
    friend class Playlist;
    PlaylistItem* next {nullptr};
    PlaylistItem* previous {nullptr};
};

#endif // PLAYLISTITEM_H
#include "playlist.h"

Playlist::Playlist()
    : m_size {0},
      m_head {nullptr},
      m_tail {nullptr}
{
}

bool Playlist::isEmpty() const
{
    return (m_head == nullptr
            && m_tail == nullptr);
}

size_t Playlist::size() const
{
    return m_size;
}

void Playlist::popBack()
{
    remove(m_tail);
}

void Playlist::popFront()
{
    remove(m_head);
}

void Playlist::pushFront(const PlaylistItem& item)
{
/* VERSION 1:
    auto* itemCopy = new PlaylistItem {item};
    if (m_head) {
        m_head->previous = itemCopy;
        itemCopy->next = m_head;
        m_head = itemCopy;
    } else {
        m_head = itemCopy;
        m_tail = itemCopy;
    }
    ++m_size;
*/
    insert(item, m_tail);
}

void Playlist::pushBack(const PlaylistItem& item)
{
/* VERSION 1:
    auto* itemCopy = new PlaylistItem {item};
    if (m_tail) {
        m_tail->next = itemCopy;
        itemCopy->previous = m_tail;
        m_tail = itemCopy;
    } else {
        m_head = itemCopy;
        m_tail = itemCopy;
    }
    ++m_size;
*/
    insert(item, m_head);
}

void Playlist::remove(const PlaylistItem& item)
{
    PlaylistItem* entryToRemove = find(item);
    remove(entryToRemove);
}

PlaylistItem* Playlist::find(const PlaylistItem& value)
{
    PlaylistItem* entry;
    for (entry = m_head; entry != nullptr; entry = entry->next) {
        if (entry->trackURI == value.trackURI) {
            break;
        }
    }

    return entry;
}

const PlaylistItem* Playlist::currentTrack() const
{
    return m_currentTrack;
}

void Playlist::switchNextTrack()
{
    if (m_currentTrack && m_currentTrack->next) {
        m_currentTrack = m_currentTrack->next;
    }
}

void Playlist::switchPreviousTrack()
{
    if (m_currentTrack && m_currentTrack->previous) {
        m_currentTrack = m_currentTrack->previous;
    }
}

void Playlist::skipForward()
{
    m_currentTrack = m_tail;
}

void Playlist::skipBack()
{
    m_currentTrack = m_head;
}

void Playlist::remove(PlaylistItem* item)
{
    if (!item) { // nothing to remove
        return;
    }

    PlaylistItem* nextItem = item->next;
    PlaylistItem* previousItem = item->previous;

    if(previousItem) {
        previousItem->next = nextItem;
    }

    if(item->next) {
        nextItem->previous = previousItem;
    }

    if(item == m_head) {
        m_head = nextItem;
    }

    if(item == m_tail) {
        m_tail = previousItem;
    }

    delete item;

    --m_size;
}

void Playlist::setCurrentTrack(const PlaylistItem& currentTrack)
{
    m_currentTrack = find(currentTrack);
}

void Playlist::insert(const PlaylistItem& value, PlaylistItem* position)
{
    auto* itemCopy = new PlaylistItem {value};
    itemCopy->next = position;

    if(position)
    {
        itemCopy->previous = position->previous;
        position->previous = itemCopy;
    }
    else
    {
        // pos is null that is at the very end of the list
        itemCopy->previous = m_tail;
        m_tail = itemCopy;
    }

    if(itemCopy->previous)
    {
        itemCopy->previous->next = itemCopy;
    }
    else
    {
        // at the very begining of the list
        m_head = itemCopy;
    }

    ++m_size;
}

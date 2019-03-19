#include "playlist.h"

Playlist::Playlist()
	: m_size{ 0 },
	m_head{ nullptr },
	m_tail{ nullptr },
	m_currentTrack{ nullptr }
{
}

bool Playlist::isEmpty() const
{
	return true;
}

size_t Playlist::size() const
{
	return 0;
}

void Playlist::popBack()
{
}

void Playlist::popFront()
{
}

void Playlist::pushFront(const PlaylistItem& item)
{
}

void Playlist::pushBack(const PlaylistItem& item)
{
}

void Playlist::remove(const PlaylistItem& item)
{
}

PlaylistItem* Playlist::find(const PlaylistItem& value)
{
	return nullptr;
}

const PlaylistItem* Playlist::currentTrack() const
{
	return nullptr;
}

void Playlist::switchNextTrack()
{
}

void Playlist::switchPreviousTrack()
{
}

void Playlist::skipForward()
{
}

void Playlist::skipBack()
{
}

void Playlist::remove(PlaylistItem* item)
{
}

void Playlist::setCurrentTrack(const PlaylistItem& currentTrack)
{
}

void Playlist::insert(const PlaylistItem& value, PlaylistItem* position)
{

}
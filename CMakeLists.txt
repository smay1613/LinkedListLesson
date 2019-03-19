cmake_minimum_required(VERSION 2.8)

set(HEADERS
    playlistitem.h
    playlist.h
    tests.h)

set(SOURCES
    playlist.cpp)

project(TrackList)
add_executable(${PROJECT_NAME} "main.cpp"
    ${HEADERS} ${SOURCES})
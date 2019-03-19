#ifndef TESTS_H
#define TESTS_H
#include <vector>
#include <cassert>
#include <iostream>
#include "playlist.h"

struct TestFixture {
    TestFixture() {
        for (const auto& file : files) { // range for loop
            playlist.pushFront(file);
        }
    }
    static Playlist playlist;
    static const std::vector<PlaylistItem> files;
};

Playlist TestFixture::playlist {};
const std::vector<PlaylistItem> TestFixture::files { // brace enclosed list initialization
    {"1.mp3"}, // note: it will not work if PlaylistItem constructor is marked explicit
    {"2.mp3"},
    {"3.mp3"},
};

static TestFixture basicTest;

void testPushBack();
void testFind();
void testRemove();
void testPushFront();
void testPopFront();
void testPopBack();

void mainTest() {
    testPushBack();
    testPushFront();
    testFind();
    testRemove();
    testPopFront();
}

void testPushBack() {
    size_t expectedSize = TestFixture::files.size();

    assert(("Playlist size expected to has file list size after pushBack",
            TestFixture::playlist.size() == expectedSize));

    assert(("Playlist have not to be empty after pushBack",
            TestFixture::playlist.isEmpty() == TestFixture::files.empty()));

    std::cout << "Push back test passed" << std::endl;
}

void testPushFront() {
    size_t expectedSize = TestFixture::files.size() + 1;

    TestFixture::playlist.pushFront({TestFixture::files.at(1)});

    assert(("Playlist size expected to increase after pushFront",
            TestFixture::playlist.size() == expectedSize));

    assert(("Playlist have not to be empty after pushFront",
            TestFixture::playlist.isEmpty() == TestFixture::files.empty()));

    std::cout << "Push front test passed" << std::endl;
}

void testFind() {
    auto expectedValue = TestFixture::files.at(2);
    auto resultValue = TestFixture::playlist.find(expectedValue);
    assert(("Find failure for second file entry",
             resultValue->trackURI == expectedValue.trackURI));

    std::string nonexistentValue = "test.mp3";
    resultValue = TestFixture::playlist.find({nonexistentValue});
    assert(("Find failure for not existent file entry",
             resultValue == nullptr));

    std::cout << "Find test passed" << std::endl;
}

void testRemove() {
    auto entryToRemove = TestFixture::files.at(2);
    size_t sizeBeforeRemoving = TestFixture::playlist.size();

    TestFixture::playlist.remove(entryToRemove);

    size_t sizeAfterRemoving = TestFixture::playlist.size();

    assert(("Size after removing a valid entry wasn't changed",
             sizeBeforeRemoving != sizeAfterRemoving));

    TestFixture::playlist.remove(entryToRemove);

    assert(("Size after removing not existent entry changed",
            sizeAfterRemoving == TestFixture::playlist.size()));

    std::cout << "Remove test passed" << std::endl;
}

void testPopFront() {
    size_t size = TestFixture::playlist.size();
    while (size--) {
        TestFixture::playlist.popFront();
    }
    assert(("Size after popFront expected to be zero",
            0 == TestFixture::playlist.size()));
    std::cout << "Pop front test passed" << std::endl;
}

void testPopBack() {
    size_t size = TestFixture::playlist.size();
    while (size--) {
        TestFixture::playlist.popBack();
    }
    assert(("Size after popBack expected to be zero",
            0 == TestFixture::playlist.size()));
    std::cout << "Pop back test passed" << std::endl;
}

#endif // TESTS_H

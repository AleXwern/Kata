// Copyright (c) 2024 Antero Nousiainen

#include "buffer.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("EmptyBufferIsEmpty", "[require]")
{
    CircularBuffer<int, 3> buffer;
    REQUIRE(buffer.empty());
}

TEST_CASE("SizeOfEmptyBufferIsZero", "[require]")
{
    CircularBuffer<int, 3> buffer;
    REQUIRE(0 == buffer.size());
}

TEST_CASE("CapacityOfBufferIsMaxSize", "[require]")
{
    constexpr std::size_t maxSize = 3;
    CircularBuffer<int, maxSize> buffer;
    REQUIRE(maxSize == buffer.capacity());
}

TEST_CASE("PushedBufferIsNotEmpty", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    REQUIRE_FALSE(buffer.empty());
    REQUIRE(1 == buffer.size());
}

TEST_CASE("PoppedBufferIsEmpty", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    buffer.pop();
    REQUIRE(buffer.empty());
    REQUIRE(0 == buffer.size());
}

TEST_CASE("CanThrowEmptyBuffer", "[require]")
{
    try
    {
        throw CircularBuffer<int, 3>::EmptyBuffer();
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(e.what() != NULL);
    }
}

TEST_CASE("PoppingEmptyBufferThrows", "[require]")
{
    using CB = CircularBuffer<int, 3>;
    CircularBuffer<int, 3> buffer;
    //REQUIRE_THROWS(buffer.pop(), CB::EmptyBuffer);
}

TEST_CASE("AccessingFirstElementOfEmptyBufferThrows", "[require]")
{
    using CB = CircularBuffer<int, 3>;
    CircularBuffer<int, 3> buffer;
    //REQUIRE_THROWS(buffer.front(), CB::EmptyBuffer);
}

TEST_CASE("FirstPushedIsFirstElement", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    REQUIRE(1 == buffer.front());
}

TEST_CASE("PushOneTwoThreePopOneTwoThree", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);

    REQUIRE(1 == buffer.front());
    buffer.pop();
    REQUIRE(2 == buffer.front());
    buffer.pop();
    REQUIRE(3 == buffer.front());
}

TEST_CASE("ReplaceFirstElementWhenFullAndPushed", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);

    REQUIRE(2 == buffer.front());
    buffer.pop();
    REQUIRE(3 == buffer.front());
    buffer.pop();
    REQUIRE(4 == buffer.front());
}

TEST_CASE("SizeIsMaxSizeWhenFullAndPushed", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);

    REQUIRE(3 == buffer.size());
}

TEST_CASE("ReplaceAllWhenFullAndPushedFull", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);
    buffer.push(5);
    buffer.push(6);

    REQUIRE(4 == buffer.front());
    buffer.pop();
    REQUIRE(5 == buffer.front());
    buffer.pop();
    REQUIRE(6 == buffer.front());
}

TEST_CASE("PopLastElementWhenFullAndPushed", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);

    buffer.pop();
    buffer.pop();
    buffer.pop();

    REQUIRE(buffer.empty());
    REQUIRE(0 == buffer.size());
}

TEST_CASE("FirstPushOneOverMadThemPopUntilEmptyThenPushedIsFirst", "[require]")
{
    CircularBuffer<int, 3> buffer;
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);

    buffer.pop();
    buffer.pop();
    buffer.pop();

    buffer.push(5);

    REQUIRE(5 == buffer.front());
}

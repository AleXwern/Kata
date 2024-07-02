#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <stdlib.h>
#include <stdexcept>

template <class T, int N>
class CircularBuffer
{
private:
    T *data;
    size_t index = 0;
    size_t items = 0;
public:
    CircularBuffer(/* args */)
    {
        data = (T*)malloc(sizeof(T));
    }

    ~CircularBuffer()
    {
        free(data);
    }

    bool empty(void)
    {
        return items == 0;
    }

    size_t size(void)
    {
        return items;
    }

    T front(void)
    {
        if (items < 1)
            throw std::runtime_error("Buffer empty");
        size_t offset = (index + N - items) % N;
        return data[offset];
    }

    void push(T item)
    {
        data[index] = item;
        index = (index + 1) % N;
        items++;
    }

    void pop(void)
    {
        if (items < 1)
            throw std::runtime_error("Buffer empty");
        index = (index + 1) % N;
        index--;
        items--;
    }

    size_t capacity()
    {
        return N;
    }

    class EmptyBuffer : public std::runtime_error
    {
    public:
        EmptyBuffer() :
            std::runtime_error("Demotest")
        {
        }
    };
};

#endif //BUFFER_HPP
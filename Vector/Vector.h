//
// Created by ehab on 20-Feb-20.
//

#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H

#include <iostream>
using  namespace std;

template <class T>
class Vector {
    private:
        unsigned int _size , _capacity;
        T* a;

        T* refactor();
    public:
        Vector();
        Vector(int _size);
        Vector(int _size , T _initial);
        Vector(Vector<T>& _vector);
        ~Vector();

        T& operator [] ( int position );

        void resize(int _size);
        void resize(int _size , int _fillValue);

        unsigned int Size();
        unsigned int Capacity();

        void push_back( T value );
        T pop_back();

        void Insert( int position , T value );
        T* erase( int position );

        void clear();

        class iterator{
            friend class Vector<T>;

            protected:
                int index;
                T* ptr;

                iterator(T* _ptr);
                iterator( int position , T* _ptr );
            public:
                iterator operator++();
                iterator operator--();
                T& operator*();
        };

        iterator begin();
        iterator end();
        iterator rbegin();
        iterator rend();

        template <class K>
        friend ostream& operator << ( ostream& out , Vector<K>& vec );
};

#endif //UNTITLED_VECTOR_H

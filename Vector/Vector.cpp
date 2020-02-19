//
// Created by ehab on 20-Feb-20.
//

#include "Vector.h"

template <class T>
Vector<T>::Vector(){
    this->_size = 0;
    this->_capacity = 1;
    this->a = new T[this->_capacity];
}

template <class T>
Vector<T>::Vector(int _size){
    this->_size = _size;
    this->_capacity = _size;
    this->a = new T[this->_size];
}

template <class T>
Vector<T>::Vector(int _size , T _initial) : Vector(_size){
    for ( int i = 0; i < this->_size; i++ ){
        this->a[i] = _initial;
    }
}

template <class T>
Vector<T>::Vector(Vector<T>& _vector){
    this->_size         = _vector.Size();
    this->_capacity     = _vector.Capacity();
    Vector(this->_size);

    for ( int i = 0; i < this->_size; ++i ){
        this->a[i] = _vector[i];
    }
}


template <class T>
Vector<T>::~Vector(){
    delete [] this->a;
    this->_capacity = 0;
    this->_size = 0;
}

template <class T>
T* Vector<T>::refactor(){
    this->_capacity *= 2;
    T* _copy = new T[this->_capacity];

    for ( int i = 0; i < this->_size; ++i ){
        _copy[i] = this->a[i];
    }
    delete[] this->a;
    this->a = _copy;
}

template <class T>
T& Vector<T>::operator [] ( int position ){
    return this->a[position];
}

template <class T>
void Vector<T>::resize(int _size){
    if ( _size < 0 )
        return;
    if ( _size > _capacity )
        this->refactor();

    this->_size = _size;
}

template <class T>
void Vector<T>::resize(int _size , int _fillValue){
    this->resize();
    for ( int i = 0; i < this->_size; ++i ){
        this->a[i] = _fillValue;
    }
}

template <class T>
unsigned int Vector<T>::Size(){
    return  this->_size;
}

template <class T>
unsigned int Vector<T>::Capacity(){
    return  this->_capacity;
}

template <class T>
void Vector<T>::push_back( T value ){
    if ( this->_size == this->_capacity ){
        this->refactor();
    }
    this->a[ this->_size++ ] = value;
}

template <class T>
T Vector<T>::pop_back(){
    return  this->a[ this->_size-- ];
}

template <class T>
void Vector<T>::Insert( int position , T value ){
    this->push_back(value);
    for ( int i = this->_size - 1; i != position; --i ){
        if ( i > 0 ){
            this->a[i] = this->a[i - 1];
        }
    }
    this->a[ position ] = value;
}

template <class T>
T* Vector<T>::erase( int position ){
    for ( int i = position; i < this->_size; ++i ){
        if ( i + 1 < this->_size ){
            this->a[i] = this->a[i + 1];
        }
    }
    this->_size--;
}

template <class T>
void Vector<T>::clear(){
    this->_size = 0;
    this->_capacity = 1;

    delete[] this->a;
    this->a = new T[this->_capacity];
}


template <class T>
typename Vector<T>::iterator Vector<T>::begin(){
    Vector<T>::iterator itr(0 , this->a);
    return itr;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end(){
    Vector<T>::iterator itr(this->_size - 1 , this->a);
    return itr;
}

template <class T>
typename Vector<T>::iterator Vector<T>::rbegin(){
    return this->end();
}

template <class T>
typename Vector<T>::iterator Vector<T>::rend(){
    return this->begin();
}

template <class T>
Vector<T>::iterator::iterator( T* _ptr ) {
    this->ptr = _ptr;
    this->index = 0;
}

template <class T>
Vector<T>::iterator::iterator(int position , T* _ptr) : iterator(_ptr) {
    this->index = position;
}

template <class T>
typename Vector<T>::iterator Vector<T>::iterator::operator++(){
    this->index++;
}

template <class T>
typename Vector<T>::iterator Vector<T>::iterator::operator--(){
    this->index--;
}

template <class T>
T& Vector<T>::iterator::operator*(){
    return this->ptr[ this->index ];
}


template <class K>
ostream& operator << ( ostream& out , Vector<K>& vec ){
    for ( int i = 0; i < vec.Size(); ++i )
        out << vec[i] << " ";
    return out;
}
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Vector {
    // Vector's redefinition
   public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = value_type*;
    using pointer = value_type*;
    using const_iterator = const value_type*;
    using size_type = size_t;
    
    // Additional functions to simplify the code
   private:
    void do_destruct() noexcept {
        this->clear();
        operator delete(this->m_pElements);
    };

    // ---------------------------------------------------------------------- //
   public:
    Vector()
        : m_nSize(), m_pElements(), m_nCapacity(){};  // creates an empty vector

    Vector(int size) : m_nSize(), m_pElements(), m_nCapacity(size) {
        this->m_pElements =
            static_cast<pointer>(operator new(size * sizeof(value_type)));
    };  // creates a vector for holding 'size' elements

    Vector(const Vector& r) {
        this->m_nCapacity = r.m_nCapacity;
        this->m_nSize = 0;
        this->m_pElements = static_cast<pointer>(operator new(
            r.m_nCapacity * sizeof(value_type)));  // Operator new
        try {  // Placement new
            for (size_type k = 0; k < r.m_nSize; ++k) {
                new (&this->m_pElements[k]) T(r.m_pElements[k]);
                ++(this->m_nSize);
            }
        } catch (...) { // Throw error
            for (size_type k = 0; k < this->m_nSize; ++k) {
                this->m_pElements[k].~T();
            }
            operator delete(this->m_pElements);
            cerr << "bad_allocation" << endl;
            throw out_of_range("index out of range.");
        }
    };  // the copy ctor

    ~Vector() { this->do_destruct(); };  // destructs the vector

    reference operator[](int index) {
        return *(this->m_pElements + index);
    };  // accesses the specified element without bounds checking

    reference at(int index) {
        if (index < 0 || index >= this->m_nSize) {
            throw out_of_range("index out of range.");
        }
        return *(this->m_pElements + index);
    };  // accesses the specified element, throws an exception of
        // type 'std::out_of_range' when index <0 or >=m_nSize

    int size() const {
        return this->m_nSize;
    };  // return the size of the container

    void push_back(const T& x) {
        if (this->m_nSize == this->m_nCapacity) {
            inflate();
        }
        size_type k = this->m_nSize;
        new (&this->m_pElements[k]) T(x);
        ++(this->m_nSize);
    };  // adds an element to the end

    void clear() {
        for (size_type k = 0; k < this->m_nSize; ++k) {
            this->m_pElements[k].~T();
        }
        this->m_nSize = 0;
    };  // clears the contents

    bool empty() const {
        return this->m_nSize == 0;
    };  // checks whether the container is empty

   private:
    void inflate() {
        this->m_nCapacity <<= 1;
        auto new_pElements = static_cast<pointer>(operator new(
            this->m_nCapacity * sizeof(value_type)));  // Operator new
        size_type new_size = 0;
        try {  // Placement new
            for (size_type k = 0; k < this->m_nSize; ++k) {
                new (&new_pElements[k]) T(move(this->m_pElements[k]));
                ++(new_size);
            }
        } catch (...) { // Throw error
            for (size_type k = 0; k < this->m_nSize; ++k) {
                new_pElements[k].~T();
            }
            operator delete(new_pElements);
            cerr << "bad_allocation" << endl;
            throw;
        }
        this->do_destruct();

        this->m_pElements = new_pElements;
        this->m_nSize = new_size;
    };  // expand the storage of the container to a new capacity,
        // e.g. 2*m_nCapacity

    T* m_pElements;   // pointer to the dynamically allocated storage
    int m_nSize;      // the number of elements in the container
    int m_nCapacity;  // the number of elements that can be held in currently
                      // allocated storage
};

#endif
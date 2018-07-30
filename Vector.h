#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <Iterator.h>
#include <IteratorTypes.h>
#include "Iterator.h"

namespace sctoys
{
template <typename T>
class Vector
{
  public:
    typedef T* Pointer;
    typedef NormalIterator<Pointer, Vector> Iterator;
    Vector() : cur_(nullptr), size_(0), capacity_(0) {}
    Iterator Begin() const noexcept {
        return Iterator(this->cur_);
    }
    Iterator End() const noexcept { return cur_ + size_; }
    void PushBack(const T &val)
    {
        if (size_ >= capacity_)
        {
            Alloc(size_ * 2);
        }
        cur_[size_++] = val;
    }
    std::size_t Size() { return size_; }

  private:
    void Alloc(std::size_t n)
    {
        T *p = new T[n];
        for (std::size_t i = 0; i < size_; ++i)
        {
            p[i] = cur_[i];
        }
        delete cur_;
        cur_ = p;
        capacity_ = n;
    }
    Pointer cur_;
    std::size_t size_;
    std::size_t capacity_;
};
}; // namespace sctoys
#endif
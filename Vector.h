#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <Iterator.h>

namespace sctoys
{
template <typename T>
class Vector
{
  public:
    typedef T *Iterator;
    typedef const T *ConstIterator;
    Vector() : data_(nullptr), size_(0), capacity_(0) {}
    Iterator Begin() const { return data_; }
    Iterator End() const { return data_ + size_; }
    void PushBack(const T &val)
    {
        if (size_ >= capacity_)
        {
            Alloc(size_ * 2);
        }
        data_[size_++] = val;
    }
    std::size_t Size() { return size_; }

  private:
    void Alloc(std::size_t n)
    {
        T *p = new T[n];
        for (std::size_t i = 0; i < size_; ++i)
        {
            p[i] = data_[i];
        }
        delete data_;
        data_ = p;
        capacity_ = n;
    }
    T *data_;
    std::size_t size_;
    std::size_t capacity_;
};
}; // namespace sctoys
#endif
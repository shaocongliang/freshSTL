#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <FIteratorTypes.h>
#include <FIterator.h>
#include <FAlgorithm.h>
#include <FAllocator.h>
namespace shaocong
{
template <typename T>
class FVector
{
  public:
    typedef T* Pointer;
    typedef T& Reference;
    typedef NormalIterator<Pointer, FVector> Iterator;
    FVector():pBegin_(nullptr), pCur_(nullptr),pEndOfStorage_(nullptr) {}
    Iterator Begin() const noexcept {
        return Iterator(this->pBegin_);
    }
    Iterator End() const noexcept { return pEndOfStorage_; }
    std::size_t Size() const { return pCur_-pBegin_; }
    std::size_t Capacity() const { return pEndOfStorage_-pBegin_;}
    void PushBack(const T &val)
    {
        if (Size() >= Capacity())
        {
            std::size_t newCapa = Size() == 0? 1 : Size()*2;
            Pointer newDst = Allocate<T>(newCapa);
            pCur_ = Copy(pBegin_, pCur_, newDst);
            Deallocate<T>(pBegin_);
            pBegin_ = newDst;
            pEndOfStorage_ = pBegin_ + newCapa;
        }
        *pCur_++ = val;
    }

  private:
    Pointer pBegin_;
    Pointer pCur_;
    Pointer pEndOfStorage_;
};
}; // namespace sctoys
#endif
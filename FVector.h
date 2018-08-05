#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <FIteratorTypes.h>
#include <FIterator.h>
#include <FAlgorithm.h>
#include <FAllocator.h>

namespace shaocong {
    template<typename T>
    class FVector {
    public:
        typedef T *Pointer;
        typedef T &Reference;
        typedef NormalIterator<Pointer, FVector> Iterator;

        explicit FVector(std::size_t nitem) {
        }

        FVector() : pBegin_(nullptr), pCur_(nullptr), pEndOfStorage_(nullptr) {}

        Iterator Begin() const noexcept {
            return Iterator(this->pBegin_);
        }

        Iterator End() const noexcept { return Iterator(pEndOfStorage_); }

        std::size_t Size() const noexcept { return pCur_ - pBegin_; }

        std::size_t Capacity() const noexcept { return pEndOfStorage_ - pBegin_; }
        void PushBack(const T &val) {
            if (Size() >= Capacity()) {
                std::size_t newCapa = Size() == 0 ? 1 : Size() * 2;
                Alloc(newCapa);
            }
            *pCur_++ = val;
        }

    private:
        void Alloc(std::size_t nitem) {
            Pointer newDst = Allocate<T>(sizeof(T)*nitem);
            pCur_ = Copy(pBegin_, pCur_, newDst);
            Deallocate<T>(pBegin_);
            pBegin_ = newDst;
            pEndOfStorage_ = pBegin_ + nitem;
        }
        Pointer pBegin_;
        Pointer pCur_;
        Pointer pEndOfStorage_;
    };
}; // namespace sctoys
#endif
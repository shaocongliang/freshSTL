//
// Created by 少聪 on 2018/7/30.
//

#ifndef FRESHSTL_ITERATOR_H
#define FRESHSTL_ITERATOR_H

#include <IteratorTypes.h>

namespace sctoys {
    template<typename Iterator, typename Container>
    class NormalIterator {
    private:
        Iterator cur_;
    public:
        typedef IteratorTraits <Iterator> TraitsType;
        typedef typename TraitsType::ValueType ValueType;
        typedef typename TraitsType::IteratorCategory IteratorCategory;
        typedef typename TraitsType::DistanceType DistanceType;
        typedef typename TraitsType::PointerType PointerType;
        typedef typename TraitsType::ReferenceType ReferenceType;

        ValueType operator*() {
            return *cur_;
        }

        explicit NormalIterator(Iterator iter) :
                cur_(iter) {}

        NormalIterator &operator+=(const DistanceType &n) {
            cur_ += n;
            return *this;
        }
    };
}
#endif //FRESHSTL_ITERATOR_H

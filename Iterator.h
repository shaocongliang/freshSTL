/**
 * @author liangshaocong1994@gmail.com
 * @date 2018-07-29
 */
#ifndef FRESHSTL_ITERATOR_H
#define FRESHSTL_ITERATOR_H
#include <stddef.h>
namespace sctoys {
struct InputIteratorTag {};
struct OutputIteratorTag {};
struct ForwardIteratorTag : public InputIteratorTag {};
struct BidirectionalIteratorTag : public ForwardIteratorTag {};
struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};
template <typename Category, typename T, typename Difference = ptrdiff_t,
          typename Pointer = T *, typename Refernce = T &>
struct Iterator {
  typedef Category IteratorCategory;
  typedef T ValueType;
  typedef Difference DistanceType;
  typedef Pointer PointerType;
  typedef Refernce ReferenceType;
};

template <typename Iterator>
struct IteratorTraits {
  typedef typename Iterator::IteratorCategory IteratorCategory;
  typedef typename Iterator::ValueType ValueType;
  typedef typename Iterator::DistanceType DistanceType;
  typedef typename Iterator::PointerType PointerType;
  typedef typename Iterator::ReferenceType ReferenceType;
};
template <typename T>
struct IteratorTraits<T *> {
  typedef RandomAccessIteratorTag IteratorCategory;
  typedef T ValueType;
  typedef ptrdiff_t DistanceType;
  typedef T *PointerType;
  typedef T &ReferenceType;
};
template <typename Iterator, typename Distance>
void __advance(Iterator &it, Distance n, const InputIteratorTag &iiter) {
  while (n--) {
    it++;
  }
}

template <typename Iterator, typename Distance>
void __advance(Iterator &it, Distance n, const RandomAccessIteratorTag &riter) {
  it += n;
}

template <typename Iterator, typename Distance>
void advance(Iterator &it, Distance n) {
  __advance(it, n, IteratorTraits<Iterator>::IteratorCategory());
}
}  // namespace sctoys
#endif
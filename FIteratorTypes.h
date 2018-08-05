/**
 * @author liangshaocong1994@gmail.com
 * @date 2018-07-29
 */
#ifndef FRESHSTL_ITERATOR_TYPES_H
#define FRESHSTL_ITERATOR_TYPES_H
#include <stddef.h>
namespace shaocong {
struct InputIteratorTag {};
struct OutputIteratorTag {};
struct ForwardIteratorTag : public InputIteratorTag {};
struct BidirectionalIteratorTag : public ForwardIteratorTag {};
struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};
template <typename Category, typename T, typename Distance = ptrdiff_t,
          typename Pointer = T *, typename Refernce = T &>
struct Iterator {
  typedef Category IteratorCategory;
  typedef T ValueType;
  typedef Distance DistanceType;
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
template <typename Iter>
inline typename IteratorTraits<Iter>::IteratorCategory GetIteratorCategory(){
    return typename IteratorTraits<Iter>::IteratorCategory();
}
template <typename Iter, typename Distance>
void __advance(Iter &it, Distance n, const RandomAccessIteratorTag &riter) {
  it += n;
}

template <typename Iter, typename Distance>
void advance(Iter &it, Distance n) {
  __advance(it, n, GetIteratorCategory<Iter>());
}
}  // namespace sctoys
#endif
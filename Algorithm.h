#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "iterator.h"
namespace sctoys{
    template <typename InputIter, typename OutputIter>
    OutputIter copy(InputIter first, InputIter last, OutputIter d_first) {
        while(first != last) {
            *d_first++ = *first++;
        }
        return d_first;
    }
}
#endif
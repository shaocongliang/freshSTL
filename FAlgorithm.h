#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <FIteratorTypes.h>
namespace shaocong{
    template <typename InputIter, typename OutputIter>
    OutputIter Copy(InputIter first, InputIter last, OutputIter dstFirst) {
        while(first != last) {
            *dstFirst++ = *first++;
        }
        return dstFirst;
    }
}
#endif
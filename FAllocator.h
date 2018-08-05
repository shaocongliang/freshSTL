/**
 * @author liangshaocong@gmail.com
 * @date 2018-0805
 */
#ifndef FRESHSTL_ALLOCATOR_H
#define FRESHSTL_ALLOCATOR_H

#include <cstddef>
#include <stdlib.h>
namespace shaocong{
    template <typename T>
    T* Allocate(std::size_t n) {
       return static_cast<T*>(malloc(sizeof(T)*n));
    }
    template <typename T>
    void Deallocate(T *hint) {
        free(hint);
    }
}
#endif //FRESHSTL_ALLOCATOR_H

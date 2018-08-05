#ifndef LIST_H
#define LIST_H
namespace shaocong
{
    template <typename T>
    struct Node{
        T value_;
        Node *next_;
        Node *prev_;
    };
class FList
{
public:
    typedef Node ValueType_;
};
} // namespace sctoys
#endif
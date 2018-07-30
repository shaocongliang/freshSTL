#ifndef LIST_H
#define LIST_H
namespace sctoys
{
    template <typename T>
    struct Node{
        T value_;
        Node *next_;
        Node *prev_;
    };
class List
{
public:
    typedef Node ValueType_;
};
} // namespace sctoys
#endif
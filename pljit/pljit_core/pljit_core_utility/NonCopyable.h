#ifndef FINAL_NON_COPYABLE_H
#define FINAL_NON_COPYABLE_H

class NonCopyable {
    protected:
    NonCopyable() = default;
    ~NonCopyable() = default;

    NonCopyable(NonCopyable const&) = delete;
    void operator=(NonCopyable const& x) = delete;
};

#endif //FINAL_NON_COPYABLE_H


template <typename T>
class LList {

private:

    struct box {
        T data;
        box *next;
    };
    
    box *first;

    box* locate(size_t i) const;

public:

    LList();
    void push(const T &data);
    void insertAt(size_t i, const T &data_);
    T getAt(size_t i) const;
    void removeAt(size_t i);
    size_t size() const;
    ~LList();
};



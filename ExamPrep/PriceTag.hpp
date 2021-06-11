
#include <vector>

template <typename T>
class PriceTag {

private:
    T data;
    double price;

public:
    PriceTag(const T product, const double price_) {
        data = product;
        price = price_;
    }
    const T& getProduct() const {
        return data;
    }

    double getPrice() const {
        return price;
    }

    void setProduct(const T& product) {
        data = product;
    }

    void setPrice(const double price_) {
        if (price_ > 0) {
            price = price_;
        }
    }

    void discount(size_t percent) {
        double sumDiscount = percent / 100 * price;
        price -= sumDiscount;
    }

    friend std::ostream& operator<<(std::ostream& os, const PriceTag &obj) {
        os << obj.getProduct();
        os << obj.getPrice();
    }
};

template <typename T>
class PriceCatalog {
private:
    std::vector<PriceTag> catalog;
public:
    PriceCatalog(const std::vector<PriceTag> &vec) {
        catalog = vec;
    }

    std::vector& operator+=(const PriceTag &obj) {
        catalog.push_back(obj);
        return *this;
    }

    friend std::ostream operator<<(std::ostream &os, const PriceCatalog &obj) {
        int size_ = obj.size();
        for (int i = 0; i < size_; ++i) {
            os << obj.vec[i] << '\n';
        }
        return os;
    }
};
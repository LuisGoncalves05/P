#include "Product.h"


class ResaleProduct: public Product {
    public:
        ResaleProduct(int id, float price, int profit_margin): Product(id, price), profit_margin(profit_margin) {}

        int get_profit_margin() const {return profit_margin; }
        
        void set_profit_margin(int margin) {
            profit_margin = margin;
        }

        float get_sell_price() const {
            return price_ * (100 + profit_margin) /100.0;
        }
    private:
        int profit_margin;
};
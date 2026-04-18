#ifndef ARTICLE_HPP
#define ARTICLE_HPP
#include <string>
class Article
{
private:
    std::string m_name;
    double m_price;
    int m_stock;
    std::string m_category;
    const int m_id;

public:
    Article(    const std::string& name, 
                double price,
                 int stock, 
                const std::string& category, 
                const int id);

    bool setPrice(double price);
    bool sell(int amount);
    bool restock(int amount);
    bool applyDiscount(double percent);
    double getPrice() const;
    bool isAvailable() const;
    void printInfo() const;
};
#endif
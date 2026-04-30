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
/**
 * @brief Set the Price object
 * 
 * @param price 
 * @return true 
 * @return false 
 */
    bool setPrice(double price);
    /**
     * @brief 
     * 
     * @param amount 
     * @return true 
     * @return false 
     */
    bool sell(int amount);
    /**
     * @brief 
     * 
     * @param amount 
     * @return true 
     * @return false 
     */
    bool restock(int amount);
    /**
     * @brief 
     * 
     * @param percent 
     * @return true 
     * @return false 
     */
    bool applyDiscount(double percent);
    /**
     * @brief Get the Price object
     * 
     * @return double 
     */
    double getPrice() const;
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isAvailable() const;
    /**
     * @brief 
     * 
     */
    void printInfo() const;
};
#endif
#include "Article.hpp"
#include <iostream>
#include <string>
#include <iomanip>
/**
 * @brief Construct a new Article:: Article object
 * 
 * @param name 
 * @param price 
 * @param stock 
 * @param category 
 * @param id 
 */
Article::Article(const std::string &name, double price, int stock,
                 const std::string &category, const int id)
    : m_name(name), m_price(price), m_stock(stock), m_category(category), m_id(id)
{
}
/**
 * @brief decreases the amount of the article
 * 
 * @param amount 
 * @return true 
 * @return false 
 */
bool Article::sell(int amount)
{
    if (amount > 0 && (m_stock - amount) >= 0)
    {
        this->m_stock -= amount;
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief increases the amount of the article
 * 
 * @param amount 
 * @return true 
 * @return false 
 */
bool Article::restock(int amount)
{
    if (amount > 0)
    {
        this->m_stock += amount;
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief applies discount to the price 
 * 
 * @param percent 
 * @return true 
 * @return false 
 */
bool Article::applyDiscount(double percent)
{
    if (percent > 0 && percent < 100)
    {
        this->m_price = m_price - m_price * percent / 100;
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief  return of Price
 * 
 * @return double 
 */
double Article::getPrice() const
{
    return m_price;
}
/**
 * @brief check whether it is still available or not
 * 
 * @return true 
 * @return false 
 */
bool Article::isAvailable() const
{
    if (m_stock > 0)
        return true;
    else
        return false;
}
/**
 * @brief prints all infos
 * 
 * @return true 
 *
 */
void Article::printInfo() const
{
    std::cout << "----------------------" << std::endl;
    std::cout << "Article: " << m_name << std::endl;
    std::cout << "Category: " << m_category << std::endl;
    std::cout << "Price: " << m_price << std::endl;
    std::cout << "Stock: " << m_stock << std::endl;
    std::cout << "ID: " << m_id << std::endl;
    std::cout << "----------------------" << std::endl;
}

;

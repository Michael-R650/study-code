#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
class SensorFailureError: public std::runtime_error{
public: 
SensorFailureError(): std::runtime_error("Sensor is unreachable"){}

};

class Sensor
{
private:
    std::string sensor_name;
    double value;
    const double MIN_VALUE;
    const double MAX_VALUE;

public:
/**
 * @brief Construct a new Sensor object
 * 
 * @param sensor_name 
 * @param value 
 * @param min_value 
 * @param max_value 
 */
    Sensor(std::string sensor_name, double value, double min_value, double max_value) : sensor_name(sensor_name),
                                                                                        value(value),
                                                                                        MIN_VALUE(min_value),
                                                                                        MAX_VALUE(max_value)
    {
        if (MIN_VALUE >= MAX_VALUE)
        {
            throw std::invalid_argument("MIN and MAX Value are the same or MIN is bigger than MAX\n");
        }

        if (value > MAX_VALUE)
        {
            throw std::invalid_argument("Value to big\n");
        }
        else if (value < MIN_VALUE)
        {
            throw std::invalid_argument("Value to small\n");
        }
    }
    /**
     * @brief 
     * 
     * @param value 
     */
    void update_value(double value)
    {
        if (value > MAX_VALUE)
        {
            throw std::out_of_range("Value to big\n");
        }
        else if (value < MIN_VALUE)
        {
            throw std::out_of_range("Value to small\n");
        }
        else
        {
            this->value = value;
        }
    }
    /**
     * @brief Get the value object
     * 
     * @return double 
     */
    double get_value() const
    {
        return value;
    }
    /**
     * @brief 
     * 
     */
    void print_info() const
    {
        std::cout << "------------------------------\n";
        std::cout << std::setw(15) << "Sensorname:" << std::setw(15) << sensor_name << std::endl;
        std::cout << std::setw(15) << "Min Value:" << std::setw(15) << MIN_VALUE << std::endl;
        std::cout << std::setw(15) << "Miax Value:" << std::setw(15) << MAX_VALUE << std::endl;
        std::cout << std::setw(15) << "Current Value" << std::setw(15) << value << std::endl;
        std::cout << "------------------------------\n";
    }
    void simulate_failure()const{
        throw SensorFailureError();
    }
};
int main()
{
    /*Das Problem hierbei ist, dass das Objekt nicht langlebig ist und nur im try catch lebt.
    Sofern  es zu einem catch kommt, wird ein "kaputtes" Objekt erstellt
    */
    try
    {
        Sensor sensor1("Temperature", 13, 15, 100);
    }
    catch (const std::exception &error)
    {
        std::cout << error.what();
    }
    try
    {
        Sensor sensor2("Temperature", 130, 15, 100);
    }
    catch (const std::exception &error)
    {
        std::cout << error.what();
    }
    try
    {
        Sensor sensor3("Temperature", 13, 100, 100);
    }
    catch (const std::exception &error)
    {
        std::cout << error.what();
    }
    try
    {
        Sensor sensor4("Hummidity", 13, 0, 100);
        sensor4.print_info();
        sensor4.update_value(101);
    }
    catch (const std::exception &error)
    {
        std::cout << error.what();
    }

    try
    {
        Sensor sensor1("Temperature", 13, 15, 100);
        Sensor sensor2("Temperature", 130, 15, 100);
        Sensor sensor3("Temperature", 13, 100, 100);
    }
    catch (const std::invalid_argument &error)
    {
        std::cout << error.what();
    }
    catch (const std::out_of_range &error)
    {
        std::cout << error.what();
    }
    catch (const std::exception &error)
    {
        std::cout << error.what();
    }
    catch (...)
    {
        std::cout<<"undifined error";
    }
    try {
        Sensor sensor1("Temperature", 13, 0, 100);
        sensor1.simulate_failure();
    }
    catch(const SensorFailureError &error){
        std::cout << error.what();
    }
    return 0;
}
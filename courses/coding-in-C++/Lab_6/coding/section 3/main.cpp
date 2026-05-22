#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <memory>
class Device
{
private:
    std::string name;
    std::string type;
    bool power = false;

public:
    /**
     * @brief Construct a new Device object
     *
     * @param name
     * @param type
     */
    Device(const std::string &name, const std::string &type) : name(name), type(type) {};
    void turn_on()
    {
        power = true;
    }
    /**
     * @brief
     *
     */
    void turn_off()
    {
        power = false;
    }
    /**
     * @brief
     *
     */
    virtual void print_info() const
    {
        std::cout << std::setw(10) << "Name" << std::setw(10) << name << std::endl;
        std::cout << std::setw(10) << "Type" << std::setw(10) << type << std::endl;
        std::cout << std::setw(10) << "Power" << std::boolalpha << std::setw(10) << power << std::endl;
    }
    /**
     * @brief Destroy the Device object
     *
     */
    virtual ~Device()
    {
        std::cout << "Device deleted" << std::endl;
    }
};
class SharedDevice : public Device
{
private:
    std::string ip;
    bool connection;

public:
    SharedDevice(const std::string &name, const std::string &type, const std::string &ip, bool connection) : Device(name, type), ip(ip), connection(connection) {};
    /**
     * @brief
     *
     */
    void connect_to_network() { connection = true; }
    /**
     * @brief
     *
     */
    void disconnect_from_network() { connection = false; }
    /**
     * @brief
     *
     */
    void print_network_info() const
    {

        std::cout << std::setw(10) << "Ip" << std::setw(10) << ip << std::endl;
        std::cout << std::setw(10) << "Connection" << std::setw(10) << connection << std::endl;
    }
    void print_info() const override
    {
        Device::print_info();
        print_network_info();
    }
    /**
     * @brief Destroy the Shared Device object
     *
     */
    ~SharedDevice() override
    {
        std::cout << "Device deleted" << std::endl;
    };
};

class Room
{
private:
    std::string name;
    std::list<std::unique_ptr<Device>> container;
    std::list<std::shared_ptr<SharedDevice>> sharedContainer;

public:
    /**
     * @brief Construct a new Room object
     *
     * @param name
     */
    Room(std::string name) : name(name) {};
    /**
     * @brief
     *
     * @param dev
     */
    void add_device(std::unique_ptr<Device> dev)
    {
        container.push_back(std::move(dev));
    }
    /**
     * @brief
     *
     */
    void remove_devide_by_name()
    {
    }
    /**
     * @brief
     *
     */
    void print_device()
    {

        for (const auto &ptr : container)
        {
            ptr->print_info();
            std::cout << "----------------------\n";
        }
    }
    /**
     * @brief
     *
     */
    void add_shared_device(std::shared_ptr<SharedDevice> &dev)
    {
        sharedContainer.push_back(dev); // kei nstd::move verpflichtend???
    }

    /**
     * @brief
     *
     */
    void print_shared_devices()
    {
        for (const auto &ptr : sharedContainer)
        {
            ptr->print_info();
            std::cout << "----------------------\n";
        }
    }
};
int main()
{
    Room kitchen("kitchen");
    Room bathroom("bathroom");

    auto p1 = std::make_unique<Device>("des1", "a");
    auto p2 = std::make_unique<Device>("des2", "c");
    auto p3 = std::make_unique<Device>("des3", "a");
    auto p4 = std::make_unique<Device>("des4", "b");

    kitchen.add_device(std::move(p1));
    kitchen.add_device(std::move(p2));
    kitchen.add_device(std::move(p3));
    kitchen.add_device(std::move(p4));

    kitchen.print_device();
    if (p1 == nullptr)
    {
        std::cout << "Objekt wurde gelöscht bzw verschoben\n";
    }

    /* ------------Part 3 ------------*/
    auto p5 = std::make_shared<SharedDevice>("shdes1", "a", "196.168.16.0", false);
    std::cout << std::endl << "Amount shared pointer" << p5.use_count() << std::endl;
    kitchen.add_shared_device(p5);
    std::cout << std::endl << "Amount shared pointer" << p5.use_count() << std::endl;
    bathroom.add_shared_device(p5);
    kitchen.print_shared_devices();
    bathroom.print_shared_devices();
    std::cout << std::endl<< "Amount shared pointer" << p5.use_count() << std::endl;

    return 0;
}

/*
------------Part 2 ------------
What happens if you try to copy a std::unique_ptr? Nicht möglich
 is std::move(...) required? Da man keine 2 Unique Pointer auf eine Adresse  zeigen lassen kann
What happens to the original pointer after moving? Es wird auf den Nullpointer gesetzt.
When is the destructor automatically called? Nach dem die Klammern{} zu sind bzw am Ende des Codes
*/

/*
------------Part 3 ------------
Why are smart pointers safer than raw pointers? Da sie nach den Programm selbständig löschen bzw nach dem Gültigkeitsbereich new und delete ist nicht mehr nötig
What problem does std::unique_ptr solve? Exklusives Recht
Why can std::unique_ptr not be copied? Da es ein Pointer auf ein Objekt bzw eine Adresse ist
What problem does std::shared_ptr solve? geteiles Uhrheberrecht auf ein Objekt
What does use_count() represent? Die Anzahl der Pointer auf ein Object
Why can cyclic references become problematic with std::shared_ptr? Objekt A hat ein Pointer auf B und B auf A. Wenn man nun beide löscht bleitb bei use_count() trotzdem eine 1 übrig
Why should the base class destructor be virtual in polymorphic class hierarchies? Damit nicht nur die Basisklasse gelöscht wird, sondern das vollständige Objekt
*/
#include <iostream>
#include <stdexcept>
#include <string>

class ConfigLoader
{
public:
    void load(const std::string *filename)
    {
        if (filename->empty() == true)
        {
            throw std::logic_error("No File found");
        }else if(filename->size()<5){
            throw std::logic_error("No name found");
        }
        else if (filename->substr(filename->size()-4) != ".cfg")
        {

            throw std::logic_error("NO matching type found");
        }
        else if(*filename == "missing.cfg"){
            throw std::runtime_error("File not found");
        }
        else if(*filename == "invalid.cfg"){
            throw std::runtime_error("File is invalid");
        }
        else{
            std::cout<<"Open File";
        }

    }
};

int main()
{
    std::cout<<"start\n";
    std::string file = ".cfgg";
    try
    {
        ConfigLoader test;
        test.load(&file);
    }
    catch (const std::logic_error &error)
    {
        std::cout << error.what();
    }
    catch ( const std::runtime_error & error)
{
    std::cout <<error.what();
}
     std::cout<<"\nend\n";
    return 0;
}
//ERR54-CPP. Catch handlers should order their parameter types from most derived to least derived
#include <iostream>

class MyException: public std::exception{
    public:
        virtual const char* what() const noexcept
        {
            return "This is my exception";
        }
};

int main()
{
    try
    {
        throw MyException();
    }
    catch(const MyException& exc)//first we catch the derived exception
    {
        std::cout<<exc.what()<<std::endl;
    }
    catch(const std::exception& e)//second we try to catch the least derived exception
    {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}
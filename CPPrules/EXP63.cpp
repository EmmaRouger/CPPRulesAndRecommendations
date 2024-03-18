//EXP63-CPP. Do not rely on the value of a moved-from object
#include <iostream>
#include <string>

class MoveExample
{
    public:
        MoveExample(std::string someString)
        {
            this->string = someString;
        }

        std::string getString()
        {
            return this->string;
        }

    private:
        std::string string;
};

int main()
{
    std::string movedString = "Hello World";
    MoveExample example(std::move(movedString));

    //std::cout<<movedString<<std::endl;  //This violates the rule because the string has been moved

    std::cout<<example.getString()<<std::endl; //This is the correct way to access the movedString data now
    return 0;
}
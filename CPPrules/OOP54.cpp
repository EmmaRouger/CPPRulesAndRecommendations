//OOP54-CPP. Gracefully handle self-copy assignment
#include <iostream>

class Names{
    private:
        std::string *name;
    public:

        Names(std::string newName)
        {
            this->name = new std::string(newName);
        }

        std::string getName()
        {
            return *name;
        }

        Names& operator=(const Names &right) // This uitilizes the self-Test method
        {
            if (this != &right)//checks if you passes in the same object
            {
                try {
                    name = new std::string(*right.name);
                }
                catch (std::bad_alloc &) {
                    name = nullptr;
                    throw;
                }
            }
            return *this;
        }

        ~Names()
        {
            delete name;
        }
};

int main()
{
    Names name("Bob");
    name = name;

    std::cout<<"Data after self assignment: "<<name.getName()<<std::endl;

    return 0;
}
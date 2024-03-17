//Example of a code that is compliant with DCL56
//DCL56 states that programmers should avoid cyclical initialization of static objects
//This example uses the idea of Meyers Singleton
//Mason Myre
class a {
    static a& getInstance(){
        static a instance;
        return instance;
    }

    private:
    a() {} //preventing instantation using private constructor
    a(const a&) = delete; //deleting the copy constructor
    a& operator = (const a&) = delete; //deleting the copy assignment constructor
};

//MEM03-C. Clear sensitive information stored in reusable resources

#include <iostream>
#include <cstring>

int main()
{
    char* ssn;
    size_t size = strlen(ssn);

    ssn = "123-45-6789";

    memset(ssn, '\0',size);//sanitize
    free(ssn);//free
    ssn = nullptr;

}

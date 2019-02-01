#include <iostream>

#include "bc_unique_ptr.hpp"

class Ua {
public:
    Ua() = default;
    ~Ua() = default;
    Ua(const Ua&) = default;
    Ua(Ua&&) = default;
    Ua& operator=(const Ua&) = default;
    Ua& operator=(Ua&&) = default;

private:
    int k = 0;

};

int main()
{
    std::cout << "HELLO\n";
//    using Uauptr = gl::cpp_basecamp::unique_ptr<Ua>; 

//    Uauptr p(new Ua);
//    std::cout << p.get() << std::endl;

    std::cout << "BYE\n";
    return 0;
}

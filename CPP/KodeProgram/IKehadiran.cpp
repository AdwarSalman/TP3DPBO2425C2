#include <string>

#ifndef IKEHADIRAN_CPP
#define IKEHADIRAN_CPP

class IKehadiran {
public:
    virtual ~IKehadiran() = default;
    virtual double hitungJamKerja() const = 0;
    virtual std::string getBulanKehadiran() const = 0;
};

#endif // IKEHADIRAN_CPP
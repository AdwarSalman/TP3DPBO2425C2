#include <string>

#ifndef IKEPEMIMPINAN_CPP
#define IKEPEMIMPINAN_CPP

class IKepemimpinan {
public:
    virtual ~IKepemimpinan() = default; 
    virtual std::string ambilKeputusanStrategis() const = 0;
    virtual std::string getUnitKerja() const = 0;
};

#endif // IKEPEMIMPINAN_CPP
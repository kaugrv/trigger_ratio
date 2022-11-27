#include <iostream>
#include <math.h>


#ifndef __RATIO__HPP
#define __RATIO__HPP

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
/// \tableofcontents
/// \section instroduction_sec What for?
/// VectorD is a super tool.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li nothing
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li if Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html





template <typename T>
class Ratio {
    
    private:
        T m_num;
        T m_den;

    public :

        // constructors
        Ratio();
        Ratio(const T val);
        Ratio(const T num, const T den);
        Ratio(const Ratio &val);

        // destructor
        //~Ratio();

        // getter
        const T& num() const;
        const T& den()const;

        // operator
        Ratio operator+(const Ratio &val) const;


        // inversion 
        Ratio invert();

        // convertisseur 
        //Ratio convertFloatToRatio(float val, uint nbIter = 100);


};




// constructor

//default
template <typename T>
Ratio<T>::Ratio()
: m_num(),m_den(T(1))
{

}

template <typename T>
Ratio<T>::Ratio(const T val)
: m_num(val), m_den(1)
{

}


// version without conversion
template <typename T>
Ratio<T>::Ratio(const T num, const T den)
: m_num(num), m_den(den)
{

}

// copy
template <typename T>
Ratio<T>::Ratio(const Ratio<T> &val)
: m_num(val.m_num), m_den(val.m_den)
{

}

// GETTER
template <typename T>
const T& Ratio<T>::num() const{
    return m_num;
}

template <typename T>
const T& Ratio<T>::den() const{
    return m_den;
}

// operators
template <typename T>
Ratio<T>  Ratio<T>::operator+(const Ratio<T> &val)const{
    return Ratio<T>(m_num*val.m_den + m_den*val.m_num,m_den*val.m_den);
}


// <<
template <typename T>
std::ostream &operator<<(std::ostream &os, const Ratio<T> &val){
    os << val.num() << "/" << val.den();
    return os;
}


// inversion
template <typename T>
Ratio<T> Ratio<T>::invert(){
    return Ratio(m_den, m_num);
}

//convertisseur :
//first version, only works with positive numbers
template <typename T = int>
Ratio<T> convertFloatToRatio(double val, uint nbIter = 20){
    std::cout << val << std::endl;

    if (val == 0.) return Ratio<T>();

    if (nbIter == 0) return Ratio<T>();

    if (val < 1){
        return convertFloatToRatio(1.0/val,nbIter).invert();
    }

    int q = std::floor(val);
    return Ratio<T>(Ratio<T>(q,1)+convertFloatToRatio(val-q,nbIter-1));

}





#endif

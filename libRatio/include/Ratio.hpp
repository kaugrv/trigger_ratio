#include <iostream>


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
        //Ratio(const T val);
        Ratio(const T num, const T den);
        Ratio(const Ratio &val);

        // destructor
        //~Ratio();

        // getter
        const T& num();
        const T& den();


        // <<
        template<class U>
        friend std::ostream &operator<<(std::ostream &os, const Ratio<U> &val);

};




// constructor

//default
template <typename T>
Ratio<T>::Ratio()
: m_num(),m_den(T(1))
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

/*template <typename T>
Ratio<T>::Ratio(const T val)
:
{

}*/

template <typename T>
const T& Ratio<T>::num(){
    return m_num;
}

template <typename T>
const T& Ratio<T>::den(){
    return m_den;
}



// operators

// <<
template <typename T>
std::ostream &operator<<(std::ostream &os, const Ratio<T> &val){
    //os << val.num() << " / " << val.den();
    os << "//";

    return os;
}



#endif

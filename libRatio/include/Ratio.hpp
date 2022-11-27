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

        // getters
        const T& num() const;
        const T& den() const;

        /// \brief Multiplies 2 rationals
        /// \return The product of 2
        Ratio<T> operator*(const Ratio<T> &val) const;

        /// \brief Checks if 2 rationnals are equal
        /// \return 1 (True) or 0 (False)
        bool operator==(const Ratio<T> &val) const;
};




// constructor

// default constructor
template <typename T>
Ratio<T>::Ratio()
: m_num(),m_den(T(1))
{

}

// constructor (version without conversion)
template <typename T>
Ratio<T>::Ratio(const T num, const T den)
: m_num(num), m_den(den)
{ 
    if (num==0) {
        m_den=1;
    }

}

// copy constructor
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


// numerator getter
template <typename T>
const T& Ratio<T>::num() const{
    return m_num;
}

// denominator getter
template <typename T>
const T& Ratio<T>::den() const{
    return m_den;
}



// operators

// <<
template <typename T>
std::ostream &operator<<(std::ostream &os, const Ratio<T> &val){
    os << val.num() << "/" << val.den();
    return os;
}

// *
template <typename T>
Ratio<T> Ratio<T>::operator*(const Ratio<T> &val) const
{
	Ratio<T> result = Ratio(T(this->num()*val.num()), T(this->den()*val.den()));
    return result;
}

// ==
template <typename T>
bool Ratio<T>::operator==(const Ratio<T> &val) const
{
    return (T(this->num()==val.num()) && T(this->den()==val.den()));
}



#endif

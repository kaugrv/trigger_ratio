#include <iostream>
#include <math.h>

#ifndef __RATIO__HPP
#define __RATIO__HPP

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \tableofcontents
/// \section instroduction_sec What for?
/// Trigger Ratio Library.
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


/// \class Ratio
/// \brief Rational numbers are defined by an integer (numerator) over another integer (denominator).
template <typename T>
class Ratio {
    
    private:
        T m_num;
        T m_den;

    public:
        /// \brief Default constructor
        /// \param None
        /// \return 0/1
        Ratio(): m_num(),m_den(T(1)){}

        /// \brief Parameterized constructor (from one integer)
        /// \param val int, uint, long int...
        /// \return val/1
        template<typename U>
        Ratio(const U val): m_num(val), m_den(1) {}

        /// \brief Parameterized constructor (from two integers)
        /// \param num int, uint, long int...
        /// \param den int, uint, long int...
        /// \return num/den
        template<typename U, typename V>
        Ratio(const U num, const V den): m_num(num), m_den(den){if (num==0) m_den=1;}
        
        /// \brief Copy constructor
        /// \param val Ratio
        /// \return Copy of val
        Ratio(const Ratio &val): m_num(val.m_num), m_den(val.m_den){
        }

        /// \brief Default destructor
        ~Ratio(){}

        /// \brief Numerator getter
        const T& num() const;

        /// \brief Denominator getter
        const T& den() const;

        /// \brief Returns den/num
        Ratio invert();

        // Operators

        /// \brief Adds 2 rationals
        Ratio operator+(const Ratio &val) const;

        /// \brief Multiplies 2 rationals
        Ratio<T> operator*(const Ratio<T> &val) const;

        /// \brief Multiplies a rational with a float
        template<typename U>
        Ratio<T> operator*(const U &val) const{
            Ratio<T> res = *this*Ratio<T>(val);
            return res;
        }

        /// \brief Checks if 2 rationnals are equal
        /// \return 1 (True) or 0 (False)
        bool operator==(const Ratio<T> &val) const;
};

// <<
template <typename T>
std::ostream &operator<<(std::ostream &os, const Ratio<T> &val){
    os << val.num() << "/" << val.den();
    return os;
}

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

// inversion
template <typename T>
Ratio<T> Ratio<T>::invert(){
    return Ratio(m_den, m_num);
}

// +
template <typename T>
Ratio<T>  Ratio<T>::operator+(const Ratio<T> &val)const{
    return Ratio<T>(m_num*val.m_den + m_den*val.m_num,m_den*val.m_den);
}

// * - with two rationals
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

// converter : first version, only works with positive numbers
template <typename T = int>
Ratio<T> convertPosFloatToRatio(double val, uint nbIter = 20){
    std::cout << val << std::endl;

    if (val == 0.) return Ratio<T>();

    if (nbIter == 0) return Ratio<T>();

    if (val < 1){
        return convertPosFloatToRatio(1.0/val,nbIter).invert();
    }

    int q = std::floor(val);
    return Ratio<T>(Ratio<T>(q,1)+convertPosFloatToRatio(val-q,nbIter-1));
}

// converter : negative version
template<typename T = int>
Ratio<T> convertFloatToRatio(double val, uint nbIter = 20){
    int sign = -(std::signbit(val)*2-1);
    return convertPosFloatToRatio(sign*val,nbIter)*sign;
}


#endif

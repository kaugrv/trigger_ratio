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



/// \brief Highest common divisor (using Euclidean algorithm)
/// \param a integer
/// \param b integer
/// \return Hcd of a and b
int hcd(int a, int b) {
    if (b==0) {
        return abs(a);
    }
    else {
        return abs(hcd(b, a%b));
    }
}

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
        Ratio(const U num, const V den): m_num(num/hcd(num, den)), m_den(den/hcd(num, den)){
            // 0 = 0/1
            if (num==0) {
                m_den=1;
            }

            // denominator is positive
            if (den<0) {
                m_den = -m_den;
                m_num = -m_num;
            }
        }
        
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


        /// \brief Numerator setter
        void setNum(const T &num);

        /// \brief Denominator setter
        void setDen(const T &den);


        /// \brief Returns den/num
        Ratio invert();

        // Operators

        /// \brief Adds 2 rationals
        Ratio operator+(const Ratio &val) const;


        Ratio operator*=(const Ratio &val) const;

        /// \brief negates a rational
        Ratio operator-() const;

        /// \brief substract 2 rationals
        Ratio operator-(const Ratio &val) const;

        /// \brief Multiplies 2 rationals
        Ratio<T> operator*(const Ratio<T> &val) const;
    
        /// \brief Multiplies a rational with a scalar
        template<typename U>
        Ratio<T> operator*(const U &val) const{
            Ratio<T> res = *this*Ratio<T>(val);
            return res;
        }

        /// \brief Division of 2 rationals
        Ratio<T> operator/(const Ratio<T> &val) const;
    
        /// \brief Divides a rational by a scalar
        template<typename U>
        Ratio<T> operator/(const U &val) const{
            Ratio<T> res = *this/Ratio<T>(val);
            return res;
        }
        
        /// \brief Checks if 2 rationnals are equal
        /// \return 1 (True) or 0 (False)
        bool operator==(const Ratio<T> &val) const;

        /// \brief Checks if 2 rationnals are not equal
        /// \return 1 (True) or 0 (False)
        bool operator!=(const Ratio<T> &val) const;

        /// \brief Less than
        /// \return 1 (True) or 0 (False)
        bool operator<(const Ratio<T> &val) const;

        /// \brief Greater than
        /// \return 1 (True) or 0 (False)
        bool operator>(const Ratio<T> &val) const;

        /// \brief Less or equal than
        /// \return 1 (True) or 0 (False)
        bool operator<=(const Ratio<T> &val) const;

        /// \brief Greater or equal than
        /// \return 1 (True) or 0 (False)
        bool operator>=(const Ratio<T> &val) const;

};

// <<
template <typename T>
std::ostream &operator<<(std::ostream &os, const Ratio<T> &val){
    if (val.den()==0) {
        os << "inf";
    }
    else {
        os << val.num() << "/" << val.den();
    }
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


// numerator setter
template <typename T>
void Ratio<T>::setNum(const T &num){
    
    m_num = num;
    
    // if num = 0 => it is 0/1
    if (num == 0) {
        m_den = 1;
        return;
    }
    
    T tempNum = m_num;
    T tempDen = m_den;

    m_num = tempNum/hcd(tempNum,tempDen);
    m_den = tempDen/hcd(tempNum,tempDen);
}


// denominator setter
template <typename T>
void Ratio<T>::setDen(const T &den){
    
    // check if the sign needs to be update
    if (den < 0){
        m_den = -den;
        m_num = -m_num;
    }
    else m_den = den;

    // if den = 0 => it is 1/0 : infini
    if (den== 0) {
        m_num = 1;
        return;
    }

    T tempNum = m_num;
    T tempDen = m_den;

    m_num = tempNum/hcd(tempNum,tempDen);
    m_den = tempDen/hcd(tempNum,tempDen);
}

// inversion
template <typename T>
Ratio<T> Ratio<T>::invert(){
    return Ratio(m_den, m_num);
}

/// \brief Converter : first version, only works with positive numbers
/// \param val float, double... (value to be converted)
/// \param nbIter
/// \returns Ratio
template <typename T = int>
Ratio<T> convertPosFloatToRatio(double val, uint nbIter = 20){
    if (val == 0.) return Ratio<T>();

    if (nbIter == 0) return Ratio<T>();

    if (val < 1){
        return convertPosFloatToRatio(1.0/val,nbIter).invert();
    }

    int q = std::floor(val);
    return Ratio<T>(Ratio<T>(q,1)+convertPosFloatToRatio(val-q,nbIter-1));
}

/// \brief Converter (works with negative)
/// \param val float, double... (value to be converted)
/// \param nbIter
/// \returns Ratio
template<typename T = int>
Ratio<T> convertFloatToRatio(double val, uint nbIter = 20){
    int sign = -(std::signbit(val)*2-1);
    return convertPosFloatToRatio(sign*val,nbIter)*sign;
}

/// \brief Converts Ratio back to float/double
/// \param val Ratio
/// \returns double (by default)
template<typename T, typename U=double>
double convertRatioToFloat(Ratio<T> val){
    return U(val.num())/U(val.den());
}

// +
template <typename T>
Ratio<T> Ratio<T>::operator+(const Ratio<T> &val)const{
    return Ratio<T>(m_num*val.m_den + m_den*val.m_num,m_den*val.m_den);
}


// - unaire
template <typename T>
Ratio<T> Ratio<T>::operator-() const{
    return Ratio<T>(-m_num,m_den);
}

// - with two rationals
template <typename T>
Ratio<T> Ratio<T>::operator-(const Ratio<T> &val) const{
    return *this + -val;
}


// * - with two rationals
template <typename T>
Ratio<T> Ratio<T>::operator*(const Ratio<T> &val) const
{
	Ratio<T> result = Ratio(T(this->num()*val.num()), T(this->den()*val.den()));
    return result;
}

// / - with two rationals
template<typename T>
Ratio<T> Ratio<T>::operator/(const Ratio<T> &val) const{
	Ratio<T> result = Ratio(T(this->num()*val.den()), T(this->den()*val.num()));
    return result;
}

// ==
template <typename T>
bool Ratio<T>::operator==(const Ratio<T> &val) const
{
    return (T(this->num()==val.num()) && T(this->den()==val.den()));
}

// !=
template <typename T>
bool Ratio<T>::operator!=(const Ratio<T> &val) const
{
    return !(*this==val);
}

// <
template <typename T>
bool Ratio<T>::operator<(const Ratio<T> &val) const
{
    return (T(this->num()*val.den()) > T(val.num()*this->den()));
}

// >
template <typename T>
bool Ratio<T>::operator>(const Ratio<T> &val) const
{
    return (T(this->num()*val.den()) > T(val.num()*this->den()));
}

// <=
template <typename T>
bool Ratio<T>::operator>=(const Ratio<T> &val) const
{
    return (T(this->num()*val.den()) >= T(val.num()*this->den()));
}

// >=
template <typename T>
bool Ratio<T>::operator<=(const Ratio<T> &val) const
{
    return (T(this->num()*val.den()) <= T(val.num()*this->den()));
}




// Sqrt
template<typename T>
Ratio<T> sqrt(const Ratio<T> &val) {
	Ratio<T> result = convertFloatToRatio<T>(sqrt(convertRatioToFloat(val)));
    return result;
}


#endif

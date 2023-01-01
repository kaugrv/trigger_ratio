#include <iostream>
#include <math.h>
#include <cmath>

#ifndef __RATIO__HPP
#define __RATIO__HPP

// Doxygen menu
/// \mainpage
/// \section A Rational Numbers Library
/// \li Tristan Debeaune
/// \li Wendy Gervais
/// https://gitlab.com/rubykiara1712/trigger-ratio

/// \brief Highest common divisor (using Euclidean algorithm)
/// \param a integer
/// \param b integer
/// \return Highest common divisor of a and b
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
        Ratio(const U val): m_num(val), m_den(1) {
            if (std::is_floating_point<U>::value == true || std::is_floating_point<T>::value == true){
                throw(std::invalid_argument("can't have floating ratio"));
            }
        }

        /// \brief Parameterized constructor (from two integers)
        /// \param num int, uint, long int...
        /// \param den int, uint, long int...
        /// \return num/den
        template<typename U, typename V>
        Ratio(const U num, const V den): m_num(num/hcd(num, den)), m_den(den/hcd(num, den)){
            
            // Ratio<float> is forbidden
            if (std::is_floating_point<U>::value == true || std::is_floating_point<V>::value ==true || std::is_floating_point<T>::value == true){
                throw(std::invalid_argument("can't have floating ratio"));
            }
            
            // 0/0 = exception
            if(den == 0 && num == 0){
                throw(std::invalid_argument("can't construct 0/0"));
                return;
            }
            
            // inf = 1/0 or -1/0
            if (den==0) {
                m_num=-(std::signbit(num)*2-1);
            }

            // 0 = 0/1
            if (num==0) {
                m_den=-(std::signbit(num)*2-1);
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

        /// \brief Adds Ratio + int
        template <typename U>
        Ratio operator+(const U &scal) const{
            Ratio result = Ratio(this->num()+scal*this->den(), this->den());
            return result;
        }

        /// \brief  Adds Ratio to itself
        /// \param val 
        void operator+=(const Ratio &val);
        
        /// \brief  Adds int to itself
        /// \param val 
        void operator+=(const T &val);

        /// \brief Negates a rational
        Ratio operator-() const;

        /// \brief Substract 2 rationals
        Ratio operator-(const Ratio &val) const;

        /// \brief Subs Ratio - int
        template <typename U>
        Ratio operator-(const U &scal) const{
            Ratio result = Ratio(this->num()-scal*this->den(), this->den());
            return result;
        }

        /// \brief  Substract Ratio to itself
        /// \param val 
        void operator-=(const Ratio &val);
        
        /// \brief  Substract int to itself
        /// \param val 
        void operator-=(const T &val);

        /// \brief Multiplies 2 rationals
        Ratio<T> operator*(const Ratio<T> &val) const;
    
        /// \brief Multiplies a rational with an int
        template<typename U>
        Ratio<T> operator*(const U &val) const{
            Ratio<T> res = (*this)*Ratio<T>(val);
            return res;
        }
        
        /// \brief  Multiplies Ratio with itself
        /// \param val 
        void operator*=(const Ratio &val);
        
        /// \brief  Multiplies int with itself
        /// \param val 
        void operator*=(const T &val);

        /// \brief Division of 2 rationals
        Ratio<T> operator/(const Ratio<T> &val) const;
    
        /// \brief Divides a rational by an int
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
        if (val.num()==1){
            os << "+inf";
        }
        if (val.num()==-1){
            os << "-inf";
        }
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
    
    // checks if the sign needs to be updated
    if (den < 0){
        m_den = -den;
        m_num = -m_num;
    }
    else m_den = den;

    // if den = 0 => it is 1/0 : infinite
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

// +
template <typename T>
Ratio<T> Ratio<T>::operator+(const Ratio<T> &val)const{
    return Ratio<T>(m_num*val.m_den + m_den*val.m_num,m_den*val.m_den);
}

// +=
template <typename T>
void Ratio<T>::operator+=(const Ratio &val){
    this->setDen((*this+val).den());
    this->setNum((*this+val).num());
}

template <typename T>
void Ratio<T>::operator+=(const T &scal){
    *this+=Ratio<T>(scal);
}

// - unary minus
template <typename T>
Ratio<T> Ratio<T>::operator-() const{
    return Ratio<T>(-m_num,m_den);
}

// - with two rationals
template <typename T>
Ratio<T> Ratio<T>::operator-(const Ratio<T> &val) const{
    return *this + -val;
}

// -=
template <typename T>
void Ratio<T>::operator-=(const Ratio &val){
    this->setDen((*this-val).den());
    this->setNum((*this-val).num());
}

template <typename T>
void Ratio<T>::operator-=(const T &scal){
    *this-=Ratio<T>(scal);
}

// * with two rationals
template <typename T>
Ratio<T> Ratio<T>::operator*(const Ratio<T> &val) const
{
	Ratio<T> result = Ratio(T(this->num()*val.num()), T(this->den()*val.den()));
    return result;
}

// *=
template <typename T>
void Ratio<T>::operator*=(const Ratio &val){
    this->setDen(m_den*val.den());
    this->setNum(m_num*val.num());
}

template <typename T>
void Ratio<T>::operator*=(const T &scal){
    *this*=Ratio<T>(scal);
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
    return (T(this->num()*val.den()) < T(val.num()*this->den()));
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


#endif

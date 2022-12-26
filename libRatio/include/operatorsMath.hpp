
#include "Ratio.hpp"

/// \brief Converter : first version, only works with positive numbers
/// \param val float, double... (value to be converted)
/// \param nbIter
/// \returns Ratio
template <typename T>
Ratio<T> convertPosFloatToRatio(long double val, uint nbIter){
    if (val <= 1e-10) return Ratio<T>();

    if (nbIter == 0) return Ratio<T>();

    if (val < 1){
        return convertPosFloatToRatio<T>(1.0/val,nbIter).invert();
    }

    int q = std::floor(val);
    return Ratio<T>(Ratio<T>(q,1)+convertPosFloatToRatio<T>(val-q,nbIter-1));
}

/// \brief Converter (works with negative)
/// \param val float, double... (value to be converted)
/// \param nbIter
/// \returns Ratio
template<typename T>
Ratio<T> convertFloatToRatio(long double val, uint nbIter = 5000){
    int sign = -(std::signbit(val)*2-1);
    return convertPosFloatToRatio<T>(sign*val,nbIter)*sign;
}

/// \brief Converts Ratio back to float/double
/// \param val Ratio
/// \returns double (by default)
template<typename T, typename U=double>
double convertRatioToFloat(Ratio<T> val){
    return U(val.num())/U(val.den());
}

/// \brief Maximum between two Ratios
/// \param val1 Ratio
/// \param val2 Ratio
/// \returns The greatest of both (Ratio)
template<typename T>
Ratio<T> max(const Ratio<T> &val1, const Ratio<T> &val2 ) {
    return (val1>=val2 ? val1 : val2);
}

/// \brief Minimum between two Ratios
/// \param val1 Ratio
/// \param val2 Ratio
/// \returns The littlest of both (Ratio)
template<typename T>
Ratio<T> min(const Ratio<T> &val1, const Ratio<T> &val2 ) {
    return (val1<=val2 ? val1 : val2);
}

/// \brief Absolute Value
/// \returns Ratio
template<typename T>
Ratio<T> abs(const Ratio<T> &val) {
	return (val<Ratio<T>() ? -val : val);
}

/// \brief Mean value of a set of Rationals
template<typename T>
Ratio<T> average(Ratio <T> val) {
    return val;
}

/// \brief Mean value of a set of Rationals
/// \param Ratio any number of Ratios (function is variadic)
/// \returns Ratio
template<typename T, typename U=double, typename... Args>
Ratio<T> average(Ratio<T> first, Args... args) {
    auto N = (sizeof...(args));
    return (first + average(args...)*N)/(N+1);
}


/// \brief Square Root
/// \param Ratio
/// \returns float/double
template<typename T, typename U=double>
U sqrt(const Ratio<T> &val) {
	U result = U (sqrtf(convertRatioToFloat(val)));
    return result;
}

/// \brief Exponential
/// \param Ratio
/// \returns float/double
template<typename T, typename U=double>
U exp(const Ratio<T> &val) {
	U result = U (expf(convertRatioToFloat(val)));
    return result;
}

/// \brief Logarithm
/// \param Ratio
/// \returns float/double
template<typename T, typename U=double>
U log(const Ratio<T> &val) {
	U result = U (logf(convertRatioToFloat(val)));
    return result;
}

/// \brief Cosine
/// \param Ratio
/// \returns float/double
template<typename T, typename U=double>
U cos(const Ratio<T> &val) {
	U result = U (cosf(convertRatioToFloat(val)));
    return result;
}

/// \brief Arccosine
/// \param Ratio
/// \returns float/double
template<typename T, typename U=double>
U acos(const Ratio<T> &val) {
	U result = U (acosf(convertRatioToFloat(val)));
    return result;
}

/// \brief Sine
/// \param Ratio
/// \returns float/double
template<typename T, typename U=double>
U sin(const Ratio<T> &val) {
	U result = U (sinf(convertRatioToFloat(val)));
    return result;
}

/// \brief Arcsine
/// \param Ratio
/// \returns float/double
template<typename T, typename U=double>
U asin(const Ratio<T> &val) {
	U result = U (asinf(convertRatioToFloat(val)));
    return result;
}

/// \brief Integer part (inf)
/// \param Ratio
/// \returns int/long int
template<typename T, typename U = int>
U floor(const Ratio<T> &val) {
    return val.num()/val.den();
}

/// \brief Integer part (sup)
/// \param Ratio
/// \returns int/long int
template<typename T, typename U = int>
U ceil(const Ratio<T> &val) {
    return 1+val.num()/val.den();
}

/// \brief Power 
template<typename T, typename U, typename R=double>
R pow(const Ratio<T> &val, U n) {
	if (std::is_floating_point<U>::value == true){
        R result = powf128(convertRatioToFloat(val),n);
        return result;
    }
    
    R result = pow(val.num(),n)/pow(val.den(),n);
    return result;
}



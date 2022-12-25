
#include "Ratio.hpp"

/// \brief Maximum between two Ratios
/// \param val1 Ratio
/// \param val2 Ratio
/// \returns The greatest of both
template<typename T>
Ratio<T> max(const Ratio<T> &val1, const Ratio<T> &val2 ) {
    return (val1>=val2 ? val1 : val2);
}

/// \brief Minimum between two Ratios
/// \param val1 Ratio
/// \param val2 Ratio
/// \returns The littlest of both
template<typename T>
Ratio<T> min(const Ratio<T> &val1, const Ratio<T> &val2 ) {
    return (val1<=val2 ? val1 : val2);
}


/// \brief Square Root
template<typename T>
Ratio<T> sqrt(const Ratio<T> &val) {
	Ratio<T> result = convertFloatToRatio<T>(sqrtf(convertRatioToFloat(val)));
    return result;
}

/// \brief Absolute Value
template<typename T>
Ratio<T> abs(const Ratio<T> &val) {
	return (val<Ratio<T>() ? -val : val);
}

/// \brief Cosinus
template<typename T>
Ratio<T> cos(const Ratio<T> &val) {
	Ratio<T> result = convertFloatToRatio<T>(cosf128(convertRatioToFloat(val)));
    return result;
}

/// \brief Arcosinus
template<typename T>
Ratio<T> acos(const Ratio<T> &val) {
	Ratio<T> result = convertFloatToRatio<T>(acosf128(convertRatioToFloat(val)));
    return result;
}


/// \brief Mean value of a set of Rationals
template<typename T>
Ratio<T> average(Ratio <T> val) {
    return val;
}

/// \brief Mean value of a set of Rationals
/// \param Ratio any number (function is variadic)
template<typename T, typename U=double, typename... Args>
Ratio<T> average(Ratio<T> first, Args... args) {
    auto N = (sizeof...(args));
    return (first + average(args...)*N)/(N+1);
}

template<typename T, typename U = int>
U floor(const Ratio<T> &val) {
    return val.num()/val.den();
}

template<typename T, typename U = int>
U ceil(const Ratio<T> &val) {
    return 1+val.num()/val.den();
}

/// \brief pow (isnt really precise with floating powers)
template<typename T, typename U>
Ratio<T> pow(const Ratio<T> &val, U n) {
	if (std::is_floating_point<U>::value == true){
        Ratio<T> result = convertFloatToRatio<T>(powf128(convertRatioToFloat(val),n));
        return result;
    }
    
    Ratio<T> result = Ratio<T>(pow(val.num(),n),pow(val.den(),n));
    return result;
}


/// \brief exponential
template<typename T>
Ratio<T> exp(const Ratio<T> &val) {
	Ratio<T> result = convertFloatToRatio<T>(expf128(convertRatioToFloat(val)));
    return result;
}


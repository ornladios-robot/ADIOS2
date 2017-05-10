/*
 * Distributed under the OSI-approved Apache License, Version 2.0.  See
 * accompanying file Copyright.txt for details.
 *
 * ADIOS1Common.tcc
 *
 *  Created on: Jun 1, 2017
 *      Author: Norbert Podhorszki pnorbert@ornl.gov
 *              William F Godoy godoywf@ornl.gov
 */

#ifndef ADIOS2_TOOLKIT_INTEROP_ADIOS1_ADIOS1COMMON_TCC_
#define ADIOS2_TOOLKIT_INTEROP_ADIOS1_ADIOS1COMMON_TCC_

#include "ADIOS1Common.h"

#include "adios2/helper/adiosFunctions.h" //GetType

namespace adios
{
namespace interop
{

template <class T>
void ADIOS1Common::WriteVariable(const std::string &name, const ShapeID shapeID,
                                 const Dims ldims, const Dims gdims,
                                 const Dims offsets, const T *values)
{
    if (ReOpenAsNeeded())
    {
        if (GetADIOS1Type<T>() != adios_unknown)
        {
            DefineVariable(
                name, shapeID, GetADIOS1Type<T>(), DimsToCSVLocalAware(ldims),
                DimsToCSVLocalAware(gdims), DimsToCSVLocalAware(offsets));
            adios_write(m_ADIOSFile, name.c_str(), values);
        }
        else
        {
            throw std::invalid_argument("ERROR: ADIOS1 doesn't support type " +
                                        GetType<T>() + ", in call to Write\n");
        }
    }
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<char>() {
    return adios_byte;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<unsigned char>() {
    return adios_unsigned_byte;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<short>() {
    return adios_short;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<unsigned short>() {
    return adios_unsigned_short;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<int>() {
    return adios_integer;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<unsigned int>() {
    return adios_unsigned_integer;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<long int>() {
    return adios_long;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<unsigned long int>() {
    return adios_unsigned_long;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<long long int>() {

    return adios_long;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<unsigned long long int>() {
    return adios_unsigned_long;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<float>() {
    return adios_real;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<double>() {
    return adios_double;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<long double>() {
    return adios_unknown;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<cfloat>() {
    return adios_complex;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<cdouble>() {
    return adios_double_complex;
}

template <>
enum ADIOS_DATATYPES ADIOS1Common::GetADIOS1Type<cldouble>() {
    return adios_unknown;
}

} // end namespace interop
} // end namespace adios

#endif /* ADIOS2_TOOLKIT_INTEROP_ADIOS1_ADIOS1COMMON_TCC_ */

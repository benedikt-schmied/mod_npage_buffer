/**
 * \addtogroup mod_npage_buffer
 * \{
 * \file mod_npage_buffer.h
 *
 */

#ifndef __mod_npage_buffer_H__
#define __mod_npage_buffer_H__

////////////////////////////////////////////////////////////////////////////////
/// Includes
////////////////////////////////////////////////////////////////////////////////

/* c - runtime */
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* system */

/* own libs */

/* project */


#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/// Macros
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// type definitions, unions, structures
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// interface function
////////////////////////////////////////////////////////////////////////////////

/**************************************************************************//**
 * @brief  mod_npage_buffer__init
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__init(void *_p);

/**************************************************************************//**
 * @brief  mod_npage_buffer__cleanup
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__cleanup(void *_p);

/**************************************************************************//**
 * @brief  mod_npage_buffer__reinit
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__reinit(void *_p);

#ifdef __cplusplus
}
#endif

#endif

/** \} */
/**
 * \addtogroup mod_npage_buffer
 * \{
 * \file mod_npage_buffer.h
 *
 */

#ifndef __mod_npage_buffer_H__
#define __mod_npage_buffer_H__

////////////////////////////////////////////////////////////////////////////////
/// Includes
////////////////////////////////////////////////////////////////////////////////

/* c - runtime */
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* system */

/* own libs */

/* project */


#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/// Macros
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// type definitions, unions, structures
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// interface function
////////////////////////////////////////////////////////////////////////////////

/**************************************************************************//**
 * @brief  mod_npage_buffer__init
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__init(void *_p);

/**************************************************************************//**
 * @brief  mod_npage_buffer__cleanup
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__cleanup(void *_p);

/**************************************************************************//**
 * @brief  mod_npage_buffer__reinit
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__reinit(void *_p);

#ifdef __cplusplus
}
#endif

#endif

/** \} */

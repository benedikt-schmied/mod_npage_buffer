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

/**
 * handle definition / declaration
 */
typedef struct mod_npage_buffer_hdl_attr mod_npage_hdl_t;

/**
 * seek function
 */
typedef int (*mod_npage_buffer_seek_t)(int _fd, int _off, unsigned off);

/**
 * read function
 */
typedef int (*mod_npage_buffer_read_t)(int _fd, char *_dst, unsigned _len);

/**
 * write function
 */
typedef int (*mod_npage_buffer_write_t)(int _fd, char *_src, unsigned _len);

/**
 * attributes necessary when opening this storage
 */
struct mod_npage_buffer_attr {
    unsigned pagesz;                /*!< page size */
    mod_npage_buffer_seek_t seek;   /*!< seek callout */
    mod_npage_buffer_read_t read;   /*!< read callout */
    mod_npage_buffer_write_t write; /*!< write callout */
};

////////////////////////////////////////////////////////////////////////////////
// interface function
////////////////////////////////////////////////////////////////////////////////

/**************************************************************************//**
 * @brief  mod_npage_buffer__init
 *
 * @param [out]     *_hdl         handle
 * @param [in]      *_arg         argument
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__open(mod_npage_hdl_t *_hdl, struct mod_npage_buffer_attr *_arg);

/**************************************************************************//**
 * @brief  mod_npage_buffer__cleanup
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__close(mod_npage_hdl_t *_hdl);

/**************************************************************************//**
 * @brief  mod_npage_buffer__seek
 *
 * @param [in]    _p         description
 * @param
 *
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__seek(mod_npage_hdl_t _hdl, int _offset, unsigned _org);

/**************************************************************************//**
 * @brief  mod_npage_buffer__reinit
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__read(mod_npage_hdl_t _hdl);

/**************************************************************************//**
 * @brief  mod_npage_buffer__reinit
 *
 * @param [in,out]   _p         description
 * @return     0, if successful or < 0, if failed
 *             + '-1', initialization has failed
 * ****************************************************************************/
int mod_npage_buffer__write(mod_npage_hdl_t _hdl);

#ifdef __cplusplus
}
#endif

#endif

/** \} */

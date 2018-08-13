/**
 * \addtogroup mod_npage_buffer mod_npage_buffer
 *
 * mod_npage_buffer
 *
 *
 */

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

/* c - runtime */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/* own libraries */

/* project */
#include "mod_npage_buffer.h"

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
/// Typedefinitions, Unions, Structures
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////////////////

/**
 * attributes necessary when opening this storage
 */
struct mod_npage_buffer_hdl_attr {
    unsigned offset;    /*!< offset */
    unsigned stat;      /*!< in use = 1, unused = 0 */
    struct {
        unsigned bgn;   /*!< begin indicator */
        unsigned crr;   /*!< current indicator */
        unsigned end;   /*!< end indicator */
    } indic;
    struct mod_npage_buffer_attr cfg; /*!< configuration */
};

static struct mod_npage_buffer_hdl_attr s_mod_npage_buffer_hdl_tab;

////////////////////////////////////////////////////////////////////////////////
// Static function prototypes
////////////////////////////////////////////////////////////////////////////////

static void mod_npage_buffer__reset(mod_npage_hdl_t _hdl)
{
    /* reset the runtime attributes */
    (_hdl)->offset         = 0;
    (_hdl)->indic.bgn      = 0;
    (_hdl)->indic.crr      = 0;
    (_hdl)->indic.end      = 0;
    (_hdl)->stat           = 0;
}

////////////////////////////////////////////////////////////////////////////////
// interface function
////////////////////////////////////////////////////////////////////////////////

/**
 * @brief  mod_npage_buffer__init
 */
int mod_npage_buffer__open(mod_npage_hdl_t *_hdl, struct mod_npage_buffer_attr *_arg)
{
    /* automatic variables */
    int ret;

    /* executable statements */

    /* check functions' arguments */
    if (NULL == _hdl || NULL == _arg) {
        return -1;
    }

    (*_hdl) = s_mod_npage_buffer_hdl_tab;
    (*_hdl)->cfg->pagesz    = _arg->pagesz;
    (*_hdl)->cfg->seek      = _arg->seek;
    (*_hdl)->cfg->read      = _arg->read;
    (*_hdl)->cfg->write      = _arg->write;

    /* reset the runtime attributes */
    mod_npage_buffer__reset(*_hdl);
    return ret;
}

/**
 * @brief  mw_module_control__cleanup
 */
int mod_npage_buffer__close(mod_npage_hdl_t *_hdl)
{
    /* automatic variables */
    int ret;

    /* executable statements */
    ret = 0;

    /* check functions' arguments */
    if (NULL == _hdl) {
        return -1;
    }

    /* reset the runtime attributes */
    mod_npage_buffer__reset(*_hdl);
    return ret;
}

/**
 * @brief  mod_npage_buffer__seek
 */
int mod_npage_buffer__seek(mod_npage_hdl_t _hdl, int _offset, unsigned _org)
{
    /* automatic variables */
    int ret;

    /* executable statements */
    ret = 0;

    /* @TODO: insert your code here! */
    return ret;
}

/**
 * @brief  mod_npage_buffer__read
 */
int mod_npage_buffer__read(mod_npage_hdl_t _hdl)
{
    /* automatic variables */
    int ret;

    /* executable statements */
    ret = 0;

    /* @TODO: insert your code here! */
    return ret;
}

/**
 * @brief  mod_npage_buffer__write
 */
int mod_npage_buffer__write(mod_npage_hdl_t _hdl)
{
    /* automatic variables */
    int ret;

    /* executable statements */
    ret = 0;

    /* @TODO: insert your code here! */
    return ret;
}

/** \} */

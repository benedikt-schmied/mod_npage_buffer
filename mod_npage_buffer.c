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
    unsigned roff;      /*!< requested offset */
    unsigned boff;      /*!< buffer's offset */
    unsigned stat;      /*!< in use = 1, unused = 0 */
    struct {
        unsigned bgn;   /*!< begin indicator */
        unsigned crr;   /*!< current indicator */
        unsigned end;   /*!< end indicator */
    } indic;
    struct mod_npage_buffer_attr cfg; /*!< configuration */
    uint8_t *mem;        /*!< memory */
};

static struct mod_npage_buffer_hdl_attr s_mod_npage_buffer_hdl_tab;

////////////////////////////////////////////////////////////////////////////////
// Static function prototypes
////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
static void mod_npage_buffer__reset(mod_npage_hdl_t _hdl);

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

    ret = 0;

    (*_hdl) = &s_mod_npage_buffer_hdl_tab;
    (*_hdl)->cfg.pagesz    = _arg->pagesz;
    (*_hdl)->cfg.seek      = _arg->seek;
    (*_hdl)->cfg.read      = _arg->read;
    (*_hdl)->cfg.write     = _arg->write;

    /* reset the runtime attributes */
    mod_npage_buffer__reset(*_hdl);

    /* allocate the memory */
    (*_hdl)->mem = (char *)malloc(_arg->pagesz);

    if (ret == 0) {
        printf("everything seems to be fine\n");
    } else {
        printf("something horrible has happened\n");
    }
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

    _hdl->roff = _offset;

    /* @TODO: insert your code here! */
    return ret;
}

/**
 * @brief  mod_npage_buffer__read
 */
int mod_npage_buffer__read(mod_npage_hdl_t _hdl, char *_dst, unsigned _len)
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
int mod_npage_buffer__write(mod_npage_hdl_t _hdl, char *_src, unsigned _len)
{
    /* automatic variables */
    int ret;

    /* executable statements */

    /* check, whether it is unused */
    if (_hdl->stat != 0) {

        /* check, whether we 're within the range */
        if (_hdl->roff < _hdl->boff || _hdl->roff > _hdl->roff + _hdl->cfg.pagesz) {

            /* do a flush operation, we will not touch it */
            ret = _hdl->cfg.seek(0, _hdl->boff, 0);
            if (0 == ret) {
                _hdl->cfg.write(0, _hdl->mem, _hdl->cfg.pagesz);
            }
            if (0 == ret) {
                _hdl->stat = 0;
            }
        }
    } else {
        ret = 0;
    }

    /* now, we can go on */
    if (0 == ret){

        if (0 == _hdl->stat) {

            /* make it being in use */
            _hdl->stat = 1;

            /* calculate the offset */
            _hdl->boff      = _hdl->roff / _hdl->cfg.pagesz;

            _hdl->indic.bgn = _hdl->roff % _hdl->cfg.pagesz;

        } else {
            ;
        }

        if (_len <= _hdl->cfg.pagesz - _hdl->indic.crr) {
            memcpy(_hdl->mem, _src, _len);



        } else {
            ; /* write and flash */
        }
    }

    if (ret == 0) {
        printf("everything seems to be fine");
    } else {
        printf("something horrible has happened");
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////////////
// (static) function definition
////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
static void mod_npage_buffer__reset(mod_npage_hdl_t _hdl)
{
    /* reset the runtime attributes */
    (_hdl)->boff           = 0;
    (_hdl)->roff           = 0;
    (_hdl)->indic.bgn      = 0;
    (_hdl)->indic.crr      = 0;
    (_hdl)->indic.end      = 0;
    (_hdl)->stat           = 0;
}

/** \} */

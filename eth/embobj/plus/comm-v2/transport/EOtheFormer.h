/*
 * Copyright (C) 2011 Department of Robotics Brain and Cognitive Sciences - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
 * website: www.robotcub.org
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/

// - include guard ----------------------------------------------------------------------------------------------------
#ifndef _EOTHEFORMER_H_
#define _EOTHEFORMER_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file       EOtheFormer.h
    @brief      This header file implements public interface to the former singleton used for communication protocol
    @author     marco.accame@iit.it
    @date       09/06/2011
**/

/** @defgroup eo_theformer Object EOtheFormer
    The EOtheFormer is a singleton which is only responsible to create the content of a message in raw data form
    
    @{        
 **/


// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"
#include "EOrop.h"



// - public #define  --------------------------------------------------------------------------------------------------
// empty-section
  

// - declaration of public user-defined types ------------------------------------------------------------------------- 


 

/** @typedef    typedef struct EOtheFormer_hid EOtheFormer
    @brief      EOtheFormer is an opaque struct. It is used to implement data abstraction for the former  
                object so that the user cannot see its private fields and he/she is forced to manipulate the
                object only with the proper public functions. 
 **/  
typedef struct EOtheFormer_hid EOtheFormer;


    
// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------
// empty-section


// - declaration of extern public functions ---------------------------------------------------------------------------
 
 
 
/** @fn         extern EOtheFormer * eo_former_Initialise(void)
    @brief      Initialise the singleton EOtheFormer. 
    @return     A valid and not-NULL const pointer to the EOtheFormer singleton.
 **/
extern EOtheFormer * eo_former_Initialise(void);


/** @fn         extern EOtheFormer * eo_former_GetHandle(void)
    @brief      Gets the handle of the EOtheFormer singleton 
    @return     Constant pointer to the singleton.
 **/
extern EOtheFormer * eo_former_GetHandle(void);


/** @fn         extern uint16_t eo_former_GetSizeOfStream(EOtheFormer *p, const EOrop *rop)
    @brief      computes the size of the stream that will come out of rop.
    @param      p               The former.
    @param      rop             The ROP to send
    @return     the size of the stream
 **/
//extern uint16_t eo_former_GetSizeOfStream(EOtheFormer *p, const EOrop *rop);

/** @fn         extern eOresult_t eo_former_GetStream(EOtheFormer *p, const EOrop *rop, const uint16_t streamcapacity, uint8_t *streamdata, uint16_t *streamsize)
    @brief      Builds the packet in stream form.
    @param      p               The former.
    @param      rop             The ROP to send
    @param      streamcapacity  The capacity of the streamdata array (its allocated size)
    @param      streamdata      The stream data coming from the rop
    @param      streamsize      The stream size coming from the rop
    @return     Normally eores_OK, eores_NOK_generic upon failure.
 **/
extern eOresult_t eo_former_GetStream(EOtheFormer *p, const EOrop *rop, const uint16_t streamcapacity, uint8_t *streamdata, uint16_t *streamsize);




/** @}            
    end of group eo_theformer  
 **/

#ifdef __cplusplus
}       // closing brace for extern "C"
#endif 

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------




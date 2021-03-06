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
#ifndef _EORECEIVER_H_
#define _EORECEIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file       EOreceiver.h
    @brief      This header file implements public interface to a frame.
    @author     marco.accame@iit.it
    @date       01/11/2010
**/

/** @defgroup eo_receiver Object EOreceiver
    The EOreceiver object is used as ...
         
    @{        
 **/



// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"
#include "EOropframe.h"
#include "EOpacket.h"
#include "EOnvSet.h"
#include "EOconfirmationManager.h"
#include "EOproxy.h"
#include "EOagent.h"




// - public #define  --------------------------------------------------------------------------------------------------
// empty-section
  

// - declaration of public user-defined types ------------------------------------------------------------------------- 


/** @typedef    typedef struct EOreceiver_hid EOreceiver
    @brief      EOreceiver is an opaque struct. It is used to implement data abstraction for the datagram 
                object so that the user cannot see its private fields and he/she is forced to manipulate the
                object only with the proper public functions. 
 **/  
typedef struct EOreceiver_hid EOreceiver;


typedef struct
{
    uint16_t                capacityofropframereply; // or of packetreply in case we want to use a apcket whcih also has ipaddr and port  
    uint16_t                capacityofropinput;
    uint16_t                capacityofropreply;    
} eOreceiver_sizes_t;


typedef struct
{
    eOipv4addr_t    remipv4addr;
    uint64_t        rec_seqnum;
    uint64_t        exp_seqnum;
    uint64_t        timeoftxofcurrent;
    uint64_t        timeoftxofprevious;       
} eOreceiver_seqnum_error_t;

typedef struct
{
    eOipv4addr_t    remipv4addr;
    EOropframe      *ropframe;
} eOreceiver_invalidframe_error_t;

typedef void (*eOreceiver_void_fp_obj_t) (EOreceiver *);

typedef struct
{
    eOreceiver_void_fp_obj_t    onerrorseqnumber;       // argument is: EOreceiver*  
    eOreceiver_void_fp_obj_t    onerrorinvalidframe;    // argument is: EOreceiver*
} eOreceiver_extfn_t;

typedef struct
{
    eOreceiver_sizes_t      sizes;
    EOagent*                agent;
    eOreceiver_extfn_t      extfn;
} eOreceiver_cfg_t;


    
// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------

extern const eOreceiver_cfg_t eo_receiver_cfg_default; //= {{256, 128, 128}, NULL, {NULL}};


// - declaration of extern public functions ---------------------------------------------------------------------------
 
 
/** @fn         extern EOreceiver* eo_receiver_New(const eOreceiver_cfg_t *cfg)
    @brief      Creates a new receiver.
    @param      cfg   the configuration. If NULL, the default is used.
    @return     The pointer to the required object.
 **/
extern EOreceiver* eo_receiver_New(const eOreceiver_cfg_t *cfg);


/** @fn         extern void eo_receiver_Delete(EOreceiver *p)
    @brief      deletes a receiver.   
    @param      p               the object
 **/
extern void eo_receiver_Delete(EOreceiver *p);


/** @fn         extern eOresult_t eo_receiver_Process(EOreceiver *p, EOpacket *packet, eObool_t *thereisareply)
    @brief      Accepts the reference to a received packet from a given remote host, uses a given NVs configuration, and process
                the ropframe contained inside the packet (if valid). For each ROP it searches the NV(endpoint, id) if local operation
                or the NV(remoteip, endpoint, id) if remote operation and if found it processes it.
                If there are any reply ROPs it sets the return boolean.   
    @param      p               the object.
    @param      packet          teh received packet
    @param      nvset          if not NULL it is the NVs configuration to use, else it is used teh one passed to teh eo_receiver_New() method.
    @param      thereisareply   if not NULL its contains information about teh presence of a reply frame whoch shall be retrieved
                                with the eo_receiver_GetReply() method.
    @return     eores_OK only if the packet is valid and contains a valid ropframe, even if empty. eores_NOK_nullpointer or
                eores_NOK_generic in case of errors.
 **/
extern eOresult_t eo_receiver_Process(EOreceiver *p, EOpacket *packet, uint16_t *numberofrops, eObool_t *thereisareply, eOabstime_t *transmittedtime);


/** @fn         extern eOresult_t eo_receiver_GetReply(EOreceiver *p, EOropframe **ropframereply, eOipv4addr_t *ipv4addr, eOipv4port_t *ipv4port)
    @brief      returns the frame to be transmitted back and the destination ip address and port.
    @param      p               the object.
    @param      ropframereply   handle of the reply frame. if no rop insde, then it is just teh default empty frame.
    @return     eores_OK only if there is a non-empty ropframe to be transmitted, eores_NOK_generic if teh ropframe is available
                but it is empty, eores_NOK_nullpointer for NULL pointer errors.
 **/
extern eOresult_t eo_receiver_GetReply(EOreceiver *p, EOropframe **ropframereply);

extern const eOreceiver_seqnum_error_t * eo_receiver_GetSequenceNumberError(EOreceiver *p);

extern const eOreceiver_invalidframe_error_t * eo_receiver_GetInvalidFrameError(EOreceiver *p);


/** @}            
    end of group eo_receiver  
 **/

#ifdef __cplusplus
}       // closing brace for extern "C"
#endif 

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


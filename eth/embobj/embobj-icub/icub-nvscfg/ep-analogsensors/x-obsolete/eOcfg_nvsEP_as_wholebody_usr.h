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
#ifndef _EOCFG_NVSEP_AS_WHOLEBODY_USR_H_
#define _EOCFG_NVSEP_AS_WHOLEBODY_USR_H_


#error --> dont use: obsolete

/** @file       eOcfg_nvsEP_as_wholebody_usr.h
	@brief      This header file gives the local configuration for the ...
	@author     marco.accame@iit.it
	@date       09/06/2011
**/

/** @defgroup eo_23sdfwervcer Local configuation of the management NVs 
    Tcecece 
    
    @{		
 **/



// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"
#include "EOconstvector.h"
#include "eOcfg_nvsEP_as_wholebody_con.h"




// - public #define  --------------------------------------------------------------------------------------------------
// empty-section


// - declaration of public user-defined types ------------------------------------------------------------------------- 
// empty-section

    
// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------

extern const EOconstvector* const eo_cfg_nvsEP_as_wholebody_usr_constvector_of_EOnv_usr;

//extern eo_cfg_nvsEP_as_wholebody_t* eo_cfg_nvsEP_as_wholebody_usr_mem_local;
//extern eo_cfg_nvsEP_as_wholebody_t* eo_cfg_nvsEP_as_wholebody_usr_mem_remote;

// - pointer to memory used if variables are locally owned. the ems use this pointer. 
extern eo_cfg_nvsEP_as_wholebody_t* eo_cfg_nvsEP_as_wholebody_usr_locallyownedmemory;

// - pointers to memory used if variables are remotely owned. the pc104 used these two pointers
extern eo_cfg_nvsEP_as_wholebody_t* eo_cfg_nvsEP_as_wholebody_usr_remotelyownedmemory_loc;
extern eo_cfg_nvsEP_as_wholebody_t* eo_cfg_nvsEP_as_wholebody_usr_remotelyownedmemory_rem;



// - declaration of extern public functions ---------------------------------------------------------------------------

extern void eo_cfg_nvsEP_as_wholebody_usr_initialise(eOnvEP_t ep, void* loc, void* rem);


/** @}            
    end of group eo_23sdfwervcer  
 **/

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------





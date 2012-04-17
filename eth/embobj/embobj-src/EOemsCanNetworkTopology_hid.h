/*
 * Copyright (C) 2011 Department of Robotics Brain and Cognitive Sciences - Istituto Italiano di Tecnologia
 * Author:  Valentina Gaggero
 * email:   valentina.gaggero@iit.it
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
#ifndef _EOEMSCANNETWORKTOPOLOGY_HID_H_
#define _EOEMSCANNETWORKTOPOLOGY_HID_H_



// - doxy -------------------------------------------------------------------------------------------------------------

/*  @file       EoemsCanNetworkTopology_hid.h
	@brief      This header file gives 
	@author     valentina.gagger@iit.it
	@date       03/08/2012
**/


// - external dependencies --------------------------------------------------------------------------------------------
#include "Eocommon.h"
#include "EoUtilities.h"
#include "EOconstLookupTbl.h"

// - declaration of extern public interface ---------------------------------------------------------------------------
#include "EoemsCanNetworkTopology.h"


// - definition of the hidden struct implementing the object ----------------------------------------------------------

/** @struct     EOemsCanNetTopo_hid
    @brief      Hidden definition. Implements private data used only internally by the 
                public or private (static) functions of the object and protected data
                used also by its derived objects.
 **/  
 
struct EOemsCanNetTopo_hid 
{
    eo_emsCanNetTopo_cfg_t cfg;
    uint8_t motorBoardHashTbl[eo_emsCanNetTopo_canports_num][0xF];
    uint8_t sensorBoardHashTbl[eo_emsCanNetTopo_canports_num][0xF];
};



/********* type definitions for can location ==> netvar ptr *************************************/


typedef enum
{
  nvsType_joint_cfg             = 0,
  nvsType_joint_setPoint        = 1,
  nvsType_joint_status          = 2  
} eo_emsCanNetTopo_nvsType_joint_t;

enum {eo_emsCanNetTopo_nvsType_joint_maxnum = 3};

typedef struct
{
    eo_icubCanProto_canBoardAddress_t      boardAddr;
    eo_icubCanProto_motorAxis_t            axis;
    eo_icubCanProto_boardType_t            boardType;
    eOnvEPID_t                             joint_nvid_list[eo_emsCanNetTopo_nvsType_joint_maxnum];
} eo_emsCanNetTopo_hid_LUTbl_item_boardNvsReferences_t;


/********* type definitions for joint/sensor ==> can location *************************************/

typedef struct
{
    eOcanport_t                         canPort;
    eo_icubCanProto_canBoardAddress_t   boardAddr;
    eo_icubCanProto_motorAxis_t         axis4board; 
} eo_emsCanNetTopo_hid_LUTbl_item_joint2BoardCanLocation_t;



typedef struct
{
    eOcanport_t                        canPort;
    eo_icubCanProto_canBoardAddress_t  boardAddr; 
} eo_emsCanNetTopo_hid_LUTbl_item_sensor2BoardCanLocation_t;


#define EO_emsCanNetTopo_BOARD_CAN_ADDR_NULL             255 /**< this value is usend in joint2BoardLocation_lookupTbl */



// - declaration of extern hidden functions ---------------------------------------------------------------------------
// empty-section


#endif  // include guard

// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


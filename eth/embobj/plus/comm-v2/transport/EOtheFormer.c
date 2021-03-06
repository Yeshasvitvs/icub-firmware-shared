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

// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include "stdlib.h"
#include "EoCommon.h"
#include "string.h"
#include "EOtheMemoryPool.h"
#include "EOtheErrorManager.h"
#include "EOnv.h"
#include "EOrop_hid.h"


// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern public interface
// --------------------------------------------------------------------------------------------------------------------

#include "EOtheFormer.h"


// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern hidden interface 
// --------------------------------------------------------------------------------------------------------------------

#include "EOtheFormer_hid.h" 


// --------------------------------------------------------------------------------------------------------------------
// - #define with internal scope
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of extern variables, but better using _get(), _set() 
// --------------------------------------------------------------------------------------------------------------------
// empty-section



// --------------------------------------------------------------------------------------------------------------------
// - typedef with internal scope
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - declaration of static functions
// --------------------------------------------------------------------------------------------------------------------



// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of static variables
// --------------------------------------------------------------------------------------------------------------------

//static const char s_eobj_ownname[] = "EOtheFormer";
 
static EOtheFormer eo_theformer = 
{
    EO_INIT(.initted)       0
};




// --------------------------------------------------------------------------------------------------------------------
// - definition of extern public functions
// --------------------------------------------------------------------------------------------------------------------

 
extern EOtheFormer * eo_former_Initialise(void) 
{
    if(1 == eo_theformer.initted)
    {
        return(&eo_theformer);
    }
    
    eo_theformer.initted = 1;
  
    return(&eo_theformer);        
}    


extern EOtheFormer * eo_former_GetHandle(void) 
{
    return( (1 == eo_theformer.initted) ? (&eo_theformer) : (eo_former_Initialise()) );
}



extern eOresult_t eo_former_GetStream(EOtheFormer *p, const EOrop *rop, const uint16_t streamcapacity, uint8_t *streamdata, uint16_t *streamsize)
{   // this function requires the access to hidden types of EOrop
    uint16_t dataeffectivesize = 0;
    uint8_t  signsize = 0;
    uint8_t  timesize = 0;

    if((NULL == p) || (NULL == rop) || (NULL == streamdata) || (NULL == streamsize))
    {    
        return(eores_NOK_nullpointer);
    }

    // we assume that the rop is legal as it was formed by the EOtheAgent or extracted from a stream by EOtheParser
    // thus we dont check too much.
    if(eobool_false == eo_rop_ropcode_is_valid(rop->stream.head.ropc))
    {
        return(eores_NOK_generic); 
    }


    if(eobool_true == eo_rop_datafield_is_present(&rop->stream.head))
    {
        dataeffectivesize = eo_rop_datafield_effective_size(rop->stream.head.dsiz);
    }

    if(1 == rop->stream.head.ctrl.plussign)
    {
        signsize = 4;
    }

    if(1 == rop->stream.head.ctrl.plustime)
    {
        timesize = 8;
    }

    // we cannot put inside tha stream what is contained inside the rop
    if(streamcapacity < (sizeof(eOrophead_t) + dataeffectivesize + signsize + timesize))
    {
        return(eores_NOK_generic);
    } 
    

    // copy head into stream
    memcpy(&streamdata[0], &rop->stream.head, sizeof(eOrophead_t));
    (*streamsize) = sizeof(eOrophead_t);

    // copy data into stream if any
    if(0 != dataeffectivesize)
    {
        memcpy(&streamdata[*streamsize], rop->stream.data, dataeffectivesize);
        (*streamsize) += dataeffectivesize;
    }
    
    
    // copy sign if any
    if(0 != signsize)
    {
        *((uint32_t*) (&streamdata[*streamsize]) ) = rop->stream.sign;
        (*streamsize) += 4; // or signsize 
    }
 
    // copy time if any
    if(0 != timesize)
    {
        *((uint64_t*) (&streamdata[*streamsize]) ) = rop->stream.time;
        (*streamsize) += 8; // or timesize
    }

    
    return(eores_OK);
}


// --------------------------------------------------------------------------------------------------------------------
// - definition of extern hidden functions 
// --------------------------------------------------------------------------------------------------------------------
// empty-section



// --------------------------------------------------------------------------------------------------------------------
// - definition of static functions 
// --------------------------------------------------------------------------------------------------------------------
// empty-section



// --------------------------------------------------------------------------------------------------------------------
// - end-of-file (leave a blank line after)
// --------------------------------------------------------------------------------------------------------------------





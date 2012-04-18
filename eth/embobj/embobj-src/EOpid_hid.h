
// - include guard ----------------------------------------------------------------------------------------------------
#ifndef _EOPID_HID_H_
#define _EOPID_HID_H_


/*  @file       EOpid_hid.h
    @brief      This header file implements hidden interface to PID controller.
    @author     alessandro.scalzo@iit.it
    @date       23/03/2012
 **/


// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"

// - declaration of extern public interface ---------------------------------------------------------------------------
 
#include "EOpid.h"


// - #define used with hidden struct ----------------------------------------------------------------------------------



// - definition of the hidden struct implementing the object ----------------------------------------------------------

/** @struct     EOpid_hid
    @brief      Hidden definition. Implements private data used only internally by the 
                public or private (static) functions of the object and protected data
                used also by its derived objects.
 **/  
 
struct EOpid_hid 
{
    float A0;
    float A1;
    float A2;
    float Yn;
    float Ymax;
    float En_1;
    float En_2;
}; 


// - declaration of extern hidden functions ---------------------------------------------------------------------------


#endif  // include guard

// - end-of-file (leave a blank line after)----------------------------------------------------------------------------





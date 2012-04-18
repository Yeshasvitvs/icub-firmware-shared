
// - include guard ----------------------------------------------------------------------------------------------------
#ifndef _EOTRAJECTORY_H_
#define _EOTRAJECTORY_H_


/** @file       EOtrajectory.h
    @brief      This header file implements public interface to a motor minimum jerk trajectory generator.
    @author     alessandro.scalzo@iit.it
    @date       27/03/2012
**/

/** @defgroup eo_trajectory Object EOtrajectory
    Does something.
     
    @{        
 **/


// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"


// - public #define  --------------------------------------------------------------------------------------------------



// - declaration of public user-defined types ------------------------------------------------------------------------- 

 

/** @typedef    typedef struct EOtrajectory_hid EOtrajectory
    @brief      EOtrajectory is an opaque struct. It is used to implement data abstraction for the 
                object so that the user cannot see its private fields and he/she is forced to manipulate the
                object only with the proper public functions. 
 **/  
typedef struct EOtrajectory_hid EOtrajectory;


// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------
// empty-section


// - declaration of extern public functions ---------------------------------------------------------------------------
 
 
/** @fn         extern EOtrajectory* eo_trajectory_New(void)
    @brief      Creates a new trajectory object 
    @return     The pointer to the required object.
 **/
extern EOtrajectory* eo_trajectory_New(void);


/** @fn         extern void eo_trajectory_Set(EOtrajectory *o, float p0, float pf, float v0, float speed)
    @brief      Sets minimum jerk trajectory new start and end points, initial and average speed. When the time is 
                expired, the function always returns the trajectory end point. 
    @param      o      The pointer to the trajectory object.
    @param      p0     The start position of the trajectory.         
    @param      pf     The end position of the trajectory.
    @param      v0     The inital velocity.
    @param      speed  The average speed.
 **/
extern void eo_trajectory_Set(EOtrajectory *o, float p0, float pf, float v0, float speed);


/** @fn         extern float eo_trajectory_Step(EOtrajectory *o)
    @brief      Executes a trajectory step.
    @param      o  The pointer to the trajectory object.
    @return     The actual trajectory point value.
 **/
extern float eo_trajectory_Step(EOtrajectory *o);



/** @fn         extern float eo_trajectory_StepDelta(EOtrajectory *o)
    @brief      Executes a trajectory step.
    @param      o  The pointer to the trajectory object.
    @return     The difference between actual trajectory point value and the previous one.
 **/
extern float eo_trajectory_StepDelta(EOtrajectory *o);



/** @fn         extern float eo_trajectory_Abort(EOtrajectory *o)
    @brief      Aborts the trajectory.
    @param      o  The pointer to the trajectory object.
 **/
extern void eo_trajectory_Abort(EOtrajectory *o);

/** @}            
    end of group eo_trajectory  
 **/

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


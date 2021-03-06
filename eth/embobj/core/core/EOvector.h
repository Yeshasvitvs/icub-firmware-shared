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
#ifndef _EOVECTOR_H_
#define _EOVECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file       EOvector.h
	@brief      This header file implements public interface to a vector object.
	@author     marco.accame@iit.it
	@date       08/03/2011
**/

/** @defgroup eo_vector Object EOvector
    The EOvector allows to manipulate vectors of any item object, implementing the vector<type> template 
    of the standard C++ library.
    At creation, the EOvector receives the dimension of the item object which will contain, their maximum number
    (capacity) and optional copy and remove functions for the item objects.
    The EOvector receives a pointer to an item object and copies the pointed item inside its internal memory,
    calling the optional copy function on it or the default memcpy. When the EOvector is asked for an item object, 
    it returns a pointer to an internal item object. If the EOvector is requested to remove the item object, the 
    optional user-defined remove function is called or the default remove which set memory to zero.
    The EOvector is a base object and is used to derive a new object to manipulate specific items. 
    
    @{		
 **/


// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"



// - public #define  --------------------------------------------------------------------------------------------------
// empty-section
  

// - declaration of public user-defined types ------------------------------------------------------------------------- 


/**	@typedef    typedef struct EOvector_hid EOvector
 	@brief 		EOvector is an opaque struct. It is used to implement data abstraction for the vector 
                object so that the user cannot see its private fields and he/she is forced to manipulate the
                object only with the proper public functions. 
 **/  
typedef struct EOvector_hid EOvector;

enum { eo_vectorcapacity_dynamic = eo_sizecntnr_dynamic };

    
// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------
// empty-section


// - declaration of extern public functions ---------------------------------------------------------------------------


 
/** @fn         extern EOvector * eo_vector_New(eOsizeitem_t item_size, eOsizecntnr_t capacity, 
                                             eOres_fp_voidp_uint32_t item_init, uint32_t init_par, 
                                             eOres_fp_voidp_voidp_t item_copy, eOres_fp_voidp_t item_clear);
    @brief      Creates a new EOvector object and reserves memory for the items that will be stored in its
                inside, taking it from the memory pool.
    @param      item_size       The size in bytes of the item object managed by the EOvector.
    @param      capacity        The max number of item objects stored by the EOvector. If its value is eo_vectorcapacity_dynamic
                                then the capacity is unlimited. the container does not pre-allocates memory in here
                                but just reallocs whet it needs at every function call.
    @param      item_init       Pointer to a specialised init function for the item object to be called at
                                creation of the object for each contained item with arguments item_init(item, item_par). 
                                If NULL, memory is just set to zero.
    @param      item_par        Argument used for @e item_init(item, item_par).                                
    @param      item_copy       Pointer to a specialised copy function for the item object to be called 
                                at each copy of an item object inside the EOvector with arguments item_copy(dest, orig).
                                If NULL it will be executed a simple memcpy of the size of the item object.                                
    @param      item_clear      Pointer to a specialised remove function for the item object to be called at each 
                                removal of an item object from the EOvector. If NULL the memory inside the container
                                will be simply set to zero.
    @return     Pointer to the required EOvector object. The pointer is guaranteed to be always valid and will 
                never be NULL, because failure is managed by the memory pool.
 **/
extern EOvector * eo_vector_New(eOsizeitem_t item_size, eOsizecntnr_t capacity,
                                eOres_fp_voidp_uint32_t item_init, uint32_t init_par, 
                                eOres_fp_voidp_voidp_t item_copy, eOres_fp_voidp_t item_clear);


/** @fn         extern eOsizecntnr_t eo_vector_Capacity(EOvector * vector)
    @brief      Returns the maximum number of item objects that the EOvector is able to contain.
    @param      vector           Pointer to the EOvector object.
    @return     Max number of storable item objects.
 **/
extern eOsizecntnr_t eo_vector_Capacity(EOvector * vector);


/** @fn         extern eOsizecntnr_t eo_vector_ItemSize(EOvector * vector)
    @brief      Returns the size of the item objects that the EOvector is able to contain.
    @param      vector           Pointer to the EOvector object.
    @return     the size of item objects.
 **/
extern eOsizecntnr_t eo_vector_ItemSize(EOvector * vector);


/** @fn         extern eOsizecntnr_t eo_vector_Size(EOvector * vector)
    @brief      Returns the number of item objects that are currently stored in the EOvector.
    @param      vector           Pointer to the EOvector object. 
    @return     Number of item objects.
 **/
extern eOsizecntnr_t eo_vector_Size(EOvector * vector);


/**  @fn        extern void eo_vector_PushBack(EOvector * vector, void *p)
     @brief     Copies the item object pointed by @e p at the back of the EOvector and calls its constructor 
                @e item_ctor(p) if passed not NULL in eo_vector_New().
     @param     vector           pointer to the EOvector object.
     @param     p               pointer to the item object to be copied into the EOvector. 
 **/
extern void eo_vector_PushBack(EOvector * vector, void *p);


/** @fn         extern void* eo_vector_Back(EOvector *vector)
    @brief      Retrieves a reference to the item object in the back of the EOvector without removing it. 
    @param      vector           Pointer to the EOvector object.
    @return     Pointer to the item object (or NULL if the vector is empty).
    @warning    Before use, the returned pointer needs to be casted to the desidered object type.
 **/
extern void* eo_vector_Back(EOvector * vector);


/** @fn         extern void eo_vector_PopBack(EOvector * vector)
    @brief      Removes the item object from the back of the EOvector, calls its destructor
                @e item_dtor(p) if passed not NULL in eo_vector_new(), and finally sets memory to zero.
    @param      vector           Pointer to the EOvector object. 
    @warning    After this function call, previously obtained references to the removed item object 
                will point to zero-ed data
 **/
extern void eo_vector_PopBack(EOvector * vector); 


/**  @fn        extern void eo_vector_PushFront(EOvector * vector, void *p)
     @brief     Copies the item object pointed by @e p at the front of the EOvector and calls its constructor 
                @e item_ctor(p) if passed not NULL in eo_vector_New().
     @param     vector          pointer to the EOvector object.
     @param     p               pointer to the item object to be copied into the EOvector. 
 **/
extern void eo_vector_PushFront(EOvector * vector, void *p);


/** @fn         extern void* eo_vector_Front(EOvector *vector)
    @brief      Retrieves a reference to the item object in the front of the EOvector without removing it. 
    @param      vector           Pointer to the EOvector object.
    @return     Pointer to the item object (or NULL if the vector is empty).
    @warning    Before use, the returned pointer needs to be casted to the desidered object type.
 **/
extern void* eo_vector_Front(EOvector * vector);


/** @fn         extern void eo_vector_PopFront(EOvector * vector)
    @brief      Removes the item object from the front of the EOvector, calls its destructor
                @e item_dtor(p) if passed not NULL in eo_vector_New(), and finally sets memory to zero.
    @param      vector           Pointer to the EOvector object. 
    @warning    After this function call, previously obtained references to the removed item object 
                will point to zero-ed data
 **/
extern void eo_vector_PopFront(EOvector * vector); 


/** @fn         extern void eo_vector_clear(EOvector * vector)
    @brief      Removes all item objects from the EOvector and for each one calls its destructor 
                @e item_dtor() if passed not NULL in eo_vector_new(). Finally sets memory to zero.
    @param      vector           Pointer to the EOvector object. 
    @warning    After this function call, previously obtained references to any item object 
                will point to zero-ed data
 **/
extern void eo_vector_Clear(EOvector * vector);


/** @fn         extern void* eo_vector_At(EOvector * vector, eOsizecntnr_t pos)
    @brief      Retrieves a reference to the item object in position pos 
    @param      vector           Pointer to the EOvector object. 
    @param      pos             Position of the desired item object.
    @return     Pointer to the item object (or NULL if pos points to an empty position or 
                beyond reserved space).
    @warning    Before use, the returned pointer needs to be casted to the desidered object type.
                If the item object is a uint32_t, use: 
                uint32_t *p = (uint32_t*) eo_vector_At(vector, pos); 
 **/
extern void * eo_vector_At(EOvector * vector, eOsizecntnr_t pos);


/** @fn         extern void eo_vector_AssignOne(EOvector * vector, eOsizecntnr_t pos, void *p)
    @brief      Assigns the item pointed by @e p to the position @e pos. If pos > size, then the
                function shall resize the EOvector. A call with pos > capacity shall do nothing.
    @param      vector          Pointer to the EOvector object.
    @param      p               Item to be assigned 
    @param      pos             Position where to assign.
    @warning    If called with @e pos higher than the capacity of the EOvector, the function shall do nothing

 **/
extern void eo_vector_AssignOne(EOvector * vector, eOsizecntnr_t pos, void *p);


extern void eo_vector_Assign(EOvector * vector, eOsizecntnr_t pos, void *items, eOsizecntnr_t nitems);


/** @fn         extern void eo_vector_Resize(EOvector * vector, eOsizecntnr_t size)
    @brief      Resize the vector and calls proper constructor or destructor for the item. 
                A call with pos > capacity shall do nothing. 
    @param      vector          Pointer to the EOvector object.
    @param      size            The new size 
 **/
extern void eo_vector_Resize(EOvector * vector, eOsizecntnr_t size);



/** @fn         extern eObool_t eo_vector_Full(EOvector * vector)
    @brief      Tells if the EOvector is full
    @param      vector          Pointer to the EOvector object. 
    @return     eobool_true or eobool_false.
 **/
extern eObool_t eo_vector_Full(EOvector * vector);


/** @fn         extern eObool_t eo_vector_Empty(EOvector * vector) 
    @brief      Tells if the EOvector is empty
    @param      vector          Pointer to the EOvector object. 
    @return     eobool_true or eobool_false.
 **/
extern eObool_t eo_vector_Empty(EOvector * vector);


/** @fn         extern eObool_t eo_vector_Find(EOvector * vector, eOresult_t (matching_rule)(void *item, void *param), void *param, eOsizecntnr_t *position)
    @brief      Tells if an item is inside the vector
    @param      vector          Pointer to the EOvector object. 
    @param      matching_rule   a user-defined function which returns eores_OK when the param matches an inside item.
                                If NULL, then the match is done using a memcmp 
    @param      p               The item to find
    @param      position        if function returns eobool_true and index is not NULL, it contains the index of the found item, 
                                so that eo_vector_At(vector, position) is the wanted item.
    @return     eobool_true or eobool_false.
 **/
extern eObool_t eo_vector_Find(EOvector * vector, eOresult_t (matching_rule)(void *item, void *param), void *param, eOsizecntnr_t *position);


extern void eo_vector_Execute(EOvector *vector, void (execute)(void *item, void *param), void *param);


extern void* eo_vector_storage_Get(EOvector * vector);

extern void eo_vector_Delete(EOvector * vector);

/** @}            
    end of group eo_vector  
 **/

#ifdef __cplusplus
}       // closing brace for extern "C"
#endif 

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------



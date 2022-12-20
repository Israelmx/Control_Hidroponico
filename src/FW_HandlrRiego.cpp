/*===========================================================================*\
 * FILE: name: FW_HandlrRiego.cpp
 *===========================================================================
 * Copyright 2021 IXGL Electronics., All Rights Reserved.
 * IXGL Electronics
 *---------------------------------------------------------------------------
 * version: 1
 * derived_by: Israel Gomez
 * date_modified: 20/FEB/2022
 *----------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the Handler Riego FW
 *
 * ABBREVIATIONS:
 *   None.
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *   C Coding Standards SW REF 264.15D SW
 *
 * DEVIATIONS FROM STANDARDS:
 *
\*===========================================================================*/
/*============================================================================*\
 * Standard Header Files
\*============================================================================*/
#include <Arduino.h>

/*============================================================================*\
 * Other Header Files
\*============================================================================*/
#include "FW_HandlrRiego.h"
#include "HW_IO.h"
#include "FW_MQTT.h"
#include "FW_Debug.h"
#include "FW_Sensores.h"

/*============================================================================*\
 * Local Preprocessor #define Constants
\*============================================================================*/
#define CORRIENTE_BAJA_NO_REGAR 150.00
#define CORRIENTE_ALTA_NO_REGAR 270.00

/*============================================================================*\
 * Local Preprocessor #define MACROS
\*============================================================================*/

/*============================================================================*\
 * Local Type Declarations
\*============================================================================*/

/*============================================================================*\
 * Exported Object Definitions
\*============================================================================*/

/*============================================================================*\
 * Local Object Definitions
\*============================================================================*/

/*============================================================================*\
 * Local Function Prototypes
\*============================================================================*/

/*============================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*============================================================================*/

/*============================================================================*\
 * Expoerted Preprocessor Declaration
\*============================================================================*/

/*******************************************************************************
 * FUNCTION: Fun_Controlar_Riego
 *******************************************************************************
 * RETURN VALUE:
 *    None.
 *     
 * PARAMETERS:
 *    corriente_bomba_validar.
 *     
 * EXTERNAL REFERENCES:
 *    None.
 *     
 * DEVIATION FROM STANDARDS:
 *    None.
 *
 * -----------------------------------------------------------------------------
 * ABSTRACT:
 * -----------------------------------------------------------------------------
 * Fun que controla el riego comprobando la corriente de bomba
 * 
 * PRECONDITIONS:
 * Debe tener una corriente en rango para validar si la bomba tiene agua.
 * 
 * POSTCONDITIONS:
 * None.      
 *
\******************************************************************************/
void Fun_Controlar_Riego(float corriente_bomba_validar)
{
  if((corriente_bomba_validar > CORRIENTE_BAJA_NO_REGAR) && (corriente_bomba_validar < CORRIENTE_ALTA_NO_REGAR))
  {
    #ifdef IDEBUGSERIAL
    Serial.println("La Corriente de la bomba esta en parametros para riego");
    #endif
    delay(5000);
    Fun_Rutina_Sensores();
    delay(5000);
    APAGAR_BOMBA();
    Fun_Rutina_Sensores();
  }
  else
  {
    APAGAR_BOMBA();
    #ifdef IDEBUGSERIAL
    Serial.println("La Corriente de la bomba no esta en parametros para riego");
    #endif
  }
}
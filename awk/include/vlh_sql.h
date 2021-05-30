#ifndef __SQL_INCLUDED__
#define __SQL_INCLUDED__

/*************************************************************************/
#include <mtrlog.h>
#include <mdbase.h>
#include <stdio.h>
#include <string.h>
#include <com_file.h>
#include <com_defs.h>
#include <mp.h>
#include <size_def.h>
#include <xref.h>
#include <utx.h>
#include "rtx.h"
#include <merror.h>
#include <LogPendientes.h>
/**************************************************************************/
struct Tipo_Rev{
    int  iProcess_Id;
    int  iPrcrec_Id;
    int  iPrcrectype_Id;
    int  iPrcrec_Count;
    char cStream_Type;
    int  iPrcfile_Id;
    double fRated_Flat_Amount;
    float fTax_Amount;
    char szRscode[6];
    char szRspid[4];
    int  iPlcode;
    int  iHome_Bid_Id;
    int  iServing_Bid_Id;
    struct Tipo_Rev *pSiguiente;
};

typedef struct Tipo_Rev revenue;


/******************************************************************************/
#define DATE 7
#define RTX_MOC 		1 
#define RTX_MTC 		2
#define POS_INV                 15
#define MARCA_INV               '1'
#define MODULO "VLH"

/***********************************************************************/
MTRLOG_ReturnValue efnInsertarDatos(RTX_GSM_BASE_STR *, int, char *, int, int *,
													revenue **, FILE *, char , char);
MTRLOG_ReturnValue efnBuscaCpp(int *, FILE *);
MTRLOG_ReturnValue efnObtenerCodigo(int, char *, FILE *);
/**********************************************************************/

#endif

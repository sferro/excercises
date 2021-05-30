#ifndef __VLH_INCLUDED__
#define __VLH_INCLUDED__

/***************************************************************************/
#include <dirent.h>
#include <sys/types.h>
#include <mtrlog.h>
#include <mdbase.h>
#include <stdio.h>
#include <string.h>
#include <com_file.h>
#include <com_defs.h>
#include <mp.h>
#include <size_def.h>
#include <xref.h>
#include "rtx.h"
#include <utx.h>
#include <dbutil.h>
#include <vlh_sql.h>
#include <dirs.h> 
#include <LogPendientes.h>
/************************************************************************/
#define MODULO       	"VLH"                 /* nombre del modulo */
#define BSCSDIR      	17                    /* codigo para el directorio base de BSCS */
#define DATABASE     	"BSC_TAS1"            /* base de datos */
#define RV_OK        	0     
#define RV_ERROR     	1
#define MAX_BUFFER_SIZE	16

#define CODIGO 			7023
#define LONG_NOM 		7362
#define DIR_ENT 		7363
#define DIR_SAL 		7364
#define ACC_ENT 		7366
#define ACC_SAL 		7367

#define CANT_REG 		6
/*************************************************************************/
MTRLOG_ReturnValue efnLeerArchRTX(const char *, int, char *, int, int *, revenue **, FILE *, int);
MTRLOG_ReturnValue efnManejoError(FILE *, char *);
/*************************************************************************/

#endif

/* $Id: size_def.h,v 1.4 1996/10/28 13:51:17 mdonald Exp $ */
#ifndef SIZE_DEF_H
#define SIZE_DEF_H
/*************************************************************/
/*                                                           */
/* ABSTRACT : SIZE Include for Message Processing Modules.   */
/*                                                           */
/* AUTHOR   : Dr. Klaus-Werner Hoefer LHS                    */
/*                                                           */
/* CREATED  : 06-DEC-1993                                    */
/*                                                           */
/* MODIFIED : 18-JAN-1994                                    */
/*                                                           */
/* DESCRIPTION :                                             */
/*                                                           */
/* This C-Include file contains the size definitions for     */
/* fields used in the UTX and RTX record.                    */
/*                                                           */
/* CALLED SUBROUTINES :                                      */
/*                                                           */
/*   N.A.                                                    */
/*                                                           */
/* RETURN CODES :                                            */
/*                                                           */
/*   N.A.                                                    */
/*                                                           */
/*************************************************************/

/*
@(#) ABSTRACT : C-INCLUDE file.
@(#) Size Includes for Message Processing.
*/


/*************************************************************/
/* Definition of field lengths.                              */
/*************************************************************/

#define  LEN_INGLCODE                 30
#define  LEN_ACCOUNTTYPE               2
#define  LEN_BCCODE                    2
#define  LEN_CALL_TYPE_IND             2
#define  LEN_CONCUACCOUNT              8
#define  LEN_CUACCOUNT                 8
#define  LEN_CUSUBACCOUNT              3
#define  LEN_DESCRPITION              32
#define  LEN_GSM_PI                   16
#define  LEN_INTRUNK                  15
#define  LEN_MSRN_BCD                 10
#define  LEN_NON_GSM_PI               16
#define  LEN_ORIG_SALES_FORCE_ID       8
#define  LEN_OUTTRUNK                 15
#define  LEN_CALLDEST                  2
#define  LEN_RATED_PARTY_IMEI_BCD      8
#define  LEN_RATED_PARTY_IMEI         16
#define  LEN_RATED_PARTY_TRUNK        10
#define  LEN_RTSP_PI                  16
#define  LEN_SERVED_PARTY_IMEI_BCD     8
#define  LEN_START_DATE_BCD            4
#define  LEN_START_TIME_BCD            3
#define  LEN_SUBSCRIBER_SEQNUM         7
#define  LEN_SVSEQNUM                  7
#define  LEN_TERM_ZONAL_POINT_NAME    32
#define  LEN_TRANSACTION_TYPE          2
#define  LEN_REMARK                   80
#define  LEN_CARRIER_NAME              4
#define  LEN_CARRIER_SERVICE_ID       11
#define  LEN_IXCCODE_BCD               3
#define  LEN_LATA                      4
#define  LEN_LATA_BCD                  2
#define  LEN_US_LOCATION_DES          15
#define  LEN_NPA_NXX                   6
#define  LEN_CITY                     10
#define  LEN_STATE                     2
#define  LEN_GEOCODE                  20


/*** Feature 42272: Jai Katikineni ****/
  #define  LEN_ISO                   3
  #define  LEN_CC                    3
  #define  LEN_COUNTRYNAME           40
  #define LEN_ISO_CODE               3
/** End Feature ***/


#define  LEN_DN_BUF                   24
#define  LEN_DN_BUF_BCD               12
#define  LEN_DN_PART_BUF              12
#define  LEN_DN_PART_BUF_BCD           6
#define  LEN_PORT_BUF                 24
#define  LEN_PORT_BUF_BCD             12
#define  LEN_PORT_PART_BUF            10
#define  LEN_PORT_PART_BUF_BCD         5
#define  LEN_DEST_BUF_BCD             14
#define  LEN_DEST_BUF                 28
#define  LEN_DEST_PART_BUF_BCD         5
#define  LEN_ORIG_BUF                 24
#define  LEN_ORIG_PART_BUF            10

#define LEN_USGSERV_CAT               10
#define LEN_USGSERV_CODE              10
#define LEN_USGSERV_TYPE               3
#define LEN_MRKGLCODE                 30
#define LEN_MRKSERV_CAT               10
#define LEN_MRKSERV_CODE              10
#define LEN_MRKSERV_TYPE               3
#define LEN_VENDOR                     5

#ifdef CONFIG_SERV_PRO

#define LEN_SERVED_PARTY_ICC_ID_BCD   14

#endif

#define LEN_HOME_BID_DESC             30
#define LEN_SERVING_BID_DESC          25
#define LEN_HOME_BID                   5
#define LEN_SERVING_BID                5

#define LEN_OPERATING_UNIT            20

#define LEN_BILL_STATUS                1
#define LEN_MARKET_ID                  3
#define LEN_START_DATE_TIME           14

/* Following added for support of Defect #19926 */
#define LEN_DES_BUF                   30

/* Following added for Feature 23544    MAT 10/4/97 */
#define LEN_COUNTRY                    3

/* Following added for feature 21723 */
#define LEN_MSISDN_START              20
#define LEN_MSISDN_END                20
#define LEN_FCCODE                     3

/* Following added for feature 29450 */
#define LEN_CIBER_CODE                 2

/* Following added for feature 30580 */
#define LEN_DEVICE_CODE                20
#define LEN_PHONENBR_CODE              20

/*
 * Note:
 * On all supported platforms (Sun,Dec,HP) int is 4 Bytes.
 * On Dec a long is 8 bytes on all other platforms 4 Bytes!
 *
 * We use int for BSCS IDs and CODEs. The maximum int value
 * is 2.147.483.648!
 */

#if defined __osf__  && defined __alpha
#	define USE_INT_FOR_BSCS_CODE_TYPE	1
#	define USE_INT_FOR_BSCS_ID_TYPE		1
#else
#	define USE_INT_FOR_BSCS_CODE_TYPE	1
#	define USE_INT_FOR_BSCS_ID_TYPE		1
#endif


#endif

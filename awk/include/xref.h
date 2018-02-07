/*****************************************************************************
*
* LH-Specification GmbH 1996.
*
* All rights reserved.
* Copying of this software or parts of this software is a violation of German
* and international laws and will be prosecuted.
*
* PROJECT     : BSCS V 4.0 for multi markets
*
* FILE        : xref.h
* CREATED     : 06-DEC-1993
* AUTHOR      : Dr. Klaus-Werner Hoefer, LHS
* MODIFIED    : 11-JAN-1996 Dr. Guenther Budzick, LHS
*               01-MAR-1996 Dr. Michael Rook, LHS
*               18-Mar-1996     Thomas Gutberlet, LHS
*               15-AUG-1996     Don Meredith, LHS Atlanta
*               25-OCT-1996     Don Meredith, LHS Atlanta, Defect 19962
*               23-DEC-1996     Don Meredith, LHS Atlanta, BSCS 4.03
*               20-MAR-1997     Don Meredith, LHS Atlanta, Feature 21755
*               20-MAR-1997     Don Meredith, LHS Atlanta, Feature 21733
*               07-MAY-1997     Don Meredith, LHS Atlanta, Feature 21723
*               09-JUL-1997     Don Meredith, LHS Atlanta, Feature 23607
*               04-AUG-1997     Don Meredith, LHS Atlanta, Feature 23758
*               19-AUG-1997     Don Meredith, LHS Atlanta, Feature 24023
*               04-OCT-1997     Mark Thomas, LHS Atlanta, Feature 23544
*               04-DEC-1997     Don Meredith, LHS Atlanta, Feature 24159
*               05-DEC-1997     Don Meredith, LHS Atlanta, Feature 24133
*               27-FEB-1998     Don Meredith, LHS Atlanta, Defect 26824
*               20-APR-1998     Bob Roeder, LHS Atlanta, Defect 27346
*               10-JUN-1998     Don Meredith, LHS Atlanta, Feature 28564
*               21-OCT-1998     Bob Roeder, LHS Atlanta, Feature 24463_1
*               01-APR-1999     Peter Zhang, LHS Atlanta, Feature 32599
*
* DESCRIPTION :
* -------------
* This C-Include file contains declarations and definitions for Message
* Processing Cross Reference Tables.
*
* Note:
*
* All character fields with a Spare Byte must be copied and
* compared using the functions 'memcpy' and 'memcmp' and
* not 'strcpy' and 'strcmp'. The Spare Byte is for internal
* print purposes only.
*
*****************************************************************************/

/*
@(#) ABSTRACT : C-INCLUDE file.
@(#) BSCS MP: Cross Reference Tables.

SCCS_VERSION="1.21.1.5"
 $Log:   V:/PAIS/Archives/Global/BATCH/Include/xref.h-arc  $
 * 
 *    Rev 1.0   Oct 23 2000 14:54:28   castev
 * Initial revision.
*/

#ifndef XREF_H
#define XREF_H

#include "size_def.h"
#include "time.h"

/*************************************************************/
/* Length definitions.                                       */
/*************************************************************/

#define  LEN_ACCNTTYPE            2
#define  LEN_ACTION_TYPE          7
#define  LEN_BC                   2
#define  MAX_BC                   99 
                                        /* must not exceed 10^LEN_BC-1  */ 

#define  LEN_RBC                  2
#define  MAX_NUM_RENTAL_BILL      99 
                                        /* must not exceed 10^LEN_RBC-1 */ 


#define  LEN_COMPARE_VALUE       16
#define  LEN_CONCUACCNT           8
#define  LEN_CUACCNT              8
#define  LEN_CUSUBACCNT           3
#define  LEN_DESCRIPTION         35
#define  LEN_DZDEFTAB_NAME        8

#define  LEN_RBDEFTAB_NAME        8
                                    /* for Rental Billing         */

#define  LEN_EXCHANGE_ID         15
#define  LEN_FTAM_PARAMETERS      1
#define  LEN_GZMODUL             10
#define  LEN_M2D_NAME            14
#define  LEN_OSFID                8
#define  LEN_PI                  16
#define  LEN_PIPREFIX            LEN_MARKET_ID 
#define  LEN_RTMODUL             10
#define  LEN_SP_M2D_NAME         10
#define  LEN_SUBSEQNO             7
#define  LEN_SRVSEQNO             7
#define  LEN_TAP_NAME             5
#define  LEN_TCDEFTAB_NAME        8
#define  LEN_TRUNK               10
#define  LEN_VAS_CODE            10

#define  LEN_DATE_OF_MEASURE_BCD  4

#define  LEN_CUSTGROUP           10
#define  LEN_GLCODE              30
#define  LEN_LEGAL_CODE          15

#define  LEN_SPARE                1

#define  LEN_SOURCE               5
#define  LEN_USGGLCODE           30

/* Added for feature 21723 */
#define  LEN_US_CITY             40
#define  LEN_US_STATE             2

/*************************************************************/
/* Type definitions.                                         */
/*************************************************************/

typedef struct sdzmemtab_str DZMEMTAB_STR;

typedef struct stcmemtab_str TCMEMTAB_STR;

typedef struct supvectab_str UPVECTAB_STR;

typedef struct scovectab_str COVECTAB_STR;

typedef struct sdir_lkptr_str DIR_LKPTR_STR;

typedef struct pn_knot PN_KNOT;

typedef struct sxref_pool_str XREF_POOL_STR;

typedef struct shpdeftab_str HPDEFTAB_STR;

typedef struct shldeftab_str HLDEFTAB_STR;

typedef struct sfideftab_str FIDEFTAB_STR;

typedef struct sgldeftab_str GLDEFTAB_STR;

typedef struct sgsdeftab_str GSDEFTAB_STR;

typedef struct sgzdeftab_str GZDEFTAB_STR;

typedef struct siadeftab_str IADEFTAB_STR;

typedef struct snedeftab_str NEDEFTAB_STR;

typedef struct stkdeftab_str TKDEFTAB_STR;

typedef struct sxrdeftab_str XRDEFTAB_STR;

typedef struct srmdeftab_str RMDEFTAB_STR;

typedef struct sccdeftab_str CCDEFTAB_STR;

typedef struct smcdeftab_str MCDEFTAB_STR;

typedef struct sffdeftab_str FFDEFTAB_STR;

typedef struct sffdddtab_str FFDDDTAB_STR;

typedef struct ssgdeftab_str SGDEFTAB_STR;

typedef struct sdzdeftab_str DZDEFTAB_STR;

typedef struct sdzlsttab_str DZLSTTAB_STR;

typedef struct stcdeftab_str TCDEFTAB_STR;

typedef struct stclsttab_str TCLSTTAB_STR;

typedef struct shodeftab_str HODEFTAB_STR;

typedef struct stmdeftab_str TMDEFTAB_STR;

typedef struct spudeftab_str PUDEFTAB_STR;

typedef struct sepdeftab_str EPDEFTAB_STR;

typedef struct secdeftab_str ECDEFTAB_STR;

typedef struct sutdeftab_str UTDEFTAB_STR;

typedef struct srgdeftab_str RGDEFTAB_STR;

typedef struct sradeftab_str RADEFTAB_STR;

typedef struct scndeftab_str CNDEFTAB_STR;

typedef struct sindeftab_str INDEFTAB_STR;

typedef struct sisdeftab_str ISDEFTAB_STR;

typedef struct scodeftab_str CODEFTAB_STR;

typedef struct slkdeftab_str LKDEFTAB_STR;

typedef struct spndeftab_str PNDEFTAB_STR;

typedef struct srbdeftab_str RBDEFTAB_STR;

typedef struct sxideftab_str XIDEFTAB_STR;

typedef struct srideftab_str RIDEFTAB_STR;

typedef struct sevdeftab_str EVDEFTAB_STR;

typedef struct segdeftab_str EGDEFTAB_STR;

typedef struct sixdeftab_str IXDEFTAB_STR;

/* Feature 10266 */

typedef struct ssbdeftab_str SBDEFTAB_STR;

/* Feature 21733 */

typedef struct srudeftab_str RUDEFTAB_STR;

typedef struct surdeftab_str URDEFTAB_STR;

/* Feature 21723 */

typedef struct shbdeftab_str HBDEFTAB_STR;

/* Set the bscs_id_t type.                                   */

#ifdef USE_SHORT_FOR_BSCS_ID_TYPE

typedef short bscs_id_t;

#define DISPLAY_ID              "%hd"

#endif  

#ifdef USE_INT_FOR_BSCS_ID_TYPE

typedef int bscs_id_t;

#define DISPLAY_ID              "%d"

#endif  


/* Set the bscs_code_t type.                                 */

#ifdef USE_SHORT_FOR_BSCS_CODE_TYPE

typedef short bscs_code_t;

#define DISPLAY_CODE            "%hd"

#endif  

#ifdef USE_INT_FOR_BSCS_CODE_TYPE

typedef int bscs_code_t;

#define DISPLAY_CODE            "%d"

#endif  

/* Define the union types                                    */

typedef union uco_union CO_UN;

typedef union ucv_union CV_UN;

typedef union utw_union TW_UN;

typedef union ugv_union GV_UN;

/* Set the union types.                                      */

union uco_union
{
        bscs_id_t      contract_id;
        CODEFTAB_STR   *codeftab;
};

union ucv_union
{
        bscs_id_t      contract_id;
        COVECTAB_STR   *covectab;
};

union utw_union
{
        bscs_code_t    twcode;
        TCMEMTAB_STR   *tcmemtab;
};

union ugv_union
{
        bscs_code_t    gvcode;
        DZMEMTAB_STR   *dzmemtab;
};

typedef         long            MpIndex;
 
#define         MpIndexNull     ((MpIndex)(-1))

/*************************************************************/
/* Action Codes for Supplementary Services.                  */
/*************************************************************/

#define SS_REGISTRATION          'R'
#define SS_ERASURE               'E'
#define SS_ACTIVATION            'A'
#define SS_DEACTIVATION          'D'
#define SS_INTERROGATION         'Q'
#define SS_INVOCATION            'I'
#define SS_PASSWORD_REGISTRATION 'P'

/*************************************************************/
/* Structure definitions.                                    */
/*************************************************************/

/*************************************************************/
/*                         HPDEFTAB                          */
/* This structure contains informatin about the Country Code */
/* and National Destination Code of the HOME PLMN. It is     */
/* needed to identify the HPLMN Subscribers during the M-M   */
/* Assembly.                                                 */
/*************************************************************/

struct shpdeftab_str
{

        time_t  vdate ;             /* Effective date and time of   */
                             /* this entry in UNIX fomat.    */

        bscs_code_t plcode;         /* A unique identifier for the  */
                                    /* HPLMN.                       */

        bscs_code_t sccode;         /* The Service Class Code       */

        int port_hml;               /* The minimum matching length  */
                                    /* to be a home port.           */

        int dn_hml;                 /* The minimum matching length  */
                                    /* to be a home directory.      */

        int dest_hml;               /* The minimum matching length  */
                                    /* to be a home destination.    */

        int port_hcl;               /* The length of the part       */
                                    /* constant for the port.       */

        int dn_hcl;                 /* The length of the part       */
                                    /* constant for the directory.  */

        char      m2d_name [ LEN_M2D_NAME + LEN_SPARE ] ;
                                    /* Identifier of the Sender of  */
                                    /* M2D Records used in Header   */
                                    /* and Trailer of M2D Files.    */

        unsigned char ndc [ LEN_DN_PART_BUF_BCD ];
                                    /* National Destination Code.   */

        unsigned char hplmn_port[ LEN_PORT_BUF_BCD ];
                                    /* The non serial part of the   */
                                    /* port numbers.                */

        unsigned char hplmn_dir[ LEN_DN_BUF_BCD ];
                                    /* The non serial part of the   */
                                    /* directory numbers.           */

        unsigned char hplmn_dest[ LEN_DEST_BUF_BCD ];
                                    /* The non serial part of the   */
                                    /* destination.                 */

        char      tap_name [ LEN_TAP_NAME + LEN_SPARE ] ;
                                    /* Identifier of the Sender of  */
                                    /* Transfer Account Records     */
                                    /* used in Header and Trailer   */
                                    /* of TAP Files.                */

        unsigned char mcc_mnc [ LEN_PORT_BUF_BCD ];
                                    /* The Mobile Country Code and  */
                                    /* Mobile Network Code of       */
                                    /* the PLMN coded in BCD.       */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        unsigned char cc [ LEN_DN_PART_BUF_BCD ] ;
                                    /* Country Code.                */

        unsigned char gmsc_id [LEN_DN_BUF + LEN_SPARE];
                                    /* Default GMSC_ID.             */

        unsigned char gmsc_msisdn [LEN_DN_BUF_BCD];
                                    /* Default MSISDN of GMSC_ID.   */

        unsigned char intrunk [LEN_INTRUNK + LEN_SPARE];
                                    /* Default Intrunk.             */

        unsigned char outtrunk [LEN_OUTTRUNK + LEN_SPARE];
                                    /* Default Outtrunk.            */

        unsigned char reconind;     /* Reconciliation Indicator.    */

 char sc_gsm_like_struct;    /* Indicator if the market is   */
                                                                            /* "GSM like". 'Y' means yes,   */
                                                                                 /* 'N' means no.                */

/* The next field is for internal purposes only.             */

        unsigned char cc_ndc[ LEN_DN_BUF_BCD ];
                                    /* CC and NDC in one field.     */

};

/*************************************************************/
/*                         HLDEFTAB                          */
/* The next structure is the layout for the HLR Definition   */
/* Table.                                                    */
/*************************************************************/

struct shldeftab_str
{

        time_t vdate;           /* Effective date and time of   */
                                    /* this entry in UNIX fomat.    */

        bscs_code_t plcode;         /* Key of the PLMN.             */

        unsigned char hlr_id[ LEN_PORT_PART_BUF_BCD ];
                                    /* The ID of the HLR.           */

        char cgi [ LEN_ORIG_BUF + LEN_SPARE ];
                                    /* Contains the CGI of the HLR. */

};

/*************************************************************/
/*                         DZDEFTAB                          */
/* This structure contains the link of Originating Zonal     */
/* Points to Terminating Zonal Points. This structure occurs */
/* as many times as Zone Coverages are specified. Each       */
/* table represents a complete Zone Coverage.                */
/*************************************************************/

#define SPECIAL_NUMBER_YES 1
#define SPECIAL_NUMBER_NO  0

struct sdzdeftab_str
{
        bscs_code_t  zncode ;     /* The Tariff Zone Code.        */
        bscs_code_t  zpcode;      /* The Dialed Zone Termination  */
                                    /* Point Code.                  */
        int       special_number_flag ;
                                    /* A flag indicating whether    */
                                    /* the Terminating Zonal Point  */
                                    /* represents a special number. */
                                    /* The values are 0: No 1: Yes  */
        unsigned char dialed_digits [ LEN_DEST_BUF_BCD ] ;
                                    /* The dialed digits represent- */
                                    /* ing the Terminating Zonal    */
                                    /* Point coded in BCD. Trailing */
                                    /* digits which are not used    */
                                    /* are filled with HEX 'F'.     */
        char      cgi [ LEN_ORIG_BUF + LEN_SPARE ];
                                    /* Contains the Cell Global     */
                                    /* Identifier represented as    */
                                    /* MCC_MNC_LAC_CI in hexadecimal*/
                                    /* format. The Location Area    */
                                    /* Code and the Cell Identifier */
                                    /* are represented full         */
                                    /* qualified. The mcc_mnc is    */
                                    /* represented with MNC only.   */

/****************************************************************/
/*                                                              */
/* Following two fields added to support tax enhancements for   */
/*   BSCS 4.01_us.  Feature 12998                               */
/*                                                              */
/****************************************************************/

    unsigned char orig_geocode[LEN_GEOCODE + LEN_SPARE];
                                /* The geocode of the           */
                                /*  originating location.       */

    unsigned char dest_geocode[LEN_GEOCODE + LEN_SPARE];
                                /* The geocode of the           */
                                /*  terminating location.       */

/* End of additions.   DLM 08/16/96                             */

/****************************************************************/
/*                                                              */
/* Following two fields added to handle defect 19926            */
/*                                                              */
/****************************************************************/

    unsigned char zodes[LEN_DEST_BUF + LEN_SPARE];
                                /* The description of the       */
                                /*  zonal origin.               */

    unsigned char zpdes[LEN_DEST_BUF + LEN_SPARE];
                                /* The description of the       */
                                /*  zonal destination.          */
};

/*************************************************************/
/*                         DZLSTTAB                          */
/* This structure contains the file names of all specified   */
/* Dialed Zone Definition Tables.                            */
/*************************************************************/

struct sdzlsttab_str
{

        bscs_code_t  zccode;      /* The Zone Coverage Code.      */

        bscs_code_t vscode;       /* The Version                  */

        char      dzdeftab_name [ LEN_DZDEFTAB_NAME + LEN_SPARE ] ;
                                    /* Contains the name of the     */
                                    /* Dialed Zone Definition Table.*/
};

/*************************************************************/
/*                         FIDEFTAB                          */
/* This structure contains informatin about all Filters used */
/* in FIH.                                                   */
/*************************************************************/

#define FILTER_TYPE_EXCLUSION      'E'

#define FILTER_TYPE_STATISTIC      'S'

#define FILTER_CONDITION_EQUAL     '='

#define FILTER_CONDITION_LOWER     '<'

#define FILTER_CONDITION_GREATER   '>'

#define FILTER_CONDITION_NOT_EQUAL '!'

struct sfideftab_str
{
        bscs_id_t  filter_id ;    /* Identifier of a Complex Filter*/
        bscs_id_t  basic_filter_id;
                                    /* Identifier for the basicfilter*/
        int       len_compare_value ;
                                    /* Actual length (in octets) of */
                                    /* the compare value.           */
        char      compare_value [ LEN_COMPARE_VALUE ] ;
                                    /* Contains the filter value.   */
                                    /* Trailing characters are      */
                                    /* filled with HEX zero. If the */
                                    /* filter value is a number such*/
                                    /* as duration, then the value  */
                                    /* is represented in binary.    */
        char      filter_type ;   /* Type of the Complex Filter   */
                                    /* (exclusion or statistic).    */
        char      condition ;     /* Conditon for that field and  */
                                    /* filter combination           */
                                    /* ( =, <, >,!=)                */
};

/*************************************************************/
/*                         GSDEFTAB                          */
/* This structure contains the GSM-Services                  */
/*************************************************************/

#define GSM_TELE_SERVICE          'T'
#define GSM_BEARER_SERVICE        'B'
#define GSM_SUPPLEMENTARY_SERVICE 'S'
#define GSM_INSENSITIVE           'I'
#define GSM_GROUP_SERVICE         'G'
#define CATCH_ALL_BSG_SEGMENT     "T**B*****"
#define LEN_CATCH_ALL_BSG_SEGMENT  9
#define LEN_BSG_SEGMENT            9
#define LEN_SCSLPREFIX             LEN_MARKET_ID

struct sgsdeftab_str
{

        char gsmcode[LEN_BSG_SEGMENT];
                                    /* The Basic Service SVLCODE    */

        char groupcode[LEN_BSG_SEGMENT];
                                    /* The Basic Service SVLCODE of */
                                    /* the group.                   */

        char market_id[LEN_PIPREFIX];
                                    /* The market's SVL-prefix.     */

        char type;                /* Service Type                 */

        unsigned char code ;      /* Service Code                 */

/* The next declaration is for internal purposes only.       */

        GSDEFTAB_STR *group;      /* Points to the group entry.   */

};

/*************************************************************/
/*                      GZDEFTAB                             */
/* This structure contains the modules for evaluation of     */
/* generic zones. A description of available modules is      */
/* given in the document "Design Local Message Processing    */
/* Rate Input Handler".                                      */
/*************************************************************/

struct sgzdeftab_str
{

        time_t  vdate ;         /* The effective timestamp of   */
                                    /* the entry.                   */
        bscs_code_t  tzcode ;     /* The Tariff Zone Code for the */
                                    /* Generic Zone.                */
        int       utx_call_type ; /* Specifies the UTX Record.    */
        char      gzmodul [ LEN_GZMODUL + LEN_SPARE ] ;
                                    /* form GZnnnnnnnn. GZ is a     */
                                    /* constant prefix, nnnnnnnn is */
                                    /* an internal number.          */
        char      piprefix [ LEN_PIPREFIX + LEN_SPARE ] ;
                                    /* Contains the prefix of the   */
                                    /* Priceable Item indicating to */
                                    /* which type of service the UTX*/
                                    /* belongs to, such as GSM and  */
                                    /* VAS. All characte are used.  */

        unsigned char source[ LEN_SOURCE + LEN_SPARE ];
                                    /* A short identifier of the    */
                                    /* network. D00D1, D00D2, E00E1.*/

};

/*************************************************************/
/*                      IADEFTAB                             */
/* This structure contains for all PLMNs the international   */
/* access codes.                                             */
/*************************************************************/

struct siadeftab_str
{

        time_t  vdate ;             /* The effective timestamp of   */
                                    /* the entry.                   */

        bscs_code_t plcode;         /* The PLMN Code                */

        unsigned char mcc_mnc [ LEN_PORT_BUF_BCD ];
                                    /* The Mobile Country Code and  */
                                    /* Mobile Network Code of       */
                                    /* the PLMN coded in BCD.       */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        unsigned char iac [ LEN_DEST_PART_BUF_BCD ];
                                    /* An Internationl Access       */
                                    /* Code of the PLMN coded in BCD*/
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        unsigned char nac [ LEN_DEST_PART_BUF_BCD ];
                                    /* An National Access           */
                                    /* Code of the PLMN coded in BCD*/
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        char      status ;          /* Specifies the status of a    */
                                    /* IAC. The values are A:Active */
                                    /* D: Deactive                  */

};

/*************************************************************/
/*                         NEDEFTAB                          */
/* This structure contains informatin about the MSC          */
/* parameters. It is needed to manage the M-M Assembly.      */
/*************************************************************/

#define MSC_TYPE_ORDINARY              1

#define MSC_TYPE_NATIONAL_GATEWAY      2

#define MSC_TYPE_INTERNATIONAL_GATEWAY 3

struct snedeftab_str
{
        time_t  vdate ;         /* Start date and time of this  */
                                    /* entry in UNIX fomat          */
        long int  version ;       /* The Software Version used.   */
        long int  retry_num;      /* Maximum number of FTAM       */
                                    /* retries.                     */
        long int  pardur ;        /* Partial record duration      */
                                    /* length, measured in seconds  */
        long int  pardur_thres ;  /* Partial record duration      */
                                    /* rating threshold, measured in*/
                                    /* seconds                      */
        long int  pardat ;        /* Partial record data vol.     */
                                    /* length, measured in segments.*/
        long int  pardat_thres ;  /* Partial record data vol.     */
                                    /* rating threshold, measured   */
                                    /* in segments.                 */
        long int  assem_gap ;     /* Maximal time gap for assembly*/
                                    /* between to partial records,  */
                                    /* measured in seconds          */
        long int  redial_gap ;    /* Maximal time gap for auto    */
                                    /* credit in redial scenarios,  */
                                    /* measured in seconds.         */
        int       msc_type ;      /* Indicates the type of the MSC*/
                                    /* ordinary MSC, national gate- */
                                    /* way or international gateway.*/
        int       del_flag ;      /* Deletion flag for CHUs on    */
                                    /* MSC site.                    */
        char      vendor [ LEN_VENDOR + LEN_SPARE ] ;
                             /* The Vendor of that MSC.      */
        unsigned char msc_msisdn [ LEN_DN_BUF_BCD ] ;
                                    /* MSISDN of the MSC. It is     */
                                    /* coded in BCD.                */
        char      exchange_id [ LEN_EXCHANGE_ID + LEN_SPARE ];
                                    /* MSC identity as populated    */
                                    /* in the call records          */
                                    /* (e.g. "DUDF21M").            */
        char             msc_cgi [ LEN_ORIG_BUF + LEN_SPARE ];
                                                                          /* GSM Cell Global Identity     */
};

/*************************************************************/
/*                         TKDEFTAB                          */
/* This structure contains informatin about the MSC Trunk    */
/* Groups. It is needed to manage the M-M Assembly. Also     */
/* this structure contains the external carrier associated   */
/* with                                                      */
/*************************************************************/

#define TRUNK_IN  'I'

#define TRUNK_OUT 'O'

struct stkdeftab_str
{

        time_t  vdate ;             /* Start date and time of this  */
                                    /* entry in UNIX fomat.         */

        bscs_code_t  eccode ;       /* Code of the external carrier.*/

        long int  cntx;             /* The X counter for dialed     */
                                    /* digits.                      */

        unsigned char msc_msisdn [ LEN_DN_BUF_BCD ] ;
                                    /* MSISDN of the MSC. It is     */
                                    /* coded in BCD.                */

        char      trunk_type ;      /* Indication if trunk is       */
                                    /* incoming = I or outgoing = O.*/

        char      trunk_id[ LEN_TRUNK + LEN_SPARE ] ;
                                    /* In or Out Trunk to external  */
                                    /* carrier as populated in call */
                                    /* records.                     */

        unsigned char dialed_digits [ LEN_DEST_BUF_BCD ] ;
                                    /* The dialed digits            */
                                    /* representing the External    */
                                    /* Carrier coded in BCD.        */
                                    /* used are filled with HEX 'F'.*/

        unsigned char trunk_dd [ LEN_DEST_BUF_BCD ];
                                                                            /* Trunk Dialed Digits          */

        char             trunk_cgi[ LEN_ORIG_BUF + LEN_SPARE ];
                             /* GSM Cell Global Identity     */

        char      status ;          /* Status of this entry         */
                                    /* 'A' = active , 'D' = deactive*/

  /* Added for feature 21755. DLM */
  char dir_ind;                     /* Indication if this is a      */
                                    /* directory assistance trunk.  */
                                    /* 'Y' = It is, 'N' = It is not */

};

/* The following xref was modified for Feature 21723         */

/*************************************************************/
/*                         XRDEFTAB                          */
/* This structure contains the Pegged Exchange Rate Table    */
/* for SDR to DM conversion                                  */
/*************************************************************/

struct sxrdeftab_str
{

  time_t  vdate ;         /* Effective date and time of      */
                          /* this entry in UNIX fomat.       */

  double    rate ;        /* The exchange rate from foreign  */
                          /* currency to home currency       */

  unsigned char fccode[LEN_FCCODE + LEN_SPARE];
                          /* The three digit ISO code for    */
                          /* this foreign currency.          */

/* The next fields are for internal purpose only.            */

  double hcur_to_fcur;    /* PER as home currency to foreign */
                          /* currency.                       */

  double fcur_to_hcur;    /* PER as foreign currency to home */
                          /* currency                        */

  unsigned char date[ LEN_BCD_DATE + LEN_BCD_TIME ];
                          /* Effective date in BCD.          */

};

/*************************************************************/
/*                      RMDEFTAB                             */
/* This structure contains the Rate Modules which perform    */
/* the actual rating.                                        */
/*************************************************************/

struct srmdeftab_str
{
        time_t  vdate ;         /* The effective timestamp of   */
                                    /* the entry.                   */
        bscs_code_t  umcode ;     /* The Unit of Meassurement.    */
        int       utx_call_type ; /* Specifies the UTX Record     */
                                    /* Type. The values are 1: MOC  */
                                    /* 2: MTC 3: EVENT 4: VAS       */
        char      rtmodul [ LEN_RTMODUL + LEN_SPARE ] ;
                                    /* Contains the name of the Rate*/
                                    /* Module in the form RMnnnnnnnn*/
                                    /* RM is a constant prefix,     */
                                    /* nnnnnnnn is an internal      */
                                    /* number                       */
        char      piprefix [ LEN_PIPREFIX + LEN_SPARE ] ;
                                    /* Contains the prefix of the   */
                                    /* Priceable Item indicating to */
                                    /* which type of service the UTX*/
                                    /* belongs to, such as GSM and  */
                                    /* VAS. All characters are used.*/
        long int umthresh;          /* Dropped calls are rated if   */
                                    /* their volume exceeds this.   */

        char uomtype;               /* The Unit of Measurement      */
                                    /* processed by this Rate Module*/

/* The next function pointer is for internal use only.       */

        int (*rate_module_fct)();
                                    /* Pointer to the Rate Module.  */

};

/*************************************************************/
/*                         CCDEFTAB                          */
/* The next structure is the layout for the Common Cell      */
/* Definition Table.                                         */
/*************************************************************/

#define GLOBAL_MICRO_CELL   'G'

#define SPECIFIC_MICRO_CELL 'S'

struct sccdeftab_str
{

        bscs_code_t mccode;       /* The Micro Cell Code.         */

        char cell_type;           /* Specifies the type of the    */
                                    /* cell.                        */

        char cust_group[ LEN_CUSTGROUP + LEN_SPARE ];
                                    /* The customer group.          */

};

/*************************************************************/
/*                         MCDEFTAB                          */
/* The next structure is the layout for the Micro Cells      */
/* Definition Table.                                         */
/*************************************************************/

#define MC_ULTRA_WEAK 'U'

#define MC_WEAK       'W'

#define MC_STRONG     'S'

struct smcdeftab_str
{

        time_t  vdate ;         /* The effective timestamp of   */
                                    /* the entry.                   */

        bscs_code_t  mccode ;     /* Code of the Micro Cell.      */

        double air_scalar;        /* Scalar for Airtime.          */

        char      cgi [ LEN_ORIG_BUF + LEN_SPARE ];
                                    /* Contains the Cell Global     */
                                    /* Identifier represented as    */
                                    /* MCC_MNC_LAC_CI in hexadecimal*/
                                    /* format. The Location Area    */
                                    /* Code and the Cell Identifier */
                                    /* are represented full         */
                                    /* qualified. The mcc_mnc is    */
                                    /* represented with MNC only.   */

        char mcflag;              /* Specifies the type of the    */
                                    /* Micro Cell.                  */

        unsigned char dialed_digits [ LEN_DEST_BUF_BCD ] ;
                                    /* The dialed digits            */
                                    /* associated with the          */
                                    /* Micro Cell coded in BCD.     */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

};

/*************************************************************/
/*                         FFDEFTAB                          */
/* This structure is the layout for the Friends and Family   */
/* Micro Cells.                                              */
/*************************************************************/

struct sffdeftab_str
{

        bscs_id_t ff_id;            /* Unique identifier for a FFMC.*/

        bscs_id_t co_id;            /* Contract_id, primary key to  */
                                                                                 /* CONTRACT_ALL.                */
   double scalefactor;         /* Scale factor for FFMC. It is */
                                                                                 /* a percentage value.          */
   char cgi[LEN_ORIG_BUF];        /* Cell Global Identity. May    */
                                                                                 /* not be qualified totally.    */
   bscs_id_t ffdddtab;         /* Index to position of first   */
                                                                                 /* corresponding dialed_digits  */
                                                                                 /* FFDDDTAB.                    */
   unsigned char num_dd;       /* Number of dialed_digits for  */
                                                                                 /* a FFMC in FFDDDTAB.          */
};

/*************************************************************/
/*                         FFDDDTAB                          */
/* This structure is the layout for the dialed_digits for    */
/* the Friends and Family Micro Cells.                       */
/*************************************************************/

struct sffdddtab_str
{

        char dialed_digits[ LEN_DEST_BUF_BCD ];
                                   /* Dialed Digits. The number   */
                                   /* doesn't need to be qualified*/
                                   /* completely.                 */

};

/*************************************************************/
/*                         SGDEFTAB                          */
/* This structure contains the GSM-Services Action Table     */
/*************************************************************/

#define ACTION_TYPE_YES 'Y'
#define ACTION_TYPE_NO  'N'

struct ssgdeftab_str
{

        time_t  vdate ;         /* Start date and time of this  */
                                    /* entry in UNIX fomat.         */

        bscs_code_t  sgcode ;     /* Service group  Code.         */

        unsigned char gs_code ;   /* GSM-Service Code.            */

        char      action_type [ LEN_ACTION_TYPE ] ;
                                    /* Action Types.                */

        char      gs_type ;       /* GSM- Service Type.           */

};

/*************************************************************/
/*                      TCDEFTAB                             */
/* This structure contains the Tariff Times. This structure  */
/* occurs as many times as Tariff Weeks are specified. Each  */
/* table represents a complete Time Coverage. To get the     */
/* correct TTCODE for a TIME_STAMP the record with the       */
/* smalest END_OF_SLOT > CALL_TIME_STAMP has to be taken.    */
/* His TTCODE is valid if it is greater than zero. If the    */
/* found TTCODE is equal -1 then the TTCODE from the record  */
/* with the smalest END_OF_SLOT > ( TIME_STAMP mod 604800 )  */
/* is the valid one.                                         */
/*************************************************************/

#define IS_A_SPECIAL_DAY 0xFF

struct stcdeftab_str
{
        bscs_code_t  ttcode ;     /* The Tariff Time Code.        */
        long int  end_of_slot ;   /* The End of Slot Time         */
                                    /* represented in seconds.      */
        unsigned char special_day[ LEN_BCD_DATE ];
                                    /* Represents a special day.    */

        unsigned char type_of_day;/* The type of day.             */
};


/*************************************************************/
/*                      TCLSTTAB                             */
/* This structure contains the file names of all specified   */
/* Time Coverage Definition Tables.                          */
/*************************************************************/

struct stclsttab_str
{

        bscs_code_t  twcode ;     /* The Tariff Week Code.        */

        bscs_code_t vscode;       /* The Version                  */

        char      tcdeftab_name [ LEN_TCDEFTAB_NAME + LEN_SPARE ] ;
                                    /* Contains the name of the     */
                                    /* Time Coverage Definition     */
                                    /* Table.                       */
};

/*************************************************************/
/*                         HODEFTAB                          */
/* The next structure is the layout of the Holiday           */
/* Definition Table.                                         */
/*************************************************************/

struct shodeftab_str
{

        unsigned char date[ LEN_BCD_DATE ];
                                    /* The date of the holiday.     */

};

/*************************************************************/
/*                      EGDEFTAB                             */
/* This structure contains the Extended Glcodes.             */
/*************************************************************/

struct segdeftab_str
{

        time_t  vdate ;             /* The effective timestamp      */
                                    /* of the entry.                */

        bscs_code_t  egcode ;       /* The EG Package Code.         */

        bscs_code_t  vscode ;       /* The Version Code.            */

        bscs_code_t  tzcode;        /* The Tariff Zone Code.        */

        bscs_code_t  ttcode;        /* The Tariff Time Code.        */

        char typeind;               /* The Type Indicator.          */

        char usgglcode[LEN_USGGLCODE + LEN_SPARE];             
                                    /* The Usage Glcode.            */

        char usgserv_cat[LEN_USGSERV_CAT + LEN_SPARE];                
                                    /* The Service Category Code.   */

        char usgserv_code[LEN_USGSERV_CODE + LEN_SPARE];                
                                    /* The Service Code.            */

        char usgserv_type[LEN_USGSERV_TYPE + LEN_SPARE];                
                                    /* The Service Type.            */

        MpIndex egindex;            /* References a row of the      */
                                    /* index list  for EGDEFTAB.    */

};

/*************************************************************/
/*                      EVDEFTAB                             */
/* This structure contains the Event Rate Packages.          */
/*************************************************************/

#define ROUNDING_IND_YES 'Y'
#define ROUNDING_IND_NO  'N'

struct sevdeftab_str
{

  double clicks_registration;
                              /* Clicks for Registration.     */

  double clicks_erasure;
                              /* Clicks for Erasure.          */

  double clicks_activation;
                              /* Clicks for Activation.       */
 
  double clicks_deactivation;
                              /* Clicks for Deactivation.     */

  double clicks_interrogation;
                              /* Clicks for Interrogation.    */

  double clicks_invocation;
                              /* Clicks for Invocation.       */

  double clicks_passwdchange;
                              /* Clicks for Password Change.  */

  time_t  vdate ;             /* The effective timestamp      */
                              /* of the entry.                */

  TW_UN  tw_un;               /* The Tariff Week Code.        */

  bscs_code_t  twvscode ;     /* The Tariff Week Version.     */

  bscs_code_t  ttcode ;       /* The Tariff Time Code.        */

  bscs_code_t  evcode ;       /* The Tariff Model Code.       */

  bscs_code_t  vscode ;       /* The Version Code.            */

  bscs_code_t  umcode ;       /* The Unit of Measure Code.    */

  unsigned char markup_flag;  /* The markup flag added for    */
                              /* feature 21464.               */

  MpIndex evindex;            /* References a row of the      */
                              /* index list for EVDEFTAB.     */

};

/*************************************************************/
/*                      RIDEFTAB                             */
/* This structure contains the Rate Interval Packages.       */
/*************************************************************/

#define NULL_DURATION 1e-7

#define MAX_NOSU 10

#define END_OF_SUCCESSION 999

#define SPLIT_INDICATOR_INITIAL 'I'
#define SPLIT_INDICATOR_SPLIT   'S'
#define SPLIT_INDICATOR_FINAL   'F'

#define TYPE_IND_AIR  'A'
#define TYPE_IND_IC   'L'
#define TYPE_IND_RL   'R'
#define TYPE_IND_CF   'C'
#define TYPE_IND_TOLL 'T'

struct srideftab_str
{

  double tu_succ[ MAX_NOSU ];
                              /* The length of the successive */
                              /* timer units for Airtime.     */

  double rr_succ[ MAX_NOSU ];
                              /* The rounding rule of the     */
                              /* successive timer units for   */
                              /* Airtime.                     */

  double clicks_succ[ MAX_NOSU ];
                              /* The clicks for the successive*/
                              /* timer units for Airtime.     */

  long int rf_succ[ MAX_NOSU ];
                              /* The Repeat factor for the    */
                              /* current Successive           */
                              /* Interval for Airtime.        */

  long int nosu;              /* Number of Successive         */
                              /* Intervalls for Airtime.      */

  time_t  vdate ;             /* The effective timestamp      */
                              /* of the entry.                */

  bscs_code_t  ricode ;       /* The Usage Package Code.      */

  bscs_code_t  vscode ;       /* The Version Code.            */

  bscs_code_t  umcode ;       /* The Unit of Measure Code.    */

  GV_UN  gv_un;               /* The Zone Coverage Code.      */

  bscs_code_t  gvvscode;      /* The Zone Coverage Version.   */

  bscs_code_t  tzcode ;       /* The Tariff Zone Code.        */

  TW_UN  tw_un;               /* The Tariff Week Code.        */

  bscs_code_t  twvscode ;     /* The Tariff Week Version.     */

  bscs_code_t  ttcode ;       /* The Tariff Time Code.        */

  char rndind;                /* Rounding Indicator.          */

  char typeind;               /* Type Indicator for Airtime   */
                              /* or Interconnect.             */

  char spind;                 /* The Split Indicator. The     */
                              /* values are I:Initial F:Final */
                              /* S:Split.                     */

/****************************************************************/
/*                                                              */
/* Following two fields were added to support dispatch rating   */
/*   for BSCS 4.01_us.  Feature 13869                           */
/*                                                              */
/****************************************************************/

  unsigned char sclind;       /* Does this entry represent a  */
                              /*  rate plan for a dispath call*/
                              /*  If so then value is 'X'.    */

  long int ri_dim;            /* The number of dispatch       */
                              /*  service areas covered by    */
                              /*  this rate plan.             */

  /* Following commented out for feature 21292

  unsigned char ris_type;

  */
                              /* The type of dispatch rating  */
                              /* interval (Private or Group)  */
                              /*  Added for BSCS 4.02_us      */

/* End of additions.  DLM 08/15/96                            */

/**************************************************************
  Following field added to support markup/surcharge feature no.
  21464 as specified by Iridium.
 **************************************************************/

  unsigned char interval_type; /* The type of rating interval */
                               /* that this is of:            */
                               /*  'M' - markup               */
                               /*  'S' - surcharge            */
                               /*  'U' - surcharge/unit       */
                               /*  'X' - normal rating int.   */

  MpIndex riindex;            /* References a row of the      */
                              /* index list for RIDEFTAB.     */

};

/*************************************************************/
/*                      TMDEFTAB                             */
/* This structure contains the Tariff Models.                */
/*************************************************************/

#define USAGE_IND_USAGE   'U'
#define USAGE_IND_EVENT   'E'
#define USAGE_IND_INBOUND 'I'

struct stmdeftab_str
{

  time_t  vdate ;             /* The effective timestamp      */
                              /* of the entry.                */

  bscs_code_t  tmcode ;       /* The Tariff Model Code.       */

  bscs_code_t  vscode ;       /* The Version Code.            */

  bscs_code_t  spcode;        /* The Service Package Code.    */

  bscs_code_t  sncode;        /* The Service Code.            */

  bscs_code_t  ricode;        /* The Rate Interval Package    */
                              /* Code.                        */

  bscs_code_t  evcode;        /* The Event Rate Package Code. */

  bscs_code_t  egcode;        /* The Extended GL Package Code.*/

  char usgind;                /* Usage Indicator.             */

  char svlcode[ LEN_PI + LEN_SPARE ];
                              /* The Priceable Item.          */
  
  char usgglcode[ LEN_USGGLCODE + LEN_SPARE ];
                              /* The Usage Glcode.            */

  char usgserv_cat[LEN_USGSERV_CAT + LEN_SPARE];                
                              /* The Service Category Code.   */

  char usgserv_code[LEN_USGSERV_CODE + LEN_SPARE];                
                              /* The Service Code.            */

  char usgserv_type[LEN_USGSERV_TYPE + LEN_SPARE];                
                              /* The Service Type.            */

  char mrkglcode[LEN_MRKGLCODE + LEN_SPARE];
                              /* Markup GLcode                */

 /* char mrkserv_cat[LEN_MRKSERV_CAT + LEN_SPARE];*/
  char mrkserv_cat[LEN_MRKSERV_CODE + LEN_SPARE];
                              /* Markup service cat code.     */

  char mrkserv_code[LEN_MRKSERV_CODE + LEN_SPARE];
                              /* Markup service code          */

  char mrkserv_type[LEN_MRKSERV_TYPE + LEN_SPARE];
                              /* Markeup service type         */
  MpIndex tmindex;            /* References a row of the      */
                              /* index list for TMDEFTAB.     */

  PUDEFTAB_STR *pudeftab;     /* Points to the local price    */
                              /* per unit                     */

};

/*************************************************************/
/*                         PUDEFTAB                          */
/* The next table is the layout for the Price per Unit       */
/* (Click) Table.                                            */
/*************************************************************/

struct spudeftab_str
{

        time_t vdate;               /* Start date and time of this  */
                                    /* entry in UNIX fomat.         */

        double ppuic;               /* The Price per Unit IC.       */

        double ppuair;              /* The Price per Unit AIR.      */

        bscs_code_t tmcode;                 /* The Tariff Model the PPU is  */
                                    /* related to.                  */

        time_t vedate;                         /* The PPU is only valid up to  */
                                    /* this date.                   */

};

/*************************************************************/
/*                         EPDEFTAB                          */
/* The next table is the layout for the Execptional Phone    */
/* Numbers Table.                                            */
/*************************************************************/

#define EP_SERVICE_TYPE_EXCEPTIONAL_NUMBER 'X'

struct sepdeftab_str
{

        int vdate;                  /* Effective date of the        */
                                    /* entry.                       */

        unsigned char dialed_digits[ LEN_DEST_BUF_BCD ] ;
                                    /* The exceptional phone number */
                                    /* coded in BCD.                */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        unsigned char trans_dialed_digits[ LEN_DEST_BUF_BCD ] ;
                                    /* The phone number to which    */
                                    /* exceptional is to be         */
                                    /* translated to coded in BCD.  */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        char service_type;          /* The service type associated  */
                                    /* to the dialed digits.        */

};

/*************************************************************/
/*                      ECDEFTAB                             */
/* This structure contains all effective dated external      */
/* carriers.                                                 */
/*************************************************************/

struct secdeftab_str
{

        time_t  vdate ;             /* The effective timestamp of   */
                                    /* the entry.                   */

        bscs_code_t  eccode ;       /* Code of the external carrier.*/

        bscs_code_t tmcode_in;      /* Contains the Tariff Model    */
                                    /* Code for calls entering the  */
                                    /* HPLMN from this external     */
                                    /* carrier.                     */

        bscs_code_t  svpcode_in ;   /* Contains the Service Package */
                                    /* Code for calls entering the  */
                                    /* HPLMN from this external     */
                                    /* carrier.                     */

        bscs_code_t  tmcode_out;    /* Contains the Tariff Model    */
                                    /* Code for calls leaving the   */
                                    /* HPLMN to this external       */
                                    /* carrier.                     */

        bscs_code_t  svpcode_out ;  /* Contains the Service Package */
                                    /* Code for calls leaving the   */
                                    /* HPLMN to this external       */
                                    /* carrier.                     */

        int       time_slice;       /* The width of the time slice  */
                             /* in minutes.                  */

        char      status ;          /* Specifies the status of an   */
                                    /* External Carrier. The values */
                                    /* are A: Active D: Deactive    */

};

/*************************************************************/
/*                         UTDEFTAB                          */
/* This structure contains for the HPLMN PLMN the time       */
/* difference to the UTC time.                               */
/*************************************************************/

struct sutdeftab_str
{

        time_t  vdate ;             /* Effective date and time of   */
                                    /* this entry in UNIX fomat.    */

        long int  time_offset ;     /* Offset in seconds.           */

   char timeshift;             /* Timeshift H/V:               */
                               /* use HPLMN/VPLMN time.        */

        unsigned char cc_ndc[ LEN_DN_BUF + LEN_SPARE ];
                                    /* CC and NDC of PLMN.          */

        unsigned char mcc_mnc[ LEN_PORT_BUF_BCD ];
                                    /* The Mobile Country Code and  */
                                    /* Mobile Network Code of       */
                                    /* the PLMN coded in BCD.       */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

};

/*************************************************************/
/*                         RGDEFTAB                          */
/* This structure contains informatin about the Country      */
/* Code, National Destination Code, etc. of VPLMNs. It is    */
/* needed to identify the Subscribers that belong to the     */
/* VPLMNs and manage the M-M Assembly for roamer. Also this  */
/* structure contains all VPLMNs to which HPLMN has a roaming*/
/* agreement.                                                */
/*************************************************************/

#define TRAC_VERSION_TD01 1

#define TRAC_VERSION_TD17 2

#define TRAC_VERSION_TD27 3

#define TRAC_VERSION_CIBER 4

#define TRAC_VERSION_EMBRATEL 6

#define PER_IND_PROCESSING_DATE  'P'

#define PER_IND_CALL_RECORD_DATE 'T'

#define TAX_TREATMENT_YES 'Y'

#define TAX_TREATMENT_NO  'N'

#define OPT_ROUTING_IND_TROMBONING 'T'

#define OPT_ROUTING_IND_OPT_ROUT   'O'

#define STATUS_ACTIVE   'A'

#define STATUS_DEACTIVE 'D'

#define EMPTY_TAP_SUPPORT_YES 'Y'

#define EMPTY_TAP_SUPPORT_NO  'N'

#define TA_MTC_IN_YES 'Y'

#define TA_MTC_IN_NO  'N'

#define TA_MTC_OUT_YES 'Y'

#define TA_MTC_OUT_NO  'N'

struct srgdeftab_str
{

  time_t  vdate ;             /* Start date and time of this  */
                              /* entry in UNIX fomat          */

  bscs_code_t plcode;         /* A unique identifier for the  */
                              /* PLMN.                        */

  bscs_code_t sccode;         /* The Service Class Code       */

  bscs_code_t tmcode;         /* Contains the Tariff Model    */
                              /* Code for this PLMN.          */

  bscs_code_t  svpcode ;      /* Contains the Service Package */
                              /* Code for this PLMN.          */

  bscs_code_t tmcode_mtc_out; /* Contains the Tariff Model    */
                              /* for outgoing roamer MTCs.    */

  bscs_code_t spcode_mtc_out; /* Contains the service package */
                              /* code for outgoing roamer MTCs*/

  long int sdr_threshold;     /* The threshold for the        */
                              /* MAX-SDR Check.               */
  
  int       tap_ver_out ;     /* TAP standard for outgoing.   */

  int       tap_ver_in ;      /* TAP standard for incoming.   */

  int       tap_version_out ; /* TAP version for outgoing.    */

  int       tap_version_in ;  /* TAP version for incoming.    */

  unsigned char cc [ LEN_DN_PART_BUF_BCD ] ;
                              /* Country Code.                */

  unsigned char ndc [ LEN_DN_PART_BUF_BCD ] ;
                              /* National Destination Code    */

  unsigned char mcc_mnc [ LEN_PORT_BUF_BCD ];
                              /* The Mobile Country Code and  */
                              /* Mobile Network Code of       */
                              /* the PLMN coded in BCD.       */
                              /* Trailing digits which are not*/
                              /* used are filled with HEX 'F'.*/

  char  vplmn_name_in [ LEN_TAP_NAME + LEN_SPARE ] ;
                              /* The TAP identifier of the    */
                              /* VPLMN for incoming TAP       */
                              /* files.                       */

  char vplmn_name_out [ LEN_TAP_NAME + LEN_SPARE ] ;
                              /* The TAP identifier of the    */
                              /* VPLMN for outgoing TAP       */
                              /* files.                       */

  char  hplmn_name_in [ LEN_TAP_NAME + LEN_SPARE ] ;
                              /* The TAP identifier of the    */
                              /* HPLMN for incoming TAP       */
                              /* files.                       */

  char hplmn_name_out [ LEN_TAP_NAME + LEN_SPARE ] ;
                              /* The TAP identifier of the    */
                              /* HPLMN for outgoing TAP       */
                              /* files.                       */

  char      status ;          /* Status of this entry         */
                              /* 'A' = active , 'D' = deactive*/

  char      opt_rout_ind ;    /* Indicates optimized routing  */
                              /* between HPLMN and the VPLMN  */

  char      tax_treat_out ;   /* Tax treatment for outgoing   */
                              /* TAP files.                   */

  char      tax_treat_in ;    /* Tax treatment for incoming   */
                              /* TAP files.                   */

  char      per_ind ;         /* Specifies which timestamp    */
                              /* is used to determine the     */
                              /* pegged exchange rate for     */
                              /* incoming TRAC User files. The*/
                              /* values are P: The processing */
                              /* date T: The timestamp in the */
                              /* call record                  */

  unsigned char empty_tap_support;
                              /* Flag for empty TAP-file support. */

  unsigned char ta_mtc_in;    /* Flag for incoming charged        */
                              /* TA_MTC support.                  */

  unsigned char ta_mtc_out;   /* Flag for outgoing charged TA_MTC */
                              /* support.                         */

/* The next field is for internal purposes only.             */

  unsigned char cc_ndc[ LEN_DN_BUF_BCD ];
                              /* CC and NDC in one field.     */

  unsigned char app_fed_tax;  /* Flag to determine whether or not */
                              /* apply federal taxes to roamer    */
                              /* records.                         */

  unsigned int customer_id;   /* The customer id that this roaming*/
                              /* agreement belongs to.            */

  unsigned char plmn_type;    /* The type of the plmn that this   */
                              /*  roaming agreement belongs to.   */

  /* Added for feature 21733 */
  unsigned char re_rate;      /* Flag to re-rate this roaming     */
                              /* partners records.                */

  unsigned int tm_re_rate;    /* The tariff model to use for      */
                              /* re-rating incollects.            */

  unsigned int sp_re_rate;    /* The service package to use for   */
                              /* re-rating incollects.            */

  /* Added for feature 21723 */
  unsigned int clearinghouse_id;
                              /* The id of the clearinghouse that */
                              /* this roaming partner uses.       */

  unsigned int fc_id;         /* The id of the foreign currency   */
                              /* that this roaming partner uses.  */
 
  unsigned char char_set_in;  /* The character set for incoming   */
                              /* CIBER files.                     */

  unsigned char char_set_out; /* The character set for outgoing   */
                              /* CIBER files.                     */

};

/*************************************************************/
/*                         RADEFTAB                          */
/* The next table is the layout for the Roaming              */
/* Administration Table.                                     */
/*************************************************************/

#define FLAT_ADMINFEE       'F'

#define PERCENTAGE_ADMINFEE 'P'

struct sradeftab_str
{

        time_t  vdate ;             /* Start date and time of this  */
                                    /* entry in UNIX fomat          */

        bscs_code_t plcode;         /* An unique identifier for the */
                                    /* PLMN.                        */

        double    adminfee ;        /* The administration fee as a  */
                                    /* flat amount (e.g. 5.38DM) or */
                                    /* fraction (e.g. 0.1 for 10%)  */


        unsigned char mcc_mnc[ LEN_PORT_BUF_BCD ];
                                    /* The Mobile Country Code and  */
                                    /* Mobile Network Code of       */
                                    /* the PLMN coded in BCD.       */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        char      adminfee_type ;   /* Specifies whether the        */
                                    /* administration for incoming  */
                                    /* charged records is a flat    */
                                    /* rate or a percentage of the  */
                                    /* charge. The values are       */
                                    /* F: Flat P: Percentage        */

  /* Following added for feature 24023.  DLM 8/19/97 */
    
        double    toll_admin_fee;   /* The administration fee as a  */
                                    /* flat amount (e.g. 5.38DM) or */
                                    /* fraction (e.g. 0.1 for 10%)  */

        char      toll_admin_type;  /* Specifies whether the        */
                                    /* administration for incoming  */
                                    /* charged records is a flat    */
                                    /* rate or a percentage of the  */
                                    /* charge. The values are       */
                                    /* F: Flat P: Percentage        */

  /* End of additions. */

};

/*************************************************************/
/*                         CNDEFTAB                          */
/* The next structure is the layout for the Dialed Digits    */
/* Counter Definition Table.                                 */
/*************************************************************/

struct scndeftab_str
{

        long int cnty;            /* The Y counter.               */

        unsigned char dialed_digits [ LEN_DEST_BUF_BCD ] ;
                                    /* The dialed digits coded in   */
                                    /* BCD.                         */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

};

/*************************************************************/
/*                         INDEFTAB                          */
/* The next structure is the layout for the Invisible        */
/* Numbers Definition Table.                                 */
/*************************************************************/

struct sindeftab_str
{

        bscs_id_t contract_id;    /* The contract id              */

        unsigned char dialed_digits [ LEN_DEST_BUF_BCD ] ;
                                    /* The dialed digits coded in   */
                                    /* BCD to be blanked.           */
                                    /* The structure is: CC_NDC_SN  */

};

/*************************************************************/
/*                         ISDEFTAB                          */
/* The next structure is the layout for the IMSI Services    */
/* Definition Table.                                         */
/*************************************************************/

struct sisdeftab_str
{

        time_t vdate;               /* Effective date.              */

        bscs_id_t contract_id;      /* Internal key for contract.   */

        bscs_code_t tmcode;         /* The tariff model code        */

        bscs_code_t sncode;         /* Service Name Code.           */

        bscs_code_t svpcode ;       /* Contains the Service Package */
                                    /* Code.                        */

        long int seqno;             /* Version number.              */

        char pi[ LEN_PI + LEN_SPARE ] ;
                                    /* The Priceable Item.          */

        char status;                /* The status of a service.     */

    /* Following field added for feature 24133.  DLM 12/05/97 */

  int pr_cust_id;               /* The customer id who is     */
                                /* payment responsible for    */
                                /* this service.              */

    /* Feature 24133 - End additions. */

};

/*************************************************************/
/*                      CODEFTAB                             */
/* This structure contains all data unique to a contract.    */
/*************************************************************/

#define AN_FLAG_YES 'Y'
#define AN_FLAG_NO 'N'

#define DELETE_AFTER_BILLING_YES 'Y'
#define DELETE_AFTER_BILLING_NO  'N'

#define TOLLRATE_MODE_OBO 'O'
#define TOLLRATE_MODE_EXT 'E'

struct scodeftab_str
{

        CV_UN cv_un;                /* Internal key for contract.   */

        bscs_id_t customer_id;      /* Internal key for customer.   */

        bscs_code_t plcode;         /* The plcode of the contract.  */

        char cust_group[ LEN_CUSTGROUP + LEN_SPARE ];
                                    /* The customer group.          */

        char      anflag ;          /* Specifies as to whether      */
                                    /* trailing digits are not to   */
                                    /* be printed on the itemised   */
                                    /* bill.                        */

        char delete_after_billing;
                                    /* Specifies as to whether a    */
                                    /* RTX Record is to be deleted  */
                                    /* after billing.               */

        char      tollrate_mode ;   /* Values: 'O' = On behalf of   */
                                    /*         'E' = External.      */

        char      bc [ LEN_BC ] ;   /* Bill Cycle.                  */

        char      rbc [ LEN_RBC ] ; /* Rental Bill Cycle            */

    /* Following field added for feature 24159.  DLM 12/04/97 */

  int costcenter_id;            /* The id of the costcenter that the*/
                                /* customer belongs to.             */

};

/*************************************************************/
/*                      LKDEFTAB                             */
/* This structure contains all HPLMN MSISDNs for the Direct  */
/* Subscribers and the associated rating relevant data.      */
/*************************************************************/

struct slkdeftab_str
{

        CO_UN  contract_un;         /* Internal key for contract.   */

        time_t  vdate ;             /* The effective timestamp of   */
                                    /* the entry.                   */

        time_t  ddate;              /* Defect 27346, rroeder 04/20/98 */
                                    /* The deactivation timestamp of  */
                                    /* the entry.                     */

        bscs_id_t dn_id;            /* Internal key for Directory   */
                                    /* Number.                      */

        bscs_id_t port_id;          /* Internal key for Port.       */

      /* Size of following field changed from LEN_DN_PART_BUF_BCD for
         feature 23758    DLM 8/4/97   */

        unsigned char sn [ LEN_DN_BUF_BCD ] ;
                                    /* Contains the SN part of      */
                                    /* the MSISDN coded in BCD.     */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        unsigned char msin [ LEN_PORT_PART_BUF_BCD ] ;
                                    /* Contains the MSIN part of the*/
                                    /* IMSI coded in BCD. Trailing  */
                                    /* digits which are not used are*/
                                    /* filled with HEX 'F'.         */

        char in_hash_table;         /* Indicates if this entry is   */
                                    /* in the hash table.           */

};

/*************************************************************/
/*                         PNDEFTAB                          */
/* The next structure is the layout for the Special Phone    */
/* Numbers Definition Table.                                 */
/*************************************************************/

#define TMFLAG_SPECIAL_NUMBER 'Y'
#define TMFLAG_SUBSCRIBER     'N'

#define FUOMSPN_SPECIAL_NUMBER_YES 'Y'
#define FUOMSPN_SPECIAL_NUMBER_NO  'N'

#define ACTION_CODE_SPECIAL_NUMBER 'S'

#define SPECIAL_NUMBER_ACTIVE   'a'
#define SPECIAL_NUMBER_DEACTIVE 'd'

struct spndeftab_str
{

        time_t vsdate;              /* The effective timestamp of   */
                                    /* the entry.                   */

        bscs_code_t tmcode;         /* Contains the Tariff Model    */
                                    /* Code for this Special Number.*/

        bscs_code_t svpcode;        /* Contains the Service Package */
                                    /* Code for this Special Number.*/

        short int an_digits;        /* Number of trailing digits to */
                                    /* be blanked out.              */

        unsigned char dialed_digits [ LEN_DEST_BUF_BCD ] ;
                                    /* The special phone number.    */
                                    /* coded in BCD.                */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        char pi[ LEN_PI + LEN_SPARE ] ;
                                    /* The Priceable Item.          */

        char tmflag;                /* Specifies whether the Tariff */
                                    /* Model from the Special Phone */
                                    /* Number is taken (Y) or from  */
                                    /* the subscriber (N).          */

        char status;                                     /* The status change of a       */
                                                                                 /* special number at the vsdate.*/

        char fuomspn;                                    /* inside/outside scope of fUoM.*/

        char anychar;               /* Character, which will be used*/
                                    /* to pad anonymized numbers.   */

};

/*************************************************************/
/*                         IXDEFTAB                          */
/* The next structure is the layout for the Interexchange    */
/* Carrier Code to Carrier Name Link Table.                  */
/*************************************************************/

struct sixdeftab_str
{

        bscs_code_t eccode;         /* Code of the external Carrier.*/

        unsigned char ixccode[ LEN_IXCCODE_BCD ];  
                                    /* Unique identifier for an     */
                                    /* interexchange carrier.       */

        char exchange_id[ LEN_EXCHANGE_ID + LEN_SPARE ];
                                    /* MSC identity from NEDEFTAB.  */

        char carrier_name[ LEN_CARRIER_NAME + LEN_SPARE ];
                                    /* The CCMI defined carrier     */
                                    /* name.                        */

        char intrastate_service[ LEN_CARRIER_SERVICE_ID + LEN_SPARE ];
                                    /* The intra state service id.  */

        char interstate_service[ LEN_CARRIER_SERVICE_ID + LEN_SPARE ];
                                    /* The inter state service id.  */

        char default_carrier;       /* If 'X' this is the default   */
                                    /* carrier.                     */

};

/* Feature 10266 */
/*************************************************************/
/*                         SBDEFTAB                          */
/* The next sturcture is the layout for the serving bid      */
/* definition table.                                         */
/*************************************************************/

struct ssbdeftab_str
{
  char bid[LEN_SERVING_BID + LEN_SPARE];
                                    /* The BID value                */

  char bid_desc[LEN_SERVING_BID_DESC + LEN_SPARE];
                                    /* The character description of */
                                    /* the bid.                     */

  unsigned char begin_cgi[LEN_ORIG_BUF + LEN_SPARE];
                                    /* The beginning cgi value      */
                                    /* associated with this bid     */

  unsigned char end_cgi[LEN_ORIG_BUF + LEN_SPARE];
                                    /* The ending cgi value         */
                                    /* associated with this bid     */

  time_t vsdate;                    /* The timestamp of the         */
                                    /* effective date of this entry */

  unsigned char geocode[LEN_GEOCODE + LEN_SPARE];
                                    /* The geocode associated with  */
                                    /* this bid.                    */

/*  unsigned char oper_unit[LEN_OPERATING_UNIT + LEN_SPARE];*/
  unsigned char oper_unit[LEN_OPERATING_UNIT + LEN_SPARE];
                                    /* The Operating Unit associated*/
                                    /*  with this bid.              */

  /* Added for feature 21723 */
  unsigned char city[LEN_US_CITY + LEN_SPARE];
                                    /* The city that this operating */
                                    /* unit is located in.          */

  unsigned char state[LEN_US_STATE + LEN_SPARE];
                                    /* The state that this operating*/
                                    /* unit is located in.          */

  /* Added for feature 23544   MAT 10/4/97 */

 /* unsigned char country[LEN_COUNTRY + LEN_SPARE];*/
  unsigned char country[LEN_COUNTRY + LEN_SPARE];
                                    /* The country used to determine */
                                    /* which tax library to use      */

    /* Added for feature 24159.  DLM 12/04/97 */

  int oucode;                   /* The Operating unit's internal ID. */
};  

/* Following two xref files created for feature 21733.       */

/*************************************************************/
/*                         RUDEFTAB                          */
/* The next structure is the layout for the roamer record    */
/* usage type to gsmcode mapping table.                      */
/*************************************************************/

struct srudeftab_str
{
  unsigned int tvcode;              /* The tap version code        */

  unsigned int usage_type;          /* The roamer record usage type*/
                                    /* as defined by the standard  */

  unsigned char code;               /* The basic number part of    */
                                    /* the svlcode                 */

  char type;                        /* The service type.           */

};

/*************************************************************/
/*                         URDEFTAB                          */
/* The next structure is the layout for the roamer record    */
/* usage type to gsmcode mapping table.                      */
/*************************************************************/

struct surdeftab_str
{
  unsigned int tvcode;              /* The tap version code        */

  unsigned int usage_type;          /* The roamer record usage type*/
                                    /* as defined by the standard  */

  char gsmcode[LEN_PI + LEN_SPARE];
                                    /* The basic number part of    */
                                    /* the svlcode                 */

  char type;                        /* The service type.           */

};

/* Following XREF structure defined for feature 21723. */

/*************************************************************/
/*                         HBDEFTAB                          */
/* The next structure is the layout for the Home Bid         */
/* Definition Table.                                         */
/*************************************************************/

struct shbdeftab_str
{
/*  unsigned char msisdn_start[LEN_MSISDN_START + LEN_SPARE];*/
  unsigned char msisdn_start[LEN_DN_BUF + LEN_SPARE];
                                    /* The beginning MSISDN in this*/
                                    /* home bid.                   */

/*  unsigned char msisdn_end[LEN_MSISDN_END + LEN_SPARE];*/
  unsigned char msisdn_end[LEN_DN_BUF + LEN_SPARE];
                                    /* The ending MSISDN in this   */
                                    /* home bid.                   */

  time_t vsdate;                    /* The effective date of this  */
                                    /* entry.                      */

  unsigned char home_bid[LEN_HOME_BID + LEN_SPARE];
                                    /* The home bid value          */

  unsigned char home_bid_desc[LEN_HOME_BID_DESC + LEN_SPARE];
                                    /* The home bid description    */

  unsigned char state[LEN_US_STATE + LEN_SPARE];
                                    /* The state of the home bid   */

};

/*************************************************************/
/*                         RBDEFTAB                          */
/* The next structure is the layout for the Rental Billing   */
/* Definition Table.                                         */
/*************************************************************/

struct srbdeftab_str
{

        bscs_code_t  tmcode;        /* The Tariff Model Code        */

        bscs_id_t  dn_id;           /* Key to Directory Number      */

        unsigned char port_num [ LEN_PORT_BUF_BCD ];
                                    /* The Port which the tariff    */
                                    /* model is assigned to         */

};

/* Added for feature 23607   DLM 7/9/97 */

/*************************************************************/
/*                        ZPDEFTAB                           */
/* Desclarations for the zonal destination table.            */
/*************************************************************/

typedef struct szpdeftab_str ZPDEFTAB_STR;

struct szpdeftab_str
{
  unsigned char digits[LEN_DEST_BUF_BCD];
                                    /* THe dialled digits associated */
                                    /* with the zone destination.    */

  unsigned char geocode[LEN_GEOCODE + LEN_SPARE];
                                    /* The geocode associated with   */
                                    /* the zone destination.         */

  /* Added for feature 24463_1 - rroeder 10/21/98 */
  unsigned char des[ LEN_DEST_BUF + LEN_SPARE ];
  /* End of additions. */

};

/* End of additions */

/*************************************************************/
/*                      ZODEFTAB                             */
/* Declaration for zonal point origins table.                */
/* Added for feature 24463_1 - rroeder 10/21/98              */
/*************************************************************/

typedef struct szodeftab_str ZODEFTAB_STR;

struct szodeftab_str
{
    unsigned char cgi[ LEN_ORIG_BUF + LEN_SPARE ];
    unsigned char geocode[ LEN_GEOCODE + LEN_SPARE ];
    unsigned char des[ LEN_DEST_BUF + LEN_SPARE ];
    long int      rowcount; 
}; 


/* Added for feature 28564.  DLM 6/10/98 */

/*************************************************************/
/*                                                           */
/*                        SVDEFTAB                           */
/* Link table from sncode to svlcode.                        */
/*                                                           */
/*************************************************************/

typedef struct ssvdeftab_str SVDEFTAB_STR;

struct ssvdeftab_str
{
  bscs_code_t sncode;           /* THe internal code for the */
                                /* service.                  */

  char svlcode[ LEN_PI + LEN_SPARE ];
                                /* The svlcode assigned to   */
                                /* this sncode.              */

  char cdr_prod_ind;            /* Indicator as to whether   */
                                /* this service could appear */
                                /* on a call record.         */

};

/*************************************************************/
/*************************************************************/
/*                                                           */
/* This file section contains declarations and definitions   */
/* for Message Processing Cross Reference Tables handling    */
/* in memory.                                                */
/*                                                           */
/*************************************************************/
/*************************************************************/

/*************************************************************/
/*                         TZP-TREE                          */
/* Declarations for Terminating Zonal Points and             */
/* Originating Zonal Points.                                 */
/*************************************************************/

#define NUM_DD_DIGITS  15

#define NUM_CGI_DIGITS 16

typedef struct sozp_tree OZP_KNOT;

typedef struct stzp_tree TZP_KNOT;

struct stzp_tree
{

        bscs_code_t tzcode;         /* The Tariff Zone Code.        */

        bscs_code_t zpcode;         /* Terminating Zonal Point Code.*/

/****************************************************************/
/*                                                              */
/* Following field was added for support of tax enhacements in  */
/*   BSCS 4.01_us.  Feature 12998.  The reason for a pointer to */
/*   the dzdeftab structure is so that no extra memory is taken */
/*   up for the geocode information.                            */
/*                                                              */
/****************************************************************/

    DZDEFTAB_STR *dzdeftab_ptr; /* Pointer to the dzdeftab xref */
                                /*  that contains the           */
                                /*  appropriate geocode info.   */

/* End of additions.  DLM 08.15.96                              */

        OZP_KNOT *ozp;              /* Points to the OZP tree       */
                                    /* associated to this DD.       */
                                    /* (used for reverse matching)  */

        TZP_KNOT *child;            /* Points to the childs.        */

};

struct sozp_tree
{

        TZP_KNOT *tzp;              /* Points to the TZP tree       */
                                    /* associated to this CGI.      */

        OZP_KNOT *child;            /* Points to the childs.        */
        
        bscs_code_t tzcode;         /* If reverse matching is used  */
                                    /* the zone code                */

/****************************************************************/
/*                                                              */
/* Following field was added for support of tax enhacements in  */
/*   BSCS 4.01_us.  Feature 12998.  The reason for a pointer to */
/*   the dzdeftab structure is so that no extra memory is taken */
/*   up for the geocode information.                            */
/*                                                              */
/****************************************************************/

    DZDEFTAB_STR *dzdeftab_ptr; /* Pointer to the dzdeftab xref */
                                /*  that contains the           */
                                /*  appropriate geocode info.   */

/* End of additions.  DLM 08.15.96                              */

};

/*************************************************************/
/*                         DZMEMTAB                          */
/* The next structure is the layout for the memory table     */
/* containing the pointers to the Dialed Zone tables.        */
/*************************************************************/

struct sdzmemtab_str
{

        bscs_code_t zccode;         /* The Zone Coverage Code.      */

        bscs_code_t vscode;         /* The Version                  */

        DZDEFTAB_STR *dzdeftab;     /* Contains the dialed zones    */
                                    /* belonging to the key.        */

        long int n_dzdeftab;        /* Number of entries in the     */
                                    /* dialed zones table.          */

        OZP_KNOT *ozp_anchor;       /* Pointer to the OZP-tree for  */
                                    /* this zone coverage.          */

        TZP_KNOT *tzp_anchor;       /* Pointer to the TZP-tree for  */
                                    /* this zone coverage.          */
                                    /* (for reversed matching)      */

};

/*************************************************************/
/*                         TCMEMTAB                          */
/* The next structure is the layout for the memory table     */
/* containing the pointers to the time code tables.          */
/*************************************************************/

struct stcmemtab_str
{

        bscs_code_t twcode;         /* The Tariff Week Code.        */

        bscs_code_t vscode;         /* The Version                  */

        TCDEFTAB_STR *tcdeftab;     /* Contains the time codes      */
                                    /* belonging to the key.        */

        long int n_tcdeftab;        /* Number of entries in the     */
                                    /* time code table.             */

};


/*************************************************************/
/*                         EMBTXTAB                          */
/*  feature 32599 -pzhang 04/01/99                           */
/*************************************************************/

typedef struct sembtxtab_str EMBTXTAB_STR; /* 32599 */

struct sembtxtab_str
{

        int embratel_tax_rates_id;       

        int file_type;         

        int nature_code;
        
        double tax_rate;

        long int  version_date;

        int rec_version;

};


/*************************************************************/
/*                      COVECTAB                             */
/* This structure contains pointers to further information   */
/* for a contract.                                           */
/*************************************************************/

struct scovectab_str
{

        bscs_id_t contract_id;      /* Internal key for contract.   */

        INDEFTAB_STR *indeftab;          /* Points to the Invisible      */
                                                                                 /* Numbers associated with a    */
                                                                                 /* contract                     */
        int n_indeftab;                          /* Number of Invisible Numbers  */
                                                                                 /* associated with a contract   */

        ISDEFTAB_STR *isdeftab;     /* Points to the services       */
                                    /* associated with a contract   */
        int n_services;             /* Number of above services.    */

        FFDEFTAB_STR *ffdeftab;     /* Pointer to the Friends and   */
                                                                                 /* Family MC associated with a  */
                                                                                 /* contract.                    */

        long int n_ffdeftab;        /* Number of different entries  */
                                                                                 /* in FFDEFTAB for a contract.  */

        MCDEFTAB_STR *mcdeftab;     /* Pointer to the first entry   */
                                    /* in a Micro Cell.             */
        int n_mcdeftab;             /* Number of Entries per        */
                                    /* Micro Cell.                  */

};

/*************************************************************/
/*                 LKDEFTAB POINTER                          */
/* The following two structures are for fast retrieving of   */
/* the data stored in the LKDEFTAB.                          */
/*************************************************************/

struct sdir_lkptr_str
{

      /* Size of following field changed from LEN_DN_PART_BUF_BCD
         for feature 23758    DLM 8/4/97  */
    
        unsigned char sn [ LEN_DN_BUF_BCD ] ;
                                    /* Contains the SN part of      */
                                    /* the MSISDN coded in BCD.     */
                                    /* Trailing digits which are not*/
                                    /* used are filled with HEX 'F'.*/

        long int  vdate ;           /* The effective timestamp of   */
                                    /* the entry.                   */

        long int  ddate;            /* Defect 27346, rroeder 04/20/98 */
                                    /* The deactivation timestamp of  */
                                    /* the entry.                     */

        char in_hash_table;         /* If not zero, the slot is in  */
                                    /* the sn hash table.           */

        LKDEFTAB_STR *lkdeftab;     /* Points to an entry           */

};


/*************************************************************/
/*                         PN-TREE                           */
/* Declarations for special numbers' trees.                  */
/*************************************************************/

struct pn_knot
{

        void *target;               /* Points to the found target   */

        PN_KNOT *child;             /* Points to the childs.        */

};

/* Added for feature 23607   DLM 7/9/97 */

/*************************************************************/
/*                         ZP-TRIE                           */
/* A trie for the zonal destinations.                        */
/*************************************************************/

typedef struct szp_node ZP_NODE;

struct szp_node
{
  unsigned char geocode[LEN_GEOCODE + LEN_SPARE];
                                    /* The geocode associated with */
                                    /* this zonal point.           */

  ZP_NODE *children[NUM_DD_DIGITS]; /* The children of this node   */

  /* Feature #24463_1 - rroeder 10/21/98 - Begin */
  unsigned char des[ LEN_DEST_BUF + LEN_SPARE ];
  /* Feature #24463_1 - End */

};

/* End of additions. */

/*************************************************************/
/*************************************************************/
/*                                                           */
/* The next structure is the pool for all Cross Reference    */
/* Table anchors.                                            */
/*                                                           */
/*************************************************************/
/*************************************************************/

struct sxref_pool_str
{

        long int memsize;           /* Counts the size of allocated */
                                    /* memory.                      */

        char teh_date[ LEN_DATE + LEN_SPARE ];
                                    /* The date of the last run of  */
                                    /* the TEH.                     */

        PN_KNOT *pn_anchor;         /* Anchor for PNDEFTAB tree     */

        PN_KNOT *ep_anchor;         /* Anchor for EPDEFTAB tree     */

        PN_KNOT *tk_anchor;         /* Anchor for EPDEFTAB tree     */

/*************************************************************/
/* The remainder are the anchors for the Cross Reference     */
/* Tables.                                                   */
/*************************************************************/

        HPDEFTAB_STR *hpdeftab;

        long int n_hpdeftab;

        HLDEFTAB_STR *hldeftab;

        long int n_hldeftab;

        CODEFTAB_STR *codeftab;

        long int n_codeftab;

        CODEFTAB_STR *codefovf;

        long int n_codefovf;

        COVECTAB_STR *covectab;

        long int n_covectab;

        COVECTAB_STR *covecovf;

        long int n_covecovf;

        DZDEFTAB_STR *dzdeftab;

        long int n_dzdeftab;

        DZLSTTAB_STR *dzlsttab;

        long int n_dzlsttab;

        DZMEMTAB_STR *dzmemtab;

        long int n_dzmemtab;

        ECDEFTAB_STR *ecdeftab;

        long int n_ecdeftab;

        EPDEFTAB_STR *epdeftab;

        long int n_epdeftab;

        FIDEFTAB_STR *fideftab;

        long int n_fideftab;

        GSDEFTAB_STR *gsdeftab;

        long int n_gsdeftab;

        GZDEFTAB_STR *gzdeftab;

        long int n_gzdeftab;

        IADEFTAB_STR *iadeftab;

        long int n_iadeftab;

        LKDEFTAB_STR *lkdeftab;

        DIR_LKPTR_STR *dir_lkptr;

        long int n_lkdeftab;

        LKDEFTAB_STR *lkdefovf;

        LKDEFTAB_STR **next_lkdefovf;

        long int n_lkdefovf;

        long int max_port_errors;

        ISDEFTAB_STR *isdeftab;

        long int n_isdeftab;

        ISDEFTAB_STR *isdefovf;

        long int n_isdefovf;

        CNDEFTAB_STR *cndeftab;

        long int n_cndeftab;

        NEDEFTAB_STR *nedeftab;

        long int n_nedeftab;

        TKDEFTAB_STR *tkdeftab;

        long int n_tkdeftab;

        XRDEFTAB_STR *xrdeftab;

        long int n_xrdeftab;

        RMDEFTAB_STR *rmdeftab;

        long int n_rmdeftab;

        MCDEFTAB_STR *mcdeftab;

        long int n_mcdeftab;

        MCDEFTAB_STR *glb_mc;         /* Points to the global MC in */
                                                                                        /* MCDEFTAB else NULL.        */
        long int n_glb_mc;            /* Number of entries for      */
                                                                                        /* global MC in MCDEFTAB else */
                                                                                        /* NULL.                      */

        FFDEFTAB_STR *ffdeftab;

        long int n_ffdeftab;

        FFDDDTAB_STR *ffdddtab;

        long int n_ffdddtab;

        CCDEFTAB_STR *ccdeftab;

        long int n_ccdeftab;

        PNDEFTAB_STR *pndeftab;

        long int n_pndeftab;

        INDEFTAB_STR *indeftab;

        long int n_indeftab;

        SGDEFTAB_STR *sgdeftab;

        long int n_sgdeftab;

        TCDEFTAB_STR *tcdeftab;

        long int n_tcdeftab;

        TCLSTTAB_STR *tclsttab;

        long int n_tclsttab;

        TCMEMTAB_STR *tcmemtab;

        long int n_tcmemtab;

        HODEFTAB_STR *hodeftab;

        long int n_hodeftab;

        TMDEFTAB_STR *tmdeftab;

        long int n_tmdeftab;

        RIDEFTAB_STR *rideftab;

        long int n_rideftab;

        EVDEFTAB_STR *evdeftab;

        long int n_evdeftab;

        EGDEFTAB_STR *egdeftab;

        long int n_egdeftab;

        PUDEFTAB_STR *pudeftab;

        long int n_pudeftab;

        UTDEFTAB_STR *utdeftab;

        long int n_utdeftab;

        RGDEFTAB_STR *rgdeftab;

        long int n_rgdeftab;

        RADEFTAB_STR *radeftab;

        long int n_radeftab;

        IXDEFTAB_STR *ixdeftab;

        long int n_ixdeftab;

        RBDEFTAB_STR *rbdeftab;

        long int n_rbdeftab;

        SBDEFTAB_STR *sbdeftab;

        long int n_sbdeftab;

  /* Feature #24463_1 - rroeder 10/21/98 - Begin */

  ZODEFTAB_STR *zodeftab;

  long int n_zodeftab;

  /* Feature #24463_1 - End */

  /* Added for feature 21733 */

  RUDEFTAB_STR *rudeftab;

  long int n_rudeftab;

  URDEFTAB_STR *urdeftab;

  long int n_urdeftab;

  /* Added for feature 21723 */

  HBDEFTAB_STR *hbdeftab;

  long int n_hbdeftab;

  /* Added for feature 28564. */

  SVDEFTAB_STR *svdeftab;

  long int n_svdeftab;

/*feature 32599 pzhang*/
  EMBTXTAB_STR *embtxtab;

  long int n_embtxtab;

};

#endif

/*************************************************************/
/*                                                           */
/* ABSTRACT : UTX Include for Message Processing Modules.    */
/*                                                           */
/* AUTHOR   : Dr. Klaus-Werner Hoefer LHS                    */
/*                                                           */
/* CREATED  : 06-DEC-1993                                    */
/*                                                           */
/* MODIFIED : 27-JAN-1994 , 20-APR-1996                      */
/*            07-APR-1996,  Don Meredith, Feature 21744      */
/*            07-APR-1996,  Don Meredith, Feature 21755      */
/*                                                           */
/* DESCRIPTION :                                             */
/*                                                           */
/* This C-Include file contains the layouts and definitions  */
/* of the UTX record.                                        */
/*                                                           */
/* CHANGES :                                                 */
/*                                                           */
/* GSM_PI + LEN_SPARE                                        */
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
/* $Log:   V:/PAIS/Archives/Global/BATCH/Include/utx.h-arc  $
 * 
 *    Rev 1.0   Dec 20 2000 12:17:42   kohnr
 * Initial revision.
*/

#ifndef UTX_STR_H
#define UTX_STR_H


#include "com_file.h"


#if 0
static const char *SCCS_VERSION="1.3.1.5";
#endif


/*************************************************************/
/* General UTX Defines.                                      */
/*************************************************************/

#define UTX_RECORD_TAG        0x01
#define UTX_HEADER_TAG        0x02
#define UTX_GSM_BASE_TAG      0x03
#define UTX_SUPL_SERV_TAG     0x04
#define UTX_NON_GSM_TAG       0x05

#define UTX_MOC                  1
#define UTX_MTC                  2
#define UTX_RCF                  3
#define UTX_LTL                  4
#define UTX_EVENT                5
#define UTX_TA_MOC              11
#define UTX_TA_MTC              12
#define UTX_TA_EVENT            13

#define UTX_IN_MOC              16
#define UTX_IN_MTC              17
#define UTX_IN_EVENT            18
#define UTX_IN_VAS              30

#define UTX_VAS                 21
#define UTX_TA_VAS              31

#define MAX_UTX_CALL_TYPE       31
/* This value has to be equal to the greatest utx.call_type. */
/* In this case it is UTX_TA_VAS.                            */

#define UTX_SINGLE             'S'
#define UTX_FIRST              'F'
#define UTX_INTERMEDIATE       'I'
#define UTX_LAST               'L'

#define UTX_TERMIND_DROPPED    'D'
#define UTX_TERMIND_COMPLETED  'C'

#define UTX_AUTOCREDIT_YES     'Y'
#define UTX_AUTOCREDIT_NO      'N'


#define UTX_USAGE_AIR          'A'
#define UTX_USAGE_LAND         'L'

#ifdef CONFIG_SERV_PRO

#define UTX_MASK_NUMBER_IND_YES   'Y'
#define UTX_MASK_NUMBER_IND_NO    'N'

#endif


#define MS_CLASS_MARK_0 '0'
#define MS_CLASS_MARK_1 '1'
#define MS_CLASS_MARK_2 '2'
#define MS_CLASS_MARK_3 '3'
#define MS_CLASS_MARK_4 '4'
#define MS_CLASS_MARK_5 '5'

/*
 * Flags for UTX field utx_params.
 */
#define UTX_PPCFLAG       0x01

/* Added for feature 21755 */

#define UTX_MDACC_MOC       0x04
#define UTX_MDACC_TRANSIT   0x08

/* Added for Feature 29450 */

#define UTX_DAILY_SURCHARGE 0x10
/*************************************************************/
/* Type definitions.                                         */
/*************************************************************/

typedef struct sutx_header_str UTX_HEADER_STR;

typedef struct sutx_gsm_base_str UTX_GSM_BASE_STR;

typedef struct sutx_supl_serv_str UTX_SUPL_SERV_STR;

typedef struct sutx_non_gsm_str UTX_NON_GSM_STR;

/*************************************************************/
/*                      TAG PART                             */
/* The UTX Record consists of several parts. These are the   */
/* GSM Base Part, additional GSM Parts and NON-GSM Part      */
/* respectively, each of them identified by a TAG and length */
/* field. The UTX Record itself is identified by a Super TAG.*/
/* The TAG Part consists of the TAG and length field and has */
/* fixed format which is used all over MP.                   */
/*************************************************************/

typedef RECORD_HDR_STR TAG_STR;

/*************************************************************/
/* The next structure is the layout for the UTX Header       */
/* containing the information of what the header follows.    */
/*************************************************************/

struct sutx_header_str
{

   short int no_of_gsm_part;
                             /* Number of GSM Base Parts in  */
                             /* the UTX Record.              */

   short int no_of_supl_serv_part;
                             /* Number of Supplementary      */
                             /* Service Parts in the UTX     */
                             /* Record.                      */

   short int no_of_non_gsm_part;
                             /* Number of Non GSM Parts in   */
                             /* the UTX Record.              */

};

/*************************************************************/
/*                   GSM Base PART (Optional)                */
/* This structure contains the layout of the UTX Base Part.  */
/* This part is used to specify the base information about a */
/* call using GSM services. If there are suppl. services     */
/* used during the call and/or AoC was used and therefore    */
/* there are e1 to e7 parameters specified, then the         */
/* coresponding parts (Suppl. Service Part and/or AoC Part)  */
/* are added to the UAR Record as many times as they occour. */
/*                                                           */
/* The Served-Party is the subscriber the call-record was    */
/* written for (A-Subscriber in case of MOC or LTL and       */
/* B-Subscriber in case of MTC or RCF respectively).         */
/*************************************************************/

struct sutx_gsm_base_str
{
   long int  timestamp ;     /* Number of seconds that pass  */
                             /* between 1. Jan. 1970 and     */
                             /* Start Day and Time of the    */
                             /* Transaction (UNIX-Time).     */
   long int  time_offset;    /* Time difference between main */
                             /* and other PLMN in seconds.   */
   long int  data_vol ;      /* The number of blocks         */
                             /* transmitted. This will be    */
                             /* zero(0) if the Service is    */
                             /* non Bearer.                  */
   long int  duration ;      /* Duration of the connection.  */
                             /* This will be one(1) if the   */
                             /* Service is an Event.         */
   long int  messages ;      /* The numbger of messages      */
                             /* transmitted. This will be    */
                             /* zero(0) if the Service is    */
                             /* not SMS.                     */
   long int  hplcode;        /* HPLMN code                   */         
   long int  sccode;         /* Service Class code           */         
   long int  gsm_pi_1 ;      /* In this field information    */
                             /* about used Tele- and         */
                             /* Bearerservices is coded by   */
                             /* the formula:                 */
                             /* 16^5 * ( 16 * TeleServiceCode*/
                             /* + Tele_Transparancy) + 16^2  */
                             /* * ( 16 * BearerServiceCode + */
                             /* Bearer_Transparancy) +       */
                             /* 16 * Radio_Chan_Reg +        */
                             /* Radio_Chan_Used              */
   long int  utx_no;         /* The position of the UTX in   */
                             /* the original RIH inputfile.  */
                             /* Only populated by RIH in its */
                             /* 'Reject Files'.              */
   double    tap_net_rate ;  /* This field contains the      */
                             /* charge from TAP records      */
                             /* converted to DM without      */
                             /* taxes (net rate).            */

   char usage_type;          /* Usage type for call.         */
   TaxInfoStr tap_taxes[MAX_NUM_OF_TAXES];
                             /* This array contains the      */
                             /* applicable taxes for the     */
                             /* NAIG TAP II record.          */
   char serving_bid[LEN_SERVING_BID + LEN_SPARE];
                             /* ID of the serving BID.       */
   char serving_bid_desc[LEN_SERVING_BID_DESC + LEN_SPARE];
                             /* Text description of serving  */
                             /* BID.                         */
   char home_bid[LEN_HOME_BID + LEN_SPARE];
                             /* ID of the home BID.          */
   char home_bid_desc[LEN_HOME_BID_DESC + LEN_SPARE];
                             /* Text description of home     */
                             /* BID.                         */

   double    tap_tax_rate ;
                             /* This field contains the      */
                             /* tax for the TAP record       */

   int      call_type ;      /* This identifies the call type*/
                             /* the UAR Record was generated */
                             /* from. ( 1 = MOC, 2 = MTC,    */
                             /* 3 = RCF, 4 = LTL, 5 = Event, */
                             /* 11 = TA-MOC, 12 = TA-MTC,    */
                             /* 13 = TA-Event)               */
   int   no_of_rejections;   /* If not zero, gives the no.   */
                             /* of times the record was      */
                             /* rejected subsequently for    */
                             /* the following reason.        */
   char  reason_code[LEN_REASON_CODE + LEN_SPARE];
                             /* Gives the reason if the      */
                             /* record was rejected for this */
                             /* part                         */
   char      type ;          /* This identifies the record   */
                             /* type the UAR-Record was      */
                             /* generated from. Single record*/
                             /* or First, Intermediate and   */
                             /* Last partial record . int    */
                             /* call_type                    */
   char served_party_ms_class_mark;
                             /* The Mobile Station Class     */
                             /* Mark.                        */
   unsigned char served_party_msisdn  [ LEN_DN_BUF_BCD ] ;
                             /* MSISDN of the Served party.  */
                             /* It is coded in BCD.          */
   unsigned char served_party_sn  [ LEN_DN_PART_BUF_BCD ] ;
                             /* SN of the Served party.      */
                             /* It is coded in BCD.          */
   unsigned char served_party_imsi  [ LEN_PORT_BUF_BCD ] ;
                             /* IMSI of Served party, if     */
                             /* available. It is coded in BCD*/
   unsigned char served_party_imei  [ LEN_SERVED_PARTY_IMEI_BCD ] ;
                             /* IMEI used by Served-party if */
                             /* available. The range of the  */
                             /* valid IMEI according to GSM  */
                             /* specifications. It is coded  */
                             /* in BCD.                      */
#ifdef CONFIG_SERV_PRO
   unsigned char served_party_icc_id [ LEN_SERVED_PARTY_ICC_ID_BCD ] ;
                             /* The serial identifier of the */
                             /* served-party SIM. It is coded*/
                             /* in BCD.                      */
#endif

   unsigned char served_party_cgi  [ LEN_ORIG_BUF + LEN_SPARE ] ;
                             /* Cell Global Identity where   */
                             /* the served-party is located. */
   unsigned char served_party_msc_id  [ LEN_DN_BUF_BCD ] ;
                             /* MSISDN of the MSC where the  */
                             /* served-party is located. It  */
                             /* is coded in BCD.             */
   unsigned char other_party_id  [ LEN_DEST_BUF_BCD ] ;
                             /* This Other-Party-ID identify */
                             /* the Dialed Digits, or in     */
                             /* case of CALL-TYPE = 'MTC'    */
                             /* the MSISDN of the            */
                             /* A-Subscriber if available.   */
                             /* It is coded in BCD.          */
   unsigned char msrn  [ LEN_MSRN_BCD ] ;
                             /* This MSRN is intended to     */
                             /* identify the MSC which is    */
                             /* responsible for the          */
                             /* B-Subscriber (TMSC), and is  */
                             /* used to determine the        */
                             /* distance between the two     */
                             /* parties. It is coded in BCD. */
   unsigned char start_date  [ LEN_START_DATE_BCD ] ;
                             /* Start Date of the            */
                             /* Transaction. It must be a    */
                             /* valid date in the form of    */
                             /* YYYYMMDD coded in BCD.       */
   unsigned char start_time  [ LEN_START_TIME_BCD ] ;
                             /* Start Time of the            */
                             /* Transaction. A valid time    */
                             /* in the format of HHMMSS      */
                             /* coded in BCD.                */
   unsigned char trac_start_date[ LEN_DATE_BCD ];
                             /* Original TRAC Start Date.    */
   unsigned char trac_start_time[ LEN_TIME_BCD ];
                             /* Original TRAC Start Time.    */
   unsigned char  outtrunk  [ LEN_OUTTRUNK + LEN_SPARE ] ;
                             /* The outgoing trunk group.    */
   unsigned char  intrunk  [ LEN_INTRUNK + LEN_SPARE ] ;
                             /* The incoming trunk group.    */
   char      gsm_pi  [ LEN_GSM_PI + LEN_SPARE ] ;
                             /* This field contains the      */
                             /* information about the used   */
                             /* GSM Service.                 */
   char      served_party_mod_ind ;
                             /* Modification Indicator.      */
   char      other_party_ton ;
                             /* Identifies the Type of Number*/
                             /* (TON) used by the Served     */
                             /* party.                       */
   char      served_party_np ;
                             /* Identifies the Numbering Plan*/
                             /* (NP) used by the Served      */
                             /* party.                       */
   unsigned char cause_for_forward;
                             /* In case of a forwarded leg   */
                             /* contains the field the       */
                             /* Supplementary Service Code,  */
                             /* otherwise it is HEX zero.    */
   char      term_ind ;      /* This indicates the value of  */
                             /* the Call Termination         */
                             /* Indicator.{Complete, Dropped}*/
   char      vas_code ;      /* In case of TAP VAS type, the */
                             /* TD17 VAS code.               */
   char remark[LEN_REMARK + LEN_SPARE];
                             /* Information about VAS        */
                             /* charging                     */
   char carrier_name[LEN_CARRIER_NAME+LEN_SPARE];
                             /* CCMI defined carrier name as */
                             /* accepted by the Toll Rater.  */
   long int ixc_code;        /* The IXC code.                */

   long int rated_units;     /* Rate information for already */
                             /* charged records.             */
   unsigned char utx_params; /* A field of bit flags.        */
                             /* Bit 0: PPC indicator.        */
                             /* Bit 1: not used.             */
                             /* Bit 2: not used.             */
                             /* Bit 3: not used.             */
                             /* Bit 4: not used.             */
                             /* Bit 5: not used.             */
                             /* Bit 6: not used.             */
                             /* Bit 7: not used.             */
      
   unsigned int ris_dim;     /* The number of dispatch areas */
                             /*   serviced by this call      */

   unsigned int ris_scl;     /* The number of users involved */
                             /*   in this dispatch call      */
#ifdef CONFIG_SERV_PRO
   long int  credit;         /* A credit for dropped calls.  */

   unsigned char mask_number_ind;
                             /* Social number indicator.     */
#endif

  double land_rate;          /* Added to support IN devices  */
                     /* as well as the markup functionality. */
                     /* BSCS 4.03_us features: 21289 & 21464 */

  int pr_count;              /* Added for feature 21744.     */
                             /* This field will contain the  */
                             /* total number of partial      */
                             /* records that comprise the UTX*/

  int utx_file_id;           /* Added for feature 21744.     */
                             /* This field will contain the  */
                             /* database file_id to track.   */

  int utx_sub_no;            /* Added for feature 21755.     */
                             /* The sub running number of    */
                             /* the UTX record.              */

  char additional_key[MAX_BUF + LEN_SPARE];
                             /* Added for feature 29450.     */
                             /* This field contains an       */
                             /* additional key for the DRH.  */

  char rated_party_loc[LEN_US_LOCATION_DES + LEN_SPARE];
                             /* Added for defect 31417.      */
                             /* The city name and the state  */
                             /* abbreviation of the rated    */
                             /* party.  Comma separated.     */

  char called_number_loc[LEN_US_LOCATION_DES + LEN_SPARE];
                             /* Added for defect 31417.      */
                             /* The city name and the state  */
                             /* abbreviation of the called   */
                             /* party.  Comma separated.     */

  unsigned char lrn[LEN_DN_BUF_BCD];
                             /* This field contains the LRN  */
                             /* value of the called party.   */
} ;

/*************************************************************/
/*              GSM Supplementary Service Part (Optional)    */
/* This part is used to specify the charges for the n-th.    */
/* suppl. services used during the call.                     */
/*************************************************************/

struct sutx_supl_serv_str
{
   long int  timestamp ;     /* Number of seconds that pass  */
                             /* between 1. Jan. 1970 and     */
                             /* Start Day and Time of the    */
                             /* Transaction (UNIX-Time).     */
   long int  time_offset;    /* Time difference between main */
                             /* and other PLMN in seconds.   */
   int       gsm_pi_2 ;      /* In this field information    */
                             /* about used Supplementary     */
                             /* Services is coded by the     */
                             /* formula: 16 * SS-Code +      */
                             /* Action-Code                  */
   double    tap_net_rate ;  /* This field contains the      */
                             /* charge from TAP records      */
                             /* converted to DM without      */
                             /* taxes (net rate).            */
   double    tap_tax_rate ;  /* This field contains the      */
                             /* tax for the TAP record       */
   unsigned char ss_code;    /* The Supplementary Service    */
                             /* Code.                        */
   int   no_of_rejections;   /* If not zero, gives the no.   */
                             /* of times the record was      */
                             /* rejected subsequently for    */
                             /* the following reason.        */
   char  reason_code[LEN_REASON_CODE + LEN_SPARE];
                             /* Gives the reason if the      */
                             /* record was rejected for this */
                             /* part                         */
   char      gsm_pi  [ LEN_GSM_PI + LEN_SPARE ] ;
                             /* This field contains the      */
                             /* information about the used   */
                             /* GSM Service.                 */
   unsigned char start_date  [ LEN_START_DATE_BCD ] ;
                             /* Start Date of the            */
                             /* Transaction. It must be a    */
                             /* valid date in the form of    */
                             /* YYYYMMDD coded in BCD.       */
   unsigned char start_time  [ LEN_START_TIME_BCD ] ;
                             /* Start Time of the            */
                             /* Transaction. A valid time    */
                             /* in the format of HHMMSS      */
                             /* coded in BCD.                */

   unsigned char trac_start_date[ LEN_DATE_BCD ];
                             /* Original TRAC Start Date.    */

   unsigned char trac_start_time[ LEN_TIME_BCD ];
                             /* Original TRAC Start Time.    */

} ;

/*************************************************************/
/*            NON-GSM PART (Optional)                        */
/* This part is used to specify the base information about   */
/* transactions using NON GSM services.                      */
/*************************************************************/

struct sutx_non_gsm_str
{
   long int  timestamp ;     /* Number of seconds that pass  */
                             /* between 1. Jan. 1970 and     */
                             /* Start Day and Time of the    */
                             /* Transaction.                 */
   long int  time_offset;    /* Time difference between main */
                             /* and other PLMN in seconds.   */
   char      type ;          /* This identifies the          */
                             /* transaction type the         */
                             /* UTX-Record was generated     */
                             /* from. (21 = VAS, 31 = TA-VAS)*/
   long int  net_rate ;      /* This field contains the      */
                             /* charge from TAP records      */
                             /* converted to DM without      */
                             /* taxes (net rate) as well as  */
                             /* from Operator Toll Tickets.  */
   unsigned char served_party_msisdn  [ LEN_DN_BUF_BCD ] ;
                             /* MSISDN of the served party   */
                             /* coded in BCD.                */
   unsigned char served_party_imsi  [ LEN_PORT_BUF_BCD ] ;
                             /* IMSI of served party coded   */
                             /* in BCD, if available.        */
   unsigned char start_date  [ LEN_START_DATE_BCD ] ;
                             /* Start Date of the            */
                             /* Transaction. It must be a    */
                             /* valid date in the form of    */
                             /* YYYYMMDD coded in BCD.       */
   unsigned char start_time  [ LEN_START_TIME_BCD ] ;
                             /* Start Time of the            */
                             /* Transaction. A valid time    */
                             /* in the format of HHMMSS      */
                             /* coded in BCD.                */
   char      non_gsm_pi  [ LEN_NON_GSM_PI + LEN_SPARE ] ;
                             /* This field contains the      */
                             /* pricable item about the      */
                             /* used (non GSM) Service.      */
   char      description  [ LEN_DESCRPITION + LEN_SPARE ] ;
                             /* This field contains the      */
                             /* description about the used   */
                             /* (non GSM) Service.           */
   char      additional_fields;
                             /* to be developed              */
};



/*************************************************************/
/* Definition of array and buffer sizes.                     */
/*************************************************************/

#define MAX_NUM_OF_SUP_SERV 20
#define UTX_BUFFER_SIZE sizeof( TAG_STR ) +                              \
                        sizeof( TAG_STR ) + sizeof( UTX_HEADER_STR )   + \
                        sizeof( TAG_STR ) + sizeof( UTX_GSM_BASE_STR ) + \
                        MAX_NUM_OF_SUP_SERV * \
                        ( sizeof( TAG_STR ) + sizeof( UTX_SUPL_SERV_STR ) )

#endif

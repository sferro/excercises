#ifndef RTX_STR_H
#define RTX_STR_H

/*************************************************************/
/* General RTX Defines.                                      */
/*************************************************************/

#define RTX_RECORD_TAG    0x11
#define RTX_HEADER_TAG    0x12
#define RTX_GSM_BASE_TAG  0x13
#define RTX_SUPL_SERV_TAG 0x14
#define RTX_NON_GSM_TAG   0x15

#define HOST_RTX_TAG      0x20

#define RTX_MOC      1
#define RTX_MTC      2
#define RTX_EVENT    3
#define RTX_VAS      4
#define RTX_RCF      5

#define RTX_IN_MOC   6
#define RTX_IN_MTC   7
#define RTX_IN_EVENT 8
#define RTX_IN_VAS   9

#define TERMIND_DROPPED    'D'
#define TERMIND_COMPLETED  'C'

#define ROAMER_IND_HPLMN 'H'
#define ROAMER_IND_VPLMN 'V'

#define FF_MICRO_CELL_APPLIES 1
#define MC_MICRO_CELL_APPLIES 2

/*
 * Flags for RTX field rtx_params.
 */
#define RTX_PPCFLAG       0x01


#define RTX_HEADER_STR UTX_HEADER_STR

/*************************************************************/
/*                      RTX Record                           */
/* The RTX Record consists of several parts. These are the   */
/* Base Part and additional Parts each of them identified by */
/* a TAG and length field. The RTX Record itself is          */
/* identified by a Super TAG.                                */
/* This part is used to specify the charge of the default    */
/* bundle level and the first tariff-time. If there are more */
/* than one bundle level in the tariff model, or the call    */
/* crosses tariff time tiers or suppl. services where used   */
/* during the call, then the coresponding parts (Bundle Part,*/
/* Tariff Time Part or Suppl. Service Part) are added to     */
/* the RTX Record as many times as they are needed.          */
/*                                                           */
/* Numbers that are BCD coded in the RTX record are          */
/* represented as ASCII strings in the HOST RTX record.      */
/*************************************************************/

#define RTX_GSM_BASE_STR struct srtx_gsm_base_str

RTX_GSM_BASE_STR
{

long int rated_party_dn_id;
                             /* Key for DIRECTORY_NUMBER .   */

long int rated_party_port_id;
                             /* Key for PORT.                */

long int rated_party_customer_id;
                             /* Key for Customer.            */

long int contract_id;        /* ID of the Contract.          */

long int eccode;             /* Code of external carrier.    */

long int rtx_sqn;            /* Sequence Number.             */

long int rtx_lfnr;           /* Running number.              */

long int rtx_sub_lfnr;       /* Sub-Running number.          */

double    actual_volume  ;   /* Actual Air Duration          */

double    rated_volume;      /* Volume in Units of           */
                             /* Measurement (UoM). This      */
                             /* will be one(1) if the used   */
                             /* service is an Event.         */

double rounded_volume;       /* The rounded volume.          */

double    aoc_amount;        /* AoC Amount                   */

long int  d2s_code;          /* D2 Service Code              */
                             /* Equals sncode.               */

double    grosrate;          /* Gros rate                    */

double    rated_flat_amount; /* Netto Rate                   */

double scalefactor;         /*  Scale factor for Friends     */
                            /*  and Family tariff .          */

double    nou;               /* Number of Tariff Units used  */

double   rated_clicks;       /* Number of clicks charged for */
                             /* the call.                    */

long int  svp_code;          /* Service Package being used   */

long int  svp_version;       /* Version Number of the Service*/
                             /* Package                      */

long int  twcode;            /* Tariff Week                  */

long int  ttcode;            /* Tariff Time                  */

long int  zccode;            /* Zone Coverage                */

long int  tzcode;            /* Tariff Zone                  */

long int  zpcode;            /* Terminating Zonal Point      */

long int  plcode;            /* PLMN the subscriber was in   */

long int        vplcode;           /* PLMN subscriber belongs to.  */

long int  hrcode;            /* Home Region Code.            */

short int hrind;             /* Inside/Outside Home Region   */
                             /* Indicator                    */

long int  taxcode;           /* Tax Code.                    */

TaxInfoStr tap_taxes[MAX_NUM_OF_TAXES];
                             /* NAIG Tap taxe structure      */

char home_bid[LEN_HOME_BID + LEN_SPARE];
                             /* Value of the home bid.       */

char home_bid_desc[LEN_HOME_BID_DESC + LEN_SPARE];
                             /* Description of the home bid  */


long int home_bid_id;        /* Home BID internal ID         */

char serving_bid[LEN_SERVING_BID + LEN_SPARE];
                             /* Value of the serving bid     */

char serving_bid_desc[LEN_SERVING_BID_DESC + LEN_SPARE];
                             /* Description of the serving   */
                             /* bid.                         */


long int serving_bid_id;     /* Serving BID internal ID.     */

double    taxrate;           /* Tax rate in percentage.      */

double    tax;               /* Tax as value.                */

long int  tmcode;            /* Tariff Model used for the    */
                             /* rated party                  */

long int  tm_version;        /* Version Number of the        */
                             /* Tariff Model                 */

long  int rivscode;         /* The version of the Rate       */
                            /* Interval Package .            */
long  int egvscode;         /* The version of the Extended   */
                            /* Gcode Package.                */
long int  uom_code;          /* Unit of Measurement Code     */

long int  used_seq_num;      /* If this record was           */
                             /* converted to a TAP or M2D    */
                             /* record this number is equal  */
                             /* to the file sequence number  */
                             /* (used in header record) of   */
                             /* the TAP or M2D file          */
                             /* respectively.                */

int       rtx_call_type;     /* Identifies the type of the   */
                             /* RTX record, values are       */
                             /* 1 = MOC, 2 = MTC, 3 = EVENT  */
                             /* or 4 = VAS                   */

char      inglcode  [ LEN_INGLCODE + LEN_SPARE];
                             /* Income account code          */

char      accounttype  [ LEN_ACCOUNTTYPE ];
                             /* Account Type                 */

char      bccode  [ LEN_BCCODE ];
                             /* Bill Cycle                   */



unsigned int ris_scl;        /* Number of users in call         */
 
unsigned int ris_dim;        /* Number of service areas in call */


unsigned char o_geocode[LEN_GEOCODE + LEN_SPARE];
                             /* The origination's geocode    */

unsigned char d_geocode[LEN_GEOCODE + LEN_SPARE];
                             /* The destination's geocode    */


char      call_compl_ind;    /* Call Completion Indicator    */

char      call_type_ind  [ LEN_CALL_TYPE_IND ];
                             /* Call Type Indicator          */

char      concuaccount  [ LEN_CONCUACCOUNT ];
                             /* Consolidated Customer Account*/

char      cuaccount  [ LEN_CUACCOUNT ];
                             /* Customer Account             */

char      cusubaccount  [ LEN_CUSUBACCOUNT ];
                             /* Customer Sub_Account         */

char      mask_ind;          /* Indicates whether the Other  */
                             /* Party ID should be masked    */
                             /* on an itemized bill          */

char      mod_ind;           /* Modification Indicator ,     */
                             /* values are 0 or 1            */

char      aoc_ind;           /* Denotes whether call is      */
                             /* AoC rated.                   */

char      orig_sales_force_id  [ LEN_ORIG_SALES_FORCE_ID ];
                             /* Orig. Sales Force Identity   */

char      vas_code;          /* In case of VAS type, the     */
                             /* TD17 VAS code.               */

char      trac_start_date  [ LEN_START_DATE_BCD ];
                             /* For incoming TRAC:           */
                             /* Original Start Date as       */
                             /* populated in the TRAC        */
                             /* record coded in BCD.         */

char      trac_start_time  [ LEN_START_TIME_BCD ];
                             /* For incoming TRAC:           */
                             /* Original Start Time as       */
                             /* populated in the TRAC        */
                             /* record coded in BCD.         */

char      init_start_date  [ LEN_START_DATE_BCD ];
                             /* Initial Start Date of the    */
                             /* coded in BCD.                */

char      init_start_time  [ LEN_START_TIME_BCD ];
                             /* Initial Start Time of the    */
                             /* coded in BCD.                */

char      start_date  [ LEN_START_DATE_BCD ];
                             /* Start Date of the call       */
                             /* related to tariff tier       */
                             /* coded in BCD.                */

char      start_time  [ LEN_START_TIME_BCD ];
                             /* Start Time of the call       */
                             /* related to tariff tier       */
                             /* coded in BCD.                */

char      other_party_msc  [ LEN_DN_BUF_BCD ];
                             /* MSISDN of the MSC where      */
                             /* the other_party is located   */
                             /* (if available). It is        */
                             /* coded in BCD.                */

char      other_party_number  [ LEN_DEST_BUF_BCD ];
                             /* Dialed Digits, the           */
                             /* 'Forwarded To Number' or     */
                             /* the Calling Number           */
                             /* depending on the RTX         */
                             /* record type. It is coded     */
                             /* in BCD.                      */

char      rated_party_cgi  [ LEN_ORIG_BUF + LEN_SPARE ];
                             /* Cell Global Identity the     */
                             /* rated party was located.     */

char      rated_party_imei  [ LEN_RATED_PARTY_IMEI_BCD ];
                             /* IMEI used by rated_party,    */
                             /* if available. It is coded    */
                             /* in BCD.                      */

char      rated_party_imsi  [ LEN_PORT_BUF_BCD ];
                             /* IMSI of rated party, if      */
                             /* available. It is coded       */
                             /* in BCD.                      */

char      rtx_type;          /* Airtime or Land.             */

unsigned char cause_for_forward;
                             /* Cause for forwarding.        */

char      call_dest[ LEN_CALLDEST + LEN_SPARE ];
                             /* Call Destination.            */

char      rated_party_ms_class_mark;
                             /* This value represents the    */
                             /* class of the mobile station. */

char      rated_party_msc  [ LEN_DN_BUF_BCD ];
                             /* MSISDN of the MSC where the  */
                             /* rated_party was located. It  */
                             /* is coded in BCD.             */

char      rated_party_np;    /* Identifies the Numbering     */
                             /* Plan (NP) used by the rated  */
                             /* party.                       */

char      rated_party_number  [ LEN_DN_BUF_BCD ];
                             /* MSISDN or Phone Number of    */
                             /* the rated party, if          */
                             /* applicable. It is coded      */
                             /* in BCD.                      */

char      other_party_ton;   /* Identifies the Type of       */
                             /* Number (TON) used by the     */
                             /* rated party.                 */

char      rated_party_trunk  [ LEN_RATED_PARTY_TRUNK + LEN_SPARE ];
                             /* The outgoing tunk in case    */
                             /* of a MOC or the incoming     */
                             /* trunk in case of a MTC,      */
                             /* otherwise blank.             */

char      roamer_ind;        /* Roamer Indicator             */

char delete_after_billing;   /* Delete After Billing Flag.   */

char      alternate_action_code;
                             /* Action code if a special     */
                             /* number was dialed.           */

char      rtsp_pi  [ LEN_RTSP_PI + LEN_SPARE ];
                             /* Rtsp Pricable item           */

char      subscriber_seqnum  [ LEN_SUBSCRIBER_SEQNUM ];
                             /* Subscriber Sequence Number   */

char      svseqnum  [ LEN_SVSEQNUM ];
                             /* Service Sequence Number      */

char      term_zonal_point_name  [ LEN_TERM_ZONAL_POINT_NAME + LEN_SPARE ];
                             /* Name of the Terminating      */
                             /* Zonal Point                  */

char      termination_ind;   /* This indicates the value     */
                             /* of the Call Termination      */
                             /* Indicator.                   */

char      transaction_type  [ LEN_TRANSACTION_TYPE ];
                             /* Transaction Type             */

char remark[LEN_REMARK];        /* Information about VAS rating */

char carrier_name [LEN_CARRIER_NAME + LEN_SPARE];
                             /* CCMI defined carrier code as */
                             /* accepted by the toll rater.  */
int       ixc_code;          /* The IXC code,up to six digits*/
                             /* coded in BCD, rigt adjusted, */
                             /* padded with hex 0s in front. */
char      rated_party_loc[LEN_US_LOCATION_DES +LEN_SPARE ];
                             /* The Sityname and the State   */
                             /* code of the rated party sepa-*/
                             /* rated by a comma .           */
char      rated_party_LATA[ LEN_LATA + LEN_SPARE ];
                             /* The LATA number of the cal-  */
                             /* ling phone number, coded in  */
                             /* BCD, left adjusted,pagged    */
                             /* with hex Fs.                 */
char     called_number_loc[LEN_US_LOCATION_DES+LEN_SPARE ];
                             /* The Sityname and the State   */
                             /* code of the called party     */
                             /* separated by a comma .       */
char     called_number_LATA[ LEN_LATA + LEN_SPARE ];
                             /* The LATA number of the cal-  */
                             /* led phone number, coded in  */
                             /* BCD, left adjusted,pagged    */
                             /* with hex Fs.                 */
char    service_type;        /* The one digit CCMI defined   */
                             /* service type.                */
char    BOC_flag;            /* Identifies if BOC or IOC     */
                             /* rates used.                  */
short   tod_class;           /* A number from 1 to 6 which   */
                             /* represents the rate period of*/
                             /* the call's start time.       */
short   rtx_sub_type;        /* Describes the call type.     */
                             /* 1   Interstate InterLATA     */
                             /* 2   Interstate IntraLATA     */
                             /* 3   Interstate InterLATA     */
                             /* 4   Interstate IntraLATA     */
                             /* 5   Local                    */
                             /* 6   Alaska                   */
                             /* 7   Hawaii                   */
                             /* 8   U.S.Caribbean            */
                             /* 9   Canada                   */
                             /* 10  Mexico                   */
                             /* 11  Non-U.S.Caribbean        */
                             /* 12  Overseas                 */
                             /* 13  Information/Diat-It      */
                             /* 14  Toll Free (800)          */
                             /* 15  Busy Line Verify         */
                             /* 16  Emergensy Interrupt      */
char    fuomspn;             /* Indicates if call is inside  */
                             /* scope of fUoM                */

char   usgserv_cat[LEN_USGSERV_CAT + LEN_SPARE];
                            /*  The Service Cat Code  for    */
                            /*  Usage .                      */
char   usgserv_code[LEN_USGSERV_CODE + LEN_SPARE];
                            /*  The Service Code for Usage   */
char   usgserv_type[LEN_USGSERV_TYPE + LEN_SPARE];
                            /*  The Service Type for Usage   */

unsigned char rtx_params;   /*  A field of bit flags.        */
                            /*  Bit 0: PPC indicator.        */
                            /*  Bit 1: Externally rated RTX. */
                            /*  Bit 2: not used.             */
                            /*  Bit 3: not used.             */
                            /*  Bit 4: not used.             */
                            /*  Bit 5: not used.             */
                            /*  Bit 6: not used.             */
                            /*  Bit 7: not used.             */

double markup_amount;       /* The marked up amount from     */
                       /* a surcharge/markup rating interval */
                       

char mrkglcode[LEN_MRKGLCODE + LEN_SPARE];
                       /* The GL account for markups.        */

char mrkserv_cat[LEN_MRKSERV_CAT + LEN_SPARE];
                       /* The service cat. code for markup   */

char mrkserv_code[LEN_MRKSERV_CODE + LEN_SPARE];
                       /* The service code for markup        */

char mrkserv_type[LEN_MRKSERV_TYPE + LEN_SPARE];
                       /* The service type for markup.       */


char re_rated;         /* Flag to indicate if this record was*/
                       /* re_rated by a roamer incollect     */
                       /* re-rate.                           */


int utx_file_id;       /* File_id to track revenue against   */


char split_ind;        /* Used to indicate that the RTX      */
                       /* record was written because of a    */
                       /* split in tariff times.             */


int usage_pr_cust_id;  /* The customer id who is payment     */
                       /* responsible for this usage amount  */

char lrn[LEN_DN_BUF_BCD]; /* The LRN of the called party. */

char country_iso_code[LEN_ISO_CODE + LEN_SPARE]; /* The ISO code of the country that was callled  */
                         
};
/*************************************************************/
/*                  RTX Bundle Part (Optional)               */
/* This part is used to specify the charge of a call         */
/* according the different bundle levels of the tariff model */
/* for that tariff time given by the TARIFF_TIME_CODE field. */
/*************************************************************/

#define RTX_BUNDLE_STR struct srtx_bundle_str

RTX_BUNDLE_STR
{
long int  bundle_tier;       /* Bundle Tier                  */
long int  tariff_time_code;  /* Tariff Time                  */
long int  netrate;           /* Netto Rate which applies     */
                             /* for Bundle Tier              */
long int  grosrate;          /* Gros Rate which applies      */
                             /* for Bundle Tier              */
long int  taxrate;           /* Tax rate in percentage       */
                             /* multiplied by 100.           */
};


/*************************************************************/
/*                 RTX Tariff Time Part (Optional)           */
/* This part is used to specify the charges for a used       */
/* tariff time (second, third, ..), if the call crosses      */
/* tariff time tiers.                                        */
/* Whether the Tariff Time Part will be handled as a trailer */
/* to the RTX or whether separate RTX Records will be        */
/* generated for each Tariff Time is specified by a system   */
/* parameter.                                                */
/*************************************************************/

#define RTX_TARIFF_TIME_STR struct srtx_tariff_time_str

RTX_TARIFF_TIME_STR
{
long int  volume;            /* Volume in Units of           */
                             /* Measurement (UoM).           */
long int  tariff_time_code;  /* Tariff Time                  */
long int  nou;               /* Number of Tariff Units used  */
long int  netrate;           /* Netto Rate which applies     */
                             /* for that Tariff Time         */
long int  grosrate;          /* Gros rate which applies      */
                             /* for that Tariff Time         */
long int  taxrate;           /* Tax rate in percentage       */
                             /* multiplied by 100.           */
long int  aoc_amount;        /* AoC Amount which applies     */
                             /* for that Time Interval       */
char      start_date  [ LEN_START_DATE_BCD ];
                             /* Start Date of the Tariff     */
                             /* Time coded in BCD.           */
char      start_time  [ LEN_START_TIME_BCD ];
                             /* Start Time of the Tariff     */
                             /* Time coded in BCD.           */
};


/*************************************************************/
/*           RTX Supplementary Service Part (Optional)       */
/* This part is used to specify the charges for the n_th.    */
/* suppl. services used during the call.                     */
/* Note: The Supplementary Service Part will be used in LMP  */
/* internaly only. The RTX Records as sent to the Host will  */
/* have separate RTX Records for each Supplementary Service. */
/*************************************************************/

#define RTX_SUPL_SERV_STR struct srtx_supl_serv_str

RTX_SUPL_SERV_STR
{

long int  umcode;            /* Tariff Time                  */

long int  d2s_code;          /* D2 Service Code              */
                             /* Equals sncode.               */

long int  spcode;            /* Service Package Code.        */

long int  ttcode;            /* Tariff Time                  */

long int  tzcode;            /* Tariff Zone                  */

long  int evvscode;         /* The version of the Event      */
                            /* Rate Package .                */
long  int egvscode;         /* The version of the Extended   */
                            /* Gcode Package.                */
double    nou;               /* Number of Tariff Units       */
                             /* used                         */

double   rated_clicks;       /* Number of clicks charged for */
                             /* the the Supplementary        */
                             /* Service.                     */

double    rated_flat_amount; /* Netto Rate                   */

double    grosrate;          /* Gros rate which applies      */
                             /* for Supplementary Service    */

long int  taxcode;           /* Tax Code.                    */

double    tax;               /* Tax as value.                */

double    taxrate;           /* Tax rate in percentage.      */

char      inglcode  [ LEN_INGLCODE + LEN_SPARE];
                             /* Income account code          */

char      start_date  [ LEN_START_DATE_BCD ];
                             /* Start Date of the call       */
                             /* where this Supplementary     */
                             /* Service was used coded       */
                             /* in BCD.                      */

char      start_time  [ LEN_START_TIME_BCD ];
                             /* Start Time of the call       */
                             /* where this Supplementary     */
                             /* Service was used coded       */
                             /* in BCD.                      */

unsigned char gsmcode;       /* GSM_Code of Supplementary    */
                             /* Service as defined in        */
                             /* GSM 09.02                    */

char      action_code;       /* Activation, Deactivation,    */
                             /* Interrogation, Registration, */
                             /* Errasure and Invocation      */
char   usgserv_cat[LEN_USGSERV_CAT + LEN_SPARE];
                             /*  The Service Cat Code  for    */
                             /*  Usage .                      */
char   usgserv_code[LEN_USGSERV_CODE + LEN_SPARE];
                             /*  The Service Code for Usage   */
char   usgserv_type[LEN_USGSERV_TYPE + LEN_SPARE];
                             /*  The Service Type for Usage   */

double markup_amount;        /* The amount that this suppl.   */
                             /* was marked up.                */

char mrkglcode[LEN_MRKGLCODE + LEN_SPARE];
                       /* The GL account for markups.        */

char mrkserv_cat[LEN_MRKSERV_CAT + LEN_SPARE];
                       /* The service cat. code for markup   */

char mrkserv_code[LEN_MRKSERV_CODE + LEN_SPARE];
                       /* The service code for markup        */

char mrkserv_type[LEN_MRKSERV_TYPE + LEN_SPARE];
                       /* The service type for markup.       */


char re_rated;         /* Flag to indicate a re-rate of      */
                       /* roamer records.                    */


long int  tmcode;               /* Tariff Model used for the    */
                                /* rated party                  */
 
long int  tm_version;           /* Version Number of the        */
                                /* Tariff Model                 */
 
long int  twcode;               /* Tariff Week                  */
 
int usage_pr_cust_id;           /* The customer id of the       */
                                /* customer who is payment      */
                                /* responsible for this record  */

                         
};

/*************************************************************/
/*            NON-GSM PART (Optional)                        */
/* This part is used to specify the base information about   */
/* transactions using NON GSM services.                      */
/*************************************************************/

#define NON_GSM_TYPE_OPERATOR_TOLL_TICKET 1

#define NON_GSM_TYPE_VPLMN_VAS            2

#define RTX_NON_GSM_STR struct srtx_non_gsm_str

RTX_NON_GSM_STR
{

   long int  timestamp ;     /* Number of seconds that pass  */
                             /* between 1. Jan. 1970 and     */
                             /* Start Day and Time of the    */
                             /* Transaction.                 */

   long int  grosrate;       /* Gros rate                    */

   long int  netrate;        /* Netto Rate                   */

   long int  taxrate;        /* Tax rate in percentage as a  */
                             /* number multiplied by 100.    */
                             /* If i.e. the tax is 15        */
                             /* percent then it is stored    */
                             /* as 1500.                     */

   char      type ;          /* This identifies the          */
                             /* transaction type the         */
                             /* RTX-Record was generated     */
                             /* from.                        */

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
/*                                                           */
/* The next structure is the layout for the RTX Records as   */
/* sent to the host.                                         */
/*                                                           */
/*************************************************************/

#define CALL_DEST_NATIONAL_PSTN      "NP"
#define CALL_DEST_INTERNATIONAL_PSTN "IP"
#define CALL_DEST_NATIONAL_PLMN      "NV"
#define CALL_DEST_INTERNATIONAL_PLMN "IV"

#define HOST_RTX_STR struct shost_rtx_str

HOST_RTX_STR
{

        long int rated_party_dn_id;
                             /* Key for DIRECTORY_NUMBER.    */

        long int rated_party_port_id;
                             /* Key for PORT.                */

        long int rated_party_customer_id;
                             /* Key for Customer.            */
        
        long int contract_id;
                             /* ID of the Contract.          */
 
        long int hplcode;          /* HPLMN code.                  */
        
        long int eccode;           /* Code of external carrier.    */

        double actual_volume  ;   /* Actual Air Duration          */

        double rated_volume;      /* Volume in Units of           */
                                  /* Measurement (UoM). This      */
                                  /* will be one(1) if the used   */
                                  /* service is an Event.         */

        double rounded_volume;    /* The rounded volume.          */

        double rated_clicks;      /* Number of clicks charged for */
                           /* the call.                    */

        double rated_flat_amount; /* Netto Rate.                  */
 
        double tap_net_rate;      /* Netto rate of VPLMN          */

        TaxInfoStr tap_taxes[MAX_NUM_OF_TAXES];
                                  /* Tax info from TD.27 records  */

        char home_bid[LEN_HOME_BID + LEN_SPARE];
                                  /* The value of the home bid.   */

        char home_bid_desc[LEN_HOME_BID_DESC + LEN_SPARE];
                                  /* The description of the home  */
                                  /* bid.                         */

        char serving_bid[LEN_SERVING_BID + LEN_SPARE];
                                  /* The value of the serving bid */

        char serving_bid_desc[LEN_SERVING_BID_DESC + LEN_SPARE];
                                  /* The description of the       */
                                  /* serving bid.                 */

        double tap_tax_rate;      /* Tax rate of VPLMN            */

        double scalefactor;       /* Scale factor for Friends     */
                                  /* and Family tariff .          */

        double credit_clicks;     /* Number of credit clicks.     */

        double aoc_amount;        /* AoC Amount                   */

        long int umcode;          /* Unit of Measurement Code     */

        long int tmcode;          /* Tariff Model used for the    */
                           /* rated party                  */

        long int tm_version;      /* Version Number of the        */
                           /* Tariff Model                 */

 long  int rpversion;      /* The version of the Rate      */
                           /* Package (RI - or EV-)        */

 long  int egversion;      /* The version of the Extended  */
                           /* Glcode Package .             */               
        long int spcode;          /* Service Package.             */

        long int sncode;          /* Name of Service Package.     */

        long int sccode;          /* Service Class Code.          */

        long int twcode;          /* Tariff Week                  */

        long int ttcode;          /* Tariff Time                  */

        long int gvcode;          /* Zone Coverage                */

        long int tzcode;          /* Tariff Zone                  */

        long int zpcode;          /* Terminating Zonal Point      */

        long int plcode;          /* PLMN the subscriber was in   */

        long int rated_party_mccode;
                           /* The Micro Cell Code.         */

        long int rtx_sqn;         /* Sequence Number.             */

        long int rtx_lfnr;        /* Running number.              */

        long int rtx_sub_lfnr;    /* Sub-Running number.          */

        short int termination_ind;/* This indicates the value     */
                           /* of the Call Termination      */
                           /* Indicator.                   */

        short int call_type;      /* Identifies the Record Type.  */

        short int rated_party_mcind;
                           /* Inside/Outside Home Region   */
                           /* Indicator                    */

        char rtx_type;            /* Airtime or Land.             */

        char aoc_ind;             /* Denotes whether call is      */
                           /* AoC rated.                   */

        char market_id[ LEN_MARKET_ID + LEN_SPARE ];

        char other_party_ton;     /* Identifies the Type of       */
                           /* Number (TON) used by the     */
                           /* rated party.                 */

        char rated_party_np;      /* Identifies the Numbering     */
                           /* Plan (NP) used by the rated  */
                           /* party.                       */
        
        char rated_party_portnumber[ LEN_PORT_BUF + LEN_SPARE ];
                           /* The Port Number.             */

        char rated_party_dnnumber[ LEN_DN_BUF + LEN_SPARE ];
                            /* The Directory Number.       */

        char rated_party_imei[ LEN_RATED_PARTY_IMEI + LEN_SPARE ];
                            /* IMEI used by rated_party,    */
                            /* if available.                */

        char rated_party_cgi[ LEN_ORIG_BUF + LEN_SPARE ];
                                   /* Cell Global Identity the     */
                                   /* rated party was located.     */

        char rated_party_msc[ LEN_DN_BUF + LEN_SPARE ];
                                   /* MSISDN of the MSC where the  */
                                   /* rated_party was located.     */

        char rated_party_ms_class_mark;
                                   /* This value represents the    */
                                   /* class of the mobile station. */

        char other_party_number[ LEN_DEST_BUF + LEN_SPARE ];
                                   /* The other party number if    */
                                   /* available.                   */

        char other_party_msc[ LEN_DN_BUF + LEN_SPARE ];
                                   /* MSISDN of the MSC where      */
                                   /* the other_party is located   */
                                   /* (if available).              */

        char other_party_cgi[ LEN_ORIG_BUF + LEN_SPARE ];
                                   /* Cell Global Identity the     */
                                   /* other party was located.     */

        char start_date_time[ LEN_START_DATE_TIME + LEN_SPARE ];
                                   /* Start Date of the call       */
                                   /* related to tariff tier.      */

        char original_start_date_time[ LEN_START_DATE_TIME + LEN_SPARE ];
                                   /* Original Start Date & Time.  */

        char trac_start_date_time[ LEN_START_DATE_TIME + LEN_SPARE ];
                                   /* For incoming TRAC the        */
                                   /* Original Start Date & Time as*/
                                   /* populated in the TRAC        */
                                   /* record.                      */

        char gsm_pi[ LEN_GSM_PI + LEN_SPARE ];
                                   /* Rtsp Pricable item           */

        char action_code;          /* Supplementary Service        */
                                   /* Action Code.                 */

        char bill_status[ LEN_BILL_STATUS + LEN_SPARE ];
                                   /* Bill Status.                 */

        char call_dest[ LEN_CALLDEST + LEN_SPARE ];
                                   /* Call Destination.            */

        char roamer_ind;           /* Roamer Indicator             */

        char delete_after_billing; /* Delete After Billing Flag.   */

        char bccode[ LEN_BCCODE ];
                                   /* Bill Cycle                   */

        unsigned int ris_scl;      /* The number of users involved */
                                   /*  in a dispatch call          */

        unsigned int ris_dim;      /* The number of dispatch areas */
                                   /*  serviced by the dispatch svc*/

 char remark[LEN_REMARK];
                                   /* Information about VAS rating */

 char carrier_name [LEN_CARRIER_NAME + LEN_SPARE];
                                   /* CCMI defined carrier code as */
                                   /* accepted by the toll rater.  */
 int       ixc_code;               /* The IXC code,up to six digits*/
                                   /* coded in BCD, rigt adjusted, */
                                   /* padded with hex 0s in front. */
 char      rated_party_loc[ LEN_US_LOCATION_DES + LEN_SPARE ];
                                   /* The Cityname and the State   */
                                   /* code of the rated party sepa-*/
                                   /* rated by a comma .           */
 char      rated_party_LATA[ LEN_LATA + LEN_SPARE ];
                                   /* The LATA number of the cal-  */
                                   /* ling phone number,           */
                                   /* as a string .                */
 char     called_number_loc[ LEN_US_LOCATION_DES + LEN_SPARE ];
                                   /* The Cityname and the State   */
                                   /* code of the called party     */
                                   /* separated by a comma .       */
 char     called_number_LATA[ LEN_LATA + LEN_SPARE ];
                                   /* The LATA number of the cal-  */
                                   /* led phone number,            */
                                   /* as a string.                 */
 char    service_type;             /* The one digit CCMI defined   */
                                   /* service type.                */
 char    BOC_flag;                 /* Identifies if BOC or IOC     */
                                   /* rates used.                  */
 short   tod_class;                /* A number from 1 to 6 which   */
                                   /* represents the rate period of*/
                                   /* the call's start time.       */
 short   rtx_sub_type;             /* Describes the call type.     */
                                   /* 1   Interstate InterLATA     */
                                   /* 2   Interstate IntraLATA     */
                                   /* 3   Interstate InterLATA     */
                                   /* 4   Interstate IntraLATA     */
                                   /* 5   Local                    */
                                   /* 6   Alaska                   */
                                   /* 7   Hawaii                   */
                                   /* 8   U.S.Caribbean            */
                                   /* 9   Canada                   */
                                   /* 10  Mexico                   */
                                   /* 11  Non-U.S.Caribbean        */
                                   /* 12  Overseas                 */
                                   /* 13  Information/Diat-It      */
                                   /* 14  Toll Free (800)          */
                                   /* 15  Busy Line Verify         */
                                   /* 16  Emergency Interrupt      */

 char     origin_geocode[ LEN_GEOCODE + LEN_SPARE ];
                                   /* The originating GEOCODE      */
 char     term_geocode[ LEN_GEOCODE + LEN_SPARE ];
                                   /* The termination GEOCODE      */
 char     fuomspn;                 /* Indicates if call is inside  */
                                   /* scope of fUoM ('Y'/'N').     */
 unsigned char rtx_params;         /*  A field of bit flags.       */
                                   /*  Bit 0: PPC indicator.       */
                                   /*  Bit 1: Externally rated RTX.*/
                                   /*  Bit 2: not used.            */
                                   /*  Bit 3: not used.            */
                                   /*  Bit 4: not used.            */
                                   /*  Bit 5: not used.            */
                                   /*  Bit 6: not used.            */
                                   /*  Bit 7: not used.            */ 

 double markup_amount;            /* The marked up amount from     */
                             /* a surcharge/markup rating interval */
                             

 char re_rated;                   /* Used to indicate that the     */
                                  /* record was re-rated for roamer*/
                                  /* incollects.                   */

 double diff_re_rate;             /* Used to store the difference  */
                                  /* between the TAP rate and the  */
                                  /* re-rate.                      */

 double diff_tax_rate;            /* Used to store the difference  */
                                  /* between the tap tax and the   */
                                  /* recalculated taxes.           */


 int utx_file_id;                 /* Used to track revenue against */
                         

 char split_ind;        /* Used to indicate that the RTX      */
                        /* record was written because of a    */
                        /* split in tariff times.             */

 int usage_pr_cust_id;  /* The customer id of the customer    */
                        /* that is payment responsible for    */
                        /* this usage record.                 */
                         
 char lrn[LEN_DN_BUF + LEN_SPARE]; /* The LRN of the called party*/

};

#endif

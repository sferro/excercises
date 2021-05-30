BEGIN {
MM_ENT = 0
MM_ENT_AMBA = 0
MM_ENT_SUR = 0
MM_SAL_TRANSFER = 0
MM_SAL = 0
MM_SAL_AMBA = 0
MM_SAL_SUR = 0
MF_TRANSFER = 0
MF = 0
MF_SUR = 0
MF_AMBA = 0
FM = 0
FM_SUR = 0
FM_AMBA = 0
print "Comienzo de proceso DIVISOR CDR"
}
{
    if(substr($0, 17, 2) == "MM") {
	if((substr($0, 112, 1) == "U" && substr($0, 113, 1) == "U" && substr($0, 237, 1)=="U" && \
		substr($0, 238, 1)!="U") || (substr($0, 112, 1) != "U" && substr($0, 113, 1) == "U" && \
		substr($0, 237, 1)=="U" && substr($0, 238, 1)!="U") || (substr($0, 112, 1) != "U" && \
		substr($0, 113, 1) != "U" && substr($0, 237, 1)=="U" && substr($0, 238,1)!="U") ) {
	    if(substr($0, 238, 1) == "A") {
		MM_ENT_AMBA++
		print $0 > "MM_ENT_AMBA"
	    }
	    else if(substr($0, 238, 1) == "S") {
		MM_ENT_SUR++
		print $0 > "MM_ENT_SUR"
	    }
	    else {
		MM_ENT++
	        print $0 > "MM_ENT"
	    }
	}
	else {
	    if( substr($0, 121, 2)=="03" || substr($0, 121, 2)=="04" || substr($0, 121, 2)=="05" || \
		    substr($0, 121, 2)=="10" || substr($0, 121, 2)=="11" || substr($0, 121, 2)=="12" || \
		    substr($0, 121, 2)=="13" ) {
		MM_SAL_TRANSFER++
		print $0 > "MM_SAL_TRANSFER"
	    }
	    else {
		if(substr($0, 113, 1) == "A") {
		    MM_SAL_AMBA++
		    print $0 > "MM_SAL_AMBA"
		}
		else if(substr($0, 113, 1) == "S") {
		    MM_SAL_SUR++
		    print $0 > "MM_SAL_SUR"
		}
		else {
		    MM_SAL++
		    print $0 > "MM_SAL"
		}
	    }
	}    
    }	
    else if(substr($0, 17, 2) == "MF") {
	if( substr($0, 121, 2)=="03" || substr($0, 121, 2)=="04" || substr($0, 121, 2)=="05" || \
		substr($0, 121, 2)=="10" || substr($0, 121, 2)=="11" || substr($0, 121, 2)=="12" || \
		substr($0, 121, 2)=="13" ) {
	    MF_TRANSFER++
	    print $0 > "MF_TRANSFER"
	}
	else {
	    if(substr($0, 113, 1) == "A") {
	        MF_AMBA++
	        print $0 > "MF_AMBA"
	    }
	    else if(substr($0, 113, 1) == "S") {
	        MF_SAL_SUR++
	        print $0 > "MF_SUR"
	    }
	    else {
		MF++
		print $0 > "MF"
	    }
	}
    }
    else if(substr($0, 17, 2) == "FM") {
	if(substr($0, 238, 1) == "A") {
	    FM_AMBA++
	    print $0 > "FM_AMBA"
	}
	else if(substr($0, 238, 1) == "S") {
	    FM_SUR++
	    print $0 > "FM_SUR"
	}
	else {
	    FM++
	    print $0 > "FM"
	}
    }
}
END {
    printf "MM_ENT = %d\n", MM_ENT
    printf "MM_ENT_SUR = %d\n", MM_ENT_AMBA
    printf "MM_ENT_AMBA = %d\n", MM_ENT_SUR
    printf "MMST= %d\n", MM_SAL_TRANSFER
    printf "MMS= %d\n", MM_SAL
    printf "MMSA= %d\n", MM_SAL_AMBA
    printf "MMSS= %d\n", MM_SAL_SUR
    printf "MFT= %d\n", MF_TRANSFER
    printf "MF= %d\n", MF
    printf "MF_AMBA= %d\n", MF_AMBA
    printf "MF_SUR= %d\n", MF_SUR
    printf "FM= %d\n", FM
    printf "FM_SUR= %d\n", FM_SUR
    printf "FM_AMBA= %d\n", FM_AMBA
    print "Fin de proceso"
}

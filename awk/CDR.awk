BEGIN {
MM_ENT = 0
MM_SAL_TRANSFER = 0
MM_SAL = 0
MF_TRANSFER = 0
MF = 0
FM = 0
print "Comienzo de proceso DIVISOR CDR"
}
{
    if(substr($0, 17, 2) == "MM") {
	if((substr($0, 112, 1) == "U" && substr($0, 113, 1) == "U" && substr($0, 237, 1)=="U" && \
		substr($0, 238, 1)!="U") || (substr($0, 112, 1) != "U" && substr($0, 113, 1) == "U" && \
		substr($0, 237, 1)=="U" && substr($0, 238, 1)!="U") || (substr($0, 112, 1) != "U" && \
		substr($0, 113, 1) != "U" && substr($0, 237, 1)=="U" && substr($0, 238,1)!="U") ) {
	    MM_ENT++
	    print $0 > "MM_ENT"
	}
	else {
	    if( substr($0, 121, 2)=="03" || substr($0, 121, 2)=="04" || substr($0, 121, 2)=="05" || \
		    substr($0, 121, 2)=="10" || substr($0, 121, 2)=="11" || substr($0, 121, 2)=="12" || \
		    substr($0, 121, 2)=="13" ) {
		MM_SAL_TRANSFER++
		print $0 > "MM_SAL_TRANSFER"
	    }
	    else {
		MM_SAL++
		print $0 > "MM_SAL"
	    }
	}    
    }	
	
    if(substr($0, 17, 2) == "MF") {
	if( substr($0, 121, 2)=="03" || substr($0, 121, 2)=="04" || substr($0, 121, 2)=="05" || \
		substr($0, 121, 2)=="10" || substr($0, 121, 2)=="11" || substr($0, 121, 2)=="12" || \
		substr($0, 121, 2)=="13" ) {
	    MF_TRANSFER++
	    print $0 > "MF_TRANSFER"
	}
	else {
	    MF++
	    print $0 > "MF"
	}
    }
    if(substr($0, 17, 2) == "FM") {
	FM++
	print $0 > "FM"
    }
}
END {
printf "MM_ENT = %d\n", MM_ENT
printf "MMST= %d\n", MM_SAL_TRANSFER
printf "MMS= %d\n", MM_SAL
printf "MFT= %d\n", MF_TRANSFER
printf "MF= %d\n", MF
printf "FM= %d\n", FM
print "Fin de proceso"
}

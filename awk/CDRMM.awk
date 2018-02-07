substr($0, 112, 1) == "U" && substr($0, 113, 1) != "U" {print $0 > MM_SAL}
substr($0, 112, 1) == "U" && substr($0, 113, 1) == "U" && substr($0, 237, 1)=="U" && substr($0, 238, 1)!="U" {print $0 > MM_ENT}
substr($0, 112, 1) != "U" && substr($0, 113, 1) == "U" && substr($0, 237, 1)=="U" && substr($0, 238, 1)!="U" {print $0 > MM_ENT}
substr($0, 112, 1) != "U" && substr($0, 113, 1) != "U" && substr($0, 237, 1)=="U" && substr($0, 238, 1)!="U" {print $0 > MM_ENT}

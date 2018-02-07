BEGIN {cont = 0
	archivo = FILENAME
}
$2 == "ferro" {cont++}
END {print cont
    print archivo}

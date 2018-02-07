BEGIN {
    sum = 0 
    sum2 = 0
    header = ""
    trailer = ""
}
substr($0, 1, 2) == "02" {
    sum += substr($0, 54, 6)
    sum2 +=substr($0, 60, 6)
}
substr($0, 1, 2) == "01" {header = $0}
substr($0, 1, 2) == "99" {trailer = $0}
END {
    print "Header"
    print header
    print "Suma= "sum
    print "suma2= "sum2
    print "Trailer"
    print trailer
}

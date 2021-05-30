BEGIN {cont = 0; sum = 0}
$2 == "ferro" && $1 == "seba" {cont++}
$2 == "ferro" {sum += $3}
$2 == "ferro" {print $1" "$2}
END {print "contador ="cont; print "suma ="sum}

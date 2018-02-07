for arch in `ls $1`
do
    echo $1/$arch
    awk -f dos2unix.awk $1/$arch > temp
    mv temp $1/$arch
done
exit 0

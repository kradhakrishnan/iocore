#!/bin/bash

which parallel
if [ $? -ne 0 ]; then
	$1
	exit $?
fi

out=`"$1" --gtest_list_tests`
prefix=`echo $out | sed "s|\..*||g"`
testcases=`echo $out | sed "s|.*\. ||g"`

cmdfile=$1.gtests

for t in $testcases; do
	echo $PWD/$1 --gtest_filter=$prefix.$t >> $cmdfile
done

cat $cmdfile

parallel -j `nproc` < $cmdfile

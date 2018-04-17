#!/bin/sh

if [[ $# != 1 ]] ; then
   echo "Usage: $0 <c file>"
   exit 1
fi

gcc -o proj_2B $1
if [[ $? != 0 ]] ; then
   echo "Compile failure!"
   exit 1
fi

rm -f ./binary_output
./proj_2B ~hank/public_html/330/projects/2B/binary_input ./binary_output

if [[ ! -f ./binary_output ]] ; then
   echo "You did not generate the correct file output name."
   exit 1
fi

diff ~hank/public_html/330/projects/2B/binary_output ./binary_output
if [[ $? != 0 ]] ; then
   echo "Your output is not correct
   exit 1
fi

echo "Your program appears to be working correctly."
echo "It compilers, runs, and generates the correct output."
echo "Please upload this c file to Canvas."
echo "Grading will consist of the steps performed by this script, complemented by inspection of your code."


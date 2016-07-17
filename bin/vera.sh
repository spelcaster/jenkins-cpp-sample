#!/bin/bash

if [[ ${#} -lt 3 ]]
then
    echo "Usage:" >&2
    echo "arg(0) to arg(n-3) - List of directories to search" >&2
    echo "arg(n-2) - The path to create the report file" >&2
    echo "arg(n-1) - The report name" >&2
    echo  >&2
    echo "Where:" >&2
    echo "n - Total of arguments" >&2
    exit 1
fi

ARG_ARRAY=( ${@} )
FIND_PATH=""

FIND_START_INDEX=0
FIND_END_INDEX=$(bc <<< "${#} - 3")
REPORT_DIR_INDEX=$(bc <<< "${#} - 2")
REPORT_NAME_INDEX=$(bc <<< "${#} - 1")

for i in $(seq ${FIND_START_INDEX} ${FIND_END_INDEX})
do
    FIND_PATH="${FIND_PATH} ${ARG_ARRAY[${i}]}"
done

REPORT_DIR=${ARG_ARRAY[${REPORT_DIR_INDEX}]}
REPORT_NAME=${ARG_ARRAY[${REPORT_NAME_INDEX}]}

retval=0

find ${FIND_PATH} -type f -regex ".+\.\(c\(c*\|p*\)\|h\(p*\)\)" |\
    vera++ - -showrules -nodup |& \
    ./vera++Report2checkstyleReport.perl > ${REPORT_DIR}/${REPORT_NAME}

retval=$(expr ${retval} + ${?})

exit ${retval}

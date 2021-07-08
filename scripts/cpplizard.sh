#!/bin/bash

WORKSPACE="$(cd $(dirname $0)/..;pwd)"
CC_THRESHOLD=15
LEN_THRESHOLD=300
NB_PARAM_THRESHOLD=7
LANGUAGE=cpp
ERROR_THRESHOLD=10000
MAX_CPU_NUM=$(nproc)
NB_THREAD=$[${MAX_CPU_NUM}-2]

exclude_files_pattern=(
    "*.pb.h"
    "*.pb.cc"
    "*/build/*"
)

EXCLUDE_FILES=""

for s in ${exclude_files_pattern[@]}
do
    EXCLUDE_FILES="${EXCLUDE_FILES} -x ${s}"
done

LIZARD_CMD="python ${WORKSPACE}/scripts/tools/lizard/lizard.py -l${LANGUAGE} ${EXCLUDE_FILES} -a${NB_PARAM_THRESHOLD} -L${LEN_THRESHOLD} -C${CC_THRESHOLD}"

# Single File Check
function check_dir() {
    d="$1"
    echo -e "CHECK FILE"
    ${LIZARD_CMD} "${d}"
}

if [[ $# -gt 0 ]]; then
    for d in "$@"; do
        echo "${d}"
        check_dir "${d}"
    done
    exit 0
fi

## All Module Check
set -ue

${LIZARD_CMD} ${WORKSPACE}
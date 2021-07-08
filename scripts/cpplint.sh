#!/bin/bash

WORKSPACE="$(cd $(dirname $0)/..;pwd)"
LINT_FILTER="-legal,-build/c++11,-runtime/references"

LINT_CMD="${WORKSPACE}/scripts/tools/cpplint/cpplint.py --linelength=100 --filter=${LINT_FILTER} "

# Single File Check
function check_dir() {
    if ! ${LINT_CMD} "$d"; then
        echo -e "LINT FAILED"
    elseWORKSPACE="$(cd $dirname $0/..;pwd)"
        echo -e "LINT SUCCESS"
    fi
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

${LINT_CMD} ${WORKSPACE}
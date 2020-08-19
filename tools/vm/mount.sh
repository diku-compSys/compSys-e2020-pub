#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
   echo "[CompSys] Scripts for mounting VM disk locally."
   echo "Usage:"
   echo "  ./mount.sh [dir]"
   echo "    dir:  The local directory to which the file should be mounted. Ensure that it is empty."
   exit 1;
fi

set -euo pipefail

VMPORT=1339
SSHPORT=22
MOUNTPOINT=$1

if [[ ! -d "${MOUNTPOINT}" ]] ; then
    echo "The given directory does not exist!"
    exit
fi

username=$(id -un)

if [ ${username} != "neumann" ] ; then
# Mount from host machine
    port=${VMPORT}
    host=neumann@localhost:.
else
    port=${SSHPORT}
    read -r host < .vm_host
fi

sshfs \
    ${host}  \
    ${MOUNTPOINT} \
    -ocache=no \
    -oport=${port}

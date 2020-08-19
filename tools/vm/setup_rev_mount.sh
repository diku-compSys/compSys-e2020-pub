#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
   echo "[CompSys] Scripts for setting up reverse-mounting local file system to VM."
   echo "Usage:"
   echo "  ./rev_mount.sh [dir]"
   echo "    dir:  The local directory that you want to get mounted on the VM"
   echo ""
   echo "We recommend that your restrict this at much as possible. Use only your"
   echo "CompSys-related directory. Mounting your entire file system can be a "
   echo "security risk."
   exit 1;
fi

set -euo pipefail

MOUNTPOINT=$1

if [[ ! -d "${MOUNTPOINT}" ]] ; then
    echo "The given directory does not exist!"
    exit
fi

echo ${MOUNTPOINT} > .revmountdir

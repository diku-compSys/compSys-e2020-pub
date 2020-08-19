#!/usr/bin/env bash

# echo "[CompSys] Scripts for setting up reverse-mounting local file system to VM."

set -euo pipefail

PORT=1339

ip=$(ifconfig | grep "inet " | grep -Fv 127.0.0.1 | awk '{print $2}')
username=$(id -un)
read -r mountdir < .revmountdir

# echo ${line} > vm_host.txt

echo ${username}@${ip}:${mountdir} > .vm_host

scp \
  -P ${PORT} \
  .vm_host \
  neumann@localhost:.

rm .vm_host

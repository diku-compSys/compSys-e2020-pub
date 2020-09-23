#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
   echo "[CompSys] Scripts for setting up x86prime tools."
   echo "Usage:"
   echo "  ./install.sh [dir]"
   echo "    dir:  The absolut tid to your tool location. On MacOS starts likely with /Users/"
   exit 1;
fi

declare -a tools=("gcc-online" "gdb-online" "prasm" "prerf" "primify" "prun")
x86prime_path=$1

if [[ ! -d "${x86prime_path}" ]] ; then
  echo "The given directory does not exist!"
  exit
fi

for tool in ${tools[@]}; do
  if [[ ! -e "${x86prime_path}/${tool}.py" ]] ; then
    echo "Cannot find ${tool}.py in ${x86prime_path} !!!"
    exit
  fi
done

for tool in ${tools[@]}; do
  echo '#!/usr/bin/env bash

set -euo pipefail
args=$(echo "${*:1}")
python3 '${x86prime_path}'/'${tool}'.py $args
' > /usr/local/bin/${tool}
  chmod a+x /usr/local/bin/${tool}
done

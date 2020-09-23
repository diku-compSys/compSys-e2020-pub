#!/usr/bin/env bash

echo ">> Setting up x86prime tools."

declare -a tools=("gcc-online" "gdb-online" "prasm" "prerf" "primify" "prun")
x86prime_path="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

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

mkdir -p /usr/local/lib/x86prime

for tool in ${tools[@]}; do
  cp ${x86prime_path}/${tool}.py /usr/local/lib/x86prime/
  echo '#!/usr/bin/env bash

set -euo pipefail
args=$(echo "${*:1}")
python3 /usr/local/lib/x86prime/'${tool}'.py $args
' > /usr/local/bin/${tool}
  chmod a+x /usr/local/bin/${tool}
done

echo "All done."
echo "Restart the terminal for the installation to have effect."

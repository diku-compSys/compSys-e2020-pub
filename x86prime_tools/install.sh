#!/usr/bin/env bash

echo ">> Installing x86prime tools."

# The list of tools
declare -a tools=("gcc-online" "gdb-online" "prasm" "prerf" "primify" "prun")
# Fint my path
x86prime_path="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Does the path exist?
if [[ ! -d "${x86prime_path}" ]] ; then
  echo "The given directory does not exist!"
  exit
fi

# Does the tools exist?
for tool in ${tools[@]}; do
  if [[ ! -e "${x86prime_path}/${tool}.py" ]] ; then
    echo "Cannot find ${tool}.py in ${x86prime_path} !!!"
    exit
  fi
done

# Path for tools
mkdir -p /usr/local/lib/x86prime

# Move each tool and create executable script for these.
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

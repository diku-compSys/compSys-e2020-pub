#!/usr/bin/env bash

echo ">> Uninstalling x86prime tools."

declare -a tools=("gcc-online" "gdb-online" "prasm" "prerf" "primify" "prun")

rm -r /usr/local/lib/x86prime

for tool in ${tools[@]}; do
  rm /usr/local/bin/${tool}
done

echo "All removed."

#!/usr/bin/env bash

# The following script can be used to generate a single folder with only the slides.
# You need to rerun this script every time you pull new slides from the repo.

# Exit immediately if any command below fails.
set -e

echo "Collecting slides in slides/"

mkdir -p slides
rm -f slides/*

cd material
for f in *; do
  cd $f
  for s in *.pdf; do
    if [[ $s != "*.pdf" ]]; then
      if [[ $s == "slides.pdf" ]]; then
        ln $s ../../slides/${f}.pdf
      else
        ln $s ../../slides/${f}-${s}
      fi
    fi
  done
  cd ..
done
cd ..

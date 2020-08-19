#!/usr/bin/env bash

set -euo pipefail

PORT=1339

ssh \
  -p ${PORT} \
  -o UserKnownHostsFile=/dev/null \
  -o StrictHostKeyChecking=no \
  -o LogLevel=ERROR \
  neumann@localhost

#!/usr/bin/bash

set -e

while [[ ! "$1" = "" ]]; do
  FILE="$1"
  BINDING="$(echo "$FILE" | sed -r 's,include/[^/]+,python/bindings,;s/[.]h$/_python.cc/')"
  MD5="$(md5sum "$FILE" | awk '{print $1}')"
  echo $FILE $MD5 $BINDING
  sed -i -r "s/(BINDTOOL_HEADER_FILE_HASH)\([a-z0-9]+\)/\1($MD5)/" "$BINDING" || true
  shift
done

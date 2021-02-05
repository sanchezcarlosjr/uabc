#! /bin/bash

set -o errexit  # the script ends if a command fails
set -o pipefail # the script ends if a command fails in a pipe
set -o nounset  # the script ends if it uses an undeclared variable
# set -o xtrace # if you want to debug

# Defaults values
logLevel=4 #4-debug;3-info;2-success;1-warning;0-error
alpha=true
beta="beta"

usage() {
  echo -n "
        SYNOPSIS
            $0 [-a|--alpha] [-b=val|--beta=val]
        DESCRIPTION
           Small template for bash shell scripts.
        OPTIONS
            -a     --alpha    Description for option a.
            -b=val --beta=val Description for option b.
            -h     --help     Displays this usage message.
        RETURN CODES
            1 If error 1 occurs.
            2 If error 2 occurs.
            ...
            N If error N occurs.
  "
}

# Log messages
error() {
  printf "\033[0;31m%s\033[0m\n" "$1"
}

warning() {
  if [[ $logLevel -gt 0 ]]; then
    printf "\033[1;33m%s\033[0m\n" "$1"
  fi
}

success() {
  if [[ $logLevel -gt 1 ]]; then
    printf "\033[0;32m%s\033[0m\n" "$1"
  fi
}

info() {
  if [[ $logLevel -gt 2 ]]; then
    printf "\033[0;34m%s\033[0m\n" "$1"
  fi
}

debug() {
  if [[ $logLevel -gt 3 ]]; then
    printf "\033[1;30m%s\033[0m\n" "$1"
  fi
}

uploadToDrive() {
  info "Uploading...";
  cp -r ../src/introduction-to-algorithms/* /run/user/1000/gvfs/google-drive:host=uabc.edu.mx,user=a361075/1qyWkx0OWTyTuZwY7TZSl2OM81XvC9P1e
}

params() {
  if [ $# -eq 0 ];
    then usage; exit 0;
  fi
  for param in "$@"; do
    case "${param}" in
      -d|--drive)
        uploadToDrive
        ;;
      -h|--help)
        usage
        exit 0
        ;;
       *)
        error "Unknown parameter ${param}"
        usage
        exit 1
        ;;
    esac
  done
}

main() {
  params "$@"
}

main "$@"
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
           UABC Environment. Please don't use sudo!
        OPTIONS
            -ap Datastructures environment
            -lisp Lisp scripts. Please install Clisp to continue.
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

shareCodeByGit() {
	code=$(ls -lt "src" | grep "^d" | awk  '{print $9}' | fzf);
	repository="src/$code"
	echo "git clone \
  		--depth 1 \
  		--filter=blob:none \
  		--no-checkout \
  		https://github.com/sanchezcarlosjr/uabc/ $repository\
	;
		cd 361075-CarlosEduardoSanchezTorres
		git sparse-checkout set $repository"
	echo "https://downgit.github.io/#/home?url=https://github.com/sanchezcarlosjr/uabc/tree/master/$repository"
}

createEnvironment() {
  mkdir images/tech
  mkdir compiler/tech
  sudo docker build . -t tech
}

compile() {
  workspace="$(pwd)/src";
  cp "$(pwd)"/etc/docker/compiler/"$2"/Dockerfile "$workspace";
  name=$(ls -lt "$workspace" | grep "^d" | grep "$1" | awk  '{print $9}' | fzf);
  project="$workspace/$name";
  compiler="$(pwd)"/etc/compiler.sh
  cd "$workspace";
  $compiler "$name"
  when-changed -1 -r "$project" -c "$compiler $name";
}

algorithm_prod() {
  compile datastructure cpp;
}

oop_test() {
  compile oop cpp;
}

shared() {
  compile shared cpp;
}

windows() {
  cd etc/windows
  vagrant up
}

params() {
  if [ $# -eq 0 ]; then
    usage
    exit 0
  fi
  for param in "$@"; do
    case "${param}" in
    -share-code)
	shareCodeByGit
	exit 0
       ;;
    -sh | --shared)
       shared
       exit 0
      ;;
    --lisp)
      name=$(ls -lt "src/lisp" | grep ".lisp" | awk  '{print $9}' | fzf);
      when-changed -1 -r "src/lisp/$name" -c clisp "src/lisp/$name";
      exit 0
      ;;
    -ap | --algorithm_prod)
      algorithm_prod
      exit 0
      ;;
    -o | --oop_test)
      oop_test
      exit 0
      ;;
    -w | --windows)
       windows
       exit 0
       ;;
    -h | --help)
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
  info "Loading..."
  params "$@"
}

main "$@"

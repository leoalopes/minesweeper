#!/usr/bin/env bash

# Parse arguments
while [[ $# -gt 0 ]]; do
	case $1 in
	--build)
		export BUILD=1
		shift
		;;
	--clean)
		export CLEAN_BUILD=1
		shift
		;;
	-* | --*)
		err "Unknown option $1"
		exit 1
		;;
	*)
		err "Illegal argument $1"
		exit 1
		;;
	esac
done

if [ -n "$BUILD" ]; then
	if [ -n "$CLEAN_BUILD" ]; then
		./scripts/build.sh --clean
	else
		./scripts/build.sh
	fi
fi

ctest --test-dir build --output-on-failure

#!/bin/sh

script_dir="`cd $(dirname $0); pwd`"

docker build -t insighttoolkit/fixedpointinversedeformationfield-test $script_dir

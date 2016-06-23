#!/bin/sh

script_dir="`cd $(dirname $0); pwd`"

docker run \
  --rm \
  -v $script_dir/../..:/usr/src/FixedPointInverseDeformationField \
    insighttoolkit/fixedpointinversedeformationfield-test \
      /usr/src/FixedPointInverseDeformationField/test/Docker/test.sh

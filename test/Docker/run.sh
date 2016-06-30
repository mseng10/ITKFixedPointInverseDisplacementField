#!/bin/sh

script_dir="`cd $(dirname $0); pwd`"

docker run \
  --rm \
  -v $script_dir/../..:/usr/src/FixedPointInverseDisplacementField \
    insighttoolkit/fixedpointinverseDisplacementfield-test \
      /usr/src/FixedPointInverseDisplacementField/test/Docker/test.sh

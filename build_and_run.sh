#!/bin/bash

rm -rf target && \
    mkdir target && \
    cd target && \
    cmake .. && \
    make -j$(nproc) && \
    ./asn1c_sequence_of_extensible_defect

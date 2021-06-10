#!/bin/bash

(cd asn1c && (test -f configure || autoreconf -iv) && ./configure && make -j$(nproc)) && \
(cd riebl_asn1c && (test -f configure || autoreconf -iv) && ./configure && make -j$(nproc)) && \
(cd mouse07410_asn1c && (test -f configure || autoreconf -iv) && ./configure && make -j$(nproc))

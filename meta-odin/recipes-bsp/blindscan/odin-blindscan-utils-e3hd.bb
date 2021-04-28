SRC_URI = "http://source.mynonpublic.com/download/odin-blindscan-utils-e3hd-${PV}-${SRC}.tar.gz"

PACKAGES = "odin-blindscan-dvbs-utils-e3hd odin-blindscan-dvbc-utils-e3hd"

RPROVIDES_odin-blindscan-dvbc-utils-e3hd += "virtual/blindscan-dvbc"
RPROVIDES_odin-blindscan-dvbs-utils-e3hd += "virtual/blindscan-dvbs"

FILES_odin-blindscan-dvbc-utils-e3hd = "${bindir}/tda1002x"
FILES_odin-blindscan-dvbs-utils-e3hd = "${bindir}/${BLINDSCAN_BINARY}"

require odin-blindscan-utils.inc

SRC_URI[md5sum] = "e6718bcdb6d451d7cb7b9cd1ddaa6721"
SRC_URI[sha256sum] = "4aec7a593d2030c3c219ae3604fb56b9d3366c2e8edf4bd2b7a552e2c4caaa8e"

COMPATIBLE_MACHINE = "^(axase3)$"

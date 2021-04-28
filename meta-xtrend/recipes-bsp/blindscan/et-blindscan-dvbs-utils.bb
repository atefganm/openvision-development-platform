DESCRIPTION = "Utils for DVB-S blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

COMPATIBLE_MACHINE = "^(et5x00|et6x00|et9x00|et4x00|et7x00|et8000|et10000)$"

PV = "1.1"

SRC_URI = "https://github.com/neo-pli-bsps/meta-xtrend/releases/download/Binaries-1.0/et-dvbs-blindscan-${PV}.zip"

PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES_${PN} += "virtual/blindscan-dvbs"

S = "${WORKDIR}"

do_compile() {
}

do_install() {
    install -d "${D}${bindir}"
    install -m 0755 "${S}/${BLINDSCAN_BINARY}" "${D}${bindir}"
}

INHIBIT_PACKAGE_STRIP = "1"

SRC_URI[md5sum] = "08343ba383c3b97356bd23ed82c0ce9f"
SRC_URI[sha256sum] = "5695f5c164f729d0c420f57cbd654216776d31d2d4d2ea37e544748d2b313ac6"

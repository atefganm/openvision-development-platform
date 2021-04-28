DESCRIPTION = "Utils for DVB-C blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

SRC_URI = "https://github.com/neo-pli-bsps/meta-xtrend/releases/download/Binaries-1.0/${MACHINE}-dvbc-blindscan-${PV}.zip"

PROVIDES += "virtual/blindscan-dvbc"
RPROVIDES_${PN} += "virtual/blindscan-dvbc"

S = "${WORKDIR}"

do_compile() {
}

do_install() {
	install -d "${D}${bindir}"
	install -m 0755 "${S}/tda1002x" "${D}${bindir}"
}

INHIBIT_PACKAGE_STRIP = "1"

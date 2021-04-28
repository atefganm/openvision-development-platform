SECTION = "base"
LICENSE = "CLOSED"

PROVIDES += "gb-bluetooth-util"
RPROVIDES_${PN} += "gb-bluetooth-util"

PR="${SRCDATE}.${SRCDATE_PR}"

SRC_URI = " \
    http://source.mynonpublic.com/gigablue/bluetooth/gb-bluetooth-util-${GBPLATFORM}-${PR}.tar.gz \
"

S="${WORKDIR}/gb-bluetooth-util-${GBPLATFORM}"

do_package_qa() {
}

PACKAGE_ARCH = "${MACHINE_ARCH}"
FILES_${PN}="/"

do_install() {
	install -d ${D}${prefix}/local/bin
	install -m 0755 ${S}/bsa_server ${D}${prefix}/local/bin/

	install -d ${D}${prefix}/local/lib
	install -d ${D}${prefix}/local${nonarch_base_libdir}/modules
	install -m 0644 ${S}/btusb.ko ${D}${prefix}/local${nonarch_base_libdir}/modules/btusb.ko
	install -m 0644 ${S}/bthid.ko ${D}${prefix}/local${nonarch_base_libdir}/modules/bthid.ko
}


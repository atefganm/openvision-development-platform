SUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE}"

RDEPENDS_${PN} += "firmware-mn8847x"

PV = "${KV}+${SRCDATE}"

SRC_URI = "http://source.mynonpublic.com/xcore/${MACHINE}-drivers-${KV}-${SRCDATE}.zip"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

do_compile() {
}

do_install() {
	install -d ${D}${nonarch_base_libdir}/modules/${KV}/extra
	install -d ${D}${sysconfdir}/modules-load.d
	for i in ${KOFILES} ; do
		install -m 0755 ${WORKDIR}/${i}.ko ${D}${nonarch_base_libdir}/modules/${KV}/extra/${i}.ko
		echo ${i} >> ${D}${sysconfdir}/modules-load.d/_${MACHINE}.conf
	done
}

FILES_${PN} += "${sysconfdir}/modules-load.d/_${MACHINE}.conf ${nonarch_base_libdir}/modules/${KV}/extra"

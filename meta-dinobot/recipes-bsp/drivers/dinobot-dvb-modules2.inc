SUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

PV = "${KV}+${SRCDATE}"

SRC_URI = "http://source.mynonpublic.com/dinobot/${MACHINETYPE}-drivers-${KV}-${SRCDATE}.tar.gz \
	file://loadmodules.sh \
	"

S = "${WORKDIR}/hiko"

INITSCRIPT_NAME = "loadmodules"
INITSCRIPT_PARAMS = "start 01 S ."

inherit update-rc.d

INHIBIT_PACKAGE_STRIP = "1"

FILES_${PN} += "${nonarch_base_libdir}/modules/${KV}/extra ${bindir}/komession ${sysconfdir}/init.d ${sysconfdir}/modules-load.d"

do_compile() {
}

do_package_qa() {
}

do_install_prepend() {
	rm -f ${S}/tntfs.ko
	find ${S}/ -type f -name "*load*" | xargs -r -L1 sed -i '/tntfs/d'
}

do_install() {
	install -d ${D}${nonarch_base_libdir}/modules/${KV}/extra
	install -d ${D}${bindir}
	install -m 0644 ${S}/*.ko ${D}${nonarch_base_libdir}/modules/${KV}/extra
	install -m 0644 ${S}/dvbmodule ${D}${nonarch_base_libdir}/modules/${KV}/extra
	install -m 0755 ${S}/komession ${D}${bindir}
	install -m 0755  ${S}/load ${D}${nonarch_base_libdir}/modules/${KV}/extra
	install -d ${D}${sysconfdir}/init.d/
	install -m 0755 ${WORKDIR}/loadmodules.sh ${D}${sysconfdir}/init.d/loadmodules
	install -d ${D}${sysconfdir}/modules-load.d
	echo "hi_media" >> ${D}${sysconfdir}/modules-load.d/_${MACHINE}.conf
}

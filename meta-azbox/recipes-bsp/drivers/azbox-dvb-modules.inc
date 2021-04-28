SUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

KV = "${KERNELVERSION}-opensat"

PV = "${KV}+${SRCDATE}"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

do_compile() {
}

FILES_${PN} += "${sysconfdir}/modules-load.d/_${MACHINE}.conf /lib/firmware/* ${nonarch_base_libdir}/modules/${KV}/extra"

do_install() {
    install -d ${D}${nonarch_base_libdir}/modules/${KV}/extra
    install -d ${D}${sysconfdir}/modules-load.d
    for i in llad em8xxx 865xi2c avl6211 avl2108 mxl241sf nimdetect sci 865xdvb; do
        install -m 0755 ${WORKDIR}/$i.ko ${D}${nonarch_base_libdir}/modules/${KV}/extra
        echo $i >> ${D}${sysconfdir}/modules-load.d/_${MACHINE}.conf
    done
    install -d ${D}${nonarch_base_libdir}/firmware
    install -m 0644 ${WORKDIR}/dvb-fe-avl2108.fw ${D}${nonarch_base_libdir}/firmware/dvb-fe-avl2108.fw
    install -m 0644 ${WORKDIR}/dvb-fe-avl2108-blind.fw ${D}${nonarch_base_libdir}/firmware/dvb-fe-avl2108-blind.fw
    install -m 0644 ${WORKDIR}/dvb-fe-avl6211.fw ${D}${nonarch_base_libdir}/firmware/dvb-fe-avl6211.fw
}

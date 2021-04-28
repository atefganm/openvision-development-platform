DESCRIPTION = "Mount sh4 root as usb."
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://${OPENVISION_BASE}/LICENSE;md5=1ebbd3e34237af26da5dc08a4e440464"

RDEPENDS_${PN} = "kernel-module-yaffs"

COMPATIBLE_MACHINE = "^(spark|spark7162)$"

SRC_URI = "file://mountsh4"

FILES_${PN} = "${sysconfdir}"

do_install () {
	install -d ${D}${sysconfdir}/init.d
	install ${WORKDIR}/mountsh4 ${D}${sysconfdir}/init.d
}

INITSCRIPT_NAME = "mountsh4"
INITSCRIPT_PARAMS = "start 39 S ."

inherit update-rc.d


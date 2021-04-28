DESCRIPTION = "VFD controller for SH4"

require sh4-apps.inc

do_install_append() {
	install -d ${D}${sbindir}
	install -m 0755 ${WORKDIR}/build/${PN} ${D}${sbindir}/
}

FILES_${PN} = "${sbindir}"

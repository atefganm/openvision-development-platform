SH4APPBIN ?= "${PN}"

do_install_append() {
	install -d ${D}${base_bindir}
	install -m 0755 ${WORKDIR}/build/${SH4APPBIN} ${D}${base_bindir}/
}

FILES_${PN} = "${base_bindir}"

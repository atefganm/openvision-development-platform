DESCRIPTION = "Tools for changing internal flash"
LICENSE = "CLOSED"

SRC_URI = "file://fw_env.config \
	file://fw_printenv \
	file://fw_setenv \
	${@bb.utils.contains_any("MACHINE", "spark spark7162", "file://setspark.sh", "", d)} \
	file://flash_erase \
	"

FILES_${PN} = "${localstatedir}/* /bin/* /sbin/*"

do_install () {
	install -d ${D}${localstatedir}
	install -m 644 ${WORKDIR}/fw_env.config ${D}${localstatedir}/
	install -d ${D}${base_bindir}
	install -m 755 ${WORKDIR}/fw_printenv ${D}${base_bindir}/
	install -m 755 ${WORKDIR}/fw_setenv ${D}${base_bindir}/
	if [ "${MACHINE}" = "spark" -o "${MACHINE}" = "spark7162" ]; then
		install -m 755 ${WORKDIR}/setspark.sh ${D}${base_bindir}/
	fi
	install -d ${D}${base_sbindir}
	install -m 755 ${WORKDIR}/flash_erase ${D}${base_sbindir}/
}

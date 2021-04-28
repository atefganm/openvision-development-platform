FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append_sh4 = " file://modutils-sh4.sh"

do_install_append_sh4() {
	install -m 0755 ${WORKDIR}/modutils-sh4.sh ${D}${sysconfdir}/init.d/modutils.sh
}

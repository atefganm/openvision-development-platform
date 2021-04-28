inherit upx_compress

do_install_append() {
	echo 'DROPBEAR_RSAKEY_ARGS="-t ecdsa -s 521"' >> ${D}${sysconfdir}/default/dropbear
}

CONFFILES_${PN} += "${D}${sysconfdir}/default/dropbear"

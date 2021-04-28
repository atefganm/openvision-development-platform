DESCRIPTION = "MME image library"

require sh4-apps.inc

FILES_${PN} += "${libdir}/libmme_host.so"
FILES_${PN}-dev = "${libdir}/libmme_host.la"


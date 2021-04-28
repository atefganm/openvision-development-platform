DESCRIPTION = "E2 Chromium Plugin"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

inherit rm_python_pyc compile_python_pyo no_python_src

PR = "20170324_r0"
SRC_URI = "http://code.vuplus.com/download/chromium/e2plugin-chromium-vuplus_${PR}.tar.gz"

DEPENDS[pkgvarcheck] = "chromium-browser"
RDEPENDS_${PN} = "chromium-browser"

do_install_append() {
	install -d ${D}${libdir}/enigma2/python/Plugins/Extensions/Chromium
	cp -aRf ${WORKDIR}/e2plugin/* ${D}${libdir}/enigma2/python/Plugins/Extensions/Chromium/
}

do_package_qa() {
}

PROVIDES += "enigma2-plugin-extensions-chromium"
RPROVIDES_${PN} += "enigma2-plugin-extensions-chromium"

FILES_${PN} = "/"

SRC_URI[md5sum] = "525ab918ae8c5e41ffec3e57d748da25"
SRC_URI[sha256sum] = "d671f1dfeaefd8f3d05a79348e86c7debd40403cc5f9d59780ccb04c7fa655cf"

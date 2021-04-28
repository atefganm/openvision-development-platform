SUMMARY = "AML remote setup"
LICENSE = "GPLv2"
SECTION = "base"
PRIORITY = "required"

require conf/license/license-gplv2.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit gitpkgv

PV = "git${SRCPV}"
PKGV = "git${GITPKGV}"

SRC_URI = "git://github.com/OpenVisionE2/amremote.git;protocol=git"

S = "${WORKDIR}/git"

do_compile() {
    oe_runmake
}

do_install() {
	install -d ${D}${bindir}
	install -d ${D}${sysconfdir}/amremote
	install -m 0755 ${S}/remotecfg ${D}${bindir}/
	install -m 0644 ${S}/wetek0.conf ${D}${sysconfdir}/amremote/remote.conf
	install -m 0644 ${S}/*.conf ${D}${sysconfdir}/amremote/
}

FILES_${PN} = "${bindir} ${sysconfdir}"

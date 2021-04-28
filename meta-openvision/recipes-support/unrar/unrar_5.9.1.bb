SUMMARY = "RAR archivers"
LICENSE = "GPLv2"

LIC_FILES_CHKSUM = "file://license.txt;md5=fc9c335ec05a5f36764ef9ce7a79daa1"

HOMEPAGE = "http://www.rarlab.com"

SRC_URI = "http://www.rarlab.com/rar/unrarsrc-${PV}.tar.gz \
        file://makefile-nostrip.patch"

SRC_URI[md5sum] = "b1e3f57234288b18f5f9dbe8ef198c3b"
SRC_URI[sha256sum] = "0eb1d1b8e02102fccae775a6d6b79336b69e2cf90e2045de92594dcfb58de100"

S = "${WORKDIR}/unrar"

BBCLASSEXTEND = "native"
NATIVE_INSTALL_WORKS = "1"

EXTRA_OEMAKE = "-f makefile DESTDIR=${D}${exec_prefix}"

do_compile() {
    oe_runmake
}

do_install() {
    oe_runmake install
}


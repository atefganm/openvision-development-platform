SUMMARY = "halt for ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "^(gbtrio4k|gbip4k)$"

RDEPENDS_${PN} = "harfbuzz"

SRCDATE = "20190907"

PV = "${SRCDATE}"

INITSCRIPT_NAME = "suspend"
INITSCRIPT_PARAMS = "start 89 0 ."
inherit update-rc.d

SRC_URI  = "http://source.mynonpublic.com/gigablue/mv200/gbmv200-hihalt-${SRCDATE}.tar.gz \
    file://suspend.sh \
"

SRC_URI[md5sum] = "a8fa73b3ef6bbabc32c59bcf7fcc1864"
SRC_URI[sha256sum] = "f8c592c5448576df8e52b32135cb0d0a064f4953fa499ed555baa2e8c68a16aa"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/hihalt ${D}${bindir}
    install -d ${D}${sysconfdir}/init.d
    install -m 0755 ${S}/suspend.sh ${D}${sysconfdir}/init.d/suspend
}

do_package_qa() {
}

FILES_${PN}  = "${bindir}/hihalt ${sysconfdir}/init.d"

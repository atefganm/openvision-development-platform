SRCDATE = "20191212"

do_install_append() {
	install -d ${D}${nonarch_base_libdir}/firmware/brcm
	install -d ${D}${sysconfdir}/modules-load.d
	install -m 0644 ${WORKDIR}/brcmfmac43455-sdio.bin ${D}${nonarch_base_libdir}/firmware/brcm
	install -m 0644 ${WORKDIR}/brcmfmac43455-sdio.txt ${D}${nonarch_base_libdir}/firmware/brcm
	install -m 0644 ${WORKDIR}/*.ko ${D}${nonarch_base_libdir}/modules/${KV}/extra
	install -m 0644 ${WORKDIR}/*.conf ${D}${sysconfdir}/modules-load.d
}

FILES_${PN} += "${nonarch_base_libdir}/firmware/brcm"

require dinobot-dvb-modules2.inc

SRC_URI += "file://u53x-platform.zip file://dinobot-sdio-wifi.zip"

SRC_URI[md5sum] = "885f3611ad924defcf1e1e1e590e4e4d"
SRC_URI[sha256sum] = "330142ee69ca19575d99c14d0cb230c89ef027bdee39c5416a67e63b8a0588a3"

COMPATIBLE_MACHINE = "^(arivacombo)$"

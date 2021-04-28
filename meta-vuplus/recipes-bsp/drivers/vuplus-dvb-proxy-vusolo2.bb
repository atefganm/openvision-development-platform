require vuplus-dvb-proxy.inc

SRCDATE = "20190429"
SRCDATE_PR = "r0"

pkg_postinst_${PN}_append () {
	if [ ! -f $D${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko ]; then
		ln -s ${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm7356.ko $D${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko
	fi
}

SRC_URI[md5sum] = "143fcd1b984990b77a115f265553198a"
SRC_URI[sha256sum] = "babe10ec849928fbbd40a07a557b5cd70d314755c66a7fdeca2ccaac454d5e02"

COMPATIBLE_MACHINE = "^(vusolo2)$"
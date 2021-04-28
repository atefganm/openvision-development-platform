require vuplus-dvb-proxy.inc

SRCDATE = "20190429"
SRCDATE_PR = "r0"

pkg_postinst_${PN}_append () {
	if [ ! -f $D${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko ]; then
		ln -s ${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm7241.ko $D${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko
	fi
}

SRC_URI[md5sum] = "f32ed929fb65645073984a4ea53d3981"
SRC_URI[sha256sum] = "a7adfb721e6d431d04410dee07ff1404909b56d3d6467617cb7485f4e4990b19"

COMPATIBLE_MACHINE = "^(vusolose)$"
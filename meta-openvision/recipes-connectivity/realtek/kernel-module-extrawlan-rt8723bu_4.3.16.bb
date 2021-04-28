DESCRIPTION = "Driver for Realtek USB wireless devices"
HOMEPAGE = "http://www.realtek.com/"
SECTION = "kernel/modules"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://README.md;md5=7c7799e38fb24c3c8a114bac8e2517de"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit module machine_kernel_pr

SRC_URI = " \
	git://github.com/lwfinger/rtl8723bu.git;branch=master \
	file://rt8723bu-makefile.patch \
	file://rt8723bu-gcc5.patch \
	"

S = "${WORKDIR}/git"

EXTRA_OEMAKE = "KSRC=${STAGING_KERNEL_DIR}"

do_install() {
	install -d ${D}${nonarch_base_libdir}/modules/${KERNEL_VERSION}/kernel/drivers/net/wireless
	install -m 0644 ${S}/8723bu.ko ${D}${nonarch_base_libdir}/modules/${KERNEL_VERSION}/kernel/drivers/net/wireless
}

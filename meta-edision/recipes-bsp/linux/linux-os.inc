DESCRIPTION = "Linux kernel for ${MACHINE}"
SECTION = "kernel"
LICENSE = "GPLv2"

PACKAGE_ARCH = "${MACHINE_ARCH}"

DEPENDS += "xz-native bc-native"

KERNEL_EXTRA_ARGS = "EXTRA_CFLAGS=-Wno-attribute-alias"

# Pick up shared functions
inherit kernel machine_kernel_pr samba_change_dialect

export OS = "Linux"

S = "${WORKDIR}/linux-${PV}"
B = "${WORKDIR}/build"

KERNEL_IMAGEDEST = "tmp"

pkg_postrm_${KERNEL_PACKAGE_NAME}-image () {
}

do_rm_work() {
}

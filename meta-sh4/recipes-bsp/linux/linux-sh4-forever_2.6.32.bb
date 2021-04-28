require linux-sh4.inc

COMPATIBLE_MACHINE = "^(forever_2424hd|forever_3434hd|forever_9898hd|forever_nanosmart)$"

STXNUMBER = "stxh205"

SRC_URI = "https://github.com/OpenVisionE2/linux-sh4-${KERNELVERSION}.71/archive/stmicro-4g.tar.gz \
	file://defconfig \
	file://${OPENVISION_BASE}/meta-openvision/recipes-linux/kernel-patches/kernel-add-support-for-gcc${VISIONGCCVERSION}.patch \
	file://st-coprocessor.h \
	file://linux-sh4-${MACHINE}_setup_stm24_${STM_PATCH_STR}.patch \
	file://linux-sh4-4g-stmmac_stm24_${STM_PATCH_STR}.patch \
	file://timeconst.patch \
	file://kmap.patch \
	"

SRC_URI[md5sum] = "769a5383eadabf82d9d8930f98ffb1fe"
SRC_URI[sha256sum] = "310ea67421c35227e8fc1bc847c154758ca0908683c18a8724065ad720d61e33"

S = "${WORKDIR}/linux-sh4-${KERNELVERSION}.71-stmicro-4g"

require conf/machine/include/oem-sh4.inc
require conf/machine/include/ird-ubi-image.inc

BOX_BRAND = "forever"

PREFERRED_PROVIDER_virtual/kernel = "linux-sh4-${BOX_BRAND}"

ROOTFS_FILE = "root.img"
KERNEL_FILE = "uImage"

IMAGE_FSTYPES += "tar.gz"

AUDIOELF = "companion_h205_audio.bin"
VIDEOELF = "companion_h205_video_Ax.bin"
VIDEOELF2 = "companion_h205_video_Bx.bin"

SOC_FAMILY = "stih205"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	kernel-module-scsi-wait-scan \
	stlinux24-sh4-stmfb-firmware-stxh205 \
	stlinux24-sh4-stxh205-fdma-firmware \
	stlinux24-sh4-stxh205-fdma-firmware-extra \
	stlirc \
	"

MACHINE_FEATURES += "hdmicec 4thgsh4 resellerid"

CAN_USE_ENIGMA2_IN_FLASH = "1"

RCTYPE = "22"
RCNAME = "hs9510"

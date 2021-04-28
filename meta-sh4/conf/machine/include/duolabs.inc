require conf/machine/include/oem-sh4.inc
require conf/machine/include/normal-sh4-image.inc
require conf/machine/include/sh4-jffs2.inc

BOX_BRAND = "duolabs"

PREFERRED_PROVIDER_virtual/kernel = "linux-sh4-${BOX_BRAND}"

ROOTFS_FILE = "root.img"
KERNEL_FILE = "uImage"

IMAGE_FSTYPES = "tar.gz"

MACHINE_FEATURES += "ci smallflash RCA SCART"

AUDIOELF = "audio_7100.elf"
VIDEOELF = "video_7100.elf"

SOC_FAMILY = "sti7100"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	firmware-sh4 \
	kernel-module-zram \
	stlinux24-sh4-stx7100-fdma-firmware \
	stlirc \
	"

CAN_USE_ENIGMA2_IN_FLASH = "0"

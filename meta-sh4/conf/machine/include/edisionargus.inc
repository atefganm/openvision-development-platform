require conf/machine/include/oem-sh4.inc
require conf/machine/include/normal-sh4-image.inc

BOX_BRAND = "edisionargus"

PREFERRED_PROVIDER_virtual/kernel = "linux-sh4-${BOX_BRAND}"

IMAGE_FSTYPES += "tar.gz"

AUDIOELF = "audio_7100.elf"
VIDEOELF = "video_7109.elf"

SOC_FAMILY = "sti7109"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	fp-control \
	stlinux24-sh4-stx7109-fdma-firmware \
	stlirc \
	"

MACHINE_FEATURES += "ci middleflash RCA YUV SCART"

CAN_USE_ENIGMA2_IN_FLASH = "1"

RCTYPE = "17"
RCNAME = "vip_1"

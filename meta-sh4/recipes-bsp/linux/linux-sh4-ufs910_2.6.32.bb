require linux-sh4.inc

COMPATIBLE_MACHINE = "^(ufs910|adb_box)$"

STXNUMBER = "stx7100"

SRC_URI_append = " \
	file://linux-sh4-stx7100_fdma_fix_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-sh4-sata_32bit_fix_stm24_${STM_PATCH_STR}.patch;patch=1 \
	${@bb.utils.contains("MACHINE", "ufs910", "file://linux-sh4-sata_stx7100_fix_stm24_${STM_PATCH_STR}.patch;patch=1", "", d)} \
	file://linux-sh4-${MACHINE}_setup_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-usbwait123_stm24.patch;patch=1 \
	file://linux-sh4-ufs910_reboot_stm24_${STM_PATCH_STR}.patch;patch=1 \
	${@bb.utils.contains("MACHINE", "ufs910", "file://linux-sh4-smsc911x_dma_stm24_${STM_PATCH_STR}.patch;patch=1", "", d)} \
	file://linux-sh4-i2c-st40-pio_stm24_${STM_PATCH_STR}.patch;patch=1 \
	"

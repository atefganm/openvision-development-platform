require linux-sh4.inc

COMPATIBLE_MACHINE = "^(vip1_v1|vip1_v2|vip2|hl101|octagon1008|tf7700|fortis_hdbox)$"

STXNUMBER = "stx7109"

SRC_URI_append = " \
	file://linux-sh4-${MACHINE}_setup_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-usbwait123_stm24.patch;patch=1 \
	file://linux-sh4-stmmac_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-sh4-i2c-st40-pio_stm24_${STM_PATCH_STR}.patch;patch=1 \
	"

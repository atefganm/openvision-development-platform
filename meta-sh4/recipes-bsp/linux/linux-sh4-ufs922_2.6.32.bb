require linux-sh4.inc

COMPATIBLE_MACHINE = "^(ufs922|ufc960)$"

STXNUMBER = "stx7109"

SRC_URI_append = " \
	file://linux-sh4-ufs922_setup_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-sh4-stmmac_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-sh4-i2c-st40-pio_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-sh4-fortis_hdbox_i2c_st40_stm24_${STM_PATCH_STR}.patch;patch=1 \
	"

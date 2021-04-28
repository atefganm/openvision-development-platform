require linux-sh4.inc

COMPATIBLE_MACHINE = "^(cuberevo|cuberevo_250hd|cuberevo_2000hd|cuberevo_3000hd|cuberevo_mini|cuberevo_mini2|cuberevo_9500hd|ipbox55|ipbox99|ipbox9900|arivalink200)$"

STXNUMBER = "stx7109"

SRC_URI_append = " \
	file://linux-sh4-${MACHINE}_setup_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-sh4-i2c-st40-pio_stm24_${STM_PATCH_STR}.patch;patch=1 \
	${@bb.utils.contains("BOX_BRAND", "cuberevo", "file://linux-sh4-cuberevo_rtl8201_stm24_${STM_PATCH_STR}.patch;patch=1", "file://linux-sh4-ipbox_bdinfo_stm24_${STM_PATCH_STR}.patch;patch=1", d)} \
	${@bb.utils.contains("MACHINE", "cuberevo_250hd", "file://linux-sh4-${MACHINE}_sound_stm24_${STM_PATCH_STR}.patch;patch=1", "", d)} \
	${@bb.utils.contains_any("MACHINE", "ipbox9900 arivalink200", "file://linux-sh4-ipbox_dvb_ca_stm24_${STM_PATCH_STR}.patch;patch=1", "", d)} \
	"

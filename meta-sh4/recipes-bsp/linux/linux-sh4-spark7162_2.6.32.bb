require linux-sh4.inc

COMPATIBLE_MACHINE = "^(spark7162|sagemcom88|atevio7500)$"

STXNUMBER = "stx7105"

SRC_URI_append = " \
	file://linux-sh4-${MACHINE}_setup_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-sh4-stmmac_stm24_${STM_PATCH_STR}.patch;patch=1 \
	file://linux-sh4-lmb_stm24_${STM_PATCH_STR}.patch;patch=1 \
	${@bb.utils.contains("MACHINE", "sagemcom88", "file://linux-sh4-${MACHINE}_sound_stm24_${STM_PATCH_STR}.patch;patch=1", "", d)} \
	"

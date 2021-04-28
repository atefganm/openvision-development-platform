EXTRA_OECONF_append_pn-enigma2 = "--with-lcddev=/dev/null --with-alphablendingacceleration=always"

SOC_FAMILY = "hisi3798cv200"
HICHIPSET = "3798cv200"
CHIPSET = "Hi3798Cv200"

require conf/machine/include/dinobot-cortexa15.inc
require conf/machine/include/dinobot-emmc.inc

MACHINETYPE = "u532"

MTD_KERNEL = "mmcblk0p10"
MTD_ROOTFS = "mmcblk0p13"

SDCARDIMG = "no"

MACHINE_FEATURES += "7segment hiaccel"

IMAGEDIR = "e2/update"

STB_PLATFORM = "${MACHINETYPE}"

EXTRA_OECONF_append_pn-enigma2 = "--with-lcddev=/dev/null --with-alphablendingacceleration=always"

SOC_FAMILY = "hisi3798cv200"
HICHIPSET = "3798cv200"
CHIPSET = "Hi3798Cv200"

KERNEL_MODULE_AUTOLOAD += "88x2bu"

require conf/machine/include/dinobot-cortexa15.inc
require conf/machine/include/dinobot-emmc.inc

MACHINETYPE = "u53"

MTD_KERNEL = "mmcblk0p10"
MTD_ROOTFS = "mmcblk0p13"

SDCARDIMG = "no"

MACHINE_FEATURES += "7segment dvb-c blindscan-dvbs textlcd hiaccel"

IMAGEDIR = "dinobot/${MACHINETYPE}"

STB_PLATFORM = "${MACHINETYPE}"

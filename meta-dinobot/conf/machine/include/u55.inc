EXTRA_OECONF_append_pn-enigma2 = "--with-lcddev=/dev/null --with-alphablendingacceleration=always"

SOC_FAMILY = "hisi3798mv200"
HICHIPSET = "3798mv200"
CHIPSET = "Hi3798Mv200"

KERNEL_MODULE_AUTOLOAD += "rt8188fu"

require conf/machine/include/dinobot-cortexa15.inc
require conf/machine/include/dinobot-ubi.inc

MACHINETYPE = "u55"

MTD_KERNEL = "mtd10"
MTD_ROOTFS = "mtd11"

SDCARDIMG = "no"

MACHINE_FEATURES += "7segment blindscan-dvbs textlcd hiaccel RCA"

STB_PLATFORM = "${MACHINETYPE}"

EXTRA_ALSA = "mv200"

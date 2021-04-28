EXTRA_OECONF_append_pn-enigma2 = "--with-lcddev=/dev/null --with-alphablendingacceleration=always"

SOC_FAMILY = "hisi3798mv200"
HICHIPSET = "3798mv200"
CHIPSET = "Hi3798Mv200"

KERNEL_MODULE_AUTOLOAD += "8192eu"

require conf/machine/include/dinobot-cortexa15.inc
require conf/machine/include/dinobot-emmc.inc

MACHINETYPE = "u56"

MTD_KERNEL = "mmcblk0p9"
MTD_ROOTFS = "mmcblk0p10"

SDCARDIMG = "no"

MACHINE_FEATURES += "blindscan-dvbs 7segment textlcd hiaccel RCA"

IMAGEDIR = "axas/axasc4k"

STB_PLATFORM = "${MACHINETYPE}"

EXTRA_ALSA = "mv200"

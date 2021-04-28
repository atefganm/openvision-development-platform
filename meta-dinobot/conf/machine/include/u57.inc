EXTRA_OECONF_append_pn-enigma2 = "--with-lcddev=/dev/null --with-alphablendingacceleration=always"

SOC_FAMILY = "hisi3798mv200"
HICHIPSET = "3798mv200"
CHIPSET = "Hi3798Mv200"

KERNEL_MODULE_AUTOLOAD += "rt8188fu"

require conf/machine/include/dinobot-cortexa15.inc
require conf/machine/include/dinobot-emmc.inc

MACHINETYPE = "u57"

SDCARDIMG = "no"

MACHINE_FEATURES += "blindscan-dvbs 7segment hiaccel RCA"

STB_PLATFORM = "${MACHINETYPE}"

EXTRA_ALSA = "mv200"

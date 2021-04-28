# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

BOX_BRAND = "gigablue"

KERNEL_FILE = "kernel.bin"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gigablue-ddbootup \
	kernel-module-rtl8192cu \
	firmware-rtl8192cu \
	firmware-rtl8192cufw \
	kernel-module-extrawlan-rtl8192eu \
	firmware-rtl8192eu \
	kernel-module-extrawlan-rt8812au \
	kernel-module-extrawlan-rt8822bu \
	gstreamer1.0-plugin-dvbmediasink \
	${@bb.utils.contains("MACHINE_FEATURES", "hisi", "" , "gigablue-cfe", d)} \
	"

DVBPROVIDER = "kernel"

PREFERRED_PROVIDER_virtual/kernel = "linux-gigablue"

KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

MACHINE_FEATURES += "alsa hdmicec switchoff blindscan-tbs gigablue HDMI"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/soc-family.inc

BLINDSCAN_BINARY = "gigablue_blindscan"

RCNAME ?= "gb0"

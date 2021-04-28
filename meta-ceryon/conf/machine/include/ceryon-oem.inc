# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

BOX_BRAND = "ceryon"

KERNEL_FILE = "kernel.bin"

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	${@bb.utils.contains_any("MACHINE", "e4hdultra protek4k", "", "ceryon-shutdown", d)} \
	gstreamer1.0-plugin-dvbmediasink \
	${@bb.utils.contains("MACHINE_FEATURES", "emmc", "ceryon-resizerootfs" , "", d)} \
	gstreamer1.0-libav \
	"

require conf/machine/include/soc-family.inc

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

PREFERRED_PROVIDER_virtual/kernel = "linux-ceryon"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "ceryon-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "ceryon-blindscan-utils"

MACHINE_FEATURES += "alsa hdmicec switchoff videoenhancement blindscan-tbs HDMI"

BOOTLOGO_FILENAME = "splash.bin"

BLINDSCAN_BINARY = "ceryon_blindscan"

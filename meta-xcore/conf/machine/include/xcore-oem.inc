# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

KERNELVERSION = "4.11"

BOX_BRAND = "xcore"

KERNEL_FILE = "kernel.bin"

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	xcore-dvb-modules-${MACHINE} \
	kernel-module-extrawlan-rt8723bs \
	firmware-rtl8723bs \
	kernel-module-hci-uart \
	gstreamer1.0-plugin-dvbmediasink \
	gstreamer1.0-libav \
	"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "xcore-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "xcore-blindscan-utils"

PREFERRED_PROVIDER_virtual/kernel = "linux-xcore"
PREFERRED_VERSION_linux-xcore = ${KERNELVERSION}"

MACHINE_FEATURES += "alsa switchoff hdmicec HDMI"

BOOTLOGO_FILENAME = "splash.bin"

KERNEL_MODULE_AUTOLOAD += "\
	r8723bs \
	hci_uart \
	"

RCNAME = "xcore1"

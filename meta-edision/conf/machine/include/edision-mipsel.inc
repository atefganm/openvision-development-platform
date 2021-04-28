TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

require conf/machine/include/tune-mips32.inc

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

BOX_BRAND = "edision"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	os-dvb-modules-${MACHINE} \
	kernel-module-extrawlan-rt8723bs \
	firmware-rtl8723bs \
	kernel-module-hci-uart \
	kernel-module-rt2800usb \
	enigma2-plugin-drivers-dvb-usb-opticombo \
	gstreamer1.0-plugin-dvbmediasink \
	edision-splash \
	"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

PREFERRED_PROVIDER_virtual/kernel = "linux-os"

KERNEL_IMAGETYPE = "vmlinux.gz"
KERNEL_CONSOLE = "ttyS0,115200n8"

KERNEL_MODULE_AUTOLOAD += "\
	r8723bs \
	hci_uart \
	"

MACHINE_FEATURES += "alsa switchoff osdposition hdmicec dvb-c videoenhancement HDMI"

require conf/machine/include/rootfs-ubi.inc

KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

STB_PLATFORM = "edisionmips"

KERNELVERSION = "4.8.3"

SOC_FAMILY = "bcm73625"

require gigablue-mips.inc

MACHINE_FEATURES += "wol osdanimation blindscan-dvbs blindscan-dvbc"

# Broken bootloader can only flash around 100 MB
FLASHSIZE = "96"

DVBSKYPROVIDER = "kernel"

PREFERRED_VERSION_linux-gigablue = "${KERNELVERSION}"

IMAGE_FSTYPES ?= "ubi"
MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gigablue-dvb-modules-gb73625 \
	"

DVBMEDIASINK_CONFIG = "--with-wmv --with-wma --with-pcm --with-dts --with-eac3 --with-amr --with-h265 --with-vb6 --with-vb8 --with-spark"

GLIBC_EXTRA_OECONF = "--with-tls --with-__thread"

STB_PLATFORM = "gb73625"

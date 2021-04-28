# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

require conf/machine/include/libeplayer-sh4-condition.inc

KERNELVERSION = "2.6.32"

IMAGEDIR = "enigma2"

KERNEL_MODULE_PACKAGE_SUFFIX = ""

TARGET_ARCH = "sh4"
DEFAULTTUNE = "sh4"

GCCVERSION_sh4 = "4.9.4"
GLIBCVERSION_sh4 = "2.25"

HOSTTOOLS_NONFATAL += "whoami"

OLDEST_KERNEL = "${KERNELVERSION}"
PREFERRED_VERSION_kernel-module-extrawlan-rt8812au = "4.3.14"
PREFERRED_VERSION_directfb = "1.7.7"
PREFERRED_PROVIDER_virtual/egl = "libstgles"
PREFERRED_PROVIDER_virtual/libgles1 = "libstgles"
PREFERRED_PROVIDER_virtual/enigma2-mediaservice = "enigma2-plugin-systemplugins-servicemp3epl"

SERIAL_CONSOLE = "115200 ttyAS0"

DVBPROVIDER = "kernel"

MACHINE_FEATURES += "alsa ext2 usbhost serial dvb-c switchoff textlcd usbconsole sh4stb ${MACHINE} HDMI"

DISTRO_FEATURES_append = " libsigc2"

KERNEL_IMAGETYPE = "uImage"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dtsdownmix --with-eac3"

# Add uImage in tar image boot directory
IMAGE_CMD_tar_prepend = "\
    cp -f ${DEPLOY_DIR_IMAGE}/uImage ${IMAGE_ROOTFS}/boot/${KERNEL_FILE}; \
    "
	
MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	devinit \
	evremote2 \
	sh4-dvb-modules \
	stfbcontrol \
	stslave-fw \
	ustslave \
	wait4button \
	libpcre \
	"

EXTRA_IMAGEDEPENDS += "\
	libpcre \
	"

require conf/machine/include/tune-sh4.inc
require conf/machine/include/soc-family.inc

EXTRA_OECONF_append_pn-enigma2 = " --with-sh4stb"

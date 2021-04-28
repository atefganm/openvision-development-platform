KERNELVERSION = "3.9.6"

SOC_FAMILY = "bcm7325"

require gigablue-mips.inc

MACHINE_FEATURES += "blindscan-dvbc ci SCART YUV RCA"

PREFERRED_VERSION_linux-gigablue = "${KERNELVERSION}"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gigablue-dvb-modules-gb7325 \
	"

DVBMEDIASINK_CONFIG = "--with-wmv"

GLIBC_EXTRA_OECONF = "--with-tls"

STB_PLATFORM = "gb7325"

PREFERRED_VERSION_kernel-module-extrawlan-rt8812au = "4.3.14"

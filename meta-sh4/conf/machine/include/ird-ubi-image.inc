MACHINE_FEATURES += "smallflash"

inherit image_types_sh4ubi

MKUBIFS_ARGS = "${@bb.utils.contains("MACHINE_FEATURES", "4thgsh4", "-m 2048 -e 129024 -c 1456 -x zlib -U", "-m 2048 -e 129024 -c 768 -x zlib -U", d)}"
UBINIZE_ARGS = "-m 2048 -p 128KiB -s 512 -x 1"

UBINIZE_DATAVOLSIZE = "${@bb.utils.contains("MACHINE_FEATURES", "4thgsh4", "179601408", "94961664", d)}"

EXTRA_IMAGECMD_COMPAT = " --eraseblock=0x20000 -n -l "

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	forever-logo-cfe \
	mtd-utils-ubifs \
	"

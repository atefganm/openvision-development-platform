DESCRIPTION = "SH4 fup tool for creating flashable images"

require sh4-native-tools.inc

LDFLAGS += "-lz"

CFLAGS += "-DUSE_ZLIB"
